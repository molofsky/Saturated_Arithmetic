#include <stdio.h> 
#include <stdlib.h>



/* Function to saturate arithmetic to be used
* in main. Saturates arithmetic if the input is greater than 
* the 16 bit max 2^16 - 1.
*/
size_t saturate(size_t n) {

  return n;
}

int main() {
  printf("What number would you like to saturate?");
  printf("The number %lu saturated is %lu"
  return 0;
}
