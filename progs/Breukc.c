/* Werken met breuken in C ... zo deden we het vroeger! */

#include <stdio.h>

typedef struct { /* een breuk bestaat uit: */
    int boven;   /*     een teller en      */
    int onder;   /*     een noemer         */
} Breuk;

int ggd(int n, int m) {
    if (n == 0) return m;
    if (m == 0) return n;
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    while (m != n)
        if (n > m) n -= m;
        else m -= n;
    return n;
}

Breuk normaliseer(Breuk b) {
    int d;
    if (b.onder < 0) {
        b.onder = -b.onder;
        b.boven = -b.boven;
    }
    d = ggd(b.boven, b.onder);
    b.boven /= d;
    b.onder /= d;
    return b;
}

Breuk som(Breuk b1, Breuk b2) {
    Breuk s;
    s.boven = b1.boven * b2.onder + b1.onder * b2.boven;
    s.onder = b1.onder * b2.onder;
    return normaliseer(s);
}

int main() {
    Breuk a = {-2, 4}, b = {6, -8}, c;

    c = som(a, b);
    printf("c = %d/%d\n", c.boven, c.onder);

    return 0;
}
