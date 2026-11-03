#include <stdio.h>
void displayWelcome(void){puts("Welcome to the Municipal Financial Management System");}
float calculateVAT(float amount){return amount*0.15f;}
float calculateSalary(float basic,float housing,float transport){return basic+housing+transport;}
float calculateBudget(float revenue,float expenses){return revenue-expenses;}
int searchEmployee(int id,int ids[],int size){for(int i=0;i<size;i++)if(ids[i]==id)return i;return -1;}
void displayMenu(void){puts("\nMUNICIPAL FINANCIAL MANAGEMENT\n1. Calculate VAT\n2. Calculate Salary\n3. Calculate Budget\n4. Search Employee\n5. Exit");}
int main(void){int choice,ids[]={101,102,103,104,105};float a,b,c,result;displayWelcome();
    while(1){displayMenu();printf("Choice: ");if(scanf("%d",&choice)!=1)return 1;
    switch(choice){case 1:printf("Amount: ");if(scanf("%f",&a)!=1)return 1;printf("VAT: %.2f\n",calculateVAT(a));break;
    case 2:printf("Basic, housing, transport: ");if(scanf("%f%f%f",&a,&b,&c)!=3)return 1;printf("Gross: %.2f\n",calculateSalary(a,b,c));break;
    case 3:printf("Revenue, expenses: ");if(scanf("%f%f",&a,&b)!=2)return 1;result=calculateBudget(a,b);printf("Balance: %.2f (%s)\n",result,result>0?"SURPLUS":result<0?"DEFICIT":"BALANCED");break;
    case 4:printf("Employee ID: ");if(scanf("%f",&a)!=1)return 1;printf("Position: %d\n",searchEmployee((int)a,ids,5));break;
    case 5:return 0;default:puts("Invalid choice");}
    }
}
