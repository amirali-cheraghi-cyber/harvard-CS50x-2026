# Volume

CS50x — Week 4

A C program that modifies the volume of a WAV audio file by applying a specified scaling factor.

## Overview

This project was completed as part of **CS50x — Introduction to Computer Science**.

The program reads a WAV audio file, adjusts the volume of its audio samples by a given factor, and writes the modified audio to a new WAV file.

## Concepts

This project applies several C programming concepts:

* File I/O
* Binary files
* Structures
* Data types
* Pointers
* Arrays
* Loops
* Command-line arguments
* Memory manipulation

## Implementation

The program opens the input WAV file and copies its header to the output file.

It then reads each audio sample, multiplies its value by the specified volume factor, and writes the modified sample to the output file.

## Verification

| Test    |  Result  |
| ------- | :------: |
| Check50 |  **5/5** |
| Style50 | **1.00** |

## Language

`C`

## File Structure

```text
Volume/
├── volume.c
└── README.md
```

## Completion

**CS50x Week 4 — Volume**

Check50: **5/5**
Style50: **1.00**

Completed as part of my CS50x coursework in 2026.
