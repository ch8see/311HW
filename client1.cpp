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
  int box1; // first element popped from stack 
	int box2; // second element popped from stack
  int result; // evaluated result using operator with box2 and box1.


  while (expression[i] != '\0') // til the end of the expression
  {
    try {
      item = expression[i]; // current char

      // if item is operand, push to stack.
			if (item >= '0' && item <= '9') {
				postfixstack.push(item - 48);
				postfixstack.displayAll();
			}

      // if its an operand, two elements are popped from stack and are evaulated with the operand.
			else if ((item == '+') || (item == '-') || (item == '*') || (item == '/') || (item == '^')) {
				box1 = postfixstack.pop();
				box2 = postfixstack.pop();

				if (item == '-') {
					result = box2 - box1;
				}
				else if (item == '+') {
					result = box2 + box1;
				}
				else if (item == '*') {
					result = box2 * box1;
				}
				else if (item == '/') {
					result = box2 * box1;
				}
				else if (item == '^') {
					result = pow(box2, box1);
				}

				// result is then pushed to the stack and stack is displayed.
				postfixstack.push(result);
				postfixstack.displayAll();
			}

			// exception thrown when item is not an operand or operator
			else {
				throw "invalid item";
			}

			i++;

      // TODO: do all the steps in the algorithm given in the handouts
    } // this closes try

    // Catch exceptions and report problems and quit the program now (exit(1)).
    // Error messages describe what is wrong with the expression.
    catch (stack::Overflow) {
      cerr << "stack overflow = stack is full, cannot push" << endl;
      return -1;
    } catch (stack::Underflow) {
      cerr << "stack underflow = stack isempty, cannot pop" << endl;
      return -1;
    } catch (char const *errormsg) { // for invalid item case
      cerr << "[Error] Expression contains invalid item! " << endl;
      return -1;
    }

    // TODO: go back to the loop after incrementing i
  

  } // end of while

  // TODO:
  // After the loop successfully completes:
  // Pop the result and show it.
  result = postfixstack.pop();
	cout << "result: " << result << endl;

  // TODO:
  // If anything is left on the stack, an incomplete expression
  // was found so also inform the user.

  if (!postfixstack.isEmpty()) {
		cerr << "[Error] Incomplete expression! " << endl
			<< endl;
		cerr << "Current stack" << endl;
		cerr << "--------------" << endl;
		postfixstack.displayAll();
	}

} // end of the program
