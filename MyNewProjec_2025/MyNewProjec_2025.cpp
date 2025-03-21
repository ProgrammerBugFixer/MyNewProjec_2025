#pragma comment (lib, "winmm.lib")
#define _USE_MATH_DEFINES
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
	srand(time(NULL));

	//int  array[5] = { 5,2,8,6,1 };
	//int temp[5];
	//temp[0] = array[0];
	//for (int i = 1; i < 5; ++i) {//array
	//	int j;
	//	for(j=0; j<i; j++)//temp
	//		if (array[i] < array[j]) {
	//			int t = i;
	//			while (t>j) {
	//				temp[t] = temp[t - 1];
	//				t--;
	//			}
	//			temp[j] = array[i];
	//			break;
	//		}
	//	if(j==i)
	//		temp[j] = array[i];
	//}
	//int x;
	//for (int i = 0; i < 5; ++i) {
	//	x = array[i];
	//	int j;
	//	for (j = i - 1; j >= 0 && array[j] > x; j--)
	//		array[j + 1] = array[j];
	//	array[j + 1] = x;
	//}


	const int ARRAY_SIZE = 20;
	int array[ARRAY_SIZE] = { 0 };
	for (int i = 0; i < ARRAY_SIZE; ++i)
		array[i] = rand() % 10 + 10;

	for (int index : array)
		cout << index << ' ';
	cout << endl;

	sort(array, array + ARRAY_SIZE);

	for (int index : array)
		cout << index << ' ';
	cout << endl;

	//binary sort
	int start = 0;
	int finish = ARRAY_SIZE - 1;
	int searchNumber = 17;
	int middleIndex;
	while (start < finish) {
		middleIndex = (start + finish) / 2;
		if (array[middleIndex] == searchNumber) {
			start = middleIndex;
			break;
		}
		else if (array[middleIndex] < searchNumber)
			start = middleIndex + 1;
		else
			finish = middleIndex - 1;
	}

	if (array[start] == searchNumber)
		cout << "Search number position is " << start << endl;
	else
		cout << "Number is not found" << endl;

	cout << *max_element(array, array+ARRAY_SIZE) << endl;


	system("pause");
}

