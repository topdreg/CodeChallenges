#include <iostream> 

int add(int x, int y, bool& flag) {
	
	flag = true; 
	return x + y;  
}

int addMore(int x, int y) {
	
	bool flag = false; 
	add(x,y, flag); 
}


int main() { 

	int x = 0; 
	int y = 2; 
	bool flag = false; 

	add(x, y, flag); 

	if (flag == true) 
		std::cout << "Good" << std::endl; 

}
