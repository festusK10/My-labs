#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
void printReport(void){printf("Total payroll: N$%.2f\nBudget balance: N$%.2f\n",calculatePayrollTotal(),calculateBudgetBalance());}
