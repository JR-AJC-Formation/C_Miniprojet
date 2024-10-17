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

/* Fonctions utilitaires */
/* Nettoyage de l'entrée */
void flush() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

/* Comparaison de string */
int compareString(char *string1, char *string2) {
    int count = 0;
    do {
        if(string1[count] != string2[count]) {
            if(string1[count] == '\0' || string2[count] == '\0') {
                count = 0;
            }
            break;
        } else {
            count++;
        }
    } while(1);
    return count;
}

/* Recherche dans le tableau */
int search(char *tableau[], char *to_search, int size) {
    for(int i = 0; i <= CONTACT_LIMIT; ++i) {
        printf("%s %s", tableau[i], to_search);
        if(compareString(tableau[i], to_search) != 0) {
            return i;
        } else if(tableau[i] == NULL) {
            return -1;
        }
    }
    return -1;
}

/* Fonctions menu */
/* Ajouter un contact */
void addContact(char *tableau_noms[], char *tableau_numeros[], int size) {
    char nom[10];
    char numero[10];
    printf("Entrez le nom du contact à ajouter > ");
    scanf("%s", nom);
    flush();
    printf("Entrez le numero du contact à ajouter > ");
    scanf("%s", numero);
    for(int i = 0; i <= size; ++i) {
        // Valeure NULL = fin du tableau
        if(i >= size) {
            printf("Plus de place dans les contacts!");
            break;
        }
        if(tableau_noms[i] == NULL || tableau_numeros == NULL) {
            *(tableau_noms + i) = nom;
            *(tableau_numeros + i) = numero;
            printf("Contact %d. %s - %s ajouté\n", i, tableau_noms[i], tableau_numeros[i]);
            break;
        }
    }
}

/* Supprimer un contact */
void removeContact(char *tableau_noms[], char *tableau_numeros[], int size) {
    int todelete = 0;
    printf("Entrez le numero du contact à supprimer > ");
    scanf("%d", &todelete);
    if(todelete > 0 && todelete < size) {
        if(tableau_noms[todelete] == NULL || tableau_numeros[todelete] == NULL) {
            printf("Ce contact n'existe pas\n");
        } else {
            tableau_noms[todelete] = NULL;
            tableau_numeros[todelete] = NULL;
            printf("Contact %d. supprimé\n", todelete);
        }
    } else {
        printf("Contact invalide, retour au menu\n");
    }
}

/* Rechercher un contact */
void searchContacts(char *tableau_noms[], char *tableau_numeros[], int size) {
    int choice;
    flush();
    printf("Chercher un 1- Nom 2- Numéro\n> ");
    scanf("%d", &choice);
    if(choice == 1) {
        char nom[10];
        flush();
        printf("Entrez le nom > ");
        scanf("%s", nom);
        int index = search(tableau_noms, nom, size);
        if(index == -1) {
            printf("Aucun résultat");
        } else {
            printf("%d. %s - %s\n", index + 1, tableau_noms[index], tableau_numeros[index]);
        }
    } else if(choice == 2) {
        char numero[10];
        flush();
        printf("Entrez le numero > ");
        scanf("%s", numero);
        int index = search(tableau_numeros, numero, size);
        if(index == -1) {
            printf("Aucun résultat");
        } else {
            printf("%d. %s - %s\n", index + 1, tableau_noms[index], tableau_numeros[index]);
        }
    } else {
        printf("\nChoix invalide, retour au menu");
    }
    printf("\n");
}

/* Afficher tous les contacts */
void viewAllContacts(char *tableau_noms[], char *tableau_numeros[], int size) {
    printf("Affichage de tous les contacts\n");
    for(int i = 0; i <= size; ++i) {
        // Valeure NULL = fin du tableau
        if(tableau_noms[i] == NULL || tableau_numeros == NULL)
            break;
        printf("%d. %s - %s\n", i, tableau_noms[i], tableau_numeros[i]);
    }
    printf("\n");
}


int main() {
    /* Déclaration des variables + données de test*/
    char* noms[CONTACT_LIMIT] = {"John", "Doe", "Julien"};
    char* numeros[CONTACT_LIMIT] = { "0695413596", "07955417596", "+33826134576" };
    int choice = 0;

    /* Affichage du menu */
    printf("=== Gestionnaire de contacts ===\n");
    do {
        printf("Choississez une action:\n");
        printf("1- Afficher tous les contacts\n2- Rechercher un contact\n3- Ajouter un contact\n4- Supprimer un contact\n5- Quitter\n\n> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                viewAllContacts(noms, numeros, CONTACT_LIMIT);
                break;
            case 2:
                searchContacts(noms, numeros, CONTACT_LIMIT);
                break;
            case 3:
                addContact(noms, numeros, CONTACT_LIMIT);
                break;
            case 4:
                removeContact(noms, numeros, CONTACT_LIMIT);
                break;
            case 5:
                break;  // Do nothing, loop will exit
            default:
                printf("Action invalide, veuillez choisir une autre action\n\n");
                flush();
                break;
        }
    } while(choice != 5);
    printf("\nA bientot!\n");

    return 0;
}