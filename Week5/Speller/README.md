# Speller

CS50x — Week 5

A C program that implements a spell checker using a hash table and a dictionary of words.

## Overview

This project was completed as part of **CS50x — Introduction to Computer Science**.

The program loads a dictionary into memory, checks words from a text file against the dictionary, reports misspelled words, and measures the performance of the spell-checking process.

## Concepts

This project applies several C programming concepts:

* Hash tables
* Linked lists
* Structures
* Pointers
* Dynamic memory allocation
* Memory management
* File I/O
* Strings
* Hash functions
* Searching
* Performance optimization

## Implementation

The dictionary is loaded into a hash table using a hash function to determine the appropriate bucket for each word.

Each bucket uses a linked list to handle collisions.

The program then checks each word in the input text against the dictionary and reports words that are not found.

After processing the text, allocated memory is released and the dictionary is unloaded.

## Verification

| Test    |   Result  |
| ------- | :-------: |
| Check50 | **10/10** |
| Style50 |  **1.00** |

## Language

`C`

## File Structure

```text id="w9q4ts"
Speller/
├── speller.c
├── dictionary.c
├── dictionary.h
└── README.md
```

## Completion

**CS50x Week 5 — Speller**

Check50: **10/10**
Style50: **1.00**

Completed as part of my CS50x coursework in 2026.
