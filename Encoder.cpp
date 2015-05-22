#include "Encoder.h"
#include "cipher_source.h"
#include "ran.h"
#include <algorithm>

using namespace std;

string Encoder::encode_to_string(string password_string, string coded_string) //pasword, message
{ //returns encoded string (password, string)
	string encoding_string = "";
	ran randomgen;
	std::vector<char> cipher_vector(c_standard, c_standard + sizeof(c_standard) / sizeof(char));
	std::vector<char> cipher_standard(c_standard, c_standard + sizeof(c_standard) / sizeof(char));
	srand(randomgen.generate_seed(password_string));
	std::random_shuffle(cipher_vector.begin(), cipher_vector.end());

	int c_position;
	//replace elements from standard array to decode


	if (coded_string.length() % 2 == 0)
	{ //if message is even: ARR
		for (unsigned int n = 0; n < coded_string.length(); n++)
		{
			c_position = find(cipher_standard.begin(), cipher_standard.end(), coded_string.at(n)) - cipher_standard.begin();

			encoding_string += cipher_vector.at(c_position); //actual
			encoding_string += cipher_vector.at(rand() % array_length); //randy
			encoding_string += cipher_vector.at(rand() % array_length); //randy
		}
	}

	else
	{ //if message is odd: RAR
		for (unsigned int n = 0; n < coded_string.length(); n++)
		{
			c_position = find(cipher_standard.begin(), cipher_standard.end(), coded_string.at(n)) - cipher_standard.begin();

			encoding_string += cipher_vector.at(rand() % array_length); //randy
			encoding_string += cipher_vector.at(c_position); //actual
			encoding_string += cipher_vector.at(rand() % array_length); //randy
		}
	}


	return encoding_string;
}
