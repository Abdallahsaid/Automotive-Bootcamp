#include <stdio.h>
#include "STD_TYPES.h"

u8_t isSorted(u32_t *arr, u8_t size);
void bubbleSort(u32_t *arr, u8_t size);
u8_t binarySearch(u32_t *arr, u8_t size, u32_t number);

int main(void)
{
    u32_t arr[5] = {61, 126, 15, 26, 21}; // after sorting {15, 21, 26, 61, 126 }
    u8_t u8_result=0;
   
    
    u8_result = binarySearch(arr, 5 , 61);
    
    if ( u8_result == 255)
    {
        printf("Not found");
    }
    else
    {
        printf ("arr[%d] = %ld",u8_result, arr[u8_result]);
    }
    
    


    return 0;
}

u8_t isSorted(u32_t *arr, u8_t size)
{
    u8_t index = 1;
    for (index = 1; index < size; index++)
    {
        if (arr[index] < arr[index - 1])
        {
            return 0;
        }
        else
        {
            // do nothing
        }
    }
    return 1;
}
void bubbleSort(u32_t *arr, u8_t size)
{
    u8_t u8_index = 1;
    u8_t u8_swap = 0;
    u32_t u32_temp = 0;
    do
    {
        u8_swap = 0;
        for (u8_index = 1; u8_index < size; u8_index++)
        {
            if (arr[u8_index] < arr[u8_index - 1])
            {
                u32_temp = arr[u8_index];
                arr[u8_index] = arr[u8_index - 1];
                arr[u8_index - 1] = u32_temp;
                u8_swap = 1;
            }
            else
            {
                // do nothing
            }
        }
        /* code */
    } while (u8_swap == 1);
}
u8_t binarySearch(u32_t *arr, u8_t size, u32_t number)
{

    u8_t u8_start = 0 , u8_end = size -1 , u8_mid = 0;

     if (isSorted(arr, 5)==0)
    {
         bubbleSort(arr, 5);
    }
    else{
        //do nothing
    }
    

    while (u8_start <= u8_end)
    {
        u8_mid = (u8_start + u8_end)/2;
       if(arr[u8_mid] == number){
           return u8_mid;
       }
       else if (arr[u8_mid] > number)
       {
           u8_end  = u8_mid - 1;
       }
       else if (arr[u8_mid] < number)
       {
          u8_start = u8_mid + 1;
       }
       else
       {
           //do nothing
       }
       
       
    }
    

    return 255;
}