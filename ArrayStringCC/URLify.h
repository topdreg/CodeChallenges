#include <string> 
#include <iostream> 

//Replaces spaces in a sentence with %20

void URLify (std::string str){

int spaces = 0;

for (int i = 0; i < str.length(); i++) {
	if (isspace(str[i])) 
		++spaces; 
}

int extLength = spaces*2; 

int i = str.length();

for (; isspace(str[i]); --i){
	std::cout << "Yes." << std::endl; 
} 

std::cout << str[i-3] << std::endl;  

for (i = str.length(); extLength != 0; i--){
	if (str[i] != ' ') 
		str[i+extLength] = str[i]; 
	if (str[i] == ' ') {
		str[i] = '0'; 
		str[i-1] = '2'; 
		str[i-2] = '%'; 
		extLength = extLength - 2; 
	}
}

}
