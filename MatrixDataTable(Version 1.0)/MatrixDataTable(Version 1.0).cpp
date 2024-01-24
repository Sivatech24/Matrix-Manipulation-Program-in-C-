#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;

public:
    // Function to insert values into the matrix
    void insertValue(int row, int col, T value) {
        if (row >= 0 && col >= 0) {
            if (row >= matrix.size()) {
                matrix.resize(row + 1);
            }
            if (col >= matrix[row].size()) {
                matrix[row].resize(col + 1);
            }

            matrix[row][col] = value;
            std::cout << "Value inserted successfully.\n";
        } else {
            std::cout << "Invalid row or column index.\n";
        }
    }

    // Function to update values in the matrix
    void updateValue(int row, int col, T value) {
        if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[row].size()) {
            matrix[row][col] = value;
            std::cout << "Value updated successfully.\n";
        } else {
            std::cout << "Invalid row or column index.\n";
        }
    }

    // Function to delete values from the matrix
    void deleteValue(int row, int col) {
        if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[row].size()) {
            matrix[row][col] = T(); // Default value (0 for numeric types, empty for strings, etc.)
            std::cout << "Value deleted successfully.\n";
        } else {
            std::cout << "Invalid row or column index.\n";
        }
    }

    // Function to display the matrix
    void displayMatrix() const {
        const int cellWidth = 15;

        // Display top border
        std::cout << "+";
        for (int i = 0; i < matrix[0].size() * (cellWidth + 1) - 1; ++i) {
            std::cout << "-";
        }
        std::cout << "+\n";

        // Display matrix rows
        for (const auto& row : matrix) {
            std::cout << "|";
            for (const T& value : row) {
                std::cout << std::setw(cellWidth) << value << "|";
            }
            std::cout << "\n+";
            for (int i = 0; i < matrix[0].size() * (cellWidth + 1) - 1; ++i) {
                std::cout << "-";
            }
            std::cout << "+\n";
        }
    }

    // Function to save matrix data to a text file
    void saveToFile(const std::string& filename) {
        std::ofstream outFile(filename);

        if (outFile.is_open()) {
            outFile << matrix.size() << " " << (matrix.empty() ? 0 : matrix[0].size()) << "\n";

            for (const auto& row : matrix) {
                for (const T& value : row) {
                    outFile << value << " ";
                }
                outFile << "\n";
            }

            std::cout << "Matrix data saved to " << filename << " successfully.\n";
            outFile.close();
        } else {
            std::cout << "Unable to open file for saving.\n";
        }
    }

    // Function to load matrix data from a text file
    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);

        if (inFile.is_open()) {
            matrix.clear(); // Clear existing matrix

            int numRows, numCols;
            inFile >> numRows >> numCols; // Read matrix dimensions

            for (int i = 0; i < numRows; ++i) {
                std::vector<T> row;
                for (int j = 0; j < numCols; ++j) {
                    T value;
                    inFile >> value;
                    row.push_back(value);
                }
                matrix.push_back(row);
            }

            std::cout << "Matrix data loaded from " << filename << " successfully.\n";
            inFile.close();
        } else {
            std::cout << "Unable to open file for loading.\n";
        }
    }
};

int main() {
    Matrix<int> intMatrix; // Creating a matrix of integers

    int opt, row, column, k, upt; // User option

    do {
        // Display menu options
        std::cout << "Options:\n"
                  << "1. Create\n"
                  << "2. Update\n"
                  << "3. Delete\n"
                  << "4. Display\n"
                  << "5. SaveToTextFile\n"
                  << "6. LoadfromTextFile\n"
                  << "7. Exit\n"
                  << "Enter the option: ";
        std::cin >> opt;

        switch (opt) {
            case 1: {
                // Creating a matrix
                int i, j, r, c, t;
                std::cout << "Enter the number of rows: ";
                std::cin >> r;
                std::cout << "Enter the number of columns: ";
                std::cin >> c;
                for (i = 0; i < r; i++) {
                    for (j = 0; j < c; j++) {
                        std::cout << "Enter the value to be inserted at [" << i << ":" << j << "]: ";
                        std::cin >> t;
                        intMatrix.insertValue(i, j, t);
                    }
                }
                break;
            }
            case 2:
                k = 1;
                while (k > 0) {
                    std::cout << "Enter the Value to be updated: ";
                    std::cin >> upt;
                    std::cout << "Enter the row value: ";
                    std::cin >> row;
                    std::cout << "Enter the column value: ";
                    std::cin >> column;
                    // Updating a value in the matrix
                    intMatrix.updateValue(row, column, upt);
                    std::cout << "For continue the update value\n0. Exit\n1. Continue\nEnter the choice: ";
                    std::cin >> k;
                }
                // Displaying the matrix after update
                std::cout << "\nMatrix after update:\n";
                intMatrix.displayMatrix();
                break;

            case 3:
                k = 1;
                while (k > 0) {
                    std::cout << "Value to be deleted: \n";
                    std::cout << "Enter the row value: ";
                    std::cin >> row;
                    std::cout << "Enter the column value: ";
                    std::cin >> column;
                    // Deleting a value from the matrix
                    intMatrix.deleteValue(row, column);
                    std::cout << "For continue the delete value\n0. Exit\n1. Continue\nEnter the choice: ";
                    std::cin >> k;
                }
                // Displaying the matrix after deletion
                std::cout << "\nMatrix after deletion:\n";
                intMatrix.displayMatrix();
                break;

            case 4:
                // Displaying the matrix
                std::cout << "Matrix:\n";
                intMatrix.displayMatrix();
                break;

            case 5:
                // Saving matrix data to a text file
                intMatrix.saveToFile("int_matrix_data.txt");
                break;

            case 6: {
                // Loading matrix data from a text file
                Matrix<int> loadedIntMatrix;
                loadedIntMatrix.loadFromFile("int_matrix_data.txt");

                // Displaying the loaded matrix
                std::cout << "\nLoaded Integer Matrix:\n";
                loadedIntMatrix.displayMatrix();
                break;
            }
            case 7:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid option. Please try again.\n";
        }

    } while (opt != 7);

    return 0;
}