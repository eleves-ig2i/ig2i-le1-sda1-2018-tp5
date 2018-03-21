/************************************************************************/
/* AUTEUR : A. TOGUYENI							*/
/* DATE : 26/11/2017							*/
/* FICHIER : test_chaineplus.c						*/
/* DESCRIPTION : Permet de tester les fonction de la partie I           */
/************************************************************************/
#include "chainesplus.h"



int menu();

int main()
{

Tchaine ch1,ch2;
short rep;

do
{
rep=(short)menu();

switch (rep)
{
    case 1 : lire(ch1);
             printf("\n Saisie : '%s'",ch1);
             break;
             
    case 2 : printf("\n Test de strpos !!!\n Ecrivez la chaine à parcourir : ");
    	     lire(ch1);
    	     printf("\n Ecrivez le mot à rechercher : \n");
    	     lire(ch2);
    	     if (strmot(ch2)==1) {
             printf("\n Position de '%s' dans '%s' : %d \n", ch2,ch1, strpos(ch2,ch1)); 
             }
             else {printf("\n ch1 ne contient pas qu'un mot !!!\n");}
             break;
             
    case 3 : printf("\n Test de la mise en minuscule !!!");
             lire(ch1);
             printf("\n Chaine finale '%s'", strmin(ch1));
             break;
             
    case 4 : printf("\n Test de premier !!!");
             lire(ch1);
             printf("\n Premier : '%s'",premier(ch1,ch2));
             break;
             
    case 5 : printf("\n Test de saufpremier !!!");
             lire(ch1);
             printf("\n SaufPremier : '%s'",saufpremier(ch1,ch2));
             break;
             
    case 6 : printf("\n Test de phrase !!!");
             lire(ch1);
             lire(ch2);
             printf("\n ch1 = '%s'\n ch2 = '%s'",ch1,ch2);
             printf("\n ch1 + ch2 = '%s'",phrase(ch1,ch2));
             break;
             
    case 7 : printf("\n Test de dernier !!!");
             lire(ch1);
             printf("\n Dernier : '%s'",dernier(ch1,ch2));
             break;
             
    case 8 : printf("\n Test de saufdernier !!!");
    	     lire(ch1);
             printf("\n Saufdernier : '%s'",saufdernier(ch1,ch2));
             break;
             
    case 9 : printf("\n Test de miroir !!!");
             lire(ch1);
             printf("\n Miroir : '%s'",miroir(ch1,ch2));
             break;
             
    case 10 :printf("\n Test de member !!! (1 si vrai, sinon faux)\n Tapez le mot à chercher : ");
             lire(ch1);
             if(strmot(ch1)==1) {
             printf("\n Tapez la chaine à parcourir : ");
             lire(ch2);
             printf("\n Member : '%d'",member(ch1,ch2));
             }
             else {printf("\n ch1 ne contient pas qu'un mot !!!\n");}
             break;
             
    case 11 :printf("\n Test de efface !!!\n Tapez le mot à effacer : ");
             lire(ch1);
             if(strmot(ch1)==1) {
             printf("\n Tapez la chaine à parcourir : ");
             lire(ch2);
             printf("\n Efface : '%s'",efface(ch1,ch2));
             }
             else {printf("\n ch1 ne contient pas qu'un mot !!!\n");}
             break;
             
    case 12 :printf("\n Test de nombremots !!!");
    	     lire(ch1);
    	     printf("\n Nombre de mots dans la chaine 1 : %d",nombremots(ch1));
    	     break;
    	     
    case 13 :printf("\n Test de strmot !!!");
    	     lire(ch1);
    	     printf("\n strmot('%s')==%d",ch1,strmot(ch1));
    case 14: break;
    
   
    default : printf("\n Option imprevue !!!\n");    
}

}
while (rep!=14);
printf("\n\n FIN DU PROGRAMME !!! \n\n");
return 1;
}// fin main



int menu()
{
    int choix;
    
    printf("\n 1 - Lire une chaine");
    printf("\n 2 - Tester strpos");
    printf("\n 3 - Tester strmin");
    printf("\n 4 - Tester premier");
    printf("\n 5 - Tester saufpremier");
    printf("\n 6 - Tester phrase ");
    printf("\n 7 - Tester dernier");
    printf("\n 8 - Tester saufdernier");
    printf("\n 9 - Tester miroir");
    printf("\n 10 - Tester member");
    printf("\n 11 - Tester efface");
    printf("\n 12 - Tester nombremots");
    printf("\n 13 - Tester strmot");
    printf("\n 14 - Sortir");
    printf("\n Votre choix : ");
    fflush(stdin); 
    scanf("%d",&choix);
    getchar();
    return choix;
}
