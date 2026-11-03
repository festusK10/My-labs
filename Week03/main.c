#include <stdio.h>
int main(void) {
    double basic,housing,transport,tax,gross;
    printf("Basic salary: "); if(scanf("%lf",&basic)!=1) return 1;
    printf("Housing allowance: "); if(scanf("%lf",&housing)!=1) return 1;
    printf("Transport allowance: "); if(scanf("%lf",&transport)!=1) return 1;
    printf("Tax amount: "); if(scanf("%lf",&tax)!=1) return 1;
    if(basic<0||housing<0||transport<0||tax<0) return 1;
    gross=basic+housing+transport;
    printf("Gross salary: N$%.2f\nNet salary: N$%.2f\n",gross,gross-tax);
    return 0;
}
