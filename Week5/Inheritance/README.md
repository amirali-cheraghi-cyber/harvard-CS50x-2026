# Inheritance

CS50x — Week 5

A C program that simulates the inheritance of blood types across multiple generations of a family.

## Overview

This project was completed as part of **CS50x — Introduction to Computer Science**.

The program creates a family tree and determines the possible alleles inherited by each family member based on the alleles of their parents.

## Concepts

This project applies several C programming concepts:

* Structures
* Pointers
* Dynamic memory allocation
* Recursion
* Arrays
* Strings
* Randomization
* Memory management
* Linked relationships between structures

## Implementation

The program represents each family member using a structure containing their alleles and pointers to their parents.

It recursively creates previous generations and assigns alleles to each individual based on the alleles inherited from their parents.

Dynamically allocated memory is also released when the family tree is no longer needed.

## Verification

| Test    |  Result  |
| ------- | :------: |
| Check50 |  **9/9** |
| Style50 | **0.96** |

## Language

`C`

## File Structure

```text
Inheritance/
├── inheritance.c
└── README.md
```

## Completion

**CS50x Week 5 — Inheritance**

Check50: **9/9**
Style50: **0.96**

Completed as part of my CS50x coursework in 2026.
