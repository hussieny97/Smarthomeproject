
/*File guard*/
#ifndef __BIT_MATH_H__
#define __BIT_MATH_H__

/*Bit manipulation functions*/
#define SET_BIT(VAR, BIT)     VAR |= (1 << BIT) //1
#define CLEAR_BIT(VAR, BIT)   VAR &= ~(1 << BIT)//o
#define TOGGLE_BIT(VAR, BIT)  VAR ^= (1 << BIT)// switch
#define GET_BIT(VAR, BIT)     ((VAR >> BIT) & 1) //scan

#endif /*__BIT_MATH_H__*/