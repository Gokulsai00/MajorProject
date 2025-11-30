 
About:

This project is a simple Sudoku solver programmed in C. Sudoku is a 9×9 puzzle where some numbers are given, and the rest must be filled in so that every row, column, and 3×3 box contains all digits from 1 to 9 without repeating. Solving easy puzzles is fun, but difficult ones can take a long time, which is why this program helps automate the process.

The solver uses a logical backtracking approach. It looks for empty spaces, tries numbers that follow Sudoku rules, and if something doesn’t fit later, it goes back and tries a different number. This continues until the puzzle is either fully solved or determined to be unsolvable.

The project mainly focuses on understanding how recursion works, how to check constraints, and how to handle a 2D grid efficiently in C.

Instructions:
1. Compile the program using any standard C compiler.
2. Run the compiled file from the terminal.
3. Enter the Sudoku puzzle, using 0 for empty cells.
4. Enter all nine rows of the puzzle.
5. The program will process the puzzle and display the solution.
6. If it cannot be solved, it will say so.

This program is useful for learning how backtracking works and for solving Sudoku puzzles efficiently.
