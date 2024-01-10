#include <iostream>
#include <random>
#include <vector>

#define matrixType std::vector<std::vector<int>>

void fillMatrix(matrixType& matrix, std::mt19937& randomGenerator) {
	for (auto& row : matrix) {
		for (auto& column : row) {
			std::uniform_int_distribution<int> distribution(-100, 100);
			column = distribution(randomGenerator);
		}
	}
}

void printMatrix(const matrixType& matrix) {
	for (auto& row : matrix) {
		for (auto& column : row) {
			std::cout << column << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void matrixCopy(const matrixType& matrixA, matrixType& matrixB) {
	// Представление матрицы
	/*												{matrix}
					 [row]				             [row]							 [row]
		{[(column), (column), (column)], [(column), (column), (column)], [(column), (column), (column)]}

	*/

	for (int row = 0; row < matrixA.size(); row++) {
		for (int column = 0; column < matrixA.size(); column++) {
			matrixB.at(row).at(column) = matrixA.at(row).at(column);
		}
	}
}

int main() {
	system("chcp 1251 > nul");
	std::mt19937 randomGenerator;
	std::random_device device;
	randomGenerator.seed(device());

	size_t matrixSize;
	std::cout << "Введите размерность матрицы: ";
	std::cin >> matrixSize;
	matrixType matrixA(matrixSize, std::vector<int>(matrixSize));
	matrixType matrixB(matrixSize, std::vector<int>(matrixSize));

	fillMatrix(matrixA, randomGenerator);
	std::cout << "matrixA: " << std::endl;
	printMatrix(matrixA);

	matrixCopy(matrixA, matrixB);
	std::cout << "matrixB: " << std::endl;
	printMatrix(matrixB);

	return 0;
}