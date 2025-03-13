#include"Matrix.h"
double** Matrix::createData(int rows, int cols)
{
	double** res = new double* [rows] { 0 };
	for (int i = 0; i < rows; ++i)
	{
		res[i] = new double[cols] { 0 };
	}
	return res;
}
void Matrix::freeData(double** data, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
}
Matrix::Matrix()
{
	this->rows = 1;
	this->cols = 1;
	this->data = createData(1, 1);
}
Matrix::Matrix(int dim)
{
	this->rows = dim;
	this->cols = dim;
	this->data = createData(dim, dim);
}
Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->data = createData(rows, cols);
}
Matrix::Matrix(const Matrix& matr)
{
	this->rows = matr.rows;
	this->cols = matr.cols;
	this->data = createData(matr.rows, matr.cols);
	for (int i = 0; i < matr.rows; ++i)
	{
		for (int j = 0; j < matr.cols; ++j)
		{
			this->data[i][j] = matr.data[i][j];
		}
	}
}
Matrix::~Matrix()
{
	if (this->data != nullptr)
	{
		freeData(this->data, this->rows);
		this->data = nullptr;
		this->rows = 0;
		this->cols = 0;
	}
}
double Matrix::get(int row, int col)
{
	if (0 <= row && row <= this->rows &&
		0 <= col && col <= this->cols)
	{
		return this->data[row][col];
	}
	else
	{
		return -1;
	}
}
void Matrix::set(int row, int col, double val)
{
	if (0 <= row && row <= this->rows &&
		0 <= col && col <= this->cols)
	{
		this->data[row][col] = val;
	}
}
int Matrix::getR()
{
	return this->rows;
}
int Matrix::getC()
{
	return this->cols;
}
void Matrix::print(std::ostream& stream)
{
	stream << "[" << this->rows << "; " << this->cols << "]\n";
	for (int i = 0; i < this->rows; ++i)
	{
		stream << "\t";
		for (int j = 0; j < this->cols; ++j)
		{
			stream << this->data[i][j] << " ";
		}
		stream << "\n";
	}
}

void Matrix::multBy(double k)
{
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->cols; ++j)
		{
			this->data[i][j] *= k;
		}
	}
}

void Matrix::addTo(Matrix matr)
{
	if (matr.rows == this->rows && matr.cols == this->cols)
	{
		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->cols; ++j)
			{
				this->data[i][j] += matr.data[i][j];
			}
		}
	}
}

double Matrix::det()
{
	if (this->rows > 0 && this->rows == this->cols)
	{
		int dim = this->rows;
		if (dim == 1)
		{
			return this->data[0][0];
		}
		double res = 0;
		for (int i = 0, mult = 1; i < dim; ++i, mult *= -1)
		{
			res += mult * this->data[0][i] * minor(0, i).det();
		}
		return res;
	}
	return 0.0;
}

Matrix Matrix::minor(int row, int col)
{
	if (this->rows > 1 &&
		this->rows == this->cols &&
		row < this->rows && col < this->cols)
	{
		int dim = this->rows - 1;
		Matrix res(dim);
		for (int i = 0, ii = 0; i < dim; ++i, ++ii)
		{
			if (ii == row)
			{
				++ii;
			}
			for (int j = 0, jj = 0; j < dim; ++j, ++jj)
			{
				if (jj == col)
				{
					++jj;
				}
				res.data[i][j] = this->data[ii][jj];
			}
		}
		return res;
	}
	return Matrix();
}

Matrix mult(Matrix m1, Matrix m2)
{
	if (m1.cols == m2.rows)
	{
		Matrix res(m1.rows, m2.cols);
		for (int i = 0; i < res.rows; ++i)
		{
			for (int j = 0; j < res.cols; ++j)
			{
				res.data[i][j] = 0;
				for (int k = 0; k < m1.cols; ++k)
				{
					res.data[i][j] += m1.data[i][k] * m2.data[k][j];
				}
			}
		}
		return res;
	}
	return Matrix();
}

