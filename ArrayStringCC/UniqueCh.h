#include <string> 

/* determines if the string is composed of non-duplicating characters */ 

bool uniqueStrCh(std::string str) {
	int ASCIILength = 128;
	int strCtr[ASCIILength];
	for (int i = 0; i < ASCIILength; i++){
		strCtr[i] = 0; 	
	}
	for (int i = 0; i < str.length(); i++) {
		strCtr[str[i]]++;  	
	}
	for (int i = 0; i < ASCIILength; i++) { 
		if (strCtr[i] > 1)
			return false; 
	}
	return true;
}
