#ifndef BITS_H
#define BITS_H


#define SET_BIT(REG,BIT_NUM) REG|=(1<<BIT_NUM)
#define CLEAR_BIT(REG,BIT_NUM) REG&=~(1<<BIT_NUM)
#define READ_BIT(REG,BIT_NUM) ((REG&(1<<BIT_NUM))>>BIT_NUM)
#define TOGGLE_BIT(REG,BIT_NUM) REG^=(1<<BIT_NUM)

#endif