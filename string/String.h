#pragma once

#include <cstddef>
#include <stdint.h>

class String
{
public:
	String();
	String(const char* str);
	String(const String& str);
	String(String&& str) noexcept;
	String(const String& str, size_t pos, size_t len);
	~String();

	String& operator= (const char* str);
	String& operator= (String&& str) noexcept;
	char& operator[] (std::size_t pos);
	bool operator< (String& str);
	bool operator== (String& str);
	friend std::ostream& operator<< (std::ostream&, String& str);

	String& insert(std::size_t pos, const char* str);
	int compare(const String& str);
	size_t find(const String& str, size_t pos) const;

private:
	std::size_t size;
	std::size_t capacity;
	char* pointer;
	void swap(String& right);
};