void Matrix::transpose()
{
	if (this->cols == this->rows)
	{
		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = i; j < this->cols; ++j)
			{

				double a = 0;
				a = this->data[i][j];
				this->data[i][j] = this->data[j][i];
				this->data[j][i] = a;
			}
		}
	}
	else
	{
		int tr = this->rows;
		int tc = this->cols;
		Matrix clone(tc, tr);
		for (int i = 0; i < tr; ++i)
		{
			for (int j = 0; j < tc; ++j)
			{
				clone.data[j][i] = this->data[i][j];
			}
		}
		freeData(this->data, this->rows);
		this->rows = tc;
		this->cols = tr;
		this->data = createData(rows, cols);
		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->cols; ++j)
			{

				this->data[i][j] = clone.data[i][j];

			}
		}
	}
}

Matrix add(Matrix m1, Matrix m2)
{
	if (m1.rows == m2.rows && m1.cols == m2.cols)
	{
		Matrix sm(m1.rows, m1.cols);
		for (int i = 0; i < sm.rows; ++i)
		{
			for (int j = 0; j < sm.cols; ++j)
			{

				sm.data[i][j] = m1.data[i][j] + m2.data[i][j];

			}
		}
		return sm;
	}
	else
	{
		printf("Error, incorrect operation\n");
		exit(0);
	}
}

Matrix transpose(Matrix m)
{
	if (m.cols == m.rows)
	{
		int tr = m.rows;
		int tc = m.cols;
		Matrix tm(tc);
		for (int i = 0; i < m.rows; ++i)
		{
			for (int j = i; j < m.cols; ++j)
			{
				double a = 0;
				a = m.data[i][j];
				tm.data[i][j] = m.data[j][i];
				m.data[j][i] = a;
			}
		}
		return tm;
	}
	else
	{
		int tr = m.rows;
		int tc = m.cols;
		Matrix tm(tc, tr);
		for (int i = 0; i < tr; ++i)
		{
			for (int j = 0; j < tc; ++j)
			{
				tm.data[j][i] = m.data[i][j];
			}
		}
		return tm;
	}
}

Matrix reverse(Matrix m)
{
	int dim = m.rows;
	if (dim > 1 && m.cols == m.rows)
	{
		Matrix rev(m.cols);
		for (int i = 0; i < m.rows; ++i)
		{
			for (int j = 0; j < m.cols; ++j)
			{
				Matrix alg = m.minor(i, j);
				rev.data[i][j] = pow(-1, i + j) * (m.minor(i, j)).det();
			}
		}
		rev.transpose();
		rev.multBy(1 / m.det());
		return rev;
	}
	if (dim == 1)
	{
		if (m.data[0][0] != 0)
		{
			Matrix rev(1);
			rev.data[0][0] = 1 / (m.data[0][0]);
			return rev;
		}
		else
		{
			printf("This Matrix has not Invertible Matrix. Please try again. Algorythm will return you your Matrix without changes.\n");
			exit(0);
		}
	}
}

Matrix solve(Matrix A, Matrix B)
{
	if (A.rows == A.cols && B.cols == 1 && B.rows == A.rows)
	{
		Matrix x(1, A.cols);
		if (A.det() != 0)
		{
			x = mult(reverse(A), B);
			for (int i = 0; i < x.cols; ++i)
			{
				double a = 0;
				a = x.data[i][0];
				printf("x[%d] = %f\n", i, a);
			}
			x.transpose();
			return x;
		}
		else
		{
			printf("Determinant of matrix A  equal to zero, solution doesn't exist\n");
			exit(0);
		}
	}
	else if (A.rows == B.rows)
	{
		Matrix x(A.cols, B.cols);
		if (A.det() != 0)
		{
			x = mult(reverse(A), B);
			return x;
		}
		else
		{
			printf("Determinant of matrix A  equal to zero, solution doesn't exist\n");
			exit(0);
		}
	}
	else
	{
		printf("Incorrect number of rows and cols in A anb B");
		exit(0);
	}
}

Matrix subtr(Matrix m1, Matrix m2)
{
	if (m1.rows == m2.rows && m1.cols == m2.cols)
	{
		Matrix str(m1.rows, m1.cols);
		m2.multBy(-1);
		str = add(m1, m2);
		return str;
	}
	else
	{
		printf("Incorrect number of rows and cols in A anb B");
		exit(0);
	}
}