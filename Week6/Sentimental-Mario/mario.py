while True:
    n = input("Height: ")

    try:
        h = int(n)
    except ValueError:
        continue

    if h >= 1 and h <= 8:
        break

for i in range(1, h + 1):
    spaces = h - i
    print(" " * spaces + "#" * i)
