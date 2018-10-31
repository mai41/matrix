// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: practicing on arrays [2D arrays and classes]
// Author:  Mai Rady Hassan Mohamed   20170302   g11
//          Andrew Emad Aziz          20170061   g12
//          Nour-Elhoda Khaled Samir  20170320   g12
// Date:    15 August 2018
// Version: 2.0

///---------------------------------------------
///|           matrix                           |
///---------------------------------------------
///|  -row: int                                 |
///|  -col: int                                 |
///|  -data: int**                              |
///----------------------------------------------
///|+friend operator<<(ostream&, matrix& ):     |
///|                                ostream     |
///|+friend operator>>(istream&, matrix& ):     |
///|                                istream     |
///|+operator+(const matrix& )const: matrix     |
///|+operator-(const matrix& )const: matrix     |
///|+operator*(const matrix& )const: matrix     |
///|+operator+(int  ): matrix                   |
///|+operator-(int  ): matrix                   |
///|+operator*(int  ): matrix                   |
///|+operator==(const matrix& )const: bool      |
///|+operator!=(const matrix& )const: bool      |
///|+isSquare  (const matrix& )const: bool      |
///|+isSymetric (const matrix& )const: bool     |
///|+isIdentity (const matrix& )const: bool     |
///|+transpose (const matrix& )const: matrix    |
///|+operator+=( matrix ): matrix               |
///|+operator-=( matrix ): matrix               |
///|+operator+=( int ): matrix                  |
///|+operator-=( int ): matrix                  |
///|+operator++( matrix& ): void                |
///|+operator--( matrix& ): void                |
///---------------------------------------------
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {3,4,5,6,8,7};
    int data5 [] = {2,5,4,1,7,2};

    Matrix mat1(4, 2, data1);
    Matrix mat3(4, 2, data3);
    Matrix mat2(2, 3, data2);
    Matrix mat4 (2, 3, data4);
    Matrix mat5 (3, 2, data5);
    Matrix matoperator(1, 1);

    cout << "Matrix 1: " << mat1 << endl;
    cout << "Matrix 2: " << mat2 << endl;
    cout << "Matrix 3: " << mat3 << endl;
    cout << "Matrix 4: " << mat4 << endl;
    cout << "Matrix 5: " << mat5 << endl;


//student no.1
    matoperator = mat1 + mat3;
    cout << matoperator<<endl;
    matoperator = mat1 - mat3;
    cout << matoperator << endl;
    matoperator = (mat4*mat5);
    cout << matoperator << endl;
    matoperator = mat1 + 1;
    cout << matoperator << endl;
    matoperator = mat3 - 1;
    cout << matoperator << endl;
    matoperator = mat1 * 2;
    cout << matoperator << endl;
    cout << endl;


//student no.2
    mat1+=mat3;
    cout << mat1 << endl;
    mat1-=mat3;
    cout << mat1 << endl;
    mat1+=3;
    cout << mat1 << endl;
    mat3-=10;
    cout << mat3 << endl;
    ++mat1;
    cout << mat1 << endl;
    --mat3;
    cout << mat3 << endl;


//student no.3
    bool check1 = (mat2 == mat3);
    bool check2 = (mat2 != mat3);
    cout << "The boolean of 2 matrices to be identical= ";
    cout << check1 <<endl;
    cout << "The boolean of 2 matrices to be not identical= ";
    cout << check2 << endl;
    cout << "The boolean of a matrix to be square= ";
    cout << mat2.isSquare(mat2) << endl;
    cout << "The boolean of a matrix to be identity= ";
    cout << mat2.isIdentity(mat2) << endl;
    cout << "The boolean of a matrix to be symmetric= ";
    cout << mat3.isSymetric(mat3) << endl;
    cout << endl;
    mat1 = mat1.transpose(mat1);
    cout << mat1 << endl;
    return 0;
}
