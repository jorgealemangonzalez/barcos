/*----------------------------------------------------------------
|	Autor: Professors de Fonaments de Programacio
|	Data: Novembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|   Nom projecte: vaixells
|	Nom fitxer: vaixell.h
|   Descripcio del Programa: cap�aleres i rutines donades.
|
| ----------------------------------------------------------------*/

#ifndef VAIXELLS_H_INCLUDED
#define VAIXELLS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define DIM_MAX     10
#define DIM_MIN     8

enum orientacio
{
    HORITZONTAL = 0,
    VERTICAL = 1
};

enum casella
{
    CASELLA_BUIDA = '?',
    CASELLA_AIGUA = '.',
    CASELLA_VAIXELL = '@',
    CASELLA_VAIXELL_TOCAT = 'X',
    CASELLA_AIGUA_TOCADA = '-'
};

enum tret
{
    ERROR = -1,
    REPETIT = 0,
    AIGUA = 1,
    TOCAT = 2,
    ENFONSAT = 3
};

/** cap�aleres funcions */
/** =========================================================================
    acci� inicia_taulell (dim:enter, var taulell_vaixells:taula de car�cters);

    - Inicialitza la disposici� dels vaixells dins del taulell de vaixells.

    - Par�metres formals:
        dim: (per valor) dimensi� del taulell, ha de ser > DIM_MIN i < DIM_MAX.
            Abans de fer la crida, s'ha de validar que dim sigui correcte.
        taulell_vaixells: (per refer�ncia) taula de dues dimensions
            DIM_MAX x DIM_MAX. La mida del taulell real dependr� del
            par�metre dim: dim x dim.
    =========================================================================*/
extern void inicia_taulell (int dim, char taulell_vaixells[][DIM_MAX]);

/** =========================================================================
    acci� inicia_taulell_fix(dim:enter,var taulell_vaixells:taula de car�cter);

    - Inicialitza la disposici� dels vaixells dins del taulell de vaixells
        sempre amb la mateixa configuraci�. Serveix per a fer proves.

    - Par�metres formals:
        dim: (per valor) dimensi� del taulell, ha de ser > 8 i < DIM_MAX.
            Abans de fer la crida, s'ha de validar que dim sigui correcte.
        taulell_vaixells: (per refer�ncia) taula de dues dimensions
            DIM_MAX x DIM_MAX. La mida del taulell real dependr� del
            par�metre dim: dim x dim.
    =========================================================================*/
//extern void inicia_taulell_fix (int dim, char taulell_vaixells[][DIM_MAX]);
extern void inicia_taulell_fix(char*** t,int dim);
/** =========================================================================
    funci� dispara (f:car�cter, c:enter, var taulell_vaixells:taula de car�cters)
        retorna enter;

    - Retorna el resultat del llan�ament (REPETIT-0, AIGUA-1...) i
        actualitza el taulell de vaixells amb les anotacions pertinents:
        CASELLA_VAIXELL_TOCAT o CASELLA_AIGUA_TOCADA.
        Si hi ha un error en la fila o columna, o en el contingut de la casella,
        retorna ERROR.

    - Par�metres formals:
        fila: (per valor) lletra de la fila, en majuscules. Ha de ser
            correcta d'acord amb les dimensions del taulell.
        col: (per valor) n�mero de la columna, ha de ser correcte d'acord
            amb les dimensions del taulell.
        Abans de fer la crida, s'ha de validar que fila i col siguin correctes!
        taulell_vaixells: (per refer�ncia) taula de dues dimensions
            DIM_MAX x DIM_MAX.
    =========================================================================*/
extern int dispara (char fila, int col, char t[][DIM_MAX]);

#endif /* VAIXELLS_H_INCLUDED */
