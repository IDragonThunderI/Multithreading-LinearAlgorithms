#include <iostream>
#include <random>
#include <vector>

#define matrixType std::vector<std::vector<int>>

void fillMatrix(matrixType& matrix, std::mt19937& randomGenerator) {
	for (auto& row : matrix) {
		for (auto& column : row) {
			std::uniform_int_distribution<int> distribution(-10, 10);
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

matrixType matrixMultiplication(const matrixType& matrixA, const matrixType& matrixB) {
	int matrixSize = matrixA.size();
	matrixType result(matrixSize, std::vector<int>(matrixSize, 0));
	
	// Представление матрицы
	/*												{matrix}
					 [row]				             [row]							 [row]
		{[(column), (column), (column)], [(column), (column), (column)], [(column), (column), (column)]}

	*/

	for (int row = 0; row < matrixSize; row++) {
		for (int column = 0; column < matrixSize; column++) {
			for (int position = 0; position < matrixSize; position++) {
				result.at(row).at(column) += matrixA.at(row).at(position) * matrixB.at(position).at(column);
			}
		}
	}
	return result;
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
	matrixType matrixC(matrixSize, std::vector<int>(matrixSize));

	fillMatrix(matrixA, randomGenerator);
	fillMatrix(matrixB, randomGenerator);

	std::cout << "matrixA: " << std::endl;
	printMatrix(matrixA);
	std::cout << "matrixB: " << std::endl;
	printMatrix(matrixB);

	matrixC = matrixMultiplication(matrixA, matrixB);
	std::cout << "matrixC = matrixA * matrixB: " << std::endl;
	printMatrix(matrixC);

	return 0;
}