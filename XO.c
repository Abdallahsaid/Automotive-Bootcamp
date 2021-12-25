/*
 ============================================================================
 Name        : XO.c
 Author      : Abdalla Saied
 Version     :v.1
 ============================================================================
 */
#define MAXIMUM_TURNS  9
//INCLUDES
#include <stdio.h>
//DATATYPES
typedef unsigned char            u8;

// FUNCTIONS PROTOTYPE
void print_XO_box(void);
void start_xo(void);
u8 edit_XO_box(u8 input, u8 player_mark);
u8 check_win(void);

//GLOBAL VARIABLES
u8 arr_XO_box[25] = {
	'_','_','_','_','_',
	'|','0','1','2','|',
	'|','3','4','5','|',                  //indexes of boxes to mark in ( 6, 7, 8)
	'|','6','7','8','|',                  //                            (11,12,13)
	'|','_','_','_','|',                  //                            (16,17,18)                            
};



int main(void) {
	start_xo();
	return 0;
}

// FUNCTIONS IMPLEMENTATION

//A FUNCTION TO PRINT OUT THE XO BOX
void print_XO_box(void){
   u8 counter = 1;
   for(counter = 1; counter<26 ; counter++){
	   printf("%c ",arr_XO_box[counter-1]);
	   if((counter % 5) == 0){
		   printf("\n");
	   }
   }
}

//A FUNCTION TO EDIT ON THE ARRAY THAT HOLDS THE VALUES OF THE XO BOX
u8 edit_XO_box(u8 input, u8 player_mark)
{
	switch (input)
	{
	case '0':
		arr_XO_box[6] = player_mark;
		break;
	case '1':
		arr_XO_box[7] = player_mark;
		break;
	case '2':
		arr_XO_box[8] = player_mark;
		break;
	case '3':
		arr_XO_box[11] = player_mark;
		break;
	case '4':
		arr_XO_box[12] = player_mark;
		break;
	case '5':
		arr_XO_box[13] = player_mark;
		break;
	case '6':
		arr_XO_box[16] = player_mark;
		break;
	case '7':
		arr_XO_box[17] = player_mark;
		break;
	case '8':
		arr_XO_box[18] = player_mark;
		break;
	default:
		return 0;
		break;
	}
	return 1;
}

//A FUNCTION TO CHECK IF A WIN CONDITION APPLIED
u8 check_win(void){
	if ((arr_XO_box[6]  == arr_XO_box[7]  &&  arr_XO_box[6]  == arr_XO_box[8] ) ||      //first  row
	    (arr_XO_box[11] == arr_XO_box[12] &&  arr_XO_box[11] == arr_XO_box[13]) ||      //second row
		(arr_XO_box[16] == arr_XO_box[17] &&  arr_XO_box[16] == arr_XO_box[18]) ||      //third  row
		(arr_XO_box[6]  == arr_XO_box[12] &&  arr_XO_box[6]  == arr_XO_box[18]) ||      //first  diagonal
		(arr_XO_box[8]  == arr_XO_box[12] &&  arr_XO_box[8]  == arr_XO_box[16]) ||      //second diagonal
		(arr_XO_box[6]  == arr_XO_box[11] &&  arr_XO_box[6]  == arr_XO_box[16]) ||      //first  column
	    (arr_XO_box[7]  == arr_XO_box[12] &&  arr_XO_box[7]  == arr_XO_box[17]) ||      //second column
		(arr_XO_box[8]  == arr_XO_box[13] &&  arr_XO_box[8]  == arr_XO_box[18]) )     //third  column
	{
		//win
		return 1;
	}
	else {
		// no win
		return 0;
	}
	
}

// A FUNCTION THAT PERFORM THE WHOLE PROCESS AND CALL OTHER FUNCTIONS
void start_xo(void)
{   
	u8 dumb;
	u8 input = 0;
	u8 turn = 0;
	u8 player_turn = 0; // X OR O
	u8 success_edit = 0;
	u8 win_status = 0;
	u8 index=0;
	for (turn = 0; turn < MAXIMUM_TURNS; turn++)
	{
		print_XO_box();
		//deciding which player's turn
		if (turn % 2 == 0)
		{
			player_turn = 'X';
		}
		else if (turn % 2 == 1)
		{
			player_turn = 'O';
		}
		else{
			//do nothing
		}
		printf("player '%c' kindly choose the number of the box you want to mark\n", player_turn);
		while (1){
			scanf("%c", &input);
			scanf("%c",&dumb);

			// Input Validation
			if ((input >= '0') && (input < '9')) // Checking for range
			{
				switch (input)
				{
				case '0':
					index = 6;
					break;
				case '1':
					index = 7;
					break;
				case '2':
					index = 8;
					break;
				case '3':
					index = 11;
					break;
				case '4':
					index = 12;
					break;
				case '5':
					index = 13;
					break;
				case '6':
					index = 16;
					break;
				case '7':
					index = 17;
					break;
				case '8':
					index = 18;
					break;
				default:
					break;
				}
				if ((arr_XO_box[index] != 'X') && (arr_XO_box[index] != 'O')) // checking if it has been already marked
				{
					break;
				}
				else{
					printf("player '%c' kindly choose again\n", player_turn);
					continue;
			    }
			}
			else
			{
				printf("player '%c' kindly choose again\n", player_turn);

			}

		}
		edit_XO_box(input,player_turn);
		if(turn >= 4){
			win_status = check_win();
		}
		else{

		}
		if (win_status == 1)
		{
			printf("player '%c' is the winner !!! \n", player_turn);
			break;
		}
		else
		{

		}
		
	}
	if(win_status == 0){
		printf("DRAW!!!");
	}
	print_XO_box();
    scanf("%c",&dumb);
    scanf("%c",&dumb);
}
