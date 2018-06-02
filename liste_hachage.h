#ifndef _LISTE_HACHAGE
#define _LISTE_HACHAGE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

/* Structure de liste pour le hachage */
typedef char* ELEMENT;
struct cellule { 
    ELEMENT val;
    int x;
    struct cellule * suiv;};
typedef struct cellule * Liste_hachage;

/* Prototypes des fonctions de hachage */
Liste_hachage creer_liste_hachage(void);
int est_vide_hachage(Liste_hachage L);
int rech_hachage(ELEMENT e, Liste_hachage L,T_SOMMET*tab,int x);
void visualiser_graphe(T_SOMMET* tab_sommets, int* k);
Liste_hachage ajout_tete_hachage(ELEMENT e, Liste_hachage L);
Liste_hachage supprimer_tete_hachage(Liste_hachage l);
unsigned int hachage(char *e, int dimension);
int dimension_tab_hachage(void);
void liberer_tab_hachage(Liste_hachage l[], int len);
void visualiser_liste_hachage(Liste_hachage l[],int len);
void visualiser_liste_hachage_2(Liste_hachage l);
#endif
