#include <string>
#include "ran.h"
#include <vector>
#include <time.h>
#include <fstream>
#include <cmath>

//this class generates controlled randomness based on a cipher key

namespace patch //workaround patch for "find" function that hasn't been patched in the gcc compiler
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}
using namespace std;


int ran::generate_seed(string password_string)
{
	int ranSeed_i = 0;
	int passLength_i = password_string.length();
	for (int i = 0; i < passLength_i; i++)
	{
		int base_i = int(pow(10, i));
		int character_i = int(password_string.at(i));
		ranSeed_i = ranSeed_i + (character_i * base_i);
	}

	return ranSeed_i;;
}


int ran::getposition(const char* array, size_t size, char c)
{
	const char* end = array + size;
	const char* match = std::find(array, end, c);
	return (end == match) ? -1 : (match - array);
}

int ran::vectorposition(vector<char>& index_vector, char& c)
{
	int pos = find(index_vector.begin(), index_vector.end(), c) - index_vector.begin();
	return pos;
}

string ran::getTime() //TODO: fix the time function, use time_s?
{
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	string time_string = asctime(timeinfo);
	return time_string;
}

void ran::write_to_file(string write_string, int iteration_i)
{
	ofstream file_out;
	string file_name = patch::to_string(iteration_i) + ".txt";
	file_out.open(file_name);
	file_out << write_string;
	file_out.close();
}

void ran::write_decode(string write_string, int id_i)
{
	ofstream file_out;
	string file_name = "d" + patch::to_string(id_i) + ".txt";
	file_name += patch::to_string(id_i);
	file_out.open(file_name);
	file_out << write_string;
	file_out.close();
}
