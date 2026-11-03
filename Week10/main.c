#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
int main(void){int c;while(1){puts("\n1 Add employee 2 List 3 Set budget 4 Report 5 Save text 6 Load text 7 Save binary 8 Load binary 0 Exit");if(scanf("%d",&c)!=1)return 1;switch(c){case 1:addEmployee();break;case 2:listEmployees();break;case 3:addBudget();break;case 4:printReport();break;case 5:saveEmployees();break;case 6:loadEmployees();break;case 7:saveEmployeesBinary();break;case 8:loadEmployeesBinary();break;case 0:return 0;default:puts("Invalid");}}}
