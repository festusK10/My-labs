#include <stdio.h>
#include <string.h>
int main(void) {
    double salaries[50],budgets[10],sum=0,search; char registrations[20][20],target[20]; int found=0;
    for(int i=0;i<50;i++){printf("Salary %d: ",i+1);if(scanf("%lf",&salaries[i])!=1||salaries[i]<0)return 1;sum+=salaries[i];}
    double high=salaries[0],low=salaries[0];
    for(int i=0;i<50;i++){printf("Salary %d: %.2f\n",i+1,salaries[i]);if(salaries[i]>high)high=salaries[i];if(salaries[i]<low)low=salaries[i];}
    printf("Average salary: %.2f; Highest: %.2f; Lowest: %.2f\n",sum/50,high,low);
    printf("Salary to search: ");if(scanf("%lf",&search)!=1)return 1;
    for(int i=0;i<50;i++)if(salaries[i]==search){printf("Found salary at index %d\n",i);found=1;}
    if(!found)puts("Salary not found");
    sum=0;
    for(int i=0;i<10;i++){printf("Budget %d: ",i+1);if(scanf("%lf",&budgets[i])!=1||budgets[i]<0)return 1;sum+=budgets[i];}
    for(int i=0;i<10;i++)for(int j=i+1;j<10;j++)if(budgets[j]<budgets[i]){double t=budgets[i];budgets[i]=budgets[j];budgets[j]=t;}
    printf("Total budget: %.2f; Average: %.2f\nSorted budgets:\n",sum,sum/10);
    for(int i=0;i<10;i++)printf("%.2f\n",budgets[i]);
    for(int i=0;i<20;i++){printf("Vehicle registration %d: ",i+1);if(scanf("%19s",registrations[i])!=1)return 1;}
    for(int i=0;i<20;i++)printf("Registration %d: %s\n",i+1,registrations[i]);
    printf("Registration to search: ");if(scanf("%19s",target)!=1)return 1;found=0;
    for(int i=0;i<20;i++)if(strcmp(target,registrations[i])==0){printf("Found at index %d\n",i);found=1;}
    if(!found)puts("Registration not found");
    return 0;
}
