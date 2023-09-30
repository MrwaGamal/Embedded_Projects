/*
 * seven_segment_bcd.h
 *
 * Created: 8/7/2018 10:11:56 AM
 *  Author: Mohamed Zaghlol
 */ 


#ifndef SEVEN_SEGMENT_BCD_H_
#define SEVEN_SEGMENT_BCD_H_
void seven_seg_init(unsigned char portname);
void seven_seg_write(unsigned char portname,unsigned char value);
#endif /* SEVEN SEGMENT BCD_H_ */