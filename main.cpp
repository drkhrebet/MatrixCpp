#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Matrix {
public:
	Matrix() : row(0), column(0) {
		matrix.resize(0, vector<double>(0));
	}

	Matrix(size_t r, size_t c) : row(r), column(c) {
		matrix.resize(r, vector<double>(c, 0));
	}

	Matrix(const Matrix& ref_matrix) {
		row = ref_matrix.Size();
		column = ref_matrix[0].size();
		matrix.resize(row, vector<double>(column));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				matrix[i][j] = ref_matrix(i, j);
			}
		}
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

	size_t Size() {
		return matrix.size();
	}
	size_t Size() const {
		return matrix.size();
	}
	Matrix MultiplyNumberR(double num) {
		Matrix newmatrix = *this;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				newmatrix[i][j] *= num;
			}
		}
		return newmatrix;
	}
	void MultiplyNumber(double num) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] *= num;
			}
		}
	}
	Matrix PlusMatrixR(const Matrix& newMatrix) {
		Matrix newmatrix = *this;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				newmatrix[i][j] += newMatrix(i, j);
			}
		}
		return newmatrix;
	}
	void PlusMatrix(const Matrix& newMatrix) {
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				matrix[i][j] += newMatrix(i, j);
			}
		}
	}
	Matrix MultiplyMatrixR(const Matrix& newMatrix) {
		Matrix EmptyMatrix(matrix.size(), matrix[0].size());
		for (int i = 0; i < EmptyMatrix.Size(); i++) {
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
			return EmptyMatrix;
		}
	}
	void Transpose() {
		for (int i = 0; i < matrix.size(); i++) {
			cout << endl;
			for (int j = 0; j < matrix[0].size(); j++) {
				cout << matrix[j][i] << " ";
			}
		}

	}
	void Determinate() {
		double determinate = 0;
		if (matrix.size() == 1 && matrix[0].size() == 1) {
			cout << matrix[0][0];
		}

		else if (matrix.size() == 2 && matrix[0].size() == 2)
			cout << matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	void MultiplyMatrix(const Matrix& newMatrix) {
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
			matrix = EmptyMatrix;
		}
		for (int i = 0; i < matrix.size(); i++) {
			cout << "\n";
			for (int j = 0; j < matrix[0].size(); j++) {
				cout << matrix[i][j] << " ";
			}
		}
	}



	void Print() {
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < column; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << '\n';
		}
	}
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
private:
	size_t row;
	size_t column;
	vector<vector<double>> matrix;
};

int main()
{
	setlocale(LC_ALL, "ru");
	size_t a;
	size_t b;
	cout << "Введите размерность 1 матрицы:" << "\n";
	cin >> a >> b;
	Matrix m1(a, b);
	cout << "Введите 1 матрицу:" << "\n";
	m1.Fill();
	cout << "Введите размерность 2 матрицы:" << "\n";
	cin >> a >> b;
	Matrix m2(a, b);
	cout << "Введите 2 матрицу:" << "\n";
	m2.Fill();
	cout << "1. Умножение матрицы на число" << "\n"
		<< "2. Умножение матрицы на матрицу" << "\n"
		<< "3. Сложение матриц" << "\n"
		<< "4. Найти определитель" << "\n"
		<< "5. Вывести матрицу" << "\n"
		<< "6. Транспонировать матрицу" << "\n";

	string cmd = "";
	bool running = true;
	while (running && cmd != "exit") {
		cin >> cmd;
		if (cmd == "1") {
			double num;
			cout << "Напишите число:" << "\n";
			cin >> num;
			m1.MultiplyNumberR(num).Print();
		}
		else if (cmd == "1$") {
			double num;
			cout << "Напишите число:" << "\n";
			cin >> num;
			m1.MultiplyNumber(num);
		}
		else if (cmd == "2") {
			m1.MultiplyMatrix(m2);
		}
		else if (cmd == "3") {
			m1.PlusMatrixR(m2).Print();
		}
		else if (cmd == "3$") {
			m1.PlusMatrix(m2);
		}
		else if (cmd == "4") {
			m1.Determinate();
		}
		else if (cmd == "5") {
			int num_of_matrix;
			cin >> num_of_matrix;
			if (num_of_matrix == 1) {
				m1.Print();
			}
			else if (num_of_matrix == 2) {
				m2.Print();
			}
			else {
				cout << "Не ломай код или я тебя сломаю!";
				return 0;
			}
		}
		else if (cmd == "6") {
			m1.Transpose();
		}
	}
}