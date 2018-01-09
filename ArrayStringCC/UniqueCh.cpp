#include <iostream> 
#include <string> 
#include "UniqueCh.h" 

int main (int argc, char** argv) { 
	for (int i = 1; i < argc; i++) {
		std::cout << "Is " <<  argv[i] <<  " unique?" << std::endl; 
		if (uniqueStrCh(argv[i]))
			std::cout << "Yes." << std::endl; 
		else std::cout << "No." << std::endl;  
	}
	return 0; 
}

