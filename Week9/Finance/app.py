import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    
    stocks = db.execute(
        "SELECT symbol, SUM(shares) as total FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total > 0",
        user_id
    )
    
    user = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = user[0]["cash"]
    total = cash
    
    for stock in stocks:
        info = lookup(stock["symbol"])
        if info:
            stock["name"] = info["name"]
            stock["price"] = info["price"]
            stock["value"] = stock["total"] * info["price"]
            total = total + stock["value"]
    
    return render_template("index.html", stocks=stocks, cash=cash, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        
        if not symbol:
            return apology("must provide symbol", 400)
        
        try:
            shares = int(shares)
            if shares <= 0:
                return apology("shares must be positive", 400)
        except ValueError:
            return apology("shares must be a number", 400)
        
        symbol = symbol.upper()
        info = lookup(symbol)
        
        if not info:
            return apology("symbol not found", 400)
        
        user_id = session["user_id"]
        user = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cost = shares * info["price"]
        
        if user[0]["cash"] < cost:
            return apology("not enough cash", 400)
        
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", cost, user_id)
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", user_id, symbol, shares, info["price"])
        
        return redirect("/")
    
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    
    transactions = db.execute("SELECT symbol, shares, price, timestamp FROM transactions WHERE user_id = ? ORDER BY timestamp DESC", user_id)
    
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    session.clear()

    if request.method == "POST":
        if not request.form.get("username"):
            return apology("must provide username", 403)

        elif not request.form.get("password"):
            return apology("must provide password", 403)

        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        session["user_id"] = rows[0]["id"]

        return redirect("/")

    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    session.clear()

    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        
        if not symbol:
            return apology("must provide symbol", 400)
        
        symbol = symbol.upper()
        info = lookup(symbol)
        
        if not info:
            return apology("symbol not found", 400)
        
        return render_template("quoted.html", info=info)
    
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        
        if not username:
            return apology("must provide username", 400)
        
        if not password:
            return apology("must provide password", 400)
        
        if not confirmation:
            return apology("must provide confirmation", 400)
        
        if password != confirmation:
            return apology("passwords do not match", 400)
        
        existing = db.execute("SELECT * FROM users WHERE username = ?", username)
        
        if len(existing) > 0:
            return apology("username already exists", 400)
        
        hashed = generate_password_hash(password)
        
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashed)
        
        return redirect("/login")
    
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session["user_id"]
    
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        
        if not symbol:
            return apology("must provide symbol", 400)
        
        try:
            shares = int(shares)
            if shares <= 0:
                return apology("shares must be positive", 400)
        except ValueError:
            return apology("shares must be a number", 400)
        
        symbol = symbol.upper()
        
        owned = db.execute("SELECT SUM(shares) as total FROM transactions WHERE user_id = ? AND symbol = ?", user_id, symbol)
        total_owned = owned[0]["total"]
        
        if not total_owned or total_owned < shares:
            return apology("not enough shares", 400)
        
        info = lookup(symbol)
        if not info:
            return apology("symbol not found", 400)
        
        sale = shares * info["price"]
        
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", sale, user_id)
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", user_id, symbol, -shares, info["price"])
        
        return redirect("/")
    
    else:
        stocks = db.execute("SELECT symbol, SUM(shares) as total FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total > 0", user_id)
        return render_template("sell.html", stocks=stocks)

