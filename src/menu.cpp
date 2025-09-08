#include "menu.h"

void Print_message_menu() {
  std::cout << "\n\tMENU" << std::endl;
  std::cout << "1.Creating matrices" << std::endl;
  std::cout << "2.Filling in the matrices" << std::endl;
  std::cout << "3.Matrix output" << std::endl;
  std::cout << "4.Matrix subtraction" << std::endl;
  std::cout << "5.Exit" << std::endl;
}

void Print_message_create_menu() {
  std::cout << "\nChoose which constructor to use to create matrices"
            << std::endl;
  std::cout << "1.Creating a default matrix" << std::endl;
  std::cout << "2.Creating a matrix with order n" << std::endl;
  std::cout << "3.Creating a matrix with the number of rows m, and the number "
               "of columns n"
            << std::endl;
  std::cout << "4.Return to the main menu" << std::endl;
}
#include <memory>

void Menu() {
  Matrix *matrix_first = nullptr;
  Matrix *matrix_second = nullptr;
  bool is_create = false;

  while (true) {
    Print_message_menu();
    int choose = Read_Int("\033[33mEnter the operation number \033[0m");

    switch (choose) {
    case 1: // Создание матриц
      // Освобождаем старые матрицы перед созданием новых
      delete matrix_first;
      delete matrix_second;
      matrix_first = nullptr;
      matrix_second = nullptr;

      Menu_Create_Matrix(&matrix_first, &matrix_second);
      is_create = (matrix_first != nullptr && matrix_second != nullptr);
      break;

    case 2: // Заполнение матриц
      if (is_create) {
        std::cout << "The first matrix" << std::endl;
        matrix_first->Create();
        std::cout << "The second matrix" << std::endl;
        matrix_second->Create();
      } else {
        std::cout << C_RED << "Error: matrices not created." << C_WHITE
                  << std::endl;
      }
      break;

    case 3: // Показать матрицы
      if (is_create) {
        std::cout << "The first matrix" << std::endl;
        matrix_first->Show();
        std::cout << "The second matrix" << std::endl;
        matrix_second->Show();
      } else {
        std::cout << C_RED << "Error: matrices not created." << C_WHITE
                  << std::endl;
      }
      break;

    case 4: // Вычитание матриц
      if (!is_create) {
        std::cout << C_RED << "Error: matrices not created." << C_WHITE
                  << std::endl;
        break;
      }

      if (matrix_first->get_numbers_columns() ==
              matrix_second->get_numbers_columns() &&
          matrix_first->get_numbers_strs() ==
              matrix_second->get_numbers_strs()) {

        std::cout << "First matrix before subtraction" << std::endl;
        matrix_first->Show();
        matrix_first->Subtraction(*matrix_second);
        std::cout << "First matrix after subtraction" << std::endl;
        matrix_first->Show();
      } else {
        std::cout << C_RED << "Matrix dimensions don't match for subtraction."
                  << C_WHITE << std::endl;
      }
      break;

    case 5: // Выход
      // Освобождаем память
      delete matrix_first;
      delete matrix_second;
      matrix_first = nullptr;
      matrix_second = nullptr;
      return;

    default:
      std::cout << C_RED << "Invalid choice, please try again." << C_WHITE
                << std::endl;
      break;
    }
  }
}

void Menu_Create_Matrix(Matrix **matrix_1, Matrix **matrix_2) {
  delete *matrix_1;
  delete *matrix_2;
  *matrix_1 = nullptr;
  *matrix_2 = nullptr;
  Print_message_create_menu();
  while (1) {
    int choose = Read_Int("Enter the operation number ");

    switch (choose) {
    case 1:
      *matrix_1 = new Matrix();
      *matrix_2 = new Matrix();
      return;
    case 2:
      std::cout << "The first matrix" << std::endl;
      *matrix_1 = new Matrix(Read_Int("Enter order of matrix "));
      std::cout << "The secound matrix" << std::endl;
      *matrix_2 = new Matrix(Read_Int("Enter order of matrix "));
      return;
    case 3:
      std::cout << "The first matrix" << std::endl;
      *matrix_1 = new Matrix(Read_Int("Enter number of rows in matrix "),
                             Read_Int("Enter number of columns in matrix "));
      std::cout << "The secound matrix" << std::endl;
      *matrix_2 = new Matrix(Read_Int("Enter number of rows in matrix "),
                             Read_Int("Enter number of columns in matrix "));
      return;
    case 4:
      return;
    default:
      std::cout << C_RED << "You make mistake, try again" << C_WHITE
                << std::endl;
      break;
    }
  }
}
