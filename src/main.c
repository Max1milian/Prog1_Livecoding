/*
 ============================================================================
 Name        : WS2223_PRG1_Testlauf.c
 Author      : Bodisco
 Copyright   : Hochschule Augsburg
 Description : Testlauf - Tannenbaum-Ausgabe
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tannenbaum.h"
#include "Konfiguration.h"

int main(void) {
    srand(time(NULL));
    puts("Oh Tannenbaum, oh Tannenbaum!\n");
    Tannenbaum* t_ptr = Tannenbaum_erzeugen(30, 10);
    Tannenbaum_init(t_ptr);
    Tannenbaum_ausgabe(t_ptr);
    Tannenbaum_schmuecken(t_ptr);
    getchar();
    Tannenbaum_ausgabe(t_ptr);
    getchar();
    return EXIT_SUCCESS;
}
