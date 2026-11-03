#ifndef RECORDS_H
#define RECORDS_H
#include <stddef.h>
#define MAX_RECORDS 100
typedef struct {int day,month,year;} Date;
typedef struct {int id;char name[30];char department[20];double salary;} Employee;
typedef struct {int id;char name[60];char email[80];char phone[30];char town[50];} Supplier;
typedef struct {int id;char name[60];double value;Date acquired;} Asset;
typedef struct {int id;char department[40];double allocated,spent;} Budget;
typedef struct {int id;char name[60];double cost;Date start,end;} Project;
#endif
