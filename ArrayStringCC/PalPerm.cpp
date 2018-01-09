#include <iostream> 
#include "PalPerm.h" 

int main(){ 

std::cout << "Enter a string: " << std::endl; 

std::string str; 

getline(std::cin, str); 

if (isPalindrome(str)) 
	std::cout << "Yes, there is a palindrome." << std::endl; 
else std::cout << "No, there is not a palindrome." << std::endl; 

return 0; 

}
