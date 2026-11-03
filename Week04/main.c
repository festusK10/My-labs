#include <stdio.h>
#include <string.h>
int main(void) {
    char name[80]; double price,budget,lowest; int registered,documents;
    printf("Supplier name: "); if(!fgets(name,sizeof name,stdin)) return 1;
    name[strcspn(name,"\n")]=0;
    printf("Supplier price: "); if(scanf("%lf",&price)!=1) return 1;
    printf("Available budget: "); if(scanf("%lf",&budget)!=1) return 1;
    printf("Registered (1=yes, 0=no): "); if(scanf("%d",&registered)!=1) return 1;
    printf("Documents complete (1=yes, 0=no): "); if(scanf("%d",&documents)!=1) return 1;
    printf("Lowest qualifying tender price: "); if(scanf("%lf",&lowest)!=1) return 1;
    if(price<0||budget<0||lowest<0) return 1;
    printf("Supplier: %s\n",name);
    if(registered!=1||documents!=1||price>budget) puts("Disqualified");
    else if(price<=lowest) puts("Preferred Supplier");
    else puts("Qualified");
    return 0;
}
