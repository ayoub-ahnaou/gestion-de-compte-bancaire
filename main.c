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

int main(){

    printf("\n");
    return 0;
}

void ouvre_fichier(char * nom_fichier){
    FILE * file;
}