#include <string>

//Checks to see if two strings are permutations of one another

bool permutationCheck(std::string str1, std::string str2) {
	if (str1.length() != str2.length()) 
		return false; 
	int ASCIILength = 128;
	int letters[ASCIILength];  
	for (int i = 0; i < str1.length(); i++){
		++letters[str1[i]];
	}
	for (int i = 0; i < str2.length(); i++){
		--letters[str2[i]]; 
		if (letters[str2[i]] < 0)
			return false; 
	}
	return true; 
}
