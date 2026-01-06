# House Class - Assignment 2

## Author Information
**Name:** Ali Nawaz  
**Reg No:** 00000526123  
**Course:** CS-212: Object Oriented Programming  
**Institute:** NUST - Institute of Geographical Information Systems

## Project Description
This project implements a House class that creates and manages ASCII art representations of houses. Each house consists of:
- A square base with a given side length (3-37)
- An equilateral triangle roof that overhangs the base by 1 unit on each side

## Files Included
1. **house.h** - Header file containing the House class declaration
2. **house.cpp** - Implementation file containing all member function definitions
3. **README** - This file

## Compilation Instructions
To compile the program, use the following command:
```bash
g++ -o house main.cpp house.cpp
```

To run the program:
```bash
./house
```

## Class Features

### Constructor
- `House(int size, char border = 'X', char fill = '*')`
- Validates size (3-37 range)
- Validates characters (ASCII 33-126)
- Sets defaults if invalid values provided

### Member Functions

**Getters:**
- `GetSize()` - Returns the base size of the house
- `Perimeter()` - Returns the total perimeter (integer)
- `Area()` - Returns the total area (double)

**Modifiers:**
- `Grow()` - Increases size by 1 (if within bounds)
- `Shrink()` - Decreases size by 1 (if within bounds)
- `SetBorder(char)` - Sets border character (validates range)
- `SetFill(char)` - Sets fill character (validates range)

**Display:**
- `Draw()` - Draws the ASCII house
- `Summary()` - Displays complete house information

## Design Decisions

1. **Character Validation:** Both border and fill characters are validated to be within ASCII range 33-126. Invalid characters revert to defaults ('X' for border, '*' for fill).

2. **Size Bounds:** Size is constrained to 3-37 to ensure reasonable display dimensions.

3. **Drawing Algorithm:** 
   - Roof is drawn line by line with decreasing leading spaces
   - Shared line represents roof bottom and base top
   - Base is drawn with consistent indentation

4. **Area Calculation:** Uses the formula for equilateral triangle area: (√3/4) × side²

5. **Perimeter Calculation:** Sums triangle perimeter (3 sides) and square perimeter (4 sides), minus the shared base length.

## Known Limitations
- Uses simple ASCII art (not true geometric proportions)
- Maximum size limited to 37 for display purposes
- Requires monospace font for proper display

## Additional Notes
- All member data is private as required
- No global variables used
- Code uses standard C++ (pre-C++11 compatible)
- Proper const correctness maintained