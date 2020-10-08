#include <stdio.h> 
#include<iostream>
using namespace std;
void print(int *arr, int m, int n) 
{ 
	int i, j; 
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// *((arr+i*n) + j) *= 5;
			// printf("%d ", *((arr+i*n) + j)); 
		}
	}
	cout << *(arr + 8);
} 

int main() 
{ 
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
	int m = 3, n = 3; 

	// We can also use "print(&arr[0][0], m, n);" 
	print((int *)arr, m, n); 
	return 0; 
} 
