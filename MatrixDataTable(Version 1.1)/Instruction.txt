### Matrix Class Template:

The code defines a template class named `Matrix` that represents a 2D matrix. It supports operations like inserting, updating, deleting values, displaying the matrix, finding the sum and average of matrix elements, searching for a specific value, and saving/loading matrix data to/from a text file.

#### Template Class Methods:

1. **insertValue(int row, int col, T value):**
   - Inserts the given value at the specified row and column indices.

2. **updateValue(int row, int col, T value):**
   - Updates the value at the specified row and column indices with a new value.

3. **deleteValue(int row, int col):**
   - Deletes the value at the specified row and column indices (sets it to the default value).

4. **displayMatrix():**
   - Displays the matrix with row and column indices.

5. **sum():**
   - Returns the sum of all elements in the matrix.

6. **average():**
   - Returns the average value of all elements in the matrix.

7. **searchValue(T value):**
   - Searches for the specified value in the matrix.

8. **saveToFile(const std::string& filename):**
   - Saves the matrix data to a text file with the provided filename.

9. **loadFromFile(const std::string& filename):**
   - Loads matrix data from a text file with the provided filename.

### Main Function:

The `main()` function is the entry point for the program. It provides a menu-driven interface for users to interact with the matrix.

#### Menu Options:

1. **Create (Option 1):**
   - Allows the user to create a matrix by specifying the number of rows and columns and entering values for each element.

2. **Update (Option 2):**
   - Enables the user to update values in the matrix by specifying the row and column indices.

3. **Delete (Option 3):**
   - Allows the user to delete values from the matrix by specifying the row and column indices.

4. **Display (Option 4):**
   - Displays the current state of the matrix.

5. **SaveToTextFile (Option 5):**
   - Saves the matrix data to a text file named "int_matrix_data.txt".

6. **LoadfromTextFile (Option 6):**
   - Loads matrix data from the "int_matrix_data.txt" file.

7. **Sum of Matrix (Option 7):**
   - Calculates and displays the sum of all elements in the matrix.

8. **Average of Matrix (Option 8):**
   - Calculates and displays the average value of all elements in the matrix.

9. **Search Value (Option 9):**
   - Allows the user to search for a specific value in the matrix.

10. **Exit (Option 10):**
    - Exits the program.

#### Usage Instructions:

1. Run the program.
2. Choose an option from the menu by entering the corresponding number.
3. Follow the prompts to perform the selected operation.
4. Repeat steps 2-3 until you choose the "Exit" option.

**Note:**
- The matrix elements are initially set to their default values (0 for numeric types).
- Ensure proper input to avoid unexpected behavior.
- The matrix data is saved to and loaded from the "int_matrix_data.txt" file.
- The program will continue to execute until the user chooses to exit (Option 10).