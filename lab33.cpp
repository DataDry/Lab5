#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

void Matrix_Generator(int Matrix[10][10], int Size) {
	int* end = &Matrix[Size - 1][Size - 1];
	for (int* pMatrix = &Matrix[0][0]; pMatrix <= end; pMatrix++) {
		*pMatrix = rand() % (Size * Size) + 1;
	}
}

void Snake_OutPut(int Full_Matrix[10][10], int Matrix[10][10], int Size, int Space_Y) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destCoord.X = 0;
	destCoord.Y = 0;
	SetConsoleCursorPosition(hStdout, destCoord);
	int Column = 0, Step_Right = 0, Space_X = 0, * pFull_Matrix = &Full_Matrix[0][0];

	for (int i = 0; i < Size; i++) {
		if (Step_Right % 2 == 0) {
			for (int i = 0; i < Size; i++) {
				Matrix[i][Column] = *(pFull_Matrix);
				destCoord.X = Column + Space_X;
				destCoord.Y = i + i + Space_Y;
				SetConsoleCursorPosition(hStdout, destCoord);
				Sleep(100);
				cout << *pFull_Matrix;
				++pFull_Matrix;
			}
			Space_X += 3;
		}
		else {
			for (int i = Size - 1; i >= 0; i--) {
				Matrix[i][Column] = *(pFull_Matrix);
				destCoord.X = Column + Space_X;
				destCoord.Y = i + i + Space_Y;
				SetConsoleCursorPosition(hStdout, destCoord);
				Sleep(100);
				cout << *pFull_Matrix;
				++pFull_Matrix;
			}
			Space_X += 3;
		}
		++Column;
		++Step_Right;
	}
	destCoord.X = 0;
	destCoord.Y = Space_Y + Size * 2 + 2;
	SetConsoleCursorPosition(hStdout, destCoord);
}

void Swap_Output(int Matrix[10][10], int Size) {
	for (int x = 0; x < Size; x++) {
		for (int y = 0; y < Size; y++) {
			if (Matrix[x][y] >= 100)
				cout << Matrix[x][y] << " ";
			else if (Matrix[x][y] >= 10)
				cout << Matrix[x][y] << "  ";
			else
				cout << Matrix[x][y] << "   ";
		}
		cout << "\n\n";
	}
	cout << "\n\n";
}

void Swap_A(int Matrix[10][10], int Size) {
	cout << "\nSwap A)\n";
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			swap(Matrix[x][y + Size / 2], Matrix[x + Size / 2][y + Size / 2]);
		}
	}
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			swap(Matrix[x][y], Matrix[x][y + Size / 2]);
		}
	}
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			swap(Matrix[x][y], Matrix[x + Size / 2][y]);
		}
	}
	Swap_Output(Matrix, Size);
}

void Swap_B(int Matrix[10][10], int Size) {
	cout << "\nSwap B)\n";
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			swap(Matrix[x][y], Matrix[x + Size / 2][y + Size / 2]);
			swap(Matrix[x + Size / 2][y], Matrix[x][y + Size / 2]);
		}
	}
	Swap_Output(Matrix, Size);
}

void Swap_C(int Matrix[10][10], int Size) {
	cout << "\nSwap C)\n";
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			swap(Matrix[x][y], Matrix[x + Size / 2][y]);
			swap(Matrix[x][y + Size / 2], Matrix[x + Size / 2][y + Size / 2]);
		}
	}
	Swap_Output(Matrix, Size);
}

void Swap_D(int Matrix[10][10], int Size) {
	cout << "\nSwap D)\n";
	for (int x = 0; x < Size / 2; x++) {
		for (int y = 0; y < Size / 2; y++) {
			swap(Matrix[x][y], Matrix[x][y + Size / 2]);
			swap(Matrix[x + Size / 2][y], Matrix[x + Size / 2][y + Size / 2]);
		}
	}
	Swap_Output(Matrix, Size);
}

