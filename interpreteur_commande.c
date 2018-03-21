#define MAX 81
#define TRUE 1
#define FALSE 0

#include "chainesplus.h"

void viderbuffer()
{
int c=0;
while(c!='\n'&&c!=EOF)	c=getchar();
}

void imprimer_le_menu() {
printf("\n\n\t Liste des commandes disponibles :\n - pre : créé une chaine contenant le 1er mot de la chaine source.\n - sfp : créé une chaine contenant tout sauf le 1er mot de la chaine source.\n - phr : concatène 2 chaines sources en mettant un espace entre elles.\n - der : créé une chaine contenant le dernier mot de la chaine source.\n - sfd : créé une chaine contenant tout sauf le dernier mot de la chaine source.\n - mir : créé une chaine contenant tous les mots de la chaine source, dans \n   l'ordre inverse.\n - mmb : renvoie 1 si la chaine mot est contenu dans ch, 0 sinon. La chaine mot    ne doit pas contenir d'espace.\n - eff : efface toutes les occurences de la chaine mot dans ch.\n - hlp : affiche le menu des commandes disponibles et leur fonction.\n - fin : arrête le programme.\n\n NB : Toutes les fonctions exceptées mmb,eff,hlp et fin renvoient NULL si la ou les chaine(s) source(s) est(sont) vide(s).\n\n\nTapez sur entrée pour continuer\n");
getchar();
}

void main()
{
char cde[5], s1[MAX], s2[MAX];
char *liste_cdes="pre-sfp-phr-der-sfd-mir-mmb-eff-hlp-fin";
int pos, termine=FALSE;

imprimer_le_menu();
do {
viderbuffer();
printf("\n\nTapez votre commande : ");
lire(cde);
pos=strpos(strmin(cde),liste_cdes);


switch (pos)
{

case 0 : printf("\n Test de premier !!!");
             lire(s1);
             printf("\n Premier : '%s'",premier(s1,s2));
             break;
	 
case 4 : printf("\n Test de saufpremier !!!");
         lire(s1);
         printf("\n SaufPremier : '%s'",saufpremier(s1,s2));
         break;

case 8 : printf("\n Test de phrase !!!");
         lire(s1);
         lire(s2);
         printf("\n s1 = '%s'\n s2 = '%s'",s1,s2);
         printf("\n s1 + s2 = '%s'",phrase(s1,s2));
         break;

case 12 : printf("\n Test de dernier !!!");
          lire(s1);
          printf("\n Dernier : '%s'",dernier(s1,s2));
          break;

case 16 : printf("\n Test de saufdernier !!!");
    	  lire(s1);
          printf("\n Saufdernier : '%s'",saufdernier(s1,s2));
          break;

case 20 : printf("\n Test de miroir !!!");
          lire(s1);
          printf("\n Miroir : '%s'",miroir(s1,s2));
          break;

case 24 : printf("\n Test de member !!!\n Tapez le mot à chercher : ");
          lire(s1);
          if(strmot(s1)==1) {
          printf("\n Tapez la chaine à parcourir : ");
          lire(s2);
          printf("\n Member : '%d'",member(s1,s2));
          }
          else {printf("\n s1 ne contient pas qu'un mot !!!\n");}
          break;

case 28 : printf("\n Test de efface !!!\n Tapez le mot à effacer : ");
          lire(s1);
          if(strmot(s1)==1) {
          printf("\n Tapez la chaine à parcourir : ");
          lire(s2);
          printf("\n Efface : '%s'",efface(s1,s2));
          }
          else {printf("\n s1 ne contient pas qu'un mot !!!\n");}
          break;

case 32 : imprimer_le_menu();
	  break;
	 
case 36 : termine=TRUE;
	  break;

default : printf("\n Commande inconnue. Recommencez!!!\n");
}

}while (!termine);

}
