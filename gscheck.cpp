#include <iostream>
#include <string>
#include "char_stack.h" 
using namespace std;

int main (){
	char_stack S;
	char c; // single character in the text file just read
	char l; // character that has been poped from stack
	char r; //expected character that matches l
	bool error =false;
	string input;		// store input in string
	int i = 1; 	// the number of lines
	string lastline;	// store the last line we read
	
	while ( getline(cin,input) && error==false){
		for (int j=0; j< input.length(); j++){//j is the index that being read in each single line
			c = input.at (j);
			if ((c == '(') || (c == '[') || (c == '{'))	// push if opening symbols
			{
				S.push( c );
			}
			else if ((c == ')') || (c == ']') || (c == '}')){	// pop if closing symbols
				if ( S.empty() ==true){	//if the Stack S is empty
					cout << "Error on line "<< i <<": Too many " << c <<endl;
					cout << input.substr(0,j+1) << endl;//print out the input from index 0 to j
					for (int k=0; k<= j; k++){
					cout << " ";//print out the space before the reminder in the next line
					}
					cout << input.substr(j+1,input.length()) << endl;//print out the reminder on the second line					
		                    error = true;
		                    break;					
				}
				l = S.pop();
				if (l == '(')
				{
					r = ')';
				}
				else if(l == '[')
				{
					r = ']';
				}
				else if(l == '{')
				{
					r = '}';
				}
				if(c != r){	//if do not match, print the error message
					cout<< "Error on line "<< i <<": Read " << c<<", expected "<< r<<endl;  // here, r is the closing symbol matching l	
					cout << input.substr(0,j+1) << endl;//print out the input from index 0 to j
					for (int k=0; k<= j; k++){
					cout << " ";//print out the space before the reminder in the next line
					}
					cout << input.substr(j+1,input.length()) << endl;//print out the reminder on the next line 				
		                    error = true;
		                    break;
		        }            
			}
		}
		i +=1;			// line numbers add 1 if we read another line
	lastline=input;//the lastline read from input 
	}
	
		if (error == false){
			if ( S.empty()==false ){
					c = S.pop();//pop out c for remaining input in the stack
				cout<< "Error on line"<< i-1 << ":Too many " << c<< endl;
				cout << lastline << endl;
			}						                   		
			else {
				cout<< "No Errors Found"<<endl;
			}
		}	
		return 0;		
}
