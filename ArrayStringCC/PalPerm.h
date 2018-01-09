#include <string> 
#include <iostream> 

//Program checks to see if there is a permutation of a palindrome given the string

bool isPalindrome(std::string str){

	int ASCIIvalue = 128; 
	int freq[ASCIIvalue]; 

	for (int i = 0; i < ASCIIvalue; i++){ 
		freq[i] = 0; 
	}
	
	for (int i = 0; i < str.length(); i++){
		if (!isspace(str[i]))
			++freq[str[i]]; 
	}

	int counter = 0; 

	for (int i = 0; i < ASCIIvalue; i++){
		if ((freq[i] % 2 != 0) || (freq[i] == 1)) 
			++counter;
	}

	std::cout << counter << std::endl;
	
	if (str.length() % 2 == 0){
		if (counter == 0)
			return true; 
	}
	else {
		if (counter == 1) 
			return true; 
	}
	return false;
}
