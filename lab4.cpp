#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

string word, mainStr = "hh hh  gg gg";
//int a = 0;

string normalize_text(string str) {
    int i, x;
    for (i = x = 0; str[i]; ++i)
        if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1])))
            str[x++] = str[i];
    str[x] = '\0';

	for (int i = 0; i < str.length(); i++) {
		if ((str[i] == '.' || str[i] == '?' || str[i] == ',' || str[i] == ':' || str[i] == ';' || str[i] == '!') && (str[i + 1] == '.' || str[i + 1] == '?' || str[i + 1] == ',' || str[i + 1] == ':' || str[i + 1] == ';' || str[i + 1] == '!')) {
			if (str[i] == '.' && str[i + 1] == '.' && str[i + 2] == '.' && (str[i + 3] == ' ' || str[i + 3] == NULL)) {
				i += 3;
			}
			else
				while (str[i + 1] == '.' || str[i + 1] == '?' || str[i + 1] == ',' || str[i + 1] == ':' || str[i + 1] == ';' || str[i + 1] == '!') {
					str.erase(i + 1, 1);
				}
		}
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			i += 2;
		}
		str[i] = tolower(str[i]);
	}
    return str;
}
void cout_in_reverse_order(string str){
	int a = 0;
	str += " ";
	cout << "In reverse order:\n";
	for (int i = str.length(); i >= 0; i--) {
		if (str[i] == ' ') {
			for (int j = i + 1; j <= (i + a); j++) {
				cout << str[j];
			}
			a = 0;
		}
		a++;
	}
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') break;
		cout << str[i];
	}
	cout << "\n\n";
}

void cout_to_uppercase(string str) {
	str[0] = toupper(str[0]);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str[i + 1] = toupper(str[i + 1]);
		}

	}
	cout << "All first letters of words are capitalized:\n" << str << "\n\n";
}

void substring_search(string str) {
	cout << "Enter the substring from the source text that you want to find:\n";
	cin >> word;
	int a = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == word[0]) {
			for (int j = 0; j < word.length(); j++) {
				if (str[i + j] == word[j]) {
					if (j == word.length() - 1) {
						++a;
					}
				}
			}
		}
	}
	if (a == 0) {
		cout << "[LN]Not found\n";
	}
	else
		cout << "[LN]Found " << a << " matches\n";

	a = 0;

	//BM variant

	
	//Creation of the table named sample on the base of string named word.
	
	int N = word.length(), sample[16] = {0}, i, j, lastChar, shiftIndex, textLen = word.length();
	for (i = N - 2; i > -1; i--) {
		sample[i] = N - i - 1;
		for (j = N - 2; j > i; j--) {
			if (word[i] == word[j]) {
				sample[i] = sample[j];
				break;
			}
		}
	}
	sample[N - 1] = N;
	for (i = N - 1; i > -1; i--) {
		if (word[N - 1] == word[i]) {
			sample[N - 1] = sample[i];
			break;
		}
	}


	//BM algo itself
	
	i = 0, j = N - 1, lastChar = str[N - 1];
	while (j + i < textLen) {
		//printf("%d ", j + i + 1);
		a++;
		if (str[j + i] != word[j] || j == 0) {
			shiftIndex = -1;
			for (int k = 0; k < N; k++) {
				if (lastChar == word[k]) {
					shiftIndex = k;
					break;
				}
			}
			if (shiftIndex == -1) {
				i += N;
			}
			else {
				i += sample[shiftIndex];
			}
			j = N - 1;
			lastChar = str[j + i];
		}
		else {
			j--;
		}
	}
	if (a == 0) {
		cout << "[BM]Not found\n";
	}
	else
		cout << "[BM]Found " << a << " matches\n\n";
}

int ChoseAction4() {
	while(true){
		Chosequestion:
		cout << "Chose one of the following options:\n2. Normalize text\n3. Cout in reverse order\n4. Cout in uppercase (first letter of every word only)\n5. Substring search\nX. Exit\n\n";
		char NumberTypeInput;
		NumberTypeInput = _getch();
		switch (NumberTypeInput) { 
			case('1'): system("cls"); ; break;
			case('2'): system("cls"); mainStr = normalize_text(mainStr); cout << "Your normalized string is\n" << mainStr<<"\n\n"; break;//task 2 
			case('3'): system("cls"); cout_in_reverse_order(mainStr); break;//task 3
			case('4'): system("cls"); cout_to_uppercase(mainStr); break;//task 4
			case('5'): system("cls"); substring_search(mainStr); break;//task 5
			case('x'): system("cls"); return 0;
			case('X'): system("cls"); return 0;
			/*case('q'): system("cls"); break; Добавить выход по q?
			case('Q'): system("cls"); break;*/
			default: goto Chosequestion; break;
		}
	}
}

int main4()
{
	cout << "Enter the string via:\n1. Cin\n2. File\n";//task 1
	int choose;
	while (true) {
		cin >> choose;
		if (choose == 1) {
			cin.ignore();
			getline(cin, mainStr);
			break;
		}
		if (choose == 2) {
			ifstream file;
			file.open("TEXT.txt");
			if (!file.is_open()) {
				cout << "File not found\n";
			}
			else
			{
				getline(file, mainStr);
			}
			file.close();
			break;
		}
		else
		{
			continue;
		}
	}
	//cout << "Your string:\n" << mainStr << "\n\n";

	ChoseAction4();
	return 0;
}