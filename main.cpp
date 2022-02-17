#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Matrix {
public:
	Matrix() : row(0), column(0) {
		matrix.resize(0, vector<double>(0));
		Fill();
	}

	Matrix(size_t r, size_t c) : row(r), column(c) {
		matrix.resize(r, vector<double>(c, 0));
		Fill();
	}

	vector<double>& operator[](const int& index) {
		return matrix[index];
	}

	vector<double> operator[](const int& index) const {
		return matrix[index];
	}

	double& operator()(const int& index_1, const int& index_2) {
		return matrix[index_1][index_2];
	}

	double operator()(const int& index_1, const int& index_2) const {
		return matrix[index_1][index_2];
	}

	int Size() {
		return matrix.size();
	}
	int Size() const {
		return matrix.size();
	}

	void MultiplyNumber(double num) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] *= num;
			}
		}
	}

	void PlusMatrix(const Matrix& newMatrix) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] += newMatrix(i, j);
			}
		}
	}
	void MultMatrix(const Matrix& newMatrix) {
	vector<vector<double>> EmptyMatrix(matrix.size(), vector<double>(newMatrix[0].size(), 0));
		for (int i = 0; i < EmptyMatrix.size(); i++) {
			for (int j = 0; j < EmptyMatrix[0].size(); j++) {
				EmptyMatrix[i][j] = 0;
			}
		}
	if (newMatrix.Size() == matrix[0].size()) {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < newMatrix[0].size(); j++) {
				for (int k = 0; k < matrix[0].size(); k++) {
						EmptyMatrix[i][j] += matrix[i][k] * newMatrix(k, j);
				}
			}
		}
		for (int i = 0; i < EmptyMatrix.size(); i++) {
			for (int j = 0; j < EmptyMatrix[0].size(); j++) {
					matrix[i][j] = EmptyMatrix[i][j];
				}
			}
		for (int i = 0; i < matrix.size(); i++) {
			cout << "\n";
				for (int j = 0; j < matrix[0].size(); j++) {
					cout << matrix[i][j] << " ";
			}
		}
	}
}


void Print() 
{
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << '\n';
		}
}

private:
	const size_t row;
	const size_t column;
	vector<vector<double>> matrix;

	void Fill()
	{
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				cin >> matrix[i][j];
			}
		}
	}
};

int main()
{
	srand(time(0));
	Matrix m1(2, 2);
	Matrix m2(2, 2);
	m1.Print();
	m2.Print();
	m1.MultMatrix(m2);
}