// Een terugblik op functie, struct en array in C

#include <stdio.h> 
/* nodig voor gebruik printf (schrijven naar scherm) 
                   en scanf  (lezen uit toetsenbord) */
 
typedef struct { // Een Tijdsduur bestaat uit:
    int uur;     //    een aantal uren en
    int minuten; //    een aantal minuten.
} Tijdsduur;

// Deze functie drukt een Tijdsduur af
void drukaf(Tijdsduur td) {
    if (td.uur == 0)
        printf("           %2d minuten\n", td.minuten);
    else
        printf("%3d uur en %2d minuten\n", td.uur, td.minuten);
}

// Deze functie drukt een rij met een aantal Tijdsduren af
void drukaf_rij(const Tijdsduur rij[], size_t aantal) {
    for (size_t teller = 0; teller < aantal; teller++)
        drukaf(rij[teller]);
}

// Deze functie berekent de totaal Tijdsduur van een rij met een aantal Tijdsduren
Tijdsduur som(const Tijdsduur rij[], size_t aantal) {
    Tijdsduur s = {0, 0};
    for (size_t teller = 0; teller < aantal; teller++) {
        s.uur += rij[teller].uur;
        s.minuten += rij[teller].minuten;
    }
    s.uur += s.minuten / 60;
    s.minuten %= 60;
    return s;
}

#define MAX_TIJDSDUREN 5

int main(void) {
    Tijdsduur tijdsduren[MAX_TIJDSDUREN];
    size_t aantal = 0;
    int aantal_gelezen_variabelen;
    do {
        printf("Type uren en minuten in: ");
        aantal_gelezen_variabelen = scanf("%d%d", &tijdsduren[aantal].uur, &tijdsduren[aantal].minuten);
    }
    while (aantal_gelezen_variabelen == 2 && ++aantal < MAX_TIJDSDUREN);
    printf("\n");
    drukaf_rij(tijdsduren, aantal);
    printf("De totaal tijdsduur is:\n");
    drukaf(som(tijdsduren, aantal));
    return 0;
}
