//
// Created by Simon on 2019-11-12.
//

#ifndef KONVERTALOSCH_MAIN_H
#define KONVERTALOSCH_MAIN_H

typedef enum Allapot {
    s_volt,
    c_volt,
    z_volt,
    egyeb
} Allapot;

void sch(FILE* forras, FILE* cel);

#endif //KONVERTALOSCH_MAIN_H
