# DNA

CS50x — Week 6

A Python program that identifies a person based on their DNA sequence.

## Overview

This project was completed as part of **CS50x — Introduction to Computer Science**.

The program analyzes a DNA sequence and compares the number of consecutive occurrences of specific Short Tandem Repeats (STRs) against a database of individuals to determine a matching person.

## Concepts

This project applies several Python programming concepts:

* File I/O
* CSV files
* Dictionaries
* Lists
* Strings
* Loops
* Functions
* String processing
* Pattern matching
* Data analysis

## Implementation

The program reads a CSV database containing individuals and their STR counts.

It then analyzes the provided DNA sequence and calculates the longest consecutive run of each STR.

The calculated STR counts are compared against the database. If all STR counts match an individual, that person's name is returned. Otherwise, the program reports that there is no match.

## Verification

| Test    |   Result  |
| ------- | :-------: |
| Check50 | **29/29** |
| Style50 |  **1.00** |

## Language

`Python`

## File Structure

```text id="v2k9sm"
DNA/
├── dna.py
└── README.md
```

## Completion

**CS50x Week 6 — DNA**

Check50: **29/29**
Style50: **1.00**

Completed as part of my CS50x coursework in 2026.
