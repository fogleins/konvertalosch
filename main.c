#include <stdio.h>
#include <stdbool.h>

#include "main.h"

int main() {
    bool fajlbol;
    int valasztaschar = 'a';
    while (valasztaschar != 'i' || valasztaschar != 'n') {
        printf("Fajlbol szeretnel beolvasni? (Ha nem, itt kell majd megadni a szoveget.) (i/n):");
        valasztaschar = getchar();
        if (valasztaschar == 'i')
            fajlbol = true;
        else if (valasztaschar == 'n')
            fajlbol = false;
        if (valasztaschar == 'i' || valasztaschar == 'n')
            break;
        else
            valasztaschar = getchar();
    }

    if (!fajlbol) {
        sch();
    }

    return  0;
}

typedef enum Allapot {
    s_volt,
    egyeb
    /* TODO
     * c_volt cs esetére
     * z_volt zs
     * dzs
     */
} Allapot;

void sch() {
    printf("Add meg a sztringet:");
    Allapot a = egyeb;
    int c;
    while ((c = getchar()) != EOF) {
        switch (a) {
            case egyeb:
                if (c == 's' || c == 'S')
                    a = s_volt;
                putchar(c);
                break;
            case s_volt:
                if (c == 'z' || c == 'Z')
                    a = egyeb;
                else {
                    // hatékonyabb, mint 2 putchar?
                    printf("ch");
                    a = egyeb;
                }
                putchar(c);
                break;
        }
    }
}