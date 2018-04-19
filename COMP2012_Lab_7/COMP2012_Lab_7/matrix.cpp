#include <iostream>

#include "matrix.h"

using namespace std;

bool print_step{false};

/**
 * Constructor for generating an num_rows * num_cols matrix.
 * The default value for each element is 0.
 * @param num_rows the number of rows
 * @param num_cols the number of columns
 */
Matrix::Matrix(int num_rows, int num_cols) : num_rows(num_rows), num_cols(num_cols) {
    if (print_step) cout << "constructor" << endl;
    ptr = new int[num_rows * num_cols];
    for (int i = 0; i < num_rows * num_cols; i++)
        ptr[i] = 0;
}

/**
 * Constructor for generating an num_rows * num_cols matrix.
 * The value of elements will be assigned according to given array.
 * @param data the data array
 * @param num_rows the number of rows
 * @param num_cols the number of columns
 */
Matrix::Matrix(int *data, int num_rows, int num_cols) : num_rows(num_rows), num_cols(num_cols) {
    if (print_step) cout << "constructor" << endl;
    ptr = new int[num_rows * num_cols];
    for (int i = 0; i < num_rows * num_cols; i++)
        ptr[i] = data[i];
}

/**
 * Destructor
 */
Matrix::~Matrix() {
    if (ptr != nullptr)
        delete[] ptr;
}

/**
 * Copy constructor
 * TODO: To be implemented in Task 1
 * @param mat
 */
Matrix::Matrix(const Matrix &mat) : num_rows(mat.num_rows), num_cols(mat.num_cols) {
    if (print_step) cout << "copy constructor" << endl;     // please keep this line
    this->ptr = new int[this->num_rows * this->num_cols];
    for (int i = 0; i < num_rows * num_cols; i++) {
        this->ptr[i] = mat.ptr[i];
    }
}

/**
 * Move constructor
 * TODO: To be implemented in Task 1
 * @param mat
 */
Matrix::Matrix(Matrix &&mat) : ptr(mat.ptr), num_rows(mat.num_rows), num_cols(mat.num_cols) {
    if (print_step) cout << "move constructor" << endl;     // please keep this line
    mat.ptr = nullptr;
    mat.num_rows = 0;
    mat.num_cols = 0;
}

/**
 * Assignment operator
 * TODO: To be implemented in Task 1
 * @param mat
 */
const Matrix& Matrix::operator=(const Matrix &mat) {
    if (print_step) cout << "operator =" << endl;     // please keep this line
    if (this != &mat) {
        this->num_rows = mat.num_rows;
        this->num_cols = mat.num_cols;
        if (this->ptr != nullptr) { delete [] this->ptr; }
        this->ptr = new int[this->num_rows * this->num_cols];
        for (int i = 0; i < num_rows * num_cols; i++) {
            this->ptr[i] = mat.ptr[i];
        }
    }
    return *this;
}

/**
 * Move assignment operator
 * TODO: To be implemented in Task 1
 * @param mat
 */
const Matrix& Matrix::operator=(Matrix &&mat) {
    if (print_step) cout << "move operator =" << endl;     // please keep this line
    if (this != &mat) {
        this->num_cols = mat.num_cols;
        this->num_rows = mat.num_rows;
        if (this->ptr != nullptr) { delete [] this->ptr; }
        this->ptr = mat.ptr;
        mat.ptr = nullptr;
        mat.num_cols = 0;
        mat.num_rows = 0;
    }
    return *this;
}

/**
 * Operator + overloading
 * TODO: To be implemented in Task 2; no rvalue is required
 * @param mat the reference of another Matrix
 * @return
 */
Matrix Matrix::operator+(const Matrix &mat) {
    if (print_step) cout << "operator +" << endl;     // please keep this line
    Matrix temp = Matrix(this->ptr, this->num_rows, this->num_cols);
    for (int i = 0; i < num_rows * num_cols; i++) {
        temp.ptr[i] += mat.ptr[i];
    }
    return temp;
}

/**
 * Operator + for rvalue overloading
 * TODO: To be implemented in Task 2
 * @param mat the rvalue reference of another Matrix
 * @return
 */
Matrix& Matrix::operator+(Matrix &&mat) {
    if (print_step) cout << "operator + for rvalue" << endl;     // please keep this line
    for (int i = 0; i < mat.num_rows * mat.num_cols; i++) {
        mat.ptr[i] += this->ptr[i];
    }
    return mat;
}

/**
 * Operator (x, y) for getting the matrix element
 * TODO: To be implemented in Task 2
 * @return the value at x-th row and y-th column
 */
int Matrix::operator()(int x, int y) const {
    return this->ptr[num_rows * x + y];
}

/* Print the elements of the matrix */
void Matrix::print() const {
    for (int i = 0; i < num_rows; i++) {
        cout << (i == 0 ? "[" : " ");
        for (int j = 0; j < num_cols; j++) {
            cout << ptr[i * num_cols + j];
            if (j != num_cols - 1) cout << ", ";
        }
        cout << (i == num_rows - 1 ? "]" : ";");
        cout << endl;
    }
}

/* Switcher for result printing.
 * Please do not modify the following methods. */
void enable_print_step() { print_step = true; }

void disable_print_step() { print_step = false; }
