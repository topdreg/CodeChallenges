#include <iostream>
#include <string> 
#include <vector>
#include <cctype>

template<typename T> 
struct Node { 
	
	T data; 
	std::vector<T> edges; 

};

template<typename T> 
struct Graph {
	
	std::vector<T> nodes; 

};


std::string buildOrder(std::string projects, std::string dependencies) {
	
	for (auto it = projects.begin(); it != projects.end(); it++) {
		if (isalpha(*it)) {
		}
	}

}

int main () { 
	
	std::string projects; 
	std::string dependencies; 
	std::cout << "projects: "; 
	std::cin >> projects; 
	std::cout << projects; 
	std::cout << "dependencies: "; 
	std::cin >> dependencies; 
	std::cout << dependencies; 

}
