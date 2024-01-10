#include <iostream>
#include <random>
#include <cmath>

void init(int A[], int n, std::mt19937& randomGenerator) {
	for (int i = 0; i < n; i++) {
		std::uniform_int_distribution<int> distribution(-100, 100);
		A[i] = distribution(randomGenerator);
	}
}

void print(int B[], int n) {
	std::cout << "Arr = { ";
	for (int i = 0; i < n; i++) {
		std::cout << B[i] << " ";
	}
	std::cout << "}" << std::endl << std::endl;
}

void Qsort(int B[], int f, int l) {
	int first = f, last = l;
	int separator = B[((first + last) / 2)];

	while (first <= last) {
		while (B[first] < separator) {
			first++;
		}
		while (B[last] > separator) {
			last--;
		}
		if (first <= last) {
			int buf = B[first];
			B[first] = B[last];
			B[last] = buf;
			first++;
			last--;
		}
	}

	if (f < last) {
		Qsort(B, f, last);
	}
	if (first < l) {
		Qsort(B, first, l);
	}
}

void Hoar_sort(int B[], int n) {
	Qsort(B, 0, n - 1);
}

int main() {
	system("chcp 1251 > nul");
	std::mt19937 randomGenerator;
	std::random_device device;
	randomGenerator.seed(device());

	int n;
	std::cout << "Введите размер массива: ";
	std::cin >> n;
	int* A = new int[n];

	init(A, n, randomGenerator);
	std::cout << "Исходный массив: " << std::endl;
	print(A, n);

	Hoar_sort(A, n);
	std::cout << "Отсортированный массив: " << std::endl;
	print(A, n);

	delete[] A;
	return 0;
}