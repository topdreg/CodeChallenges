#include <iostream> 
#include "StringCompression.h" 

int main() {
	std::string str; 
	std::cout << "Enter a string with no spaces: " << std::endl; 
	getline(std::cin, str); 
	std::string strCmp = StringCompression(str); 
	std::cout << "The compressed string is: " << strCmp << std::endl; 
	
	return 0; 
	
}
