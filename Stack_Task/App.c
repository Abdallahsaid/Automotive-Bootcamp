/*
 ============================================================================
 Name        : App.c
 Author      : Abdalla Saied
 Version     :v.1
 ============================================================================
 */
// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "Stack.h"

u8_t *balancedParentheses(u8_t *expression);

int main(void)
{

    u8_t u8_t_str[20];
    while (1)
    {
        printf("PLEASE ENTER THE EXPRESSION\n");
        gets(u8_t_str);

        printf("%s\n", balancedParentheses(u8_t_str));
    }

    return 0;
}

u8_t *balancedParentheses(u8_t *expression)
{
    u8_t u8_t_counter = 0;
    u8_t u8_t_temp_data = 0;

    u8_t u8_t_last_open = 0; // this holds the value of last open parentheses and not closed yet
    s8_t s8_t_counter_curly = 0;
    s8_t s8_t_counter_round = 0;
    s8_t s8_t_counter_square = 0;

    // putting input in a stack
    while (expression[u8_t_counter] != '\0')
    {
        stack_push(expression[u8_t_counter]);
        u8_t_counter++;
    }

    // pop out and checking for parentheses
    for (; u8_t_counter > 0; u8_t_counter--)
    {
        u8_t_temp_data = stack_pull();
        switch (u8_t_temp_data)
        {
        case ')':
            s8_t_counter_round++;
            u8_t_last_open = ')';
            break;
        case '(':

            if ((u8_t_last_open == '}') && (s8_t_counter_curly > 0))
            {
                return "UNBALANCED";
            }
            else if ((u8_t_last_open == ']') && (s8_t_counter_square > 0))
            {
                return "UNBALANCED";
            }
            else
                s8_t_counter_round--;

            break;
        case '}':
            s8_t_counter_curly++;
            u8_t_last_open = '}';
            break;
        case '{':
            if ((u8_t_last_open == ')') && (s8_t_counter_round > 0))
            {
                return "UNBALANCED";
            }
            else if ((u8_t_last_open == ']') && (s8_t_counter_square > 0))
            {
                return "UNBALANCED";
            }
            else
                s8_t_counter_curly--;
            break;
        case ']':
            s8_t_counter_square++;
            u8_t_last_open = ']';
            break;
        case '[':
            if ((u8_t_last_open == '}') && (s8_t_counter_curly > 0))
            {
                return "UNBALANCED";
            }
            else if ((u8_t_last_open == ')') && (s8_t_counter_round > 0))
            {
                return "UNBALANCED";
            }
            else
                s8_t_counter_square--;
            break;
        default:
            break;
        }
        if ((s8_t_counter_curly < 0) || (s8_t_counter_round < 0) || (s8_t_counter_square < 0))
        {
            return "UNBALANCED";
        }
        else
        {
            // do nothing
        }
    }

    if ((s8_t_counter_curly == 0) && (s8_t_counter_round == 0) && (s8_t_counter_square == 0))
    {
        return "BALANCED";
    }
    else
    {
        return "UNBALANCED";
    }
}
