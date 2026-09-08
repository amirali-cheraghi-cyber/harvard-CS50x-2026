# Finance

Finance is a full-stack web application project from CS50x Week 9.

The project involves building a simulated stock trading platform where users can register, log in, check stock prices, buy and sell stocks, and view their transaction history.

## Files

### Backend

* `app.py` — Main Flask application containing routes and application logic.
* `helpers.py` — Helper functions used by the application.
* `requirements.txt` — Python dependencies required by the project.

### Templates

* `apology.html` — Template for displaying error messages.
* `buy.html` — Interface for purchasing stocks.
* `history.html` — Displays the user's transaction history.
* `index.html` — Main portfolio page.
* `layout.html` — Shared base template for the application.
* `login.html` — User login page.
* `quote.html` — Interface for requesting a stock quote.
* `quoted.html` — Displays the result of a stock quote.
* `register.html` — User registration page.
* `sell.html` — Interface for selling stocks.

### Static Files

* `styles.css` — Custom CSS used to style the application.

## Topics Covered

* Python
* Flask
* Flask-Session
* SQL
* SQLite
* HTML
* CSS
* Jinja templates
* Forms and user input
* Authentication and sessions
* Database operations
* CRUD operations
* API usage
* Server-side validation
* Dynamic web pages
* Portfolio and transaction management

## Core Features

The application provides functionality for:

* User registration and login
* Checking stock prices
* Buying stocks
* Selling stocks
* Tracking owned stocks
* Viewing transaction history
* Managing user cash balances
* Displaying portfolio information
* Handling invalid input and application errors

## Verification

* Check50: **21/21**
* Style50: **0.97**

## Skills Demonstrated

This project strengthened my ability to build a complete web application using Flask, connect a Python backend to a SQLite database, process forms, manage user sessions, render dynamic HTML templates, and implement database-driven application logic.

## Project Structure

```text
Finance/
├── app.py
├── helpers.py
├── requirements.txt
├── static/
│   └── styles.css
├── templates/
│   ├── apology.html
│   ├── buy.html
│   ├── history.html
│   ├── index.html
│   ├── layout.html
│   ├── login.html
│   ├── quote.html
│   ├── quoted.html
│   ├── register.html
│   └── sell.html
└── README.md
```

## Repository Note

The local SQLite database file (`finance.db`) is not included in this repository. The database is used locally by the application during development and testing.

The remaining source files are included to document the completed CS50x coursework and demonstrate the implementation of the database-driven Flask web application.
