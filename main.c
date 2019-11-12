#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /// itt elég csúnya :(
    char sztring[2048];
    printf("Add meg a szoveget: ");
    gets(sztring);
    int n = strlen(sztring);
    int hossz = 0;
    for (int i = 1; i < n; ++i) {
        if (sztring[i - 1] == 's' && sztring[i] == 'z')
            hossz++;
        else if (sztring[i - 1] == 's' && sztring[i] != 'z')
            hossz += 2;
        else
            hossz++;
    }
    char* ujsztring = (char*) malloc((hossz + 1) * sizeof(char));
    int csuszas = 0; /*ennyivel kell majd eltolni a karaktereket*/
    int indexer = 0;
    for (int i = 0; sztring[i] != '\0'; ++i) {
        // ha 'sz'
        if ((sztring[i] == 's' && sztring[i + 1] == 'z')
            || (sztring[i] == 'S' && sztring[i + 1] == 'z')
            || (sztring[i] == 'S' && sztring[i + 1] == 'Z')) {
            ujsztring[indexer] = sztring[i];
            ujsztring[indexer += 1] = sztring[i += 1];
            indexer++;
        }
        // ha simán 's' van
        else if ((sztring[i] == 's') || (sztring[i] == 'S')) {
            ujsztring[indexer] = sztring[i];
            ujsztring[indexer += 1] = 'c';
            ujsztring[indexer += 1] = 'h';
            indexer++;
        }
        else {
            ujsztring[indexer] = sztring[i];
            indexer++;
        }
    }
    ujsztring[indexer] = '\0';
    int kiiridx = 0;
    while (ujsztring[kiiridx] != '\0') {
        printf("%c", ujsztring[kiiridx]);
        kiiridx++;
    }
    return 0;
}