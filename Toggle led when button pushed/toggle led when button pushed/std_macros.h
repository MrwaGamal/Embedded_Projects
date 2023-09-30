/*
 * IncFile1.h
 *
 * Created: 8/16/2022 6:02:55 PM
 *  Author: marwa
 */ 


# define SET_BIT(reg, bit)             reg|=(1<<bit)
# define CLR_BIT(reg,bit)              reg&=~(1<<bit)
# define TOG_BIT(reg,bit)              reg^=(1<<bit)
# define READ_BIT(reg,bit)             ((reg&(1<<bit))>>bit)
# define IS_BIT_SET(reg,bit)           (reg&(1<<bit))>>bit
# define IS_BIT_CLR(reg,bit)           !((reg&(1<<bit))>>bit)


#ifndef INCFILE1_H_
#define INCFILE1_H_





#endif /* INCFILE1_H_ */