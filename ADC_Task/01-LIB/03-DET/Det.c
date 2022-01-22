 /******************************************************************************
 *
 * Module: Det
 *
 * File Name: Det.c
 *
 * Description:  Det stores the development errors reported by other modules.
 *
 * Author: Abdalla Abdelhafiz
 ******************************************************************************/

#include "../01-STD_TYPES/STD_TYPES.h"
#include "Det.h"

static u8_t index_row=0;

void Det_ReportError( u8_t ModuleId , u8_t ApiId)
{
gu8arr_error[index_row][0]=ModuleId;
gu8arr_error[index_row][1]=ApiId;
index_row++;
}

