#include <iostream> 
#include "URLify.h" 

int main () { 
	
	std::cout <<  "Enter a string: "; 
	std::string str; 
	std::getline(std::cin, str); 

	std::cout << str.length() << std::endl;  

	URLify(str); 

	std::cout << "The new string is: " << str << std::endl;  
	

}
