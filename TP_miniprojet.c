#include <stdio.h>
#define CONTACT_LIMIT 40

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

/* Ajouter un contact */
void addContact(char *tableau_noms[], char *tableau_numeros[], int size) {
}

/* Supprimer un contact */
void removeContact(char *tableau_noms[], char *tableau_numeros[], int size) {
}

/* Rechercher un contact */
int searchContacts(char *tableau_noms[], char *tableau_numeros[], int size) {
    return 0;
}

/* Afficher tous les contacts */
void viewAllContacts(char *tableau_noms[], char *tableau_numeros[], int size) {
    printf("Affichage de tous les contacts\n");
    for(int i = 0; i <= CONTACT_LIMIT; ++i) {
        // Valeure NULL = fin du tableau
        if(tableau_noms[i] == NULL || tableau_numeros == NULL)
            break;
        printf("%d. %s - %s\n", i, tableau_noms[i], tableau_numeros[i]);
    }
    printf("\n");
}

/* Nettoyage de l'entrée */
void flush() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    /* Déclaration des variables + données de test*/
    char* noms[CONTACT_LIMIT][10] = {"John", "Doe", "Julien"};
    char* numeros[CONTACT_LIMIT][10] = { "0695413596", "07955417596", "+33826134576" };
    int choice = 0;

    /* Affichage du menu */
    printf("=== Gestionnaire de contacts ===\n");
    do {
        printf("Choississez une action:\n");
        printf("1- Afficher tous les contacts\n2- Rechercher un contact\n3- Ajouter un contact\n4- Supprimer un contact\n5- Quitter\n\n> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                viewAllContacts(*noms, *numeros, CONTACT_LIMIT);
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
        flush();    // Nettoyage de l'entrée pour le prochain choix
    } while(choice != 5);
    printf("\nA bientot!\n");

    return 0;
}