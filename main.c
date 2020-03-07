#include <stdio.h>

#include "main.h"

int main(int argc, char* args[]) {
    puts("Konvertalosch v2\n");

    int valasztaschar;
    printf("Fajlbol szeretnel beolvasni a szoveget? (i/n):");
    valasztaschar = getchar();
    while (valasztaschar != 'i' && valasztaschar != 'n') {
        getchar(); // entert elnyeli
        printf("Fajlbol szeretnel beolvasni a szoveget? (i/n):");
        valasztaschar = getchar();
    }
    if (valasztaschar == 'i') {
        char fajlnev[50];
        printf("Adja meg a fajl nevet: ");
        gets(fajlnev);
        FILE* fajl = fopen(fajlnev, "rt");
        sch(fajl);
        fclose(fajl);
    }
    else sch(stdin);

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

void sch(FILE* forras) {
    printf("Add meg a sztringet:");
    Allapot a = egyeb;
    int c;
    while ((c = getc(forras)) != EOF) {
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
                    puts("ch");
                    a = egyeb;
                }
                putchar(c);
                break;
        }
    }
}