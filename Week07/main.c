#include <stdio.h>
#include <string.h>
static void readLine(const char *prompt,char *out,size_t size){printf("%s",prompt);if(fgets(out,size,stdin))out[strcspn(out,"\n")]=0;}
int main(void){
    char name[100],email[100],phone[30],town[50],backup[100],description[200],search[100];
    readLine("Supplier name: ",name,sizeof name);readLine("Email: ",email,sizeof email);
    readLine("Phone: ",phone,sizeof phone);readLine("Town: ",town,sizeof town);
    printf("\n--- SUPPLIER DETAILS ---\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n",name,email,phone,town);
    printf("Name length: %zu; Email length: %zu; Town length: %zu\n",strlen(name),strlen(email),strlen(town));
    strcpy(backup,name);printf("Backup: %s\n",backup);
    strcpy(description,name);if(strlen(description)+strlen(" - ")+strlen(town)<sizeof description){strcat(description," - ");strcat(description,town);}printf("Description: %s\n",description);
    readLine("Search supplier by name: ",search,sizeof search);
    puts(strcmp(search,name)==0||strcmp(search,"ABC Office Supplies")==0||strcmp(search,"Namibia Stationery")==0?"Supplier found":"Supplier not found");
    return 0;
}
