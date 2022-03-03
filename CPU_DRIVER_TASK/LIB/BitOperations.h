 /******************************************************************************
 * File Name:   BitOperations.h
 *
 * Description: General macros definitions
 *
 * Author:      Abdalla Abdelhafiz
 *
 *******************************************************************************/

#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

#define SET_BIT(REG, BIT) REG |= (1 << (BIT))
#define CLR_BIT(REG, BIT) REG &= ~(1 << (BIT))
#define GET_BIT(REG, BIT) ((REG >> BIT) & 1)
#define TOG_BIT(REG, BIT) REG ^= (1 << (BIT))

#define RAM_BB(BYTE_ADRS, BIT) (0X22000000 + ((BYTE_ADRS - 0x20000000) * 32) + (BIT * 4))
#define PERIPHRAL_BB(BIT_OFFSET) (0X42000000 + ((BYTE_ADRS - 0x40000000) * 32) + (BIT * 4))

#endif  /*BIT_OPERATIONS_H*/