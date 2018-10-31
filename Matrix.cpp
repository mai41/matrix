
#include "Matrix.h"
#include <iostream>
using namespace std;


Matrix::Matrix(int r, int c, int num[])
{
    row = r;
    col = c;
    data = new int*[row];
    for (int i = 0; i < row; i++)
        data[i] = new int[col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            data[i][j] = num[i * col + j];
}
Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    data = new int*[row];
    for (int i = 0; i < row; i++)
        data[i] = new int[col];
}
//output matrix
ostream&operator<<(ostream &out, Matrix &obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.col; j++)
        {
            out << obj.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

//input matrix
istream& operator>> (istream&in, Matrix& mat)
{
    cout << "enter no. of rows:";
    in >> mat.row;
    cout << "enter no. of columns:";
    in >> mat.col;
    cout << "enter element of the matrix:" << endl;
    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            in >> mat.data[i][j];
        }
    }
    return in;
}
//student no.1
//summation of two matrices
//it takes the two matrices that the summation will occur bet them and return a new matrix
Matrix Matrix::operator+ (Matrix& mat1)
{
    if (mat1.col == col && mat1.row == row)
    {

        int r = mat1.row;
        int c = mat1.col;
        int x = 0;
        int *ptr;
        ptr = new int[c*r];

        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                ptr[x] = mat1.data[i][j] + data[i][j];
                x++;
            }
        }
        cout << "the sum of 2 matrices is:" << endl;
        return Matrix(r, c, ptr);
        delete[]ptr;
    }}

//subtraction of two matrices
//it takes the two matrices that the subtraction will occur bet them and return a new matrix
Matrix Matrix::operator- (const Matrix& mat1)const
{
    if (mat1.col == col && mat1.row == row)
    {
        int r = mat1.row;
        int c = mat1.col;
        int x = 0;
        int *ptr;
        ptr = new int[c*r];

        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                ptr[x] = mat1.data[i][j] - data[i][j];
                x++;
            }
        }
        cout << "the difference of 2 matrices is:" << endl;
        return Matrix(r, c, ptr);
        delete[]ptr;
    }

}

//multiplication of two matrices
//it takes the two matrices that the multiplication will occur bet them and return a new matrix
Matrix Matrix::operator*  (const Matrix& mat1)const
{
    int r = mat1.row;
    int c = mat1.col;
    int x = 0;
    int *ptr;
    ptr = new int[c*r];
    if (mat1.col == row)
    {

        for (int i = 0; i < r; i++)
        {
            for(int k=0; k<c; k++)
            {
                ptr[x] = 0;
                for (int j = 0; j<c; j++)
                {
                    ptr[x] = ptr[x] + (mat1.data[i][j] * data[k][i]);


                }
                x++;
            }
        }

    }
    cout<<"the multiplication between the two matrices is:"<<endl;
    return Matrix(r, c, ptr);
    delete[]ptr;
}

//add a scaler to matrix
Matrix Matrix::operator+ (const int s)const
{
    int r = row;
    int c = col;
    int x = 0;
    int *ptr;
    ptr = new int[c*r];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ptr[x] = data[i][j] + s;
            x++;
        }
    }
    cout << "the sum of 2 matrices is:" << endl;
    return Matrix(r, c, ptr);
    delete[]ptr;
}

//sub a scaler from a matrix
Matrix Matrix::operator- (const int s)const
{
    int r = row;
    int c = col;
    int x = 0;
    int *ptr;
    ptr = new int[c*r];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ptr[x] = data[i][j] - s;
            x++;
        }
    }
    cout << "the difference of 2 matrices is:" << endl;
    return Matrix(r, c, ptr);
    delete[]ptr;
}

