// CS311
// INSTRUCTION:
// Stack class header file template based on Notes-1
// You must complete the ** parts and then complete stack.cpp
// EMACS HINT:
//   control-S does searches
//   Tab on each line will indent perfectly for C++

// =======================================================
// HW#: HW1P1 stack
// Your name: Chase Tanner
// Compiler: VS Code
// File type: headher file stack.h
//=======================================================

const int MAX = 10; // The MAX number of elements for the stack
                    // MAX is unknown to the client
// TODO: select a type for el_t:
typedef int el_t;    // the el_t type is ** for now
                  // el_t is unknown to the client
//-------------------------------------------------------

class stack {

private:        // to be hidden from the client
  el_t el[MAX]; // el is  an array of el_t's
  int top;      // top is index to the top of stack

public: // available to the client

  // TODO: Add exception handling classes here
  class Overflow{};
  class Underflow{};


  // prototypes to be used by the client
  // Note that no parameter variables are given

   stack(); // constructor to create an object
  ~stack(); // destructor  to destroy an object

  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);

  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  el_t pop();

  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: **
  el_t peak();

  // ** Must add good comments for each function - See Notes2A

  // PURPOSE: **
  bool isEmpty();

  // PURPOSE: **
  bool isFull();

  // PURPOSE: **
  void displayAll();

  // PURPOSE: **
  void purge();
};