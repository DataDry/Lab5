#include <iostream>
#include <conio.h>
#include <iomanip>
#include "C:\Users\User\Documents\inf\proglab\1\lab1\lab1.cpp"
#include "C:\Users\User\Documents\inf\proglab\2\Lab2\Lab2.cpp"
#include "C:\Users\User\Documents\inf\proglab\3\lab33\lab33.cpp"
#include "C:\Users\User\Documents\inf\proglab\4\lab4\lab4.cpp"

using namespace std;

void main(int pic) {
	cout << setw(40) << right << "Main Window (Lab 5)\nCin Desired lab (1-4) or 'X' for exit:\n";
	int menupick = 0;
	while (true) {
		menupick = _getch();
		switch (menupick) {
		case('1'):
			main1();
			break;
		case('2'):
			main2();
			break;
		case('3'):
			main3();
			break;
		case('4'):
			main4();
			break;
		case('x'):
		case('X'):
			exit(0);
		}
		cout << setw(40) << right << "Main Window (Lab 5)\nCin Desired lab (1-4) or 'X' for exit:\n";
		menupick = 0;
	}
}