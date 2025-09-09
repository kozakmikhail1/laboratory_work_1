#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Matrix {
private:
  int number_of_rows;
  int number_of_columns;

  int** matrix = nullptr;

public:
  int get_numbers_strs() const { return number_of_rows; }
  int get_numbers_columns() const { return number_of_columns; }
  int get_matrix_value(int str_index, int column_index) const {
    return matrix[str_index][column_index];
  }

  Matrix();
  explicit Matrix(int order);
  Matrix(int rows, int columns);

  void Create();
  void Show() const;
  void Subtraction(const Matrix &subtractor);
};