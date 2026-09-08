# Recover

CS50x — Week 4

A C program that recovers JPEG images from a forensic disk image.

## Overview

This project was completed as part of **CS50x — Introduction to Computer Science**.

The program examines a forensic image of a memory card, identifies the beginning of JPEG files, and recovers the images into separate files.

## Concepts

This project applies several C programming concepts:

* File I/O
* Binary data
* Pointers
* Arrays
* Memory manipulation
* Buffer management
* File handling
* JPEG file signatures
* Command-line arguments

## Implementation

The program reads the forensic image in fixed-size blocks and searches for JPEG file signatures.

When the beginning of a JPEG file is detected, the program creates a new JPEG file and writes the corresponding data to it.

The process continues until the entire forensic image has been processed.

## Verification

| Test    |  Result  |
| ------- | :------: |
| Check50 |  **7/7** |
| Style50 | **0.95** |

## Language

`C`

## File Structure

```text
Recover/
├── recover.c
└── README.md
```

## Completion

**CS50x Week 4 — Recover**

Check50: **7/7**
Style50: **0.95**

Completed as part of my CS50x coursework in 2026.
