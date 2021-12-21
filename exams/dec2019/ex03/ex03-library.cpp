#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList(){
	allWords.push_back("121");
	wordsToPalindromeDistance["121"]=0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"]=1;
}

//Exercise 3 (a) implement this method
void WordsList::print(){
	cout << wordsToPalindromeDistance.size() << " words: " ;
	for (int i = 0; i < allWords.size(); i++)
		cout << allWords[i] << " (" << wordsToPalindromeDistance[allWords[i]] << ") ";
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s){
	if (s.length() == 1 || s.length() == 0)
		return 0;
	// for (int i = 0; i < s.length(); i++) {
	int j = s.length() -1;
	int i = 0;
	int d = 0;
	while ( i<j) {
		if (s[i] != s[j]) {
			d++;
		}
		i++;
		j--;
	}
	return d;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word){
	allWords.push_back(word);
	wordsToPalindromeDistance[word] = distancePalindrome(word);
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords(){
	int count=0;
	for(int i=0;i<allWords.size();i++){
		if(wordsToPalindromeDistance[allWords[i]]==0){
			count++;
		}
	}
	return count;
}