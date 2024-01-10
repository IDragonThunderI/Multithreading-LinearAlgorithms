#include <iostream>
#include <random>
#include <cmath>
#include <vector>

void randomizeVector(std::vector<long long>& vector, std::mt19937& randomGenerator) {
	for (auto& element : vector) {
		std::uniform_int_distribution<int> distribution(0, 100);
		element = distribution(randomGenerator);
	}
}

void printVector(const std::vector<long long>& vector) {
	std::cout << "Arr = { ";
	for (const auto& element : vector) {
		std::cout << element << " ";
	}
	std::cout << "}" << std::endl << std::endl;
}

void binaryPrintVector(std::vector<long long> vector) {
	std::string bin;
	std::cout << "Arr = { ";
	for (auto& element : vector) {
		while (element) {
			bin += char('0' + element % 2);
			element /= 2;
		}
		std::cout << std::string(bin.crbegin(), bin.crend()) << " ";
		bin = "";
	}
	std::cout << "}" << std::endl << std::endl;
}

void radixSort(std::vector<long long>& vector) {
	unsigned maxDigits = 0;
	long long count;
	unsigned currentDigit;
	for (const auto& element : vector) {
		if ((count = ceil(log2(element))) > maxDigits) {
			maxDigits = count;
		}
	}
	std::vector<std::vector<long long>> buffer(2);

	for (int i = 0; i < maxDigits; i++) {
		for (const auto& element : vector) {
			currentDigit = (element & (1ll << i)) != 0;
			buffer.at(currentDigit).push_back(element);
		}
		vector.clear();
		for (const auto& subbuffer : buffer) {
			for (const auto& element : subbuffer) {
				vector.push_back(element);
			}
		}
		for (auto& subbuffer : buffer) {
			subbuffer.clear();
		}
	}
}

int main() {
	system("chcp 1251 > nul");
	std::mt19937 randomGenerator;
	std::random_device device;
	randomGenerator.seed(device());

	size_t vectorSize;
	std::cout << "Введите размер массива: ";
	std::cin >> vectorSize;
	std::vector<long long> arr(vectorSize);

	randomizeVector(arr, randomGenerator);
	std::cout << "Исходный массив: " << std::endl;
	printVector(arr);
	std::cout << "Исходный массив в двоичном представлении: " << std::endl;
	binaryPrintVector(arr);

	radixSort(arr);
	std::cout << "Отсортированный массив в двоичном представлении: " << std::endl;
	binaryPrintVector(arr);
	std::cout << "Отсортированный массив: " << std::endl;
	printVector(arr);

	return 0;
}