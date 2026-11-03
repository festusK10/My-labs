#include <stdio.h>
#include "budget.h"
static double revenue=0,expenses=0;
void addBudget(void){printf("Revenue and expenses: ");if(scanf("%lf%lf",&revenue,&expenses)!=2)puts("Invalid input");}
double calculateBudgetBalance(void){return revenue-expenses;}
