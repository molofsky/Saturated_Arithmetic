/* A function to saturate arithmetic for n bit numbers
* 
* @author Adrian Molofsky
* @version 12/26/22
*/

#include <stdio.h> 
#include <stdlib.h>

/* Function to saturate arithmetic to be used
* in main. Saturates arithmetic if the input is greater than 
* the n bit max 2^n - 1.
*/
size_t saturate(size_t n, int d) {

  return n;
}


/* main calls the saturate function with user input */
int main() {
  printf("What number would you like to saturate?");
  
  printf("For what bit max would you like to saturate?");
  
  printf("The number %lu saturated for %d is %lu")
  return 0;
}
