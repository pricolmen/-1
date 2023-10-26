/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int size;
	cin >> size;
	cin.ignore();
	string* names = new string[size];
	string* writers = new string[size];
	int* dates = new int[size];
	int* count = new int[size];
	for (int i = 0; i < size; i++) {
		string str1, str2, str3, str4;
		cout << "Введите название книги" << " " << i + 1 << ":";
		getline(cin, str1);
		cout << "Введите автора книги" << " " << i + 1 << ":";
		getline(cin, str2);
		names[i].append(str1); writers[i].append(str2);
		cout << "Введите год издания книги" << " " << i + 1 << endl;
		cin >> dates[i];
		cout << "Введите колличество копий книги" << " " << i + 1 << endl;
		cin >> count[i];
		cin.ignore();
	}
	for (int x = 0; x < size - 1; x++) {
		for (int y = 1; y < size; y++) {
			if (names[x] > names[y]) {
				swap(names[x], names[y]);
				swap(writers[x], writers[y]);
				swap(dates[x], dates[y]);
				swap(count[x], count[y]);
			}
		}
	}
	for (int x = 0; x < size; x++) {
		cout << names[x]  << " - Автор: " << writers[x] << ", Год издания: " << dates[x] << ", Количество копий: " << count[x] << endl;
	}
	return 0;
}
