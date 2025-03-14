//#pragma comment (lib, "winmm.lib")
//#define _USE_MATH_DEFINES
//#include <iostream>
//#include <Windows.h>
//#include <iomanip>
//#include <conio.h>
//#include <cmath>
//
//using namespace std;
//
///*
//int array[10];
//int matrix[5][10]
//*/
//
//int main() {
//	srand(time(NULL));
//	//двовимірні масиви
//	int matrix_1[5][10];
//	int matrix_2[3][3] = {
//							{3, 5, 6},
//							{6, 2, 1},
//							{0, 2, 3} };
//	int matrix_3[5][4] = {
//							{3,5,6,8},
//							{6,2,1},
//							{0} };
//	
//	int matrix_4[4][4] = { {0} };
//
//	int matrix_5[][3] = { 
//							{3, 5, 6},
//							{6, 2, 1},
//							{0, 2, 3} };
//	const int ROWS = 4;
//	const int COLS = 5;
//	int matrix_6[ROWS][COLS];
//
//	for (int i = 0; i < ROWS; ++i) {
//		for (int j = 0; j < COLS; ++j) {
//			matrix_6[i][j] = rand() % 90 + 10;
//		}
//	}
//
//	for (int i = 0; i < ROWS; ++i) {
//		for (int j = 0; j < COLS; ++j) {
//			cout << matrix_6[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	
//	//трьохвимірні масиви
//	int matrix3D[2][3][4]{
//							{{1,3},
//							 {3,5}},
//	
//							{{1,3},
//							 {3,5}}, };
//
//	for (int i = 0; i < 2; ++i)
//		for (int j = 0; j < 3; ++j)
//			for (int z = 0; z < 4; ++z)
//				matrix3D[i][j][z] = rand() % 90 + 10;
//
//	for (int i = 0; i < 2; ++i) {
//		for (int j = 0; j < 3; ++j) {
//			for (int z = 0; z < 4; ++z)
//				cout <<matrix3D[i][j][z] << ' ';
//			cout << endl;
//		}
//		cout << endl<< endl;
//	}
//	cout << endl;
//
//	//цикли foreach
//	int array[] = { 3,4,5,7,7 };
//	for (int i = 0; i < 5; ++i)
//		cout << array[i] << ' ';
//	cout << endl;
//
//	for (int index : array) {
//		cout << index << ' ';
//	}
//	cout << endl;
//
//	for (int& index : array)
//		index = rand() % 10;
//
//	for (auto index : array) {
//		cout << index << ' ';
//	}
//	cout << endl << endl;
//
//	for (auto& matrixLine : matrix_3) {
//		for (auto index : matrixLine) {
//			cout << index << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl << endl;
//
//
//	for (auto& matrixLine : matrix_3) 
//		for (auto& index : matrixLine) 
//			//cin >> index;
//			index = rand() % 10;
//
//	for (auto& matrixLine : matrix_3) {
//		for (auto index : matrixLine) {
//			cout << index << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl << endl;
//
//	system("pause");
//}

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curInf;
	GetConsoleCursorInfo(h, &curInf);
	curInf.bVisible = false;
	SetConsoleCursorInfo(h, &curInf);
	COORD coord = { 0,0 };
	system("mode con cols=15 lines=27");
	srand(time(NULL));

	const int rols = 9;
	const int cols = 3;
	int speed = 200;
	int acselerator = 50;

	int matrix[rols][cols] = { 0 };
	int car[cols][cols] = {
		{0,10,0},
		{10,15,10},
		{10,15,10},
	};
	char key;
	short carPos = 1;
	int trackColor = 13;
	while (true)
	{
		for (int i = 0; i < cols; i++)
			matrix[0][i] = 0;

		if (rand() % 2)
			matrix[0][rand() % cols] = trackColor;
		coord = { 0,0 };
		for (short i = 0; i < rols; i++)
		{
			for (short j = 0; j < cols; j++)
			{
				SetConsoleTextAttribute(h, matrix[i][j]);
				for (short z = 0; z < cols; z++)
				{
					SetConsoleCursorPosition(h, { (coord.X), (coord.Y + z) });
					cout << setw(cols) << setfill(char(219)) << char(219);
				}
				coord.X += cols;
			}
			coord.X = 0;
			coord.Y += cols;
		}
		coord = { carPos * cols,(rols - 1) * cols };
		for (short y = 0; y < cols; y++)
		{
			for (short x = 0; x < cols; x++)
			{
				SetConsoleTextAttribute(h, car[x][y]);
				SetConsoleCursorPosition(h, { (coord.X) + y, (coord.Y + x) });
				cout << "^";
			}
		}
		Sleep(speed);

		if (_kbhit())
		{
			key = _getch();
			switch (key)
			{
			case 'a':
			case 'A': {carPos = (carPos == 0) ? cols - 1 : --carPos; break; }
			case 'd':
			case 'D': {carPos = (carPos == (cols - 1)) ? 0 : ++carPos; break; }
			case 'w':
			case 'W': {speed = ((speed - acselerator) < 0) ? 0 : (speed - acselerator); break; }
			case 's':
			case 'S': {speed = ((speed + acselerator) > 2000) ? 2000 : (speed + acselerator); break; }
			}
			if (key == 27)
				break;
		}
		for (int i = rols - 1; i > 0; i--)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = matrix[i - 1][j];
	}
}
