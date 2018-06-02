#include "liste_hachage.h"

/* Creation d'une liste de hachage */
Liste_hachage creer_liste_hachage(void) {return NULL;}

/* Verification si la liste de hachage est vide
 Renvoie 1 si la liste est vide, 0 sinon */
int est_vide_hachage(Liste_hachage L) {return !L;}

/* Ajout d'un element en tete de la liste de hachage */
Liste_hachage ajout_tete_hachage(ELEMENT e, Liste_hachage L){
    Liste_hachage p=(Liste_hachage) calloc(1,sizeof(*p));
    if (p==NULL) return NULL;
    p->val=strdup(e);
    p->suiv=L;
    return p;
}

/* Hachage du nom du sommet */
unsigned int hachage(char* mot, int dim_tab_hach){
	int i=0;
	unsigned long h=0,a=1;
	while(mot[i]!='\0'){
		h=(h+mot[i]*a)%dim_tab_hach;
		a=a*31;
		i=i+1;
	}
	return h;
}

/* Recherche d'un element dans la table de hachage et retourne le numero du sommet*/
int rech_hachage(ELEMENT e, Liste_hachage L,T_SOMMET*tab,int x){
    Liste_hachage p=L;
    while(!est_vide_hachage(p)&&(strcasecmp(p->val,e)!=0)){
        p=p->suiv;
    }
    if(p==NULL){
        return -1;
    }
    return tab[p->x].tas;
}

/* Suppression d'un element en tete de la liste de hachage */
Liste_hachage supprimer_tete_hachage(Liste_hachage l) {
    Liste_hachage c = NULL;
    if (est_vide_hachage(l)) {
        return NULL;
    }
    c = l->suiv;
    free(l);
    return c;
}

/* Demande a l'utilisateur d'entrer une dimension pour la table de hachage */
int dimension_tab_hachage(void){
    int dim;
    printf("Veuillez entrer une dimension de la table de hachage\n");
    scanf("%d",&dim);
	if(dim==0){
		printf("Erreur sur la dimension\n");
		exit(1);
	}
    printf("\n");
    return dim;
}

void liberer_tab_hachage(Liste_hachage l[], int len) {
	int i;
	for (i=0; i<len;i++) {
		Liste_hachage c = NULL;
		c = l[i];
		while (c != NULL) {
			c = supprimer_tete_hachage(c);
		}
	}
	free(l);
}

void visualiser_liste_hachage_2(Liste_hachage l) {
 	Liste_hachage c = NULL;
	if (est_vide_hachage(l)) {
		puts("liste vide");
		return;
	}
    for (c = l; !est_vide_hachage(c); c = c->suiv) {
		printf("%s ",c->val);
	}
	printf("\n");
}

void visualiser_liste_hachage(Liste_hachage l[],int len){
	int i;
	for(i=0;i<len;i++){
		visualiser_liste_hachage_2(l[i]);
	}
	printf("\n\n");
}
