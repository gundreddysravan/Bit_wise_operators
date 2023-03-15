#include <stdio.h>
#include <stdlib.h>
#define BITS sizeof(int) * 8 // Total bits required to represent integer
#define INT_SIZE sizeof(int) * 8 /* Integer size in bits */
#define INT_BITS 32
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

    
    printf("\n************lowest bit  of a number***********\n");
    printf("Enter any number: ");
    scanf("%d", &num);

    
    order = INT_SIZE - 1;

    
    for(i=0; i<INT_SIZE; i++)
    {
        
        if((num>>i) & 1)
        {
            order = i;

            
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

    
    printf("Enter any number: ");
    scanf("%d", &num);

    
    msb = 1 << (INT_SIZE - 1);

    count = 0;

    
    for(i=0; i<INT_SIZE; i++)
    {
        
        if((num << i) & msb)
        {
            
            break;
        }

        count++;
    }

    printf("Total number of leading zeros in %d is %d", num, count);

}


void flip_all_bits()
{
    int num, flippedNumber;

    
    printf("Enter any number: ");
    scanf("%d", &num);

    flippedNumber = ~num;

    printf("Original number = %d (in decimal)\n", num);
    printf("Number after bits are flipped = %d (in decimal)", flippedNumber);

}

void couunt_1_0()
{
    int num, zeros, ones, i;

    
    printf("Enter any number: ");
    scanf("%d", &num);

    zeros = 0;
    ones = 0;

    for(i=0; i<INT_SIZE; i++)
    {
        
        if(num & 1)
            ones++;
        else
            zeros++;

        
        num >>= 1;
    }

    printf("Total zero bit is %d\n", zeros);
    printf("Total one bit is %d", ones);

}


/************************rotation******************/

int leftRotate(int n, unsigned int d)
{
    
    return (n << d) | (n >> (INT_BITS - d));
}
 

int rightRotate(int n, unsigned int d)
{
   
    return (n >> d) | (n << (INT_BITS - d));
}
 

void rotate_left_right()
{
    int n = 16;
    int d = 2;
    printf("\nenter the number:");
    fflush(stdin);
    scanf("%d",&n);
    printf("\nenter the numer of rotations:");
    fflush(stdin);
    scanf("%d",&d);
    printf("Left Rotation of %d by %d is\n ", n, d);
    printf("%d", leftRotate(n, d));
    printf(" Right Rotation of %d by %d is\n ", n, d);
    printf("%d", rightRotate(n, d));
}

/*********************rotation**********************/


/********************decimal to binary**************/



void deciaml_to_binary(void)
{
	int num=0,i=0;
	printf("\nenter the decimal number:");
	fflush(stdin);
	scanf("%d",&num);
	printf("\nDecimal formt of the number %d is:",num);
	for(i=31;i>=0;i--)
	{
		printf("%d",(num>>i)&1);
	}
	
}

/**************************************************/


/*******************swap two numbers with bitwise operators****/
int swap_numbers_bitwise()
{
    int num1, num2;

    
    printf("\nEnter any two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("\nOriginal value of num1 = %d\n", num1);
    printf("\nOriginal value of num2 = %d\n", num2);

 
    num1 ^= num2;
    num2 ^= num1;
    num1 ^= num2;

    printf("Num1 after swapping = %d\n", num1);
    printf("Num2 after swapping = %d\n", num2);

    return 0;
}


/**************************************************************/
/******************even or odd*************************************/

int even_odd()
{
    int num;

   
    printf("Enter any number: ");
    scanf("%d", &num);

    if(num & 1)
    {
        printf("%d is odd.", num);
    }
    else
    {
        printf("%d is even.", num);
    }

    return 0;
}

/******************************************************************/



