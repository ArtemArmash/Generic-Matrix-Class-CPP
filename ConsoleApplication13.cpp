#include <iostream>
using namespace std;

template<class T>
class Matrix {
private:
	T** datas;
	int rows;
	int cols;
public:
	Matrix(int rows, int cols) : rows{ rows }, cols{ cols } {
		datas = new T * [rows];
		for (size_t i = 0; i < rows; i++)
		{
			datas[i] = new T[cols];
		}
	}

	~Matrix() {
		for (size_t i = 0; i < rows; i++)
		{
			delete[]datas[i];
		}
		delete[]datas;
	}

	void Add() {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				cin >> datas[i][j];
			}
		}
	}

	void RandomAdd() {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				datas[i][j] = rand() % 10;
			}
		}
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << datas[i][j] << ' ';
			}
			cout << endl;
		}
	}

	void SearchMin() {
		T min = datas[0][0];

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (min > datas[i][j])
					min = datas[i][j];
			}
		}
		cout << "Min: " << min << endl;
	}

	void SeacrhMax() {
		T max = datas[0][0];

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (max < datas[i][j])
					max = datas[i][j];
			}
		}
		cout << "Max: " << max << endl;
	}

	friend ostream& operator<< (ostream& out, const Matrix& matrix) {
		for (size_t i = 0; i < matrix.rows; i++)
		{
			for (size_t j = 0; j < matrix.cols; j++)
			{
				out << matrix.datas[i][j] << ' ';
			}
			out << endl;
		}
		return out;
	}

	Matrix operator+ (const Matrix& oth) {
		Matrix result(rows, cols);
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				result.datas[i][j] = datas[i][j] + oth.datas[i][j];
			}
		}
		return result;
	}
	Matrix operator- (const Matrix& oth) {
		Matrix result(rows, cols);
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				result.datas[i][j] = datas[i][j] - oth.datas[i][j];
			}
		}
		return result;
	}

	Matrix operator* (const Matrix& oth) {
		Matrix result(rows, cols);
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				result.datas[i][j] = datas[i][j] * oth.datas[i][j];
			}
		}
		return result;
	}
	Matrix operator/ (const Matrix& oth) {
		Matrix result(rows, cols);
		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < cols; j++) {
				result.datas[i][j] = datas[i][j] / oth.datas[i][j];
			}
		}
		return result;
	}
};

int main() {
	Matrix<int> m1(2, 3);
	cout << "Enter values for matrix 1:" << endl;
	m1.Add();

	cout << "Enter matrix 1" << endl << m1 << endl;

	Matrix<int>m2(3, 4);
	m2.RandomAdd();

	cout << "Matrix2 (random values):" << endl << m2 << endl;

	Matrix<int> sumMatrix = m1 + m2;
	Matrix<int> diffMatrix = m1 - m2;
	Matrix<int> prodMatrix = m1 * m2;

	cout << "Sum of matrices:" << endl;
	cout << sumMatrix;

	cout << "Difference of matrices:" << endl;
	cout << diffMatrix;

	cout << "Product of matrices:" << endl;
	cout << prodMatrix;

	m1.SearchMin();
	m2.SeacrhMax();
}