#include <iostream>
#include <cstring>
#include <cmath>
#include "String.h"

String::String()
{
	size = 0;
	capacity = 0;
	pointer = nullptr;
}

String::String(const char* str)
{
	size = strlen(str);
	capacity = strlen(str);
	pointer = new char[capacity];
	for (int i = 0; i < capacity; i++)
	{
		pointer[i] = str[i];
	}
}

String::String(const String& str) {
	size = str.size;
	capacity = str.capacity;
	pointer = new char[capacity];
	for (int i = 0; i < capacity; i++) {
		pointer[i] = str.pointer[i];
	}
}

String::String(String&& str) noexcept
{
	size = str.size;
	capacity = str.capacity;
	pointer = str.pointer;
	str.size = 0;
	str.capacity = 0;
	str.pointer = nullptr;
}

//Copies the portion of str that begins at the character position pos and spans len characters (or until the end of str, if either str is too short or if len is string::npos).
String::String(const String& str, size_t pos, size_t len = SIZE_MAX) {
	len = std::min(strlen(str.pointer) - pos, len);
	for (int i = pos; i < len; i++) {
		pointer[i] = str.pointer[i];
	}
}

String::~String() {
	if (pointer != nullptr) { 
		delete[] pointer; 
	}
}

String& String::operator= (const char* str) {
	size = strlen(str);
	capacity = strlen(str);
	delete[] pointer;
	pointer = new char[capacity];
	for (int i = 0; i < capacity; i++) {
		pointer[i] = str[i];
	}
	return *this;
}

void String::swap(String& right)
{
	std::swap(size, right.size);
	std::swap(capacity, right.capacity);
	std::swap(pointer, right.pointer);
}

String& String::operator=(String&& str) noexcept
{
	if (this != &str)
	{
		swap(str);
	}
	return *this;
}

char& String::operator[] (std::size_t pos) {
	try {
		if (pos >= 0 and pos <= size - 1)
		{
			return pointer[pos];
		}
		else { 
			throw std::runtime_error("index out of range!"); 
		}
	}
	catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << "\n";
		exit(-1);
	}
}

bool String::operator< (String& str){
	for (int i = 0; i < std::min(size, str.size); i++){
		if (pointer[i] != str.pointer[i]){
			if (pointer[i] > str.pointer[i]){ 
				return true; 
			}
			else{ 
				return false; 
			}
		}
	}
	return true;
}

bool String::operator== (String& str) {
	if (size == str.size) {
		for (int i = 0; i < size; i++) {
			if (pointer[i] != str.pointer[i]) { 
				return false; 
			}
		}
	}
	return true;
}

std::ostream& operator<< (std::ostream& out, String& str) {
	for (int i = 0; i < str.size; i++) {
		out << str.pointer[i];
	}
	return out;
}

size_t String::find(const String& str, size_t pos = 0) const {
	int index = SIZE_MAX;
	for (int i = pos; i < size - str.size + 1; i++) {
		if (pointer[i] == str.pointer[0]) {
			index = i;
			for (int j = 1; j < str.size; j++) {
				if (pointer[i + j] != str.pointer[j]) {
					index = SIZE_MAX;
					break;
				}
			}
			if (index != SIZE_MAX) { 
				return index; 
			}
		}
	}
	return index;
}

String& String::insert(std::size_t pos, const char* str)
{
	if ((strlen(str) == 0) or (pointer == nullptr) or (pos > size - 1 || pos < 0))
	{
		return *this;
	}
	char* temp = new char[strlen(str) + size];
	if (capacity < strlen(str) + size)
	{
		capacity = strlen(str) + size;
		size = capacity;
	}
	int j = 0, k = 0;
	for (int i = 0; i < pos; ++i)
	{
		temp[i] = pointer[j];
		j++;
	}
	for (int i = pos; i < strlen(str) + pos; i++)
	{
		temp[i] = str[k];
		k++;
	}
	for (int i = pos + strlen(str); i < size; i++) {
		temp[i] = pointer[j];
		j++;
	}
	delete[] pointer;
	pointer = temp;
	return *this;
}

int String::compare(const String& str)
{
	int minSize = 0;
	if (size <= str.size) {
		minSize = size;
	}
	else {
		minSize = str.size;
	}
	for (int i = 0; i < minSize; i++) {
		if (pointer[i] < str.pointer[i]) {
			return -2;
		}
		else if (pointer[i] > str.pointer[i]) {
			return 2;
		}
	}
	return 0;
}
