# Runoff

CS50x — Week 3

A C program that conducts a ranked-choice election using a runoff voting system.

## Overview

This project was completed as part of **CS50x — Introduction to Computer Science**.

The program simulates a runoff election in which voters rank candidates by preference. If no candidate receives a majority of the votes, the candidate with the fewest votes is eliminated and the remaining votes are redistributed according to the voters' next preferences.

## Concepts

This project applies several C programming concepts:

* Arrays
* Structures
* Strings
* Functions
* Loops
* Conditional statements
* Input validation
* Searching
* Vote counting
* Ranked-choice voting

## Implementation

The program records each voter's ranked preferences and repeatedly counts votes until a candidate receives a majority.

After each round, the candidate or candidates with the fewest votes are eliminated, and the votes assigned to eliminated candidates are transferred to the next valid preference.

The process continues until a winner is determined or the election results in a tie.

## Verification

| Test    |   Result  |
| ------- | :-------: |
| Check50 | **25/25** |
| Style50 |  **1.00** |

## Language

`C`

## File Structure

```text
Runoff/
├── runoff.c
└── README.md
```

## Completion

**CS50x Week 3 — Runoff**

Check50: **25/25**
Style50: **1.00**

Completed as part of my CS50x coursework in 2026.
