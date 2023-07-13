#include<iostream>
#include<cmath>
using namespace std;
const int r = 10, c = 10;
int rowA, rowB, colA, colB;
const double Max = 10E307, Min = -10E307;
void enter_int_matrix(long long int Matrix[10][10], long long int row, long long int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> Matrix[i][j];
		}
	}
}
void add_Matrices(long long int matrix_a[10][10], long long int matrix_b[10][10], long long int  matrixadd[10][10])
{
	for (int i = 0; i < rowB; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			matrixadd[i][j] = matrix_a[i][j] + matrix_b[i][j];
			cout << matrixadd[i][j] << " ";
		}
		cout << endl;
	}
}
void sub_Matrices(long long int matrix_A[10][10], long long int matrix_B[10][10], long long int  matrixsub[10][10])
{
	for (int i = 0; i < rowB; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			matrixsub[i][j] = matrix_A[i][j] - matrix_B[i][j];
			cout << matrixsub[i][j] << " ";
		}
		cout << endl;
	}
}
void multiply_Matrices(long long int matrix_1[10][10], long long int matrix_2[10][10], long long int matrixmul[10][10])
{
	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			int cum = 0;
			for (int l = 0; l < colA; l++)
			{
				cum = cum + matrix_1[i][l] * matrix_2[l][j];
			}
			matrixmul[i][j] = cum;
			cout << matrixmul[i][j] << " ";
		}
		cout << endl;
	}
}
long long int determinant(long long int matrix[10][10], int n)
{
	long long int det = 0;
	long long int submatrix[10][10];
	if (n == 1)
		return matrix[0][0];
	else if (n == 2)
		return (((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1])));
	else
	{
		for (int ex_col = 0; ex_col < n; ex_col++) // for the extracted column
		{
			int k = 0; // we need new counter of row at submatrix of the original matrix to calculate determanit
			for (int i = 1; i < n; i++) // begain always by second row
			{
				int m = 0; // we need new counter of column at submatrix of the original matrix to calculate determanit
				for (int j = 0; j < n; j++) // to change the column
				{
					if (j == ex_col) // to extract the colume we stop on it    
						continue;
					submatrix[k][m] = matrix[i][j];
					m++;
				}
				k++;
			}
			det += (pow(-1, ex_col) * matrix[0][ex_col] * determinant(submatrix, n - 1));// to alternated + or - 
		}
	}
	return det;
}
void multiply_Matrices_for_inverse(double inverse_Matrix[r][c], long long int Matrix_A[r][c], double output_matrix[r][c])
{
	if (colA == rowB)
	{
		for (int i = 0; i < rowA; i++)
		{
			for (int j = 0; j < colB; j++)
			{
				float cum = 0;
				for (int l = 0; l < colA; l++)
				{
					cum += Matrix_A[i][l] * inverse_Matrix[l][j];
				}
				output_matrix[i][j] = cum;
			}
		}
		for (int i = 0; i < rowA; i++)
		{
			for (int j = 0; j < colB; j++)
			{
				double verify, y;
				verify = output_matrix[i][j];
				y = verify - int(verify);
				if (verify <= Max && verify >= 0)
				{
					if (y >= .5)
						cout << int(verify) + 1 << " ";
					else
						cout << int(verify) << " ";
				}
				if (verify < 0 && verify >= Min)
				{
					if (-y >= .5)
						cout << int(verify) - 1 << " ";
					else
						cout << int(verify) << " ";
				}

			}
			cout << "\n";
		}
	}
	else
		cout << "The operation you chose is invalid for the given matrices." << "\n";
}
void inverse_matrix(long long int same_matrix[10][10], int n, long long int Matrixa[10][10], double inverse_MatrixB[10][10], double Matrix_res[10][10])
{
	long long int sa_matrix[10][10], gen_matrix[10][10];
	long long int sum = 0;
	sum = determinant(same_matrix, n);
	if (sum == 0)
		cout << "The operation you chose is invalid for the given matrices." << "\n";
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int h = 0; h < n; h++)
			{
				sa_matrix[i][h] = 0;
			}
		}
		for (int p = 0; p < n; p++)
		{
			for (int v = 0; v < n; v++)
			{
				int row = 0;
				for (int y = 0; y < n; y++)
				{
					int col = 0;
					for (int t = 0; t < n; t++)
					{
						if (y == p || t == v)
							continue;
						sa_matrix[row][col] = same_matrix[y][t];
						col++;
					}
					if (y == p)
						continue;
					row++;
				}
				gen_matrix[p][v] = determinant(sa_matrix, n - 1);
				for (int i = 0; i < n; i++)
				{
					for (int h = 0; h < n; h++)
					{
						sa_matrix[i][h] = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || i % 2 == 0)
			{
				for (int h = 0; h < n; h++)
					gen_matrix[i][h] = pow(-1, h) * gen_matrix[i][h];
			}
			else
			{
				for (int h = 0; h < n; h++)
					gen_matrix[i][h] = pow(-1, h + 1) * gen_matrix[i][h];
			}
		}
		int matrixtest[10][10];
		for (int i = 0; i < n; i++)
		{
			for (int h = 0; h < n; h++)
			{
				matrixtest[i][h] = gen_matrix[i][h];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				gen_matrix[i][j] = matrixtest[j][i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				inverse_MatrixB[i][j] = (1.0 / sum) * gen_matrix[i][j];
			}
		}
		multiply_Matrices_for_inverse(inverse_MatrixB, Matrixa, Matrix_res);
	}
}
int main()
{
	long long int MatrixA[r][c], MatrixB[r][c], Matrixadd[r][c], Matrixsub[r][c], Matrixmul[r][c], k = 0;
	double inverseMatrixB[r][c], Matrixres[r][c];
	cout << "Please enter dimensions of Matrix A:" << "\n";
	cin >> rowA >> colA;
	cout << "Please enter dimensions of Matrix B:" << "\n";
	cin >> rowB >> colB;
	cout << "Please enter values of Matrix A:" << "\n";
	enter_int_matrix(MatrixA, rowA, colA);
	cout << "Please enter values of Matrix B:" << "\n";
	enter_int_matrix(MatrixB, rowB, colB);
	int p = 0;
	for (p = 0; k != 7; p++)
	{
		cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << "\n";
		cin >> k;
		switch (k)
		{
		case(1):
		if (rowA == rowB && colA == colB)
				add_Matrices(MatrixA, MatrixB, Matrixadd);
			else
				cout << "The operation you chose is invalid for the given matrices." << "\n";
			break;
		case(2):
		    if (rowA == rowB && colA == colB)
				sub_Matrices(MatrixA, MatrixB, Matrixsub);
			else
				cout << "The operation you chose is invalid for the given matrices." << "\n";
			break;
		case(3):
		    if (colA == rowB)
				multiply_Matrices(MatrixA, MatrixB, Matrixmul);
			else
				cout << "The operation you chose is invalid for the given matrices." << "\n";
			break;
		case(4):
	        if (rowB == colB && colA==rowB)
				inverse_matrix(MatrixB, rowB, MatrixA, inverseMatrixB, Matrixres);
			else
				cout << "The operation you chose is invalid for the given matrices." << "\n";
			break;
		case(5):
	 	    if (rowA == colA)
				cout << determinant(MatrixA, rowA) << "\n";
			else
				cout << "The operation you chose is invalid for the given matrices." << "\n";
			break;
	    case(6):
		    if (rowB == colB)
				cout << determinant(MatrixB, rowB) << "\n";
			else
				cout << "The operation you chose is invalid for the given matrices." << "\n";
			break;
		case(7):
			cout << "Thank you!";
			break;
		
		}
	}
}