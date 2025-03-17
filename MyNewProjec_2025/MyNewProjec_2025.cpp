#pragma comment (lib, "winmm.lib")
#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <cmath>

using namespace std;


int main() {
	srand(time(NULL));


	//int a = 10;
	//int b = 100;

	//cout << "A = " << a << " B = " << b << endl;

	//a = a + b;//  10 + 100 =110
	//b = a - b;//  110 - 100 = 10
	//a = a - b;// 110 - 10 = 100

	//int temp = a;
	//a = b;
	//b = temp;

	//cout << "A = " << a << " B = " << b << endl;

	const int ARRAY_SIZE = 7;
	int array[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i)
		array[i] = rand() % 90 + 10;

	for (int i = 0; i < ARRAY_SIZE; ++i)
		cout  << array[i]<< ' ';
	cout << endl;

	bool isSwap = false;
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		isSwap = false;
		for (int j = 0; j < ARRAY_SIZE - 1 - i; ++j)
			if (array[j] > array[j + 1]) {
				//int temp = array[j];
				//array[j] = array[j + 1];
				//array[j + 1] = temp;
				swap(array[j], array[j + 1]);
				isSwap = true;
			}
		if (!isSwap)
			break;
	}
	for (int i = 0; i < ARRAY_SIZE; ++i)
		cout << array[i] << ' ';
	cout << endl;

	//bool isSort = false;
	//int counter = 0;
	//do {
	//	cout << counter << " time -> ";
	//	for (int i = 0; i < ARRAY_SIZE; ++i)
	//		cout << array[i] << ' ';
	//	cout << endl;
	//	isSort = true;
	//	for (int i = 0; i < ARRAY_SIZE - 1; ++i)
	//		if (array[i] > array[i + 1]) {
	//			isSort = false;
	//			counter++;
	//			for (int i = 0; i < ARRAY_SIZE; ++i)
	//				swap(array[i], array[rand() % ARRAY_SIZE]);
	//			break;
	//		}
	//} while (!isSort);

	//cout << "new array -> " << endl;
	//for (int i = 0; i < ARRAY_SIZE; ++i) {
	//	array[i] = rand() % 89 + 10;
	//	cout << array[i] << ' ';
	//}
	//cout << endl;


	system("pause");
}

