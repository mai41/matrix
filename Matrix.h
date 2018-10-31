#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
    //members
    // Takes an array of data and stores in matrix according
    // to rows and columns
    int row, col;
    int **data;
public:
    //constructors
    Matrix(int r, int c, int num[]);
    Matrix(int r, int c);
    friend ostream& operator<< (ostream&, Matrix&);
    friend istream& operator>> (istream&, Matrix&);
    //student1
    Matrix operator+ (Matrix& mat1);
    Matrix operator- (const Matrix& mat1)const;
    Matrix operator* (const Matrix& mat1)const;
    Matrix operator+ (const int s)const;
    Matrix operator* (const int s)const;
    Matrix operator- (const int s)const;
    //student2
    Matrix operator+= (Matrix &mat1);
    Matrix operator-= (Matrix mat1);
    Matrix operator+= (int scalar);
    Matrix operator-= (int scalar);
    void operator-- ();
    void operator++ ();
    //student3
    bool   operator== (const Matrix& mat1)const;
    bool   operator!= (const Matrix& mat1)const;
    bool   isSquare   (const Matrix& mat1)const;
    bool   isSymetric (const Matrix& mat1)const;
    bool   isIdentity (const Matrix& mat1)const;
    Matrix transpose (const Matrix& mat3)const;
    virtual ~Matrix();
};

