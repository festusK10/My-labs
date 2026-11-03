#include <stdio.h>
#include "records.h"
void swapSalaries(double *a,double *b){double t=*a;*a=*b;*b=t;}
void wrongSwap(double a,double b){double t=a;a=b;b=t;(void)a;(void)b;}
void displaySalaries(const double s[],int n){for(int i=0;i<n;i++)printf("%.2f ",s[i]);puts("");}
double findHighest(const double s[],int n){if(n<=0)return 0;double x=s[0];for(int i=1;i<n;i++)if(s[i]>x)x=s[i];return x;}
double calculateAverage(const double s[],int n){if(n<=0)return 0;double x=0;for(int i=0;i<n;i++)x+=s[i];return x/n;}
void giveRaise(double s[],int n,double percent){for(int i=0;i<n;i++)s[i]*=1+percent/100;}
void updateSalary(Employee *e,double newSalary){if(e)e->salary=newSalary;}
Employee *findEmployee(Employee list[],int n,int id){for(int i=0;i<n;i++)if(list[i].id==id)return &list[i];return NULL;}
int main(void){int value=10,*p=&value;printf("Value %d, address %p, dereferenced %d\n",value,(void*)p,*p);*p=20;printf("Updated: %d\n",value);
 double a=100,b=200;wrongSwap(a,b);printf("After wrongSwap: %.2f %.2f\n",a,b);swapSalaries(&a,&b);printf("After swapSalaries: %.2f %.2f\n",a,b);
 double s[]={100,200,300};displaySalaries(s,3);printf("Highest %.2f average %.2f\n",findHighest(s,3),calculateAverage(s,3));giveRaise(s,3,10);displaySalaries(s,3);
 Employee e[]={{101,"Anna","Finance",1000},{102,"Ben","HR",2000},{103,"Chris","IT",3000}};Employee *found=findEmployee(e,3,102);updateSalary(found,2500);printf("Updated employee: %s %.2f\n",found->name,found->salary);puts(findEmployee(e,3,999)?"Found":"ID not found");return 0;}
