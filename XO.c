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
u8 u8edit_XO_box(u8 input, u8 player_mark);
u8 u8check_win(void);

//GLOBAL VARIABLES
u8 u8g_arr_XO_box[25] = {
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
   u8 u8counter = 1;
   for(u8counter = 1; u8counter<26 ; u8counter++){
	   printf("%c ",u8g_arr_XO_box[u8counter-1]);
	   if((u8counter % 5) == 0){
		   printf("\n");
	   }
   }
}

//A FUNCTION TO EDIT ON THE ARRAY THAT HOLDS THE VALUES OF THE XO BOX
u8 u8edit_XO_box(u8 u8input, u8 u8player_mark)
{
	switch (u8input)
	{
	case '0':
		u8g_arr_XO_box[6] = u8player_mark;
		break;
	case '1':
		u8g_arr_XO_box[7] = u8player_mark;
		break;
	case '2':
		u8g_arr_XO_box[8] = u8player_mark;
		break;
	case '3':
		u8g_arr_XO_box[11] = u8player_mark;
		break;
	case '4':
		u8g_arr_XO_box[12] = u8player_mark;
		break;
	case '5':
		u8g_arr_XO_box[13] = u8player_mark;
		break;
	case '6':
		u8g_arr_XO_box[16] = u8player_mark;
		break;
	case '7':
		u8g_arr_XO_box[17] = u8player_mark;
		break;
	case '8':
		u8g_arr_XO_box[18] = u8player_mark;
		break;
	default:
		return 0;
		break;
	}
	return 1;
}

//A FUNCTION TO CHECK IF A WIN CONDITION APPLIED
u8 u8check_win(void){
	if ((u8g_arr_XO_box[6]  == u8g_arr_XO_box[7]  &&  u8g_arr_XO_box[6]  == u8g_arr_XO_box[8] ) ||      //first  row
	    (u8g_arr_XO_box[11] == u8g_arr_XO_box[12] &&  u8g_arr_XO_box[11] == u8g_arr_XO_box[13]) ||      //second row
		(u8g_arr_XO_box[16] == u8g_arr_XO_box[17] &&  u8g_arr_XO_box[16] == u8g_arr_XO_box[18]) ||      //third  row
		(u8g_arr_XO_box[6]  == u8g_arr_XO_box[12] &&  u8g_arr_XO_box[6]  == u8g_arr_XO_box[18]) ||      //first  diagonal
		(u8g_arr_XO_box[8]  == u8g_arr_XO_box[12] &&  u8g_arr_XO_box[8]  == u8g_arr_XO_box[16]) ||      //second diagonal
		(u8g_arr_XO_box[6]  == u8g_arr_XO_box[11] &&  u8g_arr_XO_box[6]  == u8g_arr_XO_box[16]) ||      //first  column
	    (u8g_arr_XO_box[7]  == u8g_arr_XO_box[12] &&  u8g_arr_XO_box[7]  == u8g_arr_XO_box[17]) ||      //second column
		(u8g_arr_XO_box[8]  == u8g_arr_XO_box[13] &&  u8g_arr_XO_box[8]  == u8g_arr_XO_box[18]) )     //third  column
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
	u8 u8dumb;
	u8 u8input = 0;
	u8 u8turn = 0;
	u8 u8player_turn = 0; // X OR O
	u8 u8win_status = 0;
	u8 u8index=0;
	for (u8turn = 0; u8turn < MAXIMUM_TURNS; u8turn++)
	{
		print_XO_box();
		//deciding which player's turn
		if (u8turn % 2 == 0)
		{
			u8player_turn = 'X';
		}
		else if (u8turn % 2 == 1)
		{
			u8player_turn = 'O';
		}
		else{
			//do nothing
		}
		printf("player '%c' kindly choose the number of the box you want to mark\n", u8player_turn);
		while (1){
			scanf("%c", &u8input);
			fflush(stdin);

			// Input Validation
			if ((u8input >= '0') && (u8input < '9')) // Checking for range
			{
				switch (u8input)
				{
				case '0':
					u8index = 6;
					break;
				case '1':
					u8index = 7;
					break;
				case '2':
					u8index = 8;
					break;
				case '3':
					u8index = 11;
					break;
				case '4':
					u8index = 12;
					break;
				case '5':
					u8index = 13;
					break;
				case '6':
					u8index = 16;
					break;
				case '7':
					u8index = 17;
					break;
				case '8':
					u8index = 18;
					break;
				default:
					break;
				}
				if ((u8g_arr_XO_box[u8index] != 'X') && (u8g_arr_XO_box[u8index] != 'O')) // checking if it has been already marked
				{
					break;
				}
				else{
					printf("player '%c' kindly choose again\n", u8player_turn);
					continue;
			    }
			}
			else
			{
				printf("player '%c' kindly choose again\n", u8player_turn);

			}

		}
		u8edit_XO_box(u8input,u8player_turn);
		if(u8turn >= 4){
			u8win_status = u8check_win();
		}
		else{

		}
		if (u8win_status == 1)
		{
			printf("player '%c' is the winner !!! \n", u8player_turn);
			break;
		}
		else
		{

		}
		
	}
	if(u8win_status == 0){
		printf("DRAW!!!");
	}
	print_XO_box();
    scanf("%c",&u8dumb);
    
}
