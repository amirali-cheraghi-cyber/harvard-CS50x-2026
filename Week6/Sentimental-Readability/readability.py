text = input("Text: ")

letters = 0
words = 1
sentences = 0

for i in range(len(text)):
    c = text[i]
    
    if (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'):
        letters = letters + 1
    elif c == ' ':
        words = words + 1
    elif c == '.' or c == '?' or c == '!':
        sentences = sentences + 1

L = letters / words * 100
S = sentences / words * 100

index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
