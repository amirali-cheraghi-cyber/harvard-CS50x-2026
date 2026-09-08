# Substitution

CS50x — Week 2

A C program that encrypts messages using a substitution cipher based on a user-provided 26-character key.

## Overview

This project was completed as part of **CS50x — Introduction to Computer Science**.

The program accepts a 26-character substitution key and a plaintext message, then encrypts the message by replacing each letter with its corresponding character from the key.

## Concepts

This project applies several C programming concepts:

* Strings
* Arrays
* Character manipulation
* Functions
* Loops
* Conditional statements
* Command-line arguments
* Input validation
* Cryptography fundamentals
* Substitution ciphers

## Implementation

The program validates the provided key to ensure that it contains exactly 26 alphabetic characters with no repeated letters.

It then processes the plaintext character by character and substitutes each alphabetic character according to the provided key while preserving the original letter case.

Non-alphabetic characters remain unchanged.

## Verification

| Test    |   Result  |
| ------- | :-------: |
| Check50 | **19/19** |
| Style50 |  **1.00** |

## Language

`C`

## File Structure

```text id="q8j7cz"
Substitution/
├── substitution.c
└── README.md
```

## Completion

**CS50x Week 2 — Substitution**

Check50: **19/19**
Style50: **1.00**

Completed as part of my CS50x coursework in 2026.
