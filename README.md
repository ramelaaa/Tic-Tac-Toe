# Tic-Tac-Toe (C++)

A two-player Tic-Tac-Toe game that runs in the terminal. This project was created as an introduction to C++ programming.

## Features

Displays a numbered 3x3 game board.

Alternates between Player 1 (x) and Player 2 (o).

Rejects invalid selections and moves to occupied squares.

Checks for wins across rows, columns, and diagonals.

Detects a draw when all nine squares are filled without a winner.

## Requirements

A C++11-compatible compiler, such as Apple Clang or GCC.

## Build and Run

If the source file is named main.cpp:

`g++ -std=c++11 -c main.cpp`

You can use clang++ instead g++ if that is the compiler installed on your system. If your source file has a different name, replace main.cpp in the command with that filename.

Additionlly, you can use the Makefile included in the project. Run in you compiler:
`Make`

## How to Play

Enter a number from 1 to 9 to choose a square. Player 1 uses x; Player 2 uses o. The first player to get three marks in a row, column, or diagonal wins. If the board fills first, the game is a draw.

## C++ Concepts Practiced

Arrays, vectors, functions, loops, conditionals, input validation, and tracking game state.

