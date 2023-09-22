#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
        int id,j, m, a;
        char titre[20],des[100],statut[25];

}To_do;

To_do tach[100];
int cup = 0; //bach ikamal min bd

int isPastDate(int day, int month, int year) {
    time_t now;
    struct tm future_date;
    //struct tm *current_date;

    time(&now);
    //current_date = localtime(&now);

    future_date.tm_year = year - 1900;
    future_date.tm_mon = month - 1;
    future_date.tm_mday = day;
    future_date.tm_hour = 0;
    future_date.tm_min = 0;
    future_date.tm_sec = 0;

    return difftime(mktime(&future_date), now) < 0;
}

void Echanger_tache(int echX, int echY){
                To_do Ech = tach[echX];
                tach[echX] = tach[echY];
                tach[echY] = Ech;
}

void Afficher_sort_trier_alpha(int num){
        for (int i = 0; i < num - 1; i++){
                for(int j = 0; j < num - i - 1; j++){
                        if(strcmp(tach[j].titre,tach[j + 1].titre) > 0){
                                Echanger_tache(j,j+1);
                        }
                }
        }
}

void Afficher_sort_trier_deadline(int num){
                for(int i = 0; i < num - 1; i++){
                        for(int j=0; j < num - i - 1; j++){
                                if(tach[j].a > tach[j + 1].a || tach[j].a == tach[j+1].a && tach[j].m > tach[j + 1].m ||  tach[j].m == tach[j+1].m && tach[j].j > tach[j + 1].j ||  tach[j].j == tach[j+1].j )
                                        Echanger_tache(j, j + 1);
                        }
                }
}

void Afficher_sort_trier_3jours(int num){
                for(int i = 0;i < num -1; i++){
                        for(int j = 0; j < num - i - 1; j++){
                                if( isPastDate(tach[i].j, tach[i].m, tach[i].a)){
                                        Echanger_tache(j, j+1);
                                }

                        }
                }
}
void Afficher_tache(int num){
                for (int i=0; i < num; i++){
                        printf("\nIdentifiant: %d\nTitre: %s\nDescription: %s\nDeadline: %d/%d/%d\nStatut: %s\n", tach[i].id,tach[i].titre, tach[i].des, tach[i].j, tach[i].m, tach[i].a, tach[i].statut);
                }
}
int Recherche_ID(int num, int id){
                for(int i=0;i<num;i++){
                        if(tach[i].id == id){
                                return i;
                        }
                }
                return -1;
}

int Recherche_Titre(int num, char titre[100]){
        for(int i = 0; i < num; i++){
                if(strcmp(tach[i].titre, titre) == 0){
                        return i;
                }
        }
        return -1;
}
void Ajouter_tache(int num){
        int st;
            char choisire[10];
        for(int i = cup; i < cup + num; i++){
                tach[i].id = i + 1;
                printf("Entez Titre: ");
                scanf(" %[^\n]", tach[i].titre);

                printf("Entez Description: ");
                scanf(" %[^\n]", tach[i].des);

                do{

                   printf("Entrez Deadline (DD/MM/YY): ");
                   scanf("%d/%d/%d", &tach[i].j, &tach[i].m, &tach[i].a);

                        if(tach[i].j < 1 || tach[i].j > 31 || tach[i].m < 1 || tach[i].m < 12 || tach[i].a < 2023){

                                printf("La date incorrec \n");


                        }
                        else if(isPastDate(tach[i].j, tach[i].m, tach[i].a)){

                                printf("La date est dans le passe. Veuillez entrer une date future.\n");}

                } while((tach[i].j < 1 || tach[i].j > 31 && tach[i].m < 1 || tach[i].m < 12, tach[i].a < 2023) ||  isPastDate(tach[i].j, tach[i].m, tach[i].a));

                do{
                        printf("Enter statut :\n  1: a realiser.\n  2: en cours de realisation.\n  3: finalisee.  \nEntrez nombre: ");
                        printf("Entre N: ");
                        scanf(" %[^\n]", choisire);
                        st = atoi(choisire);
                 }while (st < 1 || st > 3);


                            switch(st){
                                case 1:
                                        strcpy(tach[i].statut,"a realiser");
                                        break;
                                case 2:
                                        strcpy(tach[i].statut,"en cours de realisation,");
                                        break;
                                case 3:
                                        strcpy(tach[i].statut,"finalisée");
                                        break;

                                default:
                                        printf("Le Nombre incorrect.\n");
                        }
                }
        cup += num;
}

