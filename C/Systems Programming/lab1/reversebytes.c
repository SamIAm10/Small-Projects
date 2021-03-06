#include <stdio.h>

/*
 * Print the bits in n in four formats:
 *
 * hexadecimal
 * decimal with bits interpreted as signed int.
 * decimal with bits interpreted as unsigned int.
 * binary
 */
void print_bits(int n)
{
    // print the integer in different format
    printf("hex:%08X signed:%d unsigned:%u bits:", n, n, n);

    // a loop to print bits from most significant to least significant
    // also an example of sizeof use
    for (int i = sizeof(int) * 8 - 1; i >= 0; i --)
       printf("%d", (n >> i) & 1);
    printf("\n");
}

int main()
{
    int n;

    // Repeatedly read an integer 'n' from standard input and
    // reverse its bytes into 'n1' if successful.
    // To exit, press Ctrl-D or Ctr-C
    while (scanf("%d", &n) == 1) {
        int n1 = 0;

        // Your code to reverse the bytes in n and save the reversed bytes in n1.
        // TODO
	int shift1 = n;
	shift1 &= 255;
	n1 |= shift1;
	n1 <<= 8;
	int shift2 = n >> 8;
	shift2 &= 255;
	n1 |= shift2;
	n1 <<= 8;
	int shift3 = n >> 16;
	shift3 &= 255;
	n1 |= shift3;
	n1 <<= 8;
	int shift4 = n >> 24;
	n1 |= shift4;

        // call function to print the bits in n and n1
        print_bits(n);
        print_bits(n1);
    };

    /* Let the OS know everything is just peachy. */
    return 0;
}
