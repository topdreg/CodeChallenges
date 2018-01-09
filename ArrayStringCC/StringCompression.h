#include <string> 
#include <sstream>

std::string StringCompression(std::string str){

	int count = 0; 
	char c = str[0]; 
	int newPosition = 0;
	std::string newStr("");   
	std::ostringstream oss;

	for (int i = 0; i < str.length(); i++){
		if ((c != str[i]) || (i == str.length() - 1)){
			oss.str(""); 
			oss << count; 
			newStr += c;
			newStr += oss.str();
			c = str[i];
			count = 1;
			continue;   
		}
		if (c == str[i]){
			count++;  
		}
	}

	if (newStr.length() < str.length()) 
		return newStr;
	else return str;  
} 
