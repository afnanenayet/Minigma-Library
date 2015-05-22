#pragma once
#include <vector>

class ran
{
public:
	int generate_seed(std::string password_string);
	int getposition(const char* array, size_t size, char c);
	int vectorposition(std::vector<char>& index_vector, char& c);
	std::string getTime();
	void write_to_file(std::string write_string, int iteration_i);
	void write_decode(std::string write_string, int id_i);
};
