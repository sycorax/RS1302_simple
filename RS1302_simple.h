
#ifndef _RS1302_simple_h
#define _RS1302_simple_h

void ds1302_setup(int setup=0, int hours=0, int minutes=0, int seconds=0,   int dayofweek=0, int dayofmonth=0, int month=0, int year=0);
char *get_time();
char *get_date();

#endif