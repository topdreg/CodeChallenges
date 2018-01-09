#include <string> 
#include "Permutation.h"
#include <iostream> 

int main(int argc, char** argv){

	if (argc != 3)
		std::cout << "Must supply two strings." << std::endl;

	bool flag = permutationCheck(argv[1], argv[2]);

	if (flag == true)
		std::cout << "Two strings are permutations of each other" << std::endl; 
	else std::cout << "Not permutations of one another." << std::endl; 

	return 0; 
}
