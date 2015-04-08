/* File: char_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/
#include "char_stack.h"// contains the declarations of the variables and functions.

char_stack :: char_stack(){
	capacity=250000; // files contain at most 1000 lines, and there are at most 250 characters per line
	stack_size=0;
	A = new char[capacity];
}

void char_stack :: push(char item){
	A[stack_size]= item;
	stack_size=stack_size+1;
}

char char_stack::pop(){
	stack_size=stack_size-1;
	return A[stack_size];
}

char char_stack::top(){
	return A[stack_size-1];
}

bool char_stack::empty(){
	return (stack_size==0);
}

int char_stack::size(){
	return stack_size;
}
