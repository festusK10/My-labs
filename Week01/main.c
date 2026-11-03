#include <stdio.h>
int main(void) {
    char municipality[100], mayor[100];
    long population;
    puts("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM");
    puts("Welcome to Windhoek Municipality");
    printf("Municipality name: "); if (!fgets(municipality,sizeof municipality,stdin)) return 1;
    printf("Mayor's name: "); if (!fgets(mayor,sizeof mayor,stdin)) return 1;
    printf("Population: "); if (scanf("%ld",&population)!=1 || population<0) return 1;
    printf("\n--- MUNICIPAL REPORT ---\nMunicipality: %sMayor: %sPopulation: %ld\n",municipality,mayor,population);
    return 0;
}
