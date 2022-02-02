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

    vector<double> &operator[](const int &index) {
        return matrix[index];
    }

    vector<double> operator[](const int &index) const {
        return matrix[index];
    }

    double &operator()(const int &index_1, const int &index_2) {
        return matrix[index_1][index_2];
    }

    double operator()(const int &index_1, const int &index_2) const {
        return matrix[index_1][index_2];
    }

    void MultiplyNumber(double num) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] *= num;
            }
        }
    }

    void PlusMatrix(const Matrix &newMatrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] += newMatrix(i, j);
            }
        }
    }

    double Determinate(){

    }

    void Transpose(){

    }

    void Print() {
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

    void Fill() {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] = rand() % 21;
            }
        }
    }
};

int main() {
    srand(time(0));
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    m1.Print();
    m2.Print();
    m1.MultiplyNumber(3);
    m1.Print();
    m2.PlusMatrix(m1);
    m2.Print();
}
