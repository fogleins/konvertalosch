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
    else {
        printf("Add meg a sztringet: ");
        sch(stdin);
    }

    return  0;
}

void sch(FILE* forras) {
    Allapot a = egyeb;
    int c;
    while ((c = getc(forras)) != EOF) {
        switch (a) {
            case egyeb:
                if (c == 's' || c == 'S')
                    a = s_volt;
                else if (c == 'c' || c == 'C')
                    a = c_volt;
                else if (c == 'z' || c == 'Z')
                    a = z_volt;
                putchar(c);
                break;
            case s_volt:
                switch (c) {
                    case 's':
                    case 'S':
                    case 'z':
                    case 'Z':
                        break;
                    default:
                        puts("ch");
                        a = egyeb;
                        break;
                }
                putchar(c);
                break;
            case z_volt:
            case c_volt:
                if (c == 'c' || c == 'C')
                    a = c_volt;
                else if (c == 'z' || c == 'Z')
                    a = z_volt;
                else a = egyeb;
                putchar(c);
                break;
        }
    }
}