/* A set of functions to saturate arithmetic for n bit numbers.
* 
* @author Adrian Molofsky
* @version 12/26/22
*/

#include <stdio.h> 
#include <stdlib.h>

/* Function to compute the signed max */
long signed_max(int bitwidth) {
    long result = ~(~0 << (bitwidth - 1));
    return result;
}
/* Function to compute the signed min */ 
long signed_min(int bitwidth) {
    long result = ~0 << (bitwidth - 1);
    return result;
}

/* Function to compute the saturated addition of two numbers */
long sat_add(long operand1, long operand2, int bitwidth) {
    long max, min, result;
    unsigned int sigOp1, sigOp2, sigResult; 
    max = signed_max(bitwidth);
    min = signed_min(bitwidth);
    result = operand1 + operand2;
    sigOp1 = ((unsigned long)operand1 >> 63) & ~(~0 << 1); //sign of operand1
    sigOp2 = ((unsigned long)operand2 >> 63) & ~(~0 << 1); //sign of operand2
    sigResult = ((unsigned long)result >> (bitwidth - 1)) & ~(~0 << 1); //sign of positive result
    
    if (!sigOp1 && !sigOp2) { //if both operands are positive
        if (sigResult) { //if sigResult is negative
            result = max;
        }
    }
    if (sigOp1 && sigOp2) { //if both operands are negative
        if (((unsigned long)result >> 63) & ~(~0 << 1)) {//if sigResult is positiv
            result = min;
        }
    }
    return result;
}

/* main calls the sat add function with user input */
int main() {
  int n, val, bitwidth; // variables to hold numbers and bitwidth
  printf("What two numbers would you like to saturate?");
  scanf("%d", &n);
  scanf("%d", &val);
  printf("For what bitwidth would you like to saturate?");
  scanf("%d", &bitwidth);
  printf("The numbers %d and &val saturated for bitwidth %d is %d", n, val, bitwidth, sat_add(n, val, bitwidth));
  return 0;
}
