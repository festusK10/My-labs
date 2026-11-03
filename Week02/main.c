#include <stdio.h>
int main(void) {
    double revenue, expenses, balance;
    printf("Total revenue (N$): "); if(scanf("%lf",&revenue)!=1 || revenue<0) return 1;
    printf("Total expenses (N$): "); if(scanf("%lf",&expenses)!=1 || expenses<0) return 1;
    balance=revenue-expenses;
    printf("Balance: N$%.2f\n%s\n",balance,balance>0?"SURPLUS":balance<0?"DEFICIT":"BALANCED");
    return 0;
}
