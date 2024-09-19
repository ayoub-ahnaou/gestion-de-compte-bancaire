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
    float solde;
    Date date;
    char operation;
} Client;

Client clients[10] = {
    {"12345673", "alice", 1200.75, {12, 9, 2024}},
    {"23456478", "bob", 450.00, {10, 9, 2024}},
    {"34567869", "charlie", 2300.00, {9, 9, 2024}}
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
void effectuer_operation();
void effectuer_retrait(int position);
void effectuer_virement(int position);

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
            case 4: effectuer_operation(); break;
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
    printf("votre solde: "); scanf("%f", &clients[size].solde);
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
    if(size == 0){
        printf(COLOR_RED "aucun client a disponible maintenant \n" COLOR_RESET);
        return;
    }
    char num[9];
    printf("entrer le numero de compte: ");
    scanf("%s", num);
    printf("-----------------------------------------------------------------------\n");
    for(int i=0; i<size; i++){
        if(strcmp(clients[i].num_compte, num) == 0){
            printf(COLOR_VIOLET "num de compte    username       date naissance   solde actuel\n" COLOR_RESET);
            printf("%-16s %-14s %-2d/%-2d/%-10d %.2f \n", clients[i].num_compte, clients[i].username, clients[i].date.jour, clients[i].date.mois, clients[i].date.annee, clients[i].solde);
            return;
        }
    }
    printf(COLOR_RED "aucun client a trouvee sous le numero '%s' \n" COLOR_RESET, num);
}

void rechercher_par_nom(){
    system("clear");
    if(size == 0){
        printf(COLOR_RED "aucun client a disponible maintenant \n" COLOR_RESET);
        return;
    }
    char nom[30];
    printf("entrer le nom: ");
    scanf("%s", nom);
    printf("-----------------------------------------------------------------------\n");
    for(int i=0; i<size; i++){
        if(strcmp(clients[i].username, nom) == 0){
            printf(COLOR_VIOLET "num de compte    username       date naissance   solde actuel\n" COLOR_RESET);
            printf("%-16s %-14s %-2d/%-2d/%-10d %.2f \n", clients[i].num_compte, clients[i].username, clients[i].date.jour, clients[i].date.mois, clients[i].date.annee, clients[i].solde);
            return;
        }
    }
    printf(COLOR_RED "aucun client a trouvee sous le nom '%s' \n" COLOR_RESET, nom);
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
        printf("%-16s %-14s %-2d/%-2d/%-10d %.2f \n", clients[i].num_compte, clients[i].username, clients[i].date.jour, clients[i].date.mois, clients[i].date.annee, clients[i].solde);
    }
}

void effectuer_operation(){
    system("clear");
    printf(COLOR_YELLOW "-----------------------------------------------------------------------\n");
    printf("                        effectuer une operation                        \n");
    printf("-----------------------------------------------------------------------\n" COLOR_RESET);
    char nom[30]; int position = -1;
    printf("entrer votre nom de compte: ");
    scanf(" %[^\n]s", nom);
    printf("-----------------------------------------------------------------------\n");
    for(int i=0; i<size; i++){
        if(strcmp(clients[i].username, nom) == 0){
            position = i;
        }
    }
    if(position == -1){
        printf(COLOR_RED "compte ne pas trouvee \n" COLOR_RESET);
        return;
    }
    else {
        int choice;
        do{
            puts("1- effectuer un retrait");
            puts("2- effectuer un virement");
            puts("3- retour au menu principale");
            printf("-----------------------------------------------------------------------\n");
            printf("choisit une operation: "); scanf("%d", &choice);
            switch(choice){
                case 1: effectuer_retrait(position); break;
                case 2: effectuer_virement(position); break;
                case 3: return; break;
                default:
                    system("clear");
                    printf(COLOR_RED "veuillez choisit un choix valide dans le menu.\n" COLOR_RESET);
                    break;
            }
        }
        while(choice != 3);
    }
}

void effectuer_retrait(int position){
    system("clear");
    float amount;
    printf("entrer votre montant pour votre retrait: ");
    scanf("%f", &amount);
    if(amount > clients[position].solde){
        printf(COLOR_RED "vous n'avez pas cet amount dans votre compte\n" COLOR_RESET);
        return;
    }
    else {
        clients[position].solde = clients[position].solde - amount;
        printf(COLOR_GREEN "vous avez effectue un retrait du %.2f DH avec succes\n" COLOR_RESET, amount);
    }
}

void effectuer_virement(int position){
    system("clear");
    float amount;
    printf("entrer votre montant pour votre virement: ");
    scanf("%f", &amount);
    if(amount < 100){
        printf(COLOR_RED "vous pouvez verser au minum 100 DH dans votre compte\n" COLOR_RESET);
        return;
    }
    clients[position].solde = clients[position].solde + amount;
    printf(COLOR_GREEN "vous avez effectue un retrait du %.2f DH avec succes\n" COLOR_RESET, amount);
}
