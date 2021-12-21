#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n){
	if (n == -1)
		return "";
	return s[n] + reverse(s,n-1); 
}

//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2){
	if (n2 == -1) 
		return true;
	if (n2 == n1 + 1 || n1 == n2) 
		return s[n1] == s[n2]; 
	else 
		if (s[n1] == s[n2])
			return isPalindrome(s,n1+1,n2-1); 
		return false; 
}

//Exercise 2 (c) Implement this function
int distancePalindrome(string s, int n1, int n2){
	if (isPalindrome(s,n1,n2))
		return 0;
	string reversed = reverse(s,n2);
	int acc = 0;
	for (int i = 0; i<n2+1;i++){
		if (s[i] != reversed[i])
			acc += 1;
	}
	return acc/2;
}