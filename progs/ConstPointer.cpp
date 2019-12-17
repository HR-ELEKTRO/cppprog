// Constante pointers

int main() {
    int i = 3;
    const int j = 4;
    const int* p = &i;
    // p wijst naar i en je kunt i niet via p wijzigen.
    // Let op: je kunt i zelf wel rechtstreeks wijzigen!
    i = 4;
    // Goed
    *p = 5;
    // Fout (Microsoft): 'p' : you cannot assign to a variable that is const
    // Fout (GCC):       assignment of read-only location '* p'
    p = &j;
    // Goed

    int* const q = &i;
    // q wijst naar i en je kunt q nergens anders meer naar laten wijzen. 
    // Let op: je kunt i wel via q (of rechtstreeks) wijzigen.
    i = 4;
    // Goed
    *q = 5;
    // Goed
    q = &j;
    // Fout (Microsoft): 'q' : you cannot assign to a variable that is const
    // Fout (GCC):       assignment of read-only variable 'q'

    const int* const r = &i;
    // r wijst naar i en je kunt i niet via r wijzigen en je kunt r nergens anders meer naar laten wijzen.
    // Let op: je kunt i zelf wel rechtstreeks wijzigen!
    i = 4;
    // Goed
    *r = 5;
    // Fout (Microsoft): 'r' : you cannot assign to a variable that is const
    // Fout (GCC):       assignment of read-only location '*(const int*)r'
    r = &j;
    // Fout (Microsoft): 'r' : you cannot assign to a variable that is const
    // Fout (GCC):       assignment of read-only variable 'r'

    return 0;
}
