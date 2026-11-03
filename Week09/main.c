#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
int main(void){int choice;while(1){displayMenu();printf("Choice: ");if(scanf("%d",&choice)!=1)return 1;switch(choice){case 1:addEmployee();break;case 2:listEmployees();break;case 3:addBudget();break;case 4:printReport();break;case 5:return 0;default:puts("Invalid choice");}}}
