#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

//declaration du type jeton
typedef struct tJeton{
    int nX;
    int nY;
}tJeton;

//prototypes fonctions
void init(int tabCarre[TAILLE][TAILLE]);
void avancer(tJeton *,int tabCarre[TAILLE][TAILLE],int);
void recherchevide(tJeton *,int tabCarre[TAILLE][TAILLE]);
void placer(tJeton *,int tabCarre[TAILLE][TAILLE],int);
void afficher(int tabCarre[TAILLE][TAILLE]);

void avancerdroite(tJeton *,int tabCarre[TAILLE][TAILLE]);
void avancergauche(tJeton *,int tabCarre[TAILLE][TAILLE]);
void corriger(tJeton *,int tabCarre[TAILLE][TAILLE]);

//programme principal
int main(){
    //declaration des variables
    int tabCarre[TAILLE][TAILLE];
    int nNbr;
    tJeton Jeton={2,1};

    //lancement des fonctions
    nNbr=2;
    init(tabCarre);
    for (nNbr=2;nNbr<26;nNbr++){
        avancer(&Jeton,tabCarre,nNbr);
        afficher(tabCarre);
    }
    return 0;
}
/*FONCTION INIT
BUT : Initialiser le tableau
ENTREE : Tableau
SORTIE : Tableau initialisé
*/
void init(int tabCarre[TAILLE][TAILLE]){
    int nLig=0, nCol=0;
    for (nLig=0;nLig<TAILLE;nLig++){
        for (nCol=0;nCol<TAILLE;nCol++){
            tabCarre[nLig][nCol]=0;
        }
    }
    tabCarre[2][1]=1;
}
/*FONCTION AVANCER
BUT : Avancer le jeton, contient la plupart des autres fonctions
ENTREE : Chiffre actuel
SORTIE : Prochain chiffre placé à la bonne position
*/
void avancer(tJeton *Jeton, int tabCarre[TAILLE][TAILLE],int nNbr){
    recherchevide(Jeton,tabCarre);
    placer(Jeton,tabCarre,nNbr);
}
/*FONCTION RECHERCHEVIDE
BUT : Avance en haut à droite, si il y'a déjà un chiffre on rectifie vers la gauche
ENTREE : Emplacement jeton actuel
SORTIE : Prochain emplacement jeton
*/
void recherchevide(tJeton *Jeton, int tabCarre[TAILLE][TAILLE]){
    avancerdroite(Jeton,tabCarre);
    corriger(Jeton,tabCarre);
    if(tabCarre[Jeton->nX][Jeton->nY]>0){
        avancergauche(Jeton,tabCarre);
        corriger(Jeton,tabCarre);
    }
}
/*FONCTION PLACER
BUT : Placer le prochain chiffre
ENTREE : Position ou placer le chiffre
SORTIE : Chiffre placé
*/
void placer(tJeton *Jeton, int tabCarre[TAILLE][TAILLE], int nNbr){
    tabCarre[Jeton->nX][Jeton->nY]=nNbr;
}
/*FONCTION AFFICHER
BUT : Afficher le tableau, on l'affiche à chaque nouveau placement
ENTREE : Tableau
SORTIE : Tableau affiché
*/
void afficher(int tabCarre[TAILLE][TAILLE]){
    int nLig=0, nCol=0;
    for (nLig=0;nLig<TAILLE;nLig++){
        for (nCol=0;nCol<TAILLE;nCol++){
            printf("%d ",tabCarre[nCol][nLig]);
        }
        printf("\n");
    }
    printf("\n");
}
/*FONCTION AVANCERDROITE
BUT : Placer le jeton en haut à droite
ENTREE : Jeton en position actuelle
SORTIE : Jeton placé à la prochaine position
*/
void avancerdroite(tJeton *Jeton, int tabCarre[TAILLE][TAILLE]){
    Jeton->nX+=1;
    Jeton->nY-=1;
}
/*FONCTION AVANCERGAUCHE
BUT : Placer le jeton en haut à gauche de la position d'avancerdroite (si position avancerdroite déjà prise)
ENTREE : Jeton en position haut à droite
SORTIE : Jeton en position haut à gauche
*/
void avancergauche(tJeton *Jeton, int tabCarre[TAILLE][TAILLE]){
    Jeton->nX-=1;
    Jeton->nY-=1;
}
/*FONCTION CORRIGER
BUT : Corriger la position si on arrive à une extremité du tableau
ENTREE : position hors tableau
SORTIE : position correcte
*/
void corriger(tJeton *Jeton, int tabCarre[TAILLE][TAILLE]){
    if(Jeton->nX<0){
        Jeton->nX=4;
    }
    if(Jeton->nX>4){
        Jeton->nX=0;
    }
    if(Jeton->nY<0){
        Jeton->nY=4;
    }
    if(Jeton->nY>4){
        Jeton->nY=0;
    }
}