void Menu_affichage(){
        int chx;
        char choisire[10];
        printf("1:Trier les tâches par ordre alphabétique.\n");
        printf("2:Trier les tâches par deadline.\n");
        printf("3:Afficher les tâches dont le deadline est dans 3 jours ou moins.");
        ici:
        printf("\nchoisir: ");
        scanf(" %[^\n]", choisire);

        chx = atoi(choisire);
        switch (chx){
                case 1:
                        Afficher_sort_trier_alpha(cup);
                        break;
                case 2:
                        Afficher_sort_trier_deadline(cup);
                        break;
                case 3:
                        Afficher_sort_trier_3jours(cup);
                        break;
                default:
                        printf("choix invalide. essayer à nouveau .\n");
                        goto ici;
        }
}

void Menu_Modifier(){
        int chx;
        char choisire[10];
        printf("1:Modifier la description d'une tâche.\n");
        printf("2:Modifier le statut d'une tâche.\n");
        printf("3:Modifier le deadline d'une tâche.");
        ici:
        printf("\nchoisir: ");
        scanf(" %[^\n]", choisire);

        chx = atoi(choisire);
        switch (chx){
                case 1:
                        
                        break;
                case 2:
                        
                        break;
                case 3:
                        
                        break;
                default:
                        printf("choix invalide. essayer à nouveau .\n");
                        goto ici;
        }
}
void Menu_Rechercher(){
        int chx,id;
        char titre[100];
        char choisire[10];
        int indice;

        printf("1:Rechercher une tâche par son Identifiant.\n");
        printf("2:Rechercher une tâche par son Titre.\n");
        ici:
        printf("\nchoisir: ");
        scanf(" %[^\n]", choisire);

        chx = atoi(choisire);
        switch (chx){
                case 1:
                        printf("Entrez ID: ");
                        scanf("%d",&id);
                        indice  = Recherche_ID(cup,id);
                        printf("\nIdentifiant: %d\nTitre: %s\nDescription: %s\nDeadline: %d/%d/%d\nStatut: %s\n", tach[indice].id,tach[indice].titre, tach[indice].des, tach[indice].j, tach[indice].m, tach[indice].a, tach[indice].statut);
                        break;
                case 2:
                        printf("Entrez titre de tache: ");
                        scanf(" %[^\n]",titre);
                        indice = Recherche_Titre(cup,titre);
                      if(indice != -1){
                                printf("\nIdentifiant: %d\nTitre: %s\nDescription: %s\nDeadline: %d/%d/%d\nStatut: %s\n", tach[indice].id,tach[indice].titre, tach[indice].des, tach[indice].j, tach[indice].m, tach[indice].a, tach[indice].statut);
                        }
                        else{
                               printf("Tâche non trouvée.\n");
                        }
                        break;

                default:
                        printf("choix invalide. essayer à nouveau .\n");
                        goto ici;
        }
}


int main(){
    while (1)
    {
        int ch,n,id;

        char choisire[10];
        printf("\n\t\t Gestion de Taches ToDo\n");

        printf("1: Ajouter une nouvelle tache: \n");
        printf("2: Ajouter plusieurs nouvelles taches: \n");
        printf("3: Afficher la liste de toutes les taches (Identifiant, Titre, Description, Deadline, Statut): \n");
        printf("4: Modifier une tache: \n");
        printf("5: Supprimer une tache par identifiant: \n");
        printf("6: Recherer  les taches: \n");
        printf("7: Statistiques: \n");
        printf("8: Quitter\n");
        ici:
        printf("\nchoisir: ");
        scanf(" %[^\n]",choisire);
        ch = atoi(choisire);
        switch(ch){
                case 1:
                        Ajouter_tache(1);
                        break;
                case 2:
                        printf("Entrez le nombre du tache: ");
                        scanf("%d",&n);
                        Ajouter_tache(n);
                        break;
                case 3:
                        Menu_affichage();
                        Afficher_tache(cup);
                        break;
                case 5:
                        printf("Entrez ID pour supprimer la tache: ");
                        scanf("%d",&id);

                        int indice = Recherche_ID(cup,id);
                        if(indice != -1){
                                for(int i = 0; i < cup - 1; i++){
                                        tach[i]= tach[i + 1];
                                }
                                cup--;
                                printf("Tache avec l'ID: %d supprimée avec succes.\n", id);
                        }
                        else 
                                printf("Tache avec l'ID: %d non trouvee.\n", id);                       
                        
                        break;
                case 6:
                        Menu_Rechercher();
                        break;


                case 8:
                        return 0;

                default:
                        printf("esseyez autre fois ");
                        goto ici;
        }
    }

}
