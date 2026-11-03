#include <stdio.h>
int main(void) {
    double salary,total=0,highest=0,lowest=0;
    for(int i=0;i<50;i++) {
        printf("Employee %d salary: ",i+1);
        if(scanf("%lf",&salary)!=1||salary<0) return 1;
        total+=salary;
        if(i==0||salary>highest) highest=salary;
        if(i==0||salary<lowest) lowest=salary;
    }
    printf("Total: N$%.2f\nAverage: N$%.2f\nHighest: N$%.2f\nLowest: N$%.2f\n",total,total/50,highest,lowest);
    return 0;
}
