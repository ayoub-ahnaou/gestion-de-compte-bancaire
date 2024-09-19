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
    char num_compte[9];
    char username[30];
    float anc_solde;
    float nouv_solde;
    Date date;
    char operation;
} Client;

Client clients[10] = {
    {"12345673", "Alice", 0, 1200.75, {12, 9, 2024}},
    {"23456478", "Bob", 0, 450.00, {10, 9, 2024}},
    {"34567869", "Charlie", 0, 2300.00, {9, 9, 2024}}
} ;
int size = 3;

// prototypes des fonctions
void menu();
int ouvre_fichier(char * nom);
void ferme_fichier(FILE * file);
void ajouter_client();
void afficher_client();
void rechercher_par_num();
void rechercher_par_nom();
void lister_clients();

int main(){
    menu();

    printf("\n");
    return 0;
}

void menu(){
    int choice;
    do{
        printf(COLOR_YELLOW "-----------------------------------------------------------------------\n");
        printf("                            menu principale                            \n");
        printf("-----------------------------------------------------------------------\n\n");
        printf("    1- ajouter un client\n");
        printf("    2- afficher un client\n");
        printf("    3- lister tous les clients\n");
        printf("    4- effectuer une operation\n");
        printf("    5- quittez le programme\n");
        printf("\n-----------------------------------------------------------------------\n" COLOR_RESET);
        printf("choisit votre choix: "); scanf("%d", &choice);
        printf(COLOR_YELLOW "-----------------------------------------------------------------------\n" COLOR_RESET);

        switch(choice){
            case 1: ajouter_client(); break;
            case 2: afficher_client(); break;
            case 3: lister_clients(); break;
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
    printf(COLOR_YELLOW "-----------------------------------------------------------------------\n");
    printf("                             ajouter client                            \n");
    printf("-----------------------------------------------------------------------\n" COLOR_RESET);
    printf("numero de compte: "); 
    scanf(" %[^\n]s", clients[size].num_compte);
    printf("nom et prenom: ");
    scanf(" %[^\n]s", clients[size].username);
    printf("votre solde: "); scanf("%f", &clients[size].nouv_solde);
    printf("date de naissance (JJ/MM/AAAA): "); scanf("%d/%d/%d", &clients[size].date.jour, &clients[size].date.mois, &clients[size].date.annee);
    printf(COLOR_GREEN "\nnouveau client a ete ajoutee avec le numero '%s'..\n" COLOR_RESET, clients[size].num_compte);
    
    size = size + 1;
}

void afficher_client(){
    int choice;
    system("clear");
    do{
        printf(COLOR_YELLOW "-----------------------------------------------------------------------\n");
        printf("                            afficher client                            \n");
        printf("-----------------------------------------------------------------------\n");
        puts("1- chercher par numero de compte");
        puts("2- chercher par nom");
        puts("3- retour au menu principale");
        printf("-----------------------------------------------------------------------\n" COLOR_RESET);
        printf("entrer votre choix: "); scanf("%d", &choice);
        switch(choice){
            case 1: rechercher_par_num(); break;
            case 2: rechercher_par_nom(); break;
            case 3: return; break;
            default: 
                system("clear");
                printf(COLOR_RED "veuillez choisit un choix valide dans le menu.\n" COLOR_RESET);
                break;
        }
    }
    while(choice != 3);
}

void rechercher_par_num(){
    system("clear");
}

void rechercher_par_nom(){
    system("clear");
}

void lister_clients(){
    system("clear");
    printf(COLOR_YELLOW "-----------------------------------------------------------------------\n");
    printf("                        lister tous les clients                        \n");
    printf("-----------------------------------------------------------------------\n");
    if(size == 0){
        printf(COLOR_RED "aucun client a disponible maintenant \n" COLOR_RESET);
        return;
    }
    printf(COLOR_VIOLET "num de compte    username       date naissance   solde actuel\n" COLOR_RESET);
    for(int i=0; i<size; i++){
        printf("%-16s %-14s %-2d/%-2d/%-10d %.2f \n", clients[i].num_compte, clients[i].username, clients[i].date.jour, clients[i].date.mois, clients[i].date.annee, clients[i].nouv_solde);
    }
}

