# C Programming Project 1 – Assignment

## Overview
This project is part of the Programming in C course. It demonstrates fundamental programming concepts including compilation, control flow, functions, recursion, and embedded systems design. The project is divided into four main questions, each focusing on a different core concept in C programming.

---

## Question 1: C Program Lifecycle and Compilation

This section includes a simple C program that performs a basic calculation and prints formatted output. It is used to demonstrate how C programs are compiled and executed.

### Key Concepts Covered:
- Basic C syntax and structure
- Compilation process (preprocessing, compiling, assembling, linking)
- Difference between syntax and semantic errors
- Real-world application of C programming (e.g., system software and embedded systems)

---

## Question 2: Control Flow and Repetition

This section contains a menu-driven program that allows users to interact with different options using loops and conditional statements.

### Features:
- Menu-driven interface using `switch` statements
- Use of loops for repeated execution
- Input validation using `if-else`
- Use of `break` and `continue` statements

### Purpose:
To demonstrate how control flow structures are used to build interactive console applications.

---

## Question 3: Functions and Recursion

This program demonstrates modular programming using multiple functions and includes a recursive function for calculating factorial.

### Features:
- Multiple reusable functions
- Function calling and modular design
- Recursive factorial function
- Function reuse across different program features

### Key Concepts:
- Function decomposition
- Recursion with base and recursive cases
- Advantages and limitations of recursion

---

## Question 4: Embedded Systems – Smart Distance Guidance System

### Project Overview

The Smart Distance Guidance Indicator System is an embedded system that uses an ultrasonic distance sensor to measure the distance between the sensor and an object. The Arduino Uno acts as the controller by processing the distance data and determining the appropriate output. An RGB LED serves as the actuator by displaying different colors based on the measured distance. Green indicates that the object is close to the sensor, yellow indicates a medium distance, red indicates that the object is approaching the edge of the monitoring range, and white indicates that the object is outside the predefined range. The system continuously monitors distance and updates the LED color in real time, providing visual feedback to the user.

### Smart Distance Guidance System Block Diagram

````markdown
Object
   ↓
Ultrasonic Sensor
   ↓
Arduino Uno
   ↓
RGB LED