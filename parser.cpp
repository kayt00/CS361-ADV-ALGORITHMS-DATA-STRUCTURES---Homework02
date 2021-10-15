//Katie Taylor
//UIN:01122882

#include <iostream>
#include <stack>

#include "parser.h"

void Parser::checkMatch (char left, char right, int lineNumber)
{
	// TODO check the stack state and determine which output functions
	//      should be called (if any)

	Parser p(m_is, m_os);

	switch(right) {

	case ')': 
		if(left == '[' || left == '{') {  			//Use this routine to signal errors when you have encountered a }]) 
			p.mismatchError(left,right,lineNumber);         //that does not match the most recent ([{
		}	
		else if(left != '(') {
			p.unmatchedError(right, lineNumber);            //if you have encountered a )]} with no preceding ({[ (even non-matching
		}							//ones) in the input.
		break;							
	
	case ']':  
                if(left == '(' || left == '{') {                   
			p.mismatchError(left,right,lineNumber);         
      		}       
                else if(left != '[') {
                        p.unmatchedError(right, lineNumber);
                }
		break;
	
	case '}': 
		if(left == '(' || left == '[') {
			p.mismatchError(left,right,lineNumber);
		}
        	else if(left != '{') {
                        p.unmatchedError(right, lineNumber);
                }
		break;
	}

}

void Parser::Check()
{
	while(!m_Stack.empty()) {	// TODO clear the current state of the stack
		m_Stack.pop();
	}

	Parser p(m_is, m_os); 
	std::string str;
	int line = 0;

	while(getline(m_is, str)) {	// TODO read in the input character by character and update the stack accordingly
	
		for(int i=0; i<str.size(); i++){

			if ( str[i] == '(' || str[i] == '[' || str[i] == '{' ) {
				m_Stack.push(str[i]);

			}
			else if ( str[i] == ')' || str[i] == ']' || str[i] == '}' ) {	// TODO check the stack state using the checkMatch function
				char right = str[i];
				char left = m_Stack.top();
				if(!m_Stack.empty()) {
					m_Stack.pop();
				}
				p.checkMatch(left, right, line);
			}
		
		}
		line++;
	}

	while(!m_Stack.empty()) {  	//Use this routine to signal errors when you have encountered a {[(
		char left = m_Stack.top();	//and there are no )]} (even non-matching ones) left in the input
		m_Stack.pop();
		p.unmatchedError(left, line);
       	}
	
	m_os << "Done" << "\n"; // TODO output "Done" on a single line at the end of parsing
	
}
