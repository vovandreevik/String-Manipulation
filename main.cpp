#include <iostream>
#include "String.h"

void sort(String** mass, int size);
bool repeatitions(String** mass, int size);
bool equalBegin(String** mass, int size, String& search);


int main() {
	const int CSEARCH = 5;
	char csearch[CSEARCH] = { "abcd" };
	String search(csearch);

	int size = 5;
	std::cout << "Enter 5 strings: \n";
	char* buff = new char[1000];
	String** string = new String * [size];
	for (int i = 0; i < size; i++) {
		std::cin >> buff;
		string[i] = new String(buff);
	}
	
	sort(string, size);

	std::cout << "\nThe result:\n";
	for (int i = 0; i < size; i++) {
		std::cout << *(string[i]) << '\n';
	}

	if (repeatitions(string, size)) {
		std::cout << "There are repeatitions in the string \n";
	}
	else {
		std::cout << "There are no repeatitions in the string \n";
	}
	
	if (equalBegin(string, size, search)) {
		std::cout << "There are strings starting from "<< search<< '\n';
	}
	else {
		std::cout << "There are no strings starting from " << search << '\n';
	}

	delete[] string;
	return 0;
}

void sort(String** mass, int size) {
	int ind = 0;
	for (int i = 0; i < size - 1; i++) {
		ind = 0;
		String* mx = new String;
		for (int j = i; j < size; j++) {
			if (*mx < *mass[j]) {
				mx = mass[j];
				ind = j;
			}
		}
		if (ind != 0) {
			mass[ind] = mass[i];
			mass[i] = mx;
		}
	}
}

bool repeatitions(String** mass, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (*(mass[i]) == *(mass[j])) { 
				return true; 
			}
		}
	}
	return false;
}

bool equalBegin(String** mass, int size, String& search) {
	for (int i = 0; i < size; i++) {
		if (mass[i]->find(search, 0) == 0) {
			return true;
		}
	}
	return false;
}

