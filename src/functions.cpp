#include "functions.h"
#include "matrix.h"

int *Input_Row_Matrix(int number_element_of_row) {
  auto row_matrix = new int[number_element_of_row]();
  std::string number;
  std::string temp_str;

  int mines = 0;
  int index = 0;
  std::getline(std::cin, temp_str, '\n');

  for (char symbol : temp_str) {
    if (index > number_element_of_row) {
      std::cout << C_RED << "Uncorrect count number, you must enter "
                << number_element_of_row << " number" << C_WHITE << std::endl;
      delete[] row_matrix;
      return NULL;
    }
    if (symbol == ' ' ) {
      if( number.size() > 0)
      {
        row_matrix[index] = (std::stoi(number));
        index++;
        number.clear();
        mines = 0;
        continue;
      }
      else
      continue;
    }
    if ((symbol <= '9' && symbol >= '0') || (symbol == '-' && mines == 0)) {
      mines = 1;
      number.push_back(symbol);
    } else {
      std::cout << C_RED << "You must enter only number\n"
                << C_WHITE << std::endl;
      delete[] row_matrix;
      return NULL;
    }
  }
  if(number.size() > 0)
  {
    row_matrix[index] = (std::stoi(number));
    index++;
  }
  if (index != number_element_of_row) {
    std::cout << C_RED << "Uncorrect count number, you must enter "
              << number_element_of_row << " number" << C_WHITE << std::endl;
    delete[] row_matrix;
    return NULL;
  }
  return row_matrix;
}

int Read_Int(const std::string &prompt = "Enter a single integer: ") {
  int value = 0;
  while (true) {
    std::cout << C_YELLOW << prompt << C_WHITE;
    std::cin >> value;

    if (std::cin.good() && std::cin.peek() == '\n') {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return value;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << C_RED << "Incorrect input, try again! " << C_WHITE
              << std::endl;
  }
}