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
void Menu() {
  Matrix *matrix_first = nullptr;
  Matrix *matrix_secound = nullptr;
  int check = 0;

  while (1) {
    Print_message_menu();
    int choose = Read_Int("\033[33mEnter the operation number \033[0m");

    switch (choose) {
    case 1:
      Menu_Create_Matrix(&matrix_first, &matrix_secound);
      check = 1;
      break;
    case 2:
      if (matrix_first != nullptr) {
        std::cout <<"The first matrix" << std::endl;
        matrix_first->Create();
        std::cout <<"The secound matrix" << std::endl;
        matrix_secound->Create();
      } else {
        std::cout << C_RED << "Error, you did not create the matrices."
                  << C_WHITE << std::endl;
      }
      break;
    case 3:
      if (matrix_first != nullptr) {
        std::cout <<"The first matrix" << std::endl;
        matrix_first->Show();
        std::cout <<"The secound matrix" << std::endl;
        matrix_secound->Show();
      } else {
        std::cout << C_RED << "Error, you did not create the matrices."
                  << C_WHITE << std::endl;
      }
      break;
    case 4:
      if (check == 0) {
        std::cout << C_RED << "Error, you did not create the matrices."
                  << C_WHITE << std::endl;
        continue;
      }
      if (check == 1 &&
          matrix_first->get_numbers_columns() ==
              matrix_secound->get_numbers_columns() &&
          matrix_first->get_numbers_strs() ==
              matrix_secound->get_numbers_strs()) {

        std::cout << "First matrix before subtraction" << std::endl;
        matrix_first->Show();
        matrix_first->Subtraction(*matrix_secound);
        std::cout << "First matrix after subtraction" << std::endl;
        matrix_first->Show();
      } else {
        std::cout << C_RED << "Yours matrixs don't equele" << C_WHITE
                  << std::endl;
      }
      break;
    case 5:
      return;
    default:
      std::cout << C_RED << "You made mistake, try again " << C_WHITE
                << std::endl;
      break;
    }
  }
}

void Menu_Create_Matrix(Matrix **matrix_1, Matrix **matrix_2) {
  Print_message_create_menu();
  while (1) {
    int choose = Read_Int("Enter the operation number ");

    switch (choose) {
    case 1:
      *matrix_1 = new Matrix();
      *matrix_2 = new Matrix();
      return;
    case 2:
      std::cout <<"The first matrix" << std::endl;
      *matrix_1 = new Matrix(Read_Int("Enter order of matrix "));
      std::cout <<"The secound matrix" << std::endl;
      *matrix_2 = new Matrix(Read_Int("Enter order of matrix "));
      return;
    case 3:
      std::cout <<"The first matrix" << std::endl;
      *matrix_1 = new Matrix(Read_Int("Enter number of rows in matrix "),
                             Read_Int("Enter number of columns in matrix "));
      std::cout <<"The secound matrix" << std::endl;
      *matrix_2 = new Matrix(Read_Int("Enter number of rows in matrix "),
                             Read_Int("Enter number of columns in matrix "));
      return;
    case 4:
      return;
    default:
      std::cout <<C_RED<< "You make mistake, try again" <<C_WHITE<< std::endl;
      break;
    }
  }
}
