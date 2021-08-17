# RPNcalculator
A simple version of the RPN stack based calculator written in C.

In such a calculator, all operations are organized around a stack. 
Entering a number like 37 would push that value on the stack, entering an operation like + or would consume numbers from the top of the stack and push the result on the top of the stack.

All of the numbers are expressed as rational number (fractions), avoiding the roundoff issues endemic to floating point representations. 

### rpn.c 
This file contains the main routine of the calculator.
### stack.c 
This file implements the fundamental operations on the stack such as adding and deleting elements.
### stack.h 
This is a header file containing declarations of relevant data structures and functions provided by stack.c.
