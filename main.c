#include <stdio.h>
#include <string.h>

#include "main.h"

int main(int argc, char* args[]) {
    puts("Konvertalosch v2\n");

    char bemeneti_fajlnev[128] = {'\0'};
    char kimeneti_fajlnev[128] = {'\0'};

    if (argc >= 3 && strcmp(args[1], "-b") == 0) strcpy(bemeneti_fajlnev, args[2]);
    else if (argc == 3 && strcmp(args[1], "-k") == 0) strcpy(kimeneti_fajlnev, args[2]);
    if (argc == 5 && strcmp(args[3], "-k") == 0) strcpy(kimeneti_fajlnev, args[4]);

    if (bemeneti_fajlnev[0] != '\0') {
        FILE* bemeneti_fajl = fopen(bemeneti_fajlnev, "rt");
        printf("Reading from file %s", bemeneti_fajlnev);
        if (kimeneti_fajlnev[0] != '\0') {
            FILE* kimeneti_fajl = fopen(kimeneti_fajlnev, "wt");
            printf(", writing to file %s\n", kimeneti_fajlnev);
            sch(bemeneti_fajl, kimeneti_fajl);
            fclose(kimeneti_fajl);
            puts("\nDone");
        }
        else {
            puts("\n");
            sch(bemeneti_fajl, stdout);
        }
        fclose(bemeneti_fajl);
    }
    else {
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
            FILE *fajl = fopen(fajlnev, "rt");
            sch(fajl, stdout);
            fclose(fajl);
        } else {
            printf("Add meg a sztringet: ");
            sch(stdin, stdout);
        }
    }

    return  0;
}

void sch(FILE* forras, FILE* cel) {
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
                putc(c, cel);
                break;
            case s_volt:
                switch (c) {
                    case 's':
                    case 'S':
                        break;
                    case 'z':
                    case 'Z':
                        a = egyeb;
                        break;
                    default:
                        fputs("ch", cel);
                        a = egyeb;
                        break;
                }
                putc(c, cel);
                break;
            case z_volt:
            case c_volt:
                if (c == 'c' || c == 'C')
                    a = c_volt;
                else if (c == 'z' || c == 'Z')
                    a = z_volt;
                else a = egyeb;
                putc(c, cel);
                break;
        }
    }
}