void Matrix_Bubble_Sort(int Matrix[10][10], int Size) {
	int  Matrix_6x6[6][6], Matrix_8x8[8][8];
	if (Size == 6) {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				Matrix_6x6[i][j] = Matrix[i][j];
			}
		}
		int* pMatrix_6x6_End = &Matrix_6x6[Size - 1][Size - 1];
		for (int* pMatrix_6x6_Begin_i = &Matrix_6x6[0][0]; pMatrix_6x6_Begin_i <= pMatrix_6x6_End; pMatrix_6x6_Begin_i++) {
			for (int* pMatrix_6x6_Begin_j = pMatrix_6x6_Begin_i + 1; pMatrix_6x6_Begin_j <= pMatrix_6x6_End; pMatrix_6x6_Begin_j++) {
				if (*pMatrix_6x6_Begin_i > *pMatrix_6x6_Begin_j) {
					swap(*pMatrix_6x6_Begin_i, *pMatrix_6x6_Begin_j);
				}
			}
		}
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				Matrix[i][j] = Matrix_6x6[i][j];
			}
		}
	}
	if (Size == 8) {
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				Matrix_8x8[i][j] = Matrix[i][j];
			}
		}
		int* pMatrix_8x8_End = &Matrix_8x8[Size - 1][Size - 1];
		for (int* pMatrix_8x8_Begin_i = &Matrix_8x8[0][0]; pMatrix_8x8_Begin_i <= pMatrix_8x8_End; pMatrix_8x8_Begin_i++) {
			for (int* pMatrix_8x8_Begin_j = pMatrix_8x8_Begin_i + 1; pMatrix_8x8_Begin_j <= pMatrix_8x8_End; pMatrix_8x8_Begin_j++) {
				if (*pMatrix_8x8_Begin_i > *pMatrix_8x8_Begin_j) {
					swap(*pMatrix_8x8_Begin_i, *pMatrix_8x8_Begin_j);
				}
			}
		}
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				Matrix[i][j] = Matrix_8x8[i][j];
			}
		}
	}
	else {
		int* pMatrix_End = &Matrix[Size - 1][Size - 1];
		for (int* pMatrix_Begin_i = &Matrix[0][0]; pMatrix_Begin_i <= pMatrix_End; pMatrix_Begin_i++) {
			for (int* pMatrix_Begin_j = pMatrix_Begin_i + 1; pMatrix_Begin_j <= pMatrix_End; pMatrix_Begin_j++) {
				if (*pMatrix_Begin_i > *pMatrix_Begin_j) {
					swap(*pMatrix_Begin_i, *pMatrix_Begin_j);
				}
			}
		}
	}
	Swap_Output(Matrix, Size);
}


int main3() {
	setlocale(0, "Rus");
	srand(time(0));
	cout << "Task 1\n";
	int Size, Matrix[10][10], Matrix2[10][10], Space_Y = 5, choose, num;

	while (true) {
		cout << "Enter the size of the quadratic matrix (6, 8, 10): ";
		cin >> Size;
		if (Size != 6 && Size != 8 && Size != 10) {
			cout << "Wrong number\nTry again\n\n";
			Space_Y += 5;
		}
		else
			break;
	}

	Matrix_Generator(Matrix, Size);
	Snake_OutPut(Matrix, Matrix, Size, Space_Y);
	short int menupick; system("pause");
	__asm {taskm:};
	system("cls");
	cout << "2. Shifting\n3. Sorting\n4. Modifying matrix using a number\n5. PHW\n0. Exit\n\n";
	cin >> menupick;
	switch (menupick) {
	case(2):
		__asm {jmp task2};
	case(3):
		__asm {jmp task3};
	case(4):
		__asm {jmp task4};
	case(5):
		__asm {jmp taskPHW};
	case(0):
		return 0;
	default:
		__asm {jmp taskm};
	}

	__asm {task2:};
	cout << "Task 2\n1) Shift each block to the next block\n2) Cross to cross\n3) Top blocks with bottom blocks\n4) Right blocks with left blocks\n";
	while (true) {
		cin >> choose;
		cout << "\nShifted matrix:\n";

		if (choose == 1) {
			Swap_A(Matrix, Size);
			break;
		}
		if (choose == 2) {
			Swap_B(Matrix, Size);
			break;
		}
		if (choose == 3) {
			Swap_C(Matrix, Size);
			break;
		}
		if (choose == 4) {
			Swap_D(Matrix, Size);
			break;
		}
		else
			cout << "Wrong number\n Try again\n";
	}system("pause"); __asm {jmp taskm};

	__asm {task3:};
	cout << "\n\nTask 3\n";
	Matrix_Bubble_Sort(Matrix, Size); system("pause"); __asm {jmp taskm};

	__asm {task4:};
	cout << "\n\nTask 4\nChoose the action you want to do with the matrix:\n1) Decrease by a number\n2) Increase by a number\n3) Divide by a number\n4) Multiply by a number";
	while (true) {
		cout << "\nModifying variant:\n";
		cin >> choose;
		if (choose == 1) {
			cout << "By what do we reduce it?\n";
			cin >> num;
			for (int i = 0; i < Size; i++) {
				for (int j = 0; j < Size; j++) {
					Matrix[i][j] -= num;
				}
			}
			break;
		}
		if (choose == 2) {
			cout << "By what do we increase it?\n";
			cin >> num;
			for (int i = 0; i < Size; i++) {
				for (int j = 0; j < Size; j++) {
					Matrix[i][j] += num;
				}
			}
			break;
		}
		if (choose == 3) {
			cout << "By what do we divide it?\n";
			cin >> num;
			for (int i = 0; i < Size; i++) {
				for (int j = 0; j < Size; j++) {
					Matrix[i][j] /= num;
				}
			}
			break;
		}
		if (choose == 4) {
			cout << "By what do we multiply it?\n";
			cin >> num;
			for (int i = 0; i < Size; i++) {
				for (int j = 0; j < Size; j++) {
					Matrix[i][j] *= num;
				}
			}
			break;
		}
		else
			cout << "Wrong number\nTry again\n";
	}
	Swap_Output(Matrix, Size); system("pause"); __asm {jmp taskm};

	__asm {taskPHW:};

	Matrix_Generator(Matrix2, Size);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			Matrix[i][j] = Matrix[i][j] + Matrix2[i][j];
			system("cls"); Swap_Output(Matrix, Size);
			Sleep(150);
		}
	}

	system("pause"); __asm {jmp taskm};
	return 0;
}