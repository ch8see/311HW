// CS311
// INSTRUCTION:
// Look for TODO's to complete this program and comments (Use control-S)
// The output should match my hw1stackDemo.out
//=========================================================
// HW#: HW1P1 stack application (post-fix evaluation)
// Your name: Chase Tanner 
// Compiler: VS Code
// File type: client program client1.cpp
//===========================================================

#include "stack.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// Purpose of the program: Program will convert user inputted strings in postfix notation to integers and display the solution 
// Algorithm: Evaluate postfix expression by pushing numbers onto the stack and applying operators to popped values

int main() {
  stack postfixstack; // integer stack
  string expression;  // user entered expression

  cout << "type a postfix expression: ";//prompts user to input expression
  cin >> expression;//obtains user input

  if(expression.length() > 12){
    cerr << "Error: Expression too long!" << endl;
    exit(1); // exit if the expression is too long
  }

  int i = 0; // character position within expression
  char item; // one char out of the expression
  
  int result;


  while (expression[i] != '\0') // til the end of the expression
  {
    try {
      item = expression[i]; // current char

      // TODO: do all the steps in the algorithm given in the handouts

    } // this closes try

    // Catch exceptions and report problems and quit the program now (exit(1)).
    // Error messages describe what is wrong with the expression.
    catch (stack::Overflow) {
      cerr << "stack overflow = stack is full, cannot push" << endl;
    } catch (stack::Underflow) {
      cerr << "stack underflow = stack isempty, cannot pop" << endl;
    } catch (char const *errormsg) { // for invalid item case
      // TODO: handle invalid expression symbol
    }

    // TODO: go back to the loop after incrementing i

  } // end of while

  // TODO:
  // After the loop successfully completes:
  // Pop the result and show it.

  // TODO:
  // If anything is left on the stack, an incomplete expression
  // was found so also inform the user.

} // end of the program