//multiply a scaler by a matrix
Matrix Matrix::operator*(const int s)const
{
    int r = row;
    int c = col;
    int x = 0;
    int *ptr;
    ptr = new int[c*r];
    for (int i = 0; i<r; i++)
    {
        for (int j = 0; j<c; j++)
        {
            ptr[x] = data[i][j] * s;
            x++;
        }
    }
    cout << "The multiplication of matrix with scaler: " << endl;
    return Matrix(r, c, ptr);
    delete[]ptr;
}
//student2
//mat1 changes + returns new matrix with sum
Matrix Matrix:: operator+= (Matrix& mat1)
{
    for (int i = 0; i < mat1.row; i++)
    {
        for (int j = 0; j < mat1.col; j++)
        {
            data[i][j]+=mat1.data[i][j];
        }
    }
    cout << "The new mat1 is: " << endl;
    return *this;
}

// mat1 changes + returns new matrix with difference
Matrix Matrix:: operator-= (Matrix mat1)
{
    for (int i = 0; i < mat1.row; i++)
    {
        for (int j = 0; j < mat1.col; j++)
        {
            data[i][j]-=mat1.data[i][j] ;
        }
    }
    cout << "The new mat1 is: " << endl;
    return *this;
}

//mat changes and returns new matrix + scalar
Matrix Matrix::operator+= ( int scalar)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            data[i][j] += scalar;
        }
    }
    cout << "The same matrix after adding a scalar is: " << endl;
    return *this;
}

//mat changes and returns new matrix - scalar
Matrix Matrix:: operator-= (int scalar)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            data[i][j] -= scalar;
        }
    }
    cout << "The same matrix after subbing a scalar is: " << endl;
    return *this;
}

// Add 1 to each element in mat
void Matrix:: operator++ ()
{
    cout << "Mat++: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            data[i][j]++;
        }
    }

}

// sub 1 from each element in mat
void Matrix::operator-- ()
{
    cout << "Mat--: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            data[i][j]--;
        }
    }
}
//student no.3
//returns true if 2 matrices are the same
bool Matrix::operator==(const Matrix& mat1)const{
    if ((mat1.row == row) && (mat1.col == col))
    {
        for(int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

//returns true if 2 matrices are not the same
bool Matrix::operator!=(const Matrix& mat1)const{
    if ((mat1.row == row) && (mat1.col == col))
    {
        for(int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != data[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
        return true;
}

//returns true if matrix is square
bool Matrix::isSquare(const Matrix& mat1)const{
    if(mat1.row == mat1.col)
    {
        return true;
    }
    else
        return false;
}

//returns true if matrix is square and symmetric
bool Matrix::isSymetric(const Matrix& mat1)const{
    if(mat1.row == mat1.col)               //make sure that matrix is square
    {
        for(int i = 0; i < mat1.row; i++)     //make sure that matrix is symmetric
            for(int j = 0; j < mat1.col; j++)
                if(mat1.data[i][j] != data[j][i])
                    return false;
        return true;
    }
    else
        return false;
}

//returns true if matrix is square and identity
bool Matrix::isIdentity(const Matrix& mat1)const{
    bool check;
    if(mat1.row == mat1.col)                 //make sure that matrix is square
    {
        for(int i = 0; i < mat1.row; i++)   //make sure that matrix is identity
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(i == j)
                {
                    if(mat1.data[i][j] == 1)
                    {
                        check = true;
                    }
                    else
                        return false;
                }
                else
                {
                    if(mat1.data[i][j] == 0)
                    {
                        check = true;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

//returns new matrix with the transpose
Matrix Matrix::transpose(const Matrix& mat1)const{
    int newRow = mat1.row;
    int newCol = mat1.col;
    int x = 0;
    int *ptr;      //pointer to data in the matrix with the transposed
    ptr = new int [newCol * newRow];
    for (int i = 0; i < newRow; i++)
    {
        for (int j = 0; j < newCol; j++)
        {
            ptr[x] = mat1.data[i][j];
            x++;
        }
    }
    cout << "The transpose of matrix is: " << endl;
    return Matrix(newCol,newRow,ptr);   //creating the transpose of the matrix
    delete[]ptr;

}

Matrix::~Matrix()
{
}
