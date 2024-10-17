#include <stdio.h>

/*
    mini_projet1

    enoncé :

    nous allons utiliser deux tableaux :
    un tableau pour stocker les noms et un autre pour les numéros de téléphone.

    PAS DE "STRUCT"

    utilisation de fonctions obligatoire , donc utilisation modulaire

    Ce projet est un gestionnaire de contacts simple. L'objectif est de créer
    un programme en C qui permet de gérer une liste de contacts avec les fonctionnalités suivantes :

    - Ajouter un contact (nom, numéro de téléphone). (verification des doublons)
    - Rechercher un contact par nom.
    - Afficher tous les contacts.
    - Supprimer un contact.
*/

void addContact(char*** tableau_noms, char*** tableau_numeros) {
}

void removeContact(char*** tableau_noms, char*** tableau_numeros) {
}

int searchContacts(char*** tableau_noms, char*** tableau_numeros) {
    return 0;
}

void viewAllContacts(char*** tableau_noms, char*** tableau_numeros) {
}

void flush() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char** noms[40][10];
    int** numeros[40][10];
    int choice = 0;

    printf("=== Gestionnaire de contacts ===\n");
    do {
        printf("Choississez une action:\n");
        printf("1- Afficher tous les contacts\n2- Rechercher un contact\n3- Ajouter un contact\n4- Supprimer un contact\n5- Quitter\n\n> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //viewAllContacts(char ***tableau_noms, char ***tableau_numeros);
                break;
            case 2:
                //searchContacts(char ***tableau_noms, char ***tableau_numeros);
                break;
            case 3:
                //addContact(char ***tableau_noms, char ***tableau_numeros);
                break;
            case 4:
                //removeContact(char ***tableau_noms, char ***tableau_numeros);
                break;
            case 5:
                break;  // Do nothing, loop will exit
            default:
                printf("Action invalide, veuillez choisir une autre action\n\n");
                break;
        }
        flush();
    } while(choice != 5);
    printf("\nA bientot!\n");

    return 0;
}