#include "ex02-library.h"
#include <iostream>

//Do not modify
int Node::countChildren(){
	return children.size();
}

//Exercise 2 (a) Implement the constructor and getName()
Node::Node(string name){
	this->name = name;
}

string Node::getName(){
	return this->name;
}

//Exercise 2 (b) Implement this method
void Node::addChild(Node * child){
	this->children.push_back(child);
}

//Exercise 2 (c) Check and correct if necessary
void Node::printParentNodes(){
	if (children.size() == 0) return;
	cout << this->name << ' ';
	for(int i = 0; i < children.size(); i++){
		children[i]->printParentNodes();
	}
}

//Exercise 2 (d) Implement this method
void Node::printMembersOfSubTree(int generation){
	if (children.size() == 0){
		cout << this->name << " " << generation << " ";
		return;
	}
	cout << this->name << " " << generation << " ";

	for(int i = 0; i < children.size(); i++) {
		// cout << children[i]->name << " " << generation << " ";
		children[i]->printMembersOfSubTree(generation + 1);
	}
	
	return;
}
