/*
 * Tannenbaum.h
 *
 *  Created on: 13.01.2023
 *      Author: student
 */

#ifndef TANNENBAUM_H_
#define TANNENBAUM_H_
#include <string.h>
#include <stdlib.h>
#include "Konfiguration.h"
#include "Cursor.h"

struct Tannenbaum
{
    char bild[MAX_AUSDEHNUNG][MAX_AUSDEHNUNG];
    int breite;
    int hoehe;
};

typedef struct Tannenbaum Tannenbaum;

/* Aufgabe 1a */
Tannenbaum* Tannenbaum_erzeugen(int breite, int hoehe)
{
   Tannenbaum* t = calloc(1, sizeof(Tannenbaum));
   if (t == NULL) {
   	printf("Fehler bei der Speicherallocierung!\n");
	exit(EXIT_FAILURE);
   }

   for (int x = 0; x < MAX_AUSDEHNUNG; x++) {
   	for (int y = 0; y < MAX_AUSDEHNUNG; y++) {
   		t->bild[x][y] = SYMBOL_LEER;	
   	}	
   }
   if (breite > MAX_AUSDEHNUNG -1) {
   	breite = MAX_AUSDEHNUNG -1;	
   }
   if (hoehe > MAX_AUSDEHNUNG -1) {
   	hoehe  = MAX_AUSDEHNUNG -1 ;
   }
   t->hoehe = hoehe;
   t->breite = breite;
   	
    return t;
}

/* Aufgabe 1b */
void Tannenbaum_init(Tannenbaum* t_ptr)
{
	for (int x= 0; x < t_ptr->breite; x++) {
		for (int y = 0; y < t_ptr->hoehe; y++) {
			if (x >= t_ptr->breite / 2 -y && x <= t_ptr->breite / 2 + y
					&& y < t_ptr->hoehe - 2) {
				t_ptr->bild[x][y] = SYMBOL_NADEL;
			}

			if (y >= t_ptr->hoehe -2 && x >= t_ptr->breite / 2 -1
					&& x <= t_ptr->breite / 2 + 1) {
				t_ptr->bild[x][y]= SYMBOL_STAMM;	
			}
	
		}
	}
}

/* Aufgabe 1c */
void Tannenbaum_schmuecken(Tannenbaum* t_ptr)
{
	for (int x = 0; x < t_ptr->breite; x++) {
		for (int y = 0; y < t_ptr->hoehe; ++y) {
			if (t_ptr->bild[x][y] == SYMBOL_NADEL && ZUFALL == 0) {
				t_ptr->bild[x][y] = SYMBOL_KUGEL;	
			}	
		}
	}	
}

/* Aufgabe 1d */
void Tannenbaum_ausgabe(Tannenbaum* t_ptr)
{
	for (int x = 0; x < t_ptr->breite; x++) {
		for (int y = 0; y < t_ptr->hoehe; y++) {
			switch (t_ptr->bild[x][y]) {
				case SYMBOL_NADEL:
					cursor_setze_farbe(farben[GRUEN]);
					break;
				case SYMBOL_STAMM:
					cursor_setze_farbe(farben[BRAUN]);
					break;
				case SYMBOL_KUGEL:
				      cursor_setze_farbe(farben[ZUFALL]);
				      break;

				default:
				      cursor_setze_farbe(farben[BLAU]);
				      break;
					
			}
			cursor_zeichne_punkt(x + OFFSET, y + OFFSET, t_ptr->bild[x][y]);
		}	
	}
}
#endif
