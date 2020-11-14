#include <stdio.h>

void print_total_and_average(double total, double average)
// function to print total and average
{
  printf("Total=%f Average=%f\n", total, average);
}

int main()
{
  double total = 0; // initiate all vars as 0
  double average = 0;
  double x = 0;
  double counter = 0;
  while (scanf("%lf", &x) == 1) {
    counter++;    
    total += x;
    average = total / counter;

    // call function to print total and average
    print_total_and_average(total, average);
  };

  // end of main function
  return 0;
}
