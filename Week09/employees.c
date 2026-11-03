#include <stdio.h>
#include "employees.h"
static double salaries[100];static int count=0;
void addEmployee(void){if(count>=100){puts("Full");return;}printf("Salary: ");if(scanf("%lf",&salaries[count])==1&&salaries[count]>=0)count++;else puts("Invalid salary");}
void listEmployees(void){for(int i=0;i<count;i++)printf("Employee %d: N$%.2f\n",i+1,salaries[i]);}
double calculatePayrollTotal(void){double sum=0;for(int i=0;i<count;i++)sum+=salaries[i];return sum;}
