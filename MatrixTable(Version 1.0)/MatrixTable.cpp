#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;
    std::vector<std::string> rowLabels;
    std::vector<std::string> colLabels;

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
        const int cellWidth = 20;

        // Display top border
        std::cout << "+";
        for (int i = 0; i < matrix[0].size() * (cellWidth + 1) - 1; ++i) {
            std::cout << "-";
        }
        std::cout << "+\n";

        // Display column labels
        std::cout << "|";
        for (const std::string& label : colLabels) {
            std::cout << std::setw(cellWidth) << label << "|";
        }
        std::cout << "\n+";
        for (int i = 0; i < matrix[0].size() * (cellWidth + 1) - 1; ++i) {
            std::cout << "-";
        }
        std::cout << "+\n";

        // Display matrix rows
        for (size_t i = 0; i < matrix.size(); ++i) {
            // Display row label
            std::cout << "|";
            std::cout << std::setw(cellWidth) << rowLabels[i] << "|";

            for (const T& value : matrix[i]) {
                std::cout << std::setw(cellWidth) << value << "|";
            }
            std::cout << "\n+";
            for (int j = 0; j < matrix[0].size() * (cellWidth + 1) - 1; ++j) {
                std::cout << "-";
            }
            std::cout << "+\n";
        }
    }

    // Function to set row labels
    void setRowLabels(const std::vector<std::string>& labels) {
        rowLabels = labels;
    }

    // Function to set column labels
    void setColLabels(const std::vector<std::string>& labels) {
        colLabels = labels;
    }
};

// Template specialization for string type
template<>
class Matrix<std::string> {
private:
    std::vector<std::vector<std::string>> matrix;
    std::vector<std::string> rowLabels;
    std::vector<std::string> colLabels;

public:
    // Function to insert values into the matrix
    void insertValue(int row, int col, const std::string& value) {
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
    void updateValue(int row, int col, const std::string& value) {
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
            matrix[row][col].clear(); // Clear string
            std::cout << "Value deleted successfully.\n";
        } else {
            std::cout << "Invalid row or column index.\n";
        }
    }

    // Function to display the matrix
    void displayMatrix() const {
        const int cellWidth = 20;

        // Display top border
        std::cout << "+";
        for (int i = 0; i < matrix[0].size() * (cellWidth + 1) - 1; ++i) {
            std::cout << "-";
        }
        std::cout << "+\n";

        // Display column labels
        std::cout << "|";
        for (const std::string& label : colLabels) {
            std::cout << std::setw(cellWidth) << label << "|";
        }
        std::cout << "\n+";
        for (int i = 0; i < matrix[0].size() * (cellWidth + 1) - 1; ++i) {
            std::cout << "-";
        }
        std::cout << "+\n";

        // Display matrix rows
        for (size_t i = 0; i < matrix.size(); ++i) {
            // Display row label
            std::cout << "|";
            std::cout << std::setw(cellWidth) << rowLabels[i] << "|";

            for (const std::string& value : matrix[i]) {
                std::cout << std::setw(cellWidth) << value << "|";
            }
            std::cout << "\n+";
            for (int j = 0; j < matrix[0].size() * (cellWidth + 1) - 1; ++j) {
                std::cout << "-";
            }
            std::cout << "+\n";
        }
    }

    // Function to set row labels
    void setRowLabels(const std::vector<std::string>& labels) {
        rowLabels = labels;
    }

    // Function to set column labels
    void setColLabels(const std::vector<std::string>& labels) {
        colLabels = labels;
    }
};

int main() {
    int opt, row, column;
    std::string value;

    // Creating a matrix of strings
    Matrix<std::string> stringMatrix;

    do {
        // Display menu options
        std::cout << "Options:\n"
                  << "1. Insert Value\n"
                  << "2. Update Value\n"
                  << "3. Delete Value\n"
                  << "4. Display Matrix\n"
                  << "5. Set Row Labels\n"
                  << "6. Set Column Labels\n"
                  << "7. Exit\n"
                  << "Enter the option: ";
        std::cin >> opt;

        switch (opt) {
            case 1:
                std::cout << "Enter row and column indices: ";
                std::cin >> row >> column;
                std::cout << "Enter value: ";
                std::cin >> value;
                stringMatrix.insertValue(row, column, value);
                break;

            case 2:
                std::cout << "Enter row and column indices: ";
                std::cin >> row >> column;
                std::cout << "Enter new value: ";
                std::cin >> value;
                stringMatrix.updateValue(row, column, value);
                break;

            case 3:
                std::cout << "Enter row and column indices: ";
                std::cin >> row >> column;
                stringMatrix.deleteValue(row, column);
                break;

            case 4:
                stringMatrix.displayMatrix();
                break;

            case 5: {
                int numRows;
                std::cout << "Enter the number of rows: ";
                std::cin >> numRows;

                std::vector<std::string> rowLabels(numRows);
                for (int i = 0; i < numRows; ++i) {
                    std::cout << "Enter label for row " << i << ": ";
                    std::cin >> rowLabels[i];
                }

                stringMatrix.setRowLabels(rowLabels);
                break;
            }

            case 6: {
                int numCols;
                std::cout << "Enter the number of columns: ";
                std::cin >> numCols;

                std::vector<std::string> colLabels(numCols);
                for (int i = 0; i < numCols; ++i) {
                    std::cout << "Enter label for column " << i << ": ";
                    std::cin >> colLabels[i];
                }

                stringMatrix.setColLabels(colLabels);
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
