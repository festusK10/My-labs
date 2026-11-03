#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "records.h"
static Employee employees[MAX_RECORDS];static int ec=0;
static Supplier suppliers[MAX_RECORDS];static int sc=0;
static Asset assets[MAX_RECORDS];static int ac=0;
static Budget budgets[MAX_RECORDS];static int bc=0;
static Project projects[MAX_RECORDS];static int pc=0;
static void line(const char *label,char *out,size_t n){printf("%s",label);if(!fgets(out,n,stdin)){out[0]=0;return;}out[strcspn(out,"\n")]=0;}
static int number(const char *label){char s[100];line(label,s,sizeof s);return (int)strtol(s,NULL,10);}
static double money(const char *label){char s[100];line(label,s,sizeof s);return strtod(s,NULL);}
static Date date(const char *label){Date d;printf("%s\n",label);d.day=number("Day: ");d.month=number("Month: ");d.year=number("Year: ");return d;}
static void addEmployee(void){if(ec==MAX_RECORDS){puts("Employee array full");return;}Employee *e=&employees[ec++];e->id=number("ID: ");line("Name: ",e->name,sizeof e->name);line("Department: ",e->department,sizeof e->department);e->salary=money("Salary: ");}
static void listEmployees(void){for(int i=0;i<ec;i++)printf("%d | %s | %s | N$%.2f\n",employees[i].id,employees[i].name,employees[i].department,employees[i].salary);}
static void addSupplier(void){if(sc==MAX_RECORDS){puts("Supplier array full");return;}Supplier *s=&suppliers[sc++];s->id=number("ID: ");line("Name: ",s->name,sizeof s->name);line("Email: ",s->email,sizeof s->email);line("Phone: ",s->phone,sizeof s->phone);line("Town: ",s->town,sizeof s->town);}
static void listSuppliers(void){for(int i=0;i<sc;i++)printf("%d | %s | %s | %s | %s\n",suppliers[i].id,suppliers[i].name,suppliers[i].email,suppliers[i].phone,suppliers[i].town);}
static void addAsset(void){if(ac==MAX_RECORDS){puts("Asset array full");return;}Asset *a=&assets[ac++];a->id=number("ID: ");line("Name: ",a->name,sizeof a->name);a->value=money("Value: ");a->acquired=date("Acquired date");}
static void listAssets(void){for(int i=0;i<ac;i++){Asset *a=&assets[i];printf("%d | %s | N$%.2f | %02d/%02d/%04d\n",a->id,a->name,a->value,a->acquired.day,a->acquired.month,a->acquired.year);}}
static void addBudget(void){if(bc==MAX_RECORDS){puts("Budget array full");return;}Budget *b=&budgets[bc++];b->id=number("ID: ");line("Department: ",b->department,sizeof b->department);b->allocated=money("Allocated: ");b->spent=money("Spent: ");}
static void listBudgets(void){for(int i=0;i<bc;i++){Budget *b=&budgets[i];printf("%d | %s | Balance N$%.2f\n",b->id,b->department,b->allocated-b->spent);}}
static void addProject(void){if(pc==MAX_RECORDS){puts("Project array full");return;}Project *p=&projects[pc++];p->id=number("ID: ");line("Name: ",p->name,sizeof p->name);p->cost=money("Cost: ");p->start=date("Start date");p->end=date("End date");}
static void listProjects(void){for(int i=0;i<pc;i++){Project *p=&projects[i];printf("%d | %s | N$%.2f | %02d/%02d/%04d - %02d/%02d/%04d\n",p->id,p->name,p->cost,p->start.day,p->start.month,p->start.year,p->end.day,p->end.month,p->end.year);}}
static void saveEmployees(void){FILE *f=fopen("employees.bin","wb");if(!f){perror("save");return;}if(fwrite(&ec,sizeof ec,1,f)!=1||fwrite(employees,sizeof employees[0],(size_t)ec,f)!=(size_t)ec)perror("write");fclose(f);}
static void loadEmployees(void){FILE *f=fopen("employees.bin","rb");int n;if(!f){perror("load");return;}if(fread(&n,sizeof n,1,f)==1&&n>=0&&n<=MAX_RECORDS&&fread(employees,sizeof employees[0],(size_t)n,f)==(size_t)n)ec=n;else puts("Invalid file");fclose(f);}
int main(void){int choice;while(1){puts("\n1 Add employee 2 List employees 3 Add supplier 4 List suppliers 5 Add asset 6 List assets 7 Add budget 8 List budgets 9 Add project 10 List projects 11 Save employees 12 Load employees 0 Exit");choice=number("Choice: ");switch(choice){case 1:addEmployee();break;case 2:listEmployees();break;case 3:addSupplier();break;case 4:listSuppliers();break;case 5:addAsset();break;case 6:listAssets();break;case 7:addBudget();break;case 8:listBudgets();break;case 9:addProject();break;case 10:listProjects();break;case 11:saveEmployees();break;case 12:loadEmployees();break;case 0:return 0;default:puts("Invalid choice");}}}
