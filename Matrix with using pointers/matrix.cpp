/*Represent matrix using two-dimensional arrays and perform the following operations with
pointers: i. Addition ii. multiplication iii. transpose iv. Saddle point
*/

#include <iostream>
using namespace std;
#define SIZE 3

void inputMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> *(*(matrix + i) + j);
        }
    }
}

void displayMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            *(*(result + i) + j) = *(*(matrix1 + i) + j) + *(*(matrix2 + i) + j);
            // result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void transpose(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << *(*(matrix + j) + i) << " ";
            // cout<<matrix[j][i]
        }
        cout << endl;
    }
}

void multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int multiplication[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                multiplication[i][j] = multiplication[i][j] + matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void SaddlePoint(int matrix[SIZE][SIZE])
{
    // 1. check for minimum element in row
    for (int i = 0; i < SIZE; i++)
    {
        int min = matrix[i][0];
        int col = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (min > matrix[i][j])
            {
                min = matrix[i][j];
                // 2. store the column index of that minimum element
                col = j;
            }
        }

        // 3. check if this minimum element is maximum in its column
        int k;
        for (k = 0; k < SIZE; k++)
        {
            if (min < matrix[k][col])
            {
                break;
            }
        }
        if (k == SIZE)
        {
            cout << "Saddle Point is :" << min;
            return;
        }
    }
    cout << "No Saddle Point found";
    return;
}

int main()
{
    int ch;
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result[SIZE][SIZE] = {0}, multiplication[SIZE][SIZE] = {0};

    while (1)
    {
        cout << "\n1 | Matrix Addition\n2 | Transpose\n3 | Matrix Multiplication\n4 | Saddle Point\n5 | Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Matrix 1 :  \n";
            inputMatrix(matrix1);
            cout << "Enter Matrix 2 :  \n";
            inputMatrix(matrix2);
            addMatrices(matrix1, matrix2, result);
            cout << "\nAddition Matrix is:\n";
            displayMatrix(result);
            break;
        case 2:
            cout << "Enter Matrix for Transpose :  \n";
            inputMatrix(matrix1);
            cout << "\nTranspose of Matrix is: \n";
            transpose(matrix1);
            break;
        case 3:
            cout << "Enter Matrix 1 :  \n";
            inputMatrix(matrix1);
            cout << "Enter Matrix 2 :  \n";
            inputMatrix(matrix2);
            multiplyMatrices(matrix1, matrix2, multiplication);
            cout << "\n Multiplication of Matrix 1 and Matrix 2 is : \n";
            displayMatrix(multiplication);
            break;
        case 4:
            cout << "Enter Matrix for Saddle Point :  \n";
            inputMatrix(matrix1);
            cout << "\n";
            SaddlePoint(matrix1);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\nPlease Enter Valid Choice !";
        }
    }
}