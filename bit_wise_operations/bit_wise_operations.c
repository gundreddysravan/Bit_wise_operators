#include <stdio.h>
#include <stdlib.h>
#define BITS sizeof(int) * 8 // Total bits required to represent integer
#define INT_SIZE sizeof(int) * 8 /* Integer size in bits */

void lsb_of_num(void)
{
    int num;
printf("\n************LSB of a number***********\n");
    printf("Enter the number: ");
    scanf("%d", &num);

    if(num & 1)
        printf("LSB of %d is set (1).", num);
    else
        printf("LSB of %d is unset (0).", num);
}




void msb_of_nmbr(void)
{
	    int num, msb;
	    printf("\n************MSB of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    num =num>> (BITS - 1);

    if(num)
        printf("MSB of the number is set (1).");
    else
        printf("MSB of the number is unset (0).");


}

void get_nth_bit_of_a_nmbr(void)
{
    int num, n, bitStatus;

    /* Input number from user */
    printf("\n************Get nth bit of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to check */
    printf("Enter nth bit to check (0-31): ");
    scanf("%d", &n);

    /* Right shift num, n times and perform bitwise AND with 1 */
    bitStatus = (num >> n) & 1;

    printf("The %d bit is set to %d", n, bitStatus);

}


void set_nthbit_of_a_nmbr()
{
    int num, n, newNum;

    /* Input number from user */
    printf("\n************Set nth bit of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to set */
    printf("Enter nth bit to set (0-31): ");
    scanf("%d", &n);

    /* Left shift 1, n times and perform bitwise OR with num */
    newNum = (1 << n) | num;

    printf("Bit set successfully.\n\n");
    printf("Number before setting %d bit: %d (in decimal)\n", n, num);
    printf("Number after setting %d bit: %d (in decimal)\n", n, newNum);
}



void clear_nth_bit_of_a_nmbr(void)
{
    int num, n, newNum;

    /* Input number from user */
    printf("\n************Clear nth bit of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit number you want to clear */
    printf("Enter nth bit to clear (0-31): ");
    scanf("%d", &n);

    /*
     * Left shifts 1 to n times
     * Perform complement of above
     * finally perform bitwise AND with num and result of above
     */
    newNum = num & (~(1 << n));

    printf("Bit cleared successfully.\n\n");
    printf("Number before clearing %d bit: %d (in decimal)\n", n, num);
    printf("Number after clearing %d bit: %d (in decimal)\n", n, newNum);

}


void toggle_a_bit(void)
{
    int num, n, newNum;

    /* Input number from user */
    printf("\n************toggle a bit  of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to toggle */
    printf("Enter nth bit to toggle (0-31): ");
    scanf("%d", &n);

    /*
     * Left shifts 1, n times
     * then perform bitwise XOR with num
     */
    newNum = num ^ (1 << n);

    printf("Bit toggled successfully.\n\n");
    printf("Number before toggling %d bit: %d (in decimal)\n", n, num);
    printf("Number after toggling %d bit: %d (in decimal)\n", n, newNum);

}




void get_highest_bit(void)
{
    int num, order = -1, i;

    /* Input number from user */
    printf("\n************Get highest bit  of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Iterate over each bit of integer */
    for(i=0; i<INT_SIZE; i++)
    {
        /* If current bit is set */
        if((num>>i) & 1)
            order = i;
    }

    if (order != -1)
        printf("Highest order set bit in %d is %d", num, order);
    else 
        printf("0 has no set bits.");

}



void lowest_bit_of_a_nmbr(void)
{
    int num, order, i;

    /* Input number from user */
    printf("\n************lowest bit  of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Initially set the order to max size of integer */
    order = INT_SIZE - 1;

    /* Iterate through each bit of integer */
    for(i=0; i<INT_SIZE; i++)
    {
        /* If current bit is set */
        if((num>>i) & 1)
        {
            order = i;

            /* Terminate the loop */
            break;
        }
    }

    printf("Lowest order set bit in %d is %d", num, order);

}

void trailing_zeros()
{
    int num, count, i;

    
    printf("Enter any number: ");
    scanf("%d", &num);

    count = 0;

    for(i=0; i<INT_SIZE; i++)
    {
       
        if((num >> i ) & 1)
        {
            
            break;
        }
      
        count++;
    }

    printf("Total number of trailing zeros in %d is %d.", num, count);

 
}


void leading_zeros()
{
    int num, count, msb, i;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    // Equivalent to
    // 10000000 00000000 00000000 00000000
    msb = 1 << (INT_SIZE - 1);

    count = 0;

    /* Iterate over each bit */
    for(i=0; i<INT_SIZE; i++)
    {
        /* If leading set bit is found */
        if((num << i) & msb)
        {
            /* Terminate the loop */
            break;
        }

        count++;
    }

    printf("Total number of leading zeros in %d is %d", num, count);

}


void flip_all_bits()
{
    int num, flippedNumber;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    flippedNumber = ~num;

    printf("Original number = %d (in decimal)\n", num);
    printf("Number after bits are flipped = %d (in decimal)", flippedNumber);

}

void couunt_1_0()
{
    int num, zeros, ones, i;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    zeros = 0;
    ones = 0;

    for(i=0; i<INT_SIZE; i++)
    {
        /* If LSB is set then increment ones otherwise zeros */
        if(num & 1)
            ones++;
        else
            zeros++;

        /* Right shift bits of num to one position */
        num >>= 1;
    }

    printf("Total zero bit is %d\n", zeros);
    printf("Total one bit is %d", ones);

}




