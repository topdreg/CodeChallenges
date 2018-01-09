#include <iostream>   

#define m 3

void rotateArr(int arr[][m]){
	int temp{0};  	
	for (int i = 0; i < m/2; i++) {
		for (int j = 0; j < m/2; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[m-i][j];
			arr[m-i][j] = arr[m-i][m-j];
			arr[m-i][m-j] = arr[i][m-j]; 
			arr[m-i][j] = temp;  
				
		}
	}

}

int main() {
	
	int size{3};  
	int arr[size][size] = {{1,1,1},{2,2,2},{3,3,3}}; 
	rotateArr(arr); 
	for (int i = 0; i < size; i++) { 
		for (int j = 0; j < size; j++) { 
			std::cout << arr[i][j] << " "; 
		}
		std::cout << std::endl; 
	}

	return 0;  	

}
