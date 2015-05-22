#include "Decoder.h"
#include "cipher_source.h"
#include "ran.h"
#include <vector>
#include <algorithm>
#include <string>


using namespace std;


string Decoder::decode_string(std::string password_string, std::string coded)
{ //password, message
	int c_position;
	ran randomgen;
	int ran_seed_i = randomgen.generate_seed(password_string);
	string decoded_string = "";
	int length_i = coded.length();


	vector<char> shuffled_vector(c_standard, c_standard + sizeof(c_standard) / sizeof(char));
	srand(randomgen.generate_seed(password_string));
	std::random_shuffle(shuffled_vector.begin(), shuffled_vector.end());

	if (length_i % 2 == 0) //a, r, r
	{
		for (int i = 0; i < length_i; i += 3)
		{
			c_position = randomgen.vectorposition(shuffled_vector, coded.at(i));
			decoded_string += c_standard[c_position];
		}
	}

	else //r, a, r
	{
		for (int i = 1; i < length_i - 3; i += 3)
		{
			c_position = randomgen.vectorposition(shuffled_vector, coded.at(i));
			decoded_string += c_standard[c_position];
		}
	}
	return decoded_string;
}
