#include <stdio.h>
#include "employees.h"
static double salaries[100];static int count=0;
void addEmployee(void){if(count>=100){puts("Full");return;}printf("Salary: ");if(scanf("%lf",&salaries[count])==1&&salaries[count]>=0)count++;else puts("Invalid salary");}
void listEmployees(void){for(int i=0;i<count;i++)printf("Employee %d: N$%.2f\n",i+1,salaries[i]);}
double calculatePayrollTotal(void){double sum=0;for(int i=0;i<count;i++)sum+=salaries[i];return sum;}
void saveEmployees(void){FILE *f=fopen("employees.txt","w");if(!f){perror("employees.txt");return;}for(int i=0;i<count;i++)fprintf(f,"%.17g\n",salaries[i]);if(fclose(f)!=0)perror("close");else puts("Saved text");}
void loadEmployees(void){FILE *f=fopen("employees.txt","r");double value;if(!f){perror("employees.txt");return;}count=0;while(count<100&&fscanf(f,"%lf",&value)==1)if(value>=0)salaries[count++]=value;fclose(f);puts("Loaded text");}
void saveEmployeesBinary(void){FILE *f=fopen("employees.bin","wb");if(!f){perror("employees.bin");return;}if(fwrite(&count,sizeof count,1,f)!=1||fwrite(salaries,sizeof salaries[0],(size_t)count,f)!=(size_t)count)perror("write");fclose(f);}
void loadEmployeesBinary(void){FILE *f=fopen("employees.bin","rb");int n;if(!f){perror("employees.bin");return;}if(fread(&n,sizeof n,1,f)==1&&n>=0&&n<=100&&fread(salaries,sizeof salaries[0],(size_t)n,f)==(size_t)n)count=n;else puts("Invalid binary data");fclose(f);}
