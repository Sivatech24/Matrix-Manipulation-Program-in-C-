Certainly! This C++ code defines a template class `Matrix` that can store values of any data type in a 2D matrix. It includes functionalities to insert, update, and delete values, display the matrix, and set row/column labels. There's also a specialization for handling matrices of strings separately.

Here are instructions on how to use this code:

### Matrix Class Usage:

1. **Insert Value (`1`):**
   - Choose option `1` from the menu.
   - Enter the row and column indices where you want to insert a value.
   - Input the value.

2. **Update Value (`2`):**
   - Choose option `2` from the menu.
   - Enter the row and column indices of the value you want to update.
   - Input the new value.

3. **Delete Value (`3`):**
   - Choose option `3` from the menu.
   - Enter the row and column indices of the value you want to delete.

4. **Display Matrix (`4`):**
   - Choose option `4` from the menu.
   - The matrix, along with labels, will be displayed.

5. **Set Row Labels (`5`):**
   - Choose option `5` from the menu.
   - Enter the number of rows.
   - Input labels for each row.

6. **Set Column Labels (`6`):**
   - Choose option `6` from the menu.
   - Enter the number of columns.
   - Input labels for each column.

7. **Exit (`7`):**
   - Choose option `7` to exit the program.

### Example Usage:

```plaintext
Options:
1. Insert Value
2. Update Value
3. Delete Value
4. Display Matrix
5. Set Row Labels
6. Set Column Labels
7. Exit
Enter the option: 1
Enter row and column indices: 0 0
Enter value: John
Value inserted successfully.

Options:
1. Insert Value
2. Update Value
3. Delete Value
4. Display Matrix
5. Set Row Labels
6. Set Column Labels
7. Exit
Enter the option: 4
+---------------------+
|                    |
+---------------------+

|       John         |
+---------------------+

Options:
1. Insert Value
2. Update Value
3. Delete Value
4. Display Matrix
5. Set Row Labels
6. Set Column Labels
7. Exit
Enter the option: 2
Enter row and column indices: 0 0
Enter new value: Jane
Value updated successfully.

Options:
1. Insert Value
2. Update Value
3. Delete Value
4. Display Matrix
5. Set Row Labels
6. Set Column Labels
7. Exit
Enter the option: 4
+---------------------+
|                    |
+---------------------+

|       Jane         |
+---------------------+

Options:
1. Insert Value
2. Update Value
3. Delete Value
4. Display Matrix
5. Set Row Labels
6. Set Column Labels
7. Exit
Enter the option: 7
Exiting...
```

Feel free to modify the code or integrate it into your project as needed.
