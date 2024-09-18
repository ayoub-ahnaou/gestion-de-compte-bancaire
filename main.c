#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date {
    int jour, mois, annee;
} Date;

typedef struct Client {
    char num_compte[8];
    char nom[20];
    char operation;
    float anc_solde;
    float nouv_solde;
    Date date;
} Client;

// prototypes des fonctions
int ouvre_fichier(char * nom);
void ferme_fichier(FILE * file);

int main(){

    printf("\n");
    return 0;
}

int ouvre_fichier(char * nom){
    FILE * file;
    file = fopen(nom, "a+");
    if(file != NULL){
        printf("fichier ouvree..\n");
        return 1;
    }
    else{
        printf("erreur en ouvrant le fichier. essayez une autre fois..\n");
        return 0;
    }
}

void ferme_fichier(FILE * file){
    fclose(file);
    printf("fichier fermee avec success..\n");
}