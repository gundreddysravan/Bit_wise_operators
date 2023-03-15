#include <stdio.h>
#include <stdlib.h>
#include"bit_wise_operations.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
 int  choice=0;
 while(1)
 {

 printf("\nenter the value as per the below given menu\n");
 printf("1.LSB of a number\n2.MSB of a number\n3.GET nth bit of a number\n4.Clear nth bit of a number\n5.Toggle nth bit\n6.Set nth bit\n7.Lowest bit of an number");
 printf("8.Get highest bit of a number\n9.Trailing zeros\n10.Leading Zeros\n11.Flip all bits\n12.count number of 1's and zeros\n13.Rotate a number\n14.Decimal to Binary\n15.swap two numbers\n16.Even or Odd\n");//
 
 scanf("%d",&choice);
 switch(choice)
 {
 	case 1:
	{
		lsb_of_num();
 			
	}break;
	case 2:
	{
		msb_of_nmbr();
 			
	}break;
 	case 3:
	{
		get_nth_bit_of_a_nmbr();
 			
	}break;
 	case 4:
	{
		clear_nth_bit_of_a_nmbr();
 			
	}break;
 	case 5:
	{
		toggle_a_bit();
 			
	}break;
 	case 6:
	{
		set_nthbit_of_a_nmbr();
 			
	}break;
 	case 7:
	{
		lowest_bit_of_a_nmbr();
 			
	}break;
 	case 8:
	{
		get_highest_bit();
 			
	}break;
 	case 9:
	{
		trailing_zeros();
 			
	}break;
 	case 10:
	{
		
 			leading_zeros();
	}break;
 	case 11:
	{
		flip_all_bits();
 			
	}break;
 	case 12:
	{
		couunt_1_0();
 			
	}break;
	case 13:
	{
		rotate_left_right();
 			
	}break;

	case 14:
	{
		deciaml_to_binary();
 			
	}break; 
	case 15:
	{
		swap_numbers_bitwise();
 			
	}break;
	case 16:
	{
		even_odd();
 			
	}break;

	default :
 	{
 		printf("entered wrong data");
	}

 }
 
}

	return 0;
}
