#include <stdio.h>

int main() {
    printf("Type een foating point getal in: ");
    double d;
    scanf("%d", d); // deze regel bevat $\color{hrred}\textbf{twee fouten}$!
    printf("d = %.3lf\n", d);
}
