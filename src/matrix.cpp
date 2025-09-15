#include "matrix.h"
#include "functions.h"

Matrix::Matrix() : Matrix(2,2) {}

Matrix::Matrix(int order) : Matrix(order, order) {}

Matrix::Matrix(int rows, int columns)
    : number_of_rows(rows), number_of_columns(columns) {
    matrix = new int *[number_of_rows];
    for (int i = 0; i < number_of_rows; i++) {
      matrix[i] = new int[number_of_columns]{};
    }
}

void Matrix::Create() {
  for (int i = 0; i < number_of_rows; i++) {
    cout << C_YELLOW << "Enter " << i + 1
         << "-th line of matrix (number element in line " << number_of_columns
         << ")" << C_WHITE << endl;
    matrix[i] = Input_Row_Matrix(number_of_columns);
    if (matrix[i] == nullptr)
      i--;
  }
}

void Matrix::Show() const {
  for (int i = 0; i < number_of_rows; i++) {
    for (int j = 0; j < number_of_columns; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void Matrix::Subtraction (const Matrix &subtractor) {
  if (subtractor.get_numbers_columns() == number_of_columns &&
      subtractor.get_numbers_strs() == number_of_rows) {
    for (int i = 0; i < number_of_rows; i++) {
      for (int j = 0; j < number_of_columns; j++) {
        matrix[i][j] -= subtractor.get_matrix_value(i, j);
      }
    }
  } else {
    cout << C_RED << "Error, Matrices are not equal\n" << C_WHITE;
  }
}