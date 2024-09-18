#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_VIOLET  "\x1b[35m"
#define COLOR_RESET   "\x1b[0m"

typedef struct Date {
    int jour, mois, annee;
} Date;

typedef struct Client {
    char num_compte[8];
    char username[20];
    char operation;
    float anc_solde;
    float nouv_solde;
    Date date;
} Client;

Client clients[10];
int size = 0;

// prototypes des fonctions
void menu();
int ouvre_fichier(char * nom);
void ferme_fichier(FILE * file);
void ajouter_client();

int main(){
    menu();

    printf("\n");
    return 0;
}

void menu(){
    int choice;
    do{
        printf(COLOR_YELLOW "----------------------------------------------\n");
        printf("               menu principale                \n");
        printf("----------------------------------------------\n\n");
        printf("    1- ajouter un client\n");
        printf("    2- afficher un client\n");
        printf("    3- lister tous les clients\n");
        printf("    4- effectuer une operation\n");
        printf("    5- quittez le programme\n");
        printf("\n----------------------------------------------\n" COLOR_RESET);
        printf("choisit votre choix: "); scanf("%d", &choice);
        printf(COLOR_YELLOW "----------------------------------------------\n" COLOR_RESET);

        switch(choice){
            case 1: ajouter_client(); break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: exit(0); break;
            default:
                system("clear");
                printf(COLOR_RED "veuillez choisit un choix valide dans le menu.\n" COLOR_RESET);
                break;
        }
    }
    while(choice != 6);

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

void ajouter_client(){
    system("clear");
    printf(COLOR_YELLOW "----------------------------------------------\n");
    printf("                ajouter client                \n");
    printf("----------------------------------------------\n" COLOR_RESET);
    printf("numero de compte: "); 
    scanf(" %[^\n]s", clients[size].num_compte);
    printf("nom et prenom: ");
    scanf(" %[^\n]s", clients[size].username);
    printf("votre solde: "); scanf("%f", &clients[size].anc_solde);
    printf("date de naissance (JJ/MM/AAAA): "); scanf("%d/%d/%d", &clients[size].date.jour, &clients[size].date.mois, &clients[size].date.annee);
    printf(COLOR_GREEN "\nnouveau client a ete ajoutee avec le numero '%s'..\n" COLOR_RESET, clients[size].num_compte);
    
    size = size + 1;
}