/************************************************************************/
/* AUTEUR : SALEZ Nathan						*/
/* DATE : 15/01/2017							*/
/* FICHIER : chaineplus.c						*/
/* DESCRIPTION : Bibliotheque de fonctions avancee de traitement des    */
/* chaines de caracteres                                                */
/************************************************************************/
#include "chainesplus.h"


/***************************************************************************/
/* NOM FONCTION : lire						  	   */
/* DESCRIPTION :  réalise la saisie d'une chaine et la formate de manière à*/
/* ce qu'elle respecte les spécifications imposées au début de cet énoncé. */
/* Retourne :un pointeur sur la chaine lue			   	   */
/* Effets de bords : Saisie de la chaine a formatee au clavier		   */
/* Paramètres en entree :                                       	   */
/* Paramètres en sortie :  ch (la chaine modifiee)       		   */
/***************************************************************************/
char* lire(char* ch) {
char c;
int i=0;
Tstate etat=debut;
do {
	c=getchar();
	switch(etat) {
	case debut :	if(((c>='a') && (c<='z'))||((c>='A') && (c<='Z'))) {	//c appartient à l'alphabet	
				etat=inmot;
				ch[i]=c;
				i++;
				}
			if(c==10) etat=fin;
			break;
	case inmot :	if(((c>='a') && (c<='z'))||((c>='A') && (c<='Z'))) {
				//etat=inmot;
				ch[i]=c;
				i++;
				}
			if(((c<'a') || (c>'z'))&&((c<'A') || (c>'Z'))) {//c n'appartient pas à l'alphabet
				etat=outmot;
				ch[i]=' ';
				i++;
				}
			if(c==10) etat=fin;
			break;
	case outmot :   /*if(((c<'a') || (c>'z'))&&((c<'A') || (c>'Z'))) {  //c n'appartient à l'alphabet
				etat=outmot;
				}	*/
			if(((c>='a') && (c<='z'))||((c>='A') && (c<='Z'))) {
				etat=inmot;
				ch[i]=c;
				i++;
				}
			if(c==10) {
				if(ch[i-1]==' ') i--;
				etat=fin;
				}
			break;
	default : 	printf("\n\nProblème dans la fonction de lecture !\n\n");
			break;
	}
}while((etat!=fin)&&(i!=MAXCAR-1));
ch[i]='\0';
if(ch[i-1]==' ') ch[i-1]=ch[i];
return ch;
}

// On introduit la fonction suivante :
/***************************************************************************/
/* NOM FONCTION : strmot						   */
/* DESCRIPTION :  retourne 1 si la chaine source contient un seul mot,     */ 
/* 0 sinon.	                                                           */
/* Retourne : 1 ou 0 (cf ligne au dessus			   	   */
/* Effets de bords :                                    		   */
/* Paramètres en entree :  mot	                                           */
/* Paramètres en sortie :                                  		   */
/***************************************************************************/
int strmot(const char* mot) {
int i=0;
if(mot[0]=='\0') {return 0;}
else{
	while(mot[i]!='\0' && mot[i]!=' ') i++;
	if (mot[i]=='\0') {return 1;}
	else {return 0;}
	}
}


/***************************************************************************/
/* NOM FONCTION : strpos						   */
/* DESCRIPTION :  retourne la position du mot pointe par mot dans la chaine*/ 
/* pointee par ch                                                          */
/* Retourne : la position de mot 			   	           */
/* Effets de bords :                                    		   */
/* Paramètres en entree :  mot et ch                                       */
/* Paramètres en sortie :                                  		   */
/***************************************************************************/
int strpos(const char *mot, const char *ch)
{int i=0,a,p,mottrouve=0;		// On considère que la chaine mot ne contient pas d'espaces.
	while((ch[i]!='\0')&&(mottrouve==0)) {
		a=0;
		p=i;
		while((ch[i]==mot[a])&&(mot[a]!='\0')) {
			i++;a++;
			}
		if(mot[a]=='\0') mottrouve=1;	//On a trouvé le mot
		if(ch[i]!=mot[a]) i=p+1;	//On incrémente la position de départ.
		}
	if(mottrouve==1) {return p;}
	else {return -1;}
}


/***************************************************************************/
/* NOM FONCTION : strmin						   */
/* DESCRIPTION :  Elle convertit en miniscule les caractères de la chaine  */
/* pointée par ch.                                                         */
/* Retourne : Retourne un pointeur sur le début de cette chaine 	   */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (avec des caracteres pouvant etre en majuscule*/
/* Paramètres en sortie : ch                                		   */
/***************************************************************************/
char *strmin(char * ch)
{int i=0;
while(ch[i]!='\0') {
	if((ch[i]>='A') && (ch[i]<='Z')) ch[i]=ch[i]+32;
	i++;
	}
return ch;
}


/* Partie 2 */



/***************************************************************************/
/* NOM FONCTION : premier						   */
/* DESCRIPTION : Crée une chaine avec le premier mot de ch qui ne doit pas */
/* modifie.                                                                */
/* Retourne : Retourne un pointeur sur une chaine contenant le premier mot */
/* ou NULL si la chaine ch est vide                                        */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch chaine dont on veut extraire le premier mot   */
/* Paramètres en sortie : mot (chaine contenant le premier mot)            */
/***************************************************************************/
char *premier(const char *ch, char *mot)
{int i=0;
if (strlen(ch)!=0) {
	strcpy(mot,ch);
	while((mot[i]!='\0')&&(mot[i]!=' ')) i++; 	
//Dans le cas où on tombe sur l'espace, on a bien à la fin de la boucle : mot[i]==' '
	mot[i]='\0';
	return mot;
}
else {return NULL;}
}

//On ajoute la fonction suivante :

/***************************************************************************/
/* NOM FONCTION : nombremots						   */
/* DESCRIPTION : Renvoie le nombre de mots dans le chaine ch               */
/* Retourne : le nombre de mots dans la chaine ch			   */
/* ou 0 si ch est vide                                                  */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch                                               */
/* Paramètres en sortie : nombre de mots dans ch	                   */
/***************************************************************************/
int nombremots(const char* ch) {
int i=0, nombremot=0;
if (ch[0]=='\0') {return 0;}
else {	
	nombremot=1;
	while( ch[i]!='\0') {
		while(ch[i]!=' '&& ch[i]!='\0') i++;
		if(ch[i]!='\0') nombremot++;
		i++;
		}
	return nombremot;
	}
}

/***************************************************************************/
/* NOM FONCTION : saufpremier						   */
/* DESCRIPTION : Crée une chaine avec tous les mots de ch sauf le premier  */
/* modifie.                                                                */
/* Retourne : Retourne un pointeur sur le reste de la chaine               */
/* ou NULL si la chaine ch est vide                                        */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (chaine dont on veut extraire le premier mot) */
/* Paramètres en sortie : restch (chaine contenant le reste de ch)         */
/***************************************************************************/
char *saufpremier(const char *ch, char *restch)
{int i,j=0,n;
n=nombremots(ch);
strcpy(restch,ch);
if (n>1) {
	while((restch[j]!='\0')&&(restch[j]!=' ')) j++;	
	for(i=0;i<=strlen(ch)-j-1;i++) restch[i]=restch[i+j+1];	
	return restch;
	}
else { if(n==1) {return restch;}	//S'il y a un mot, on retourne ce même mot.
       else {return NULL;};		//S'il n'y a aucun mot, on retourne NULL.
     }
}

  
/***************************************************************************/
/* NOM FONCTION : phrase						   */
/* DESCRIPTION : Concatenation de ch et ch2 dans la limite des MAXCAR      */
/* caracteres. Le resutant est mis dans ch qui est modofie                 */
/* Retourne : Retourne un pointeur sur la chaine concatenee                */
/* ou NULL si ch et ch2 sont vides                                         */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch et ch2                                        */
/* Paramètres en sortie : ch qui contient les deux chaines concatenee      */
/***************************************************************************/
char *phrase (char * ch, const char * ch2)  
{int j=0,i=strlen(ch);	//On positionne i sur la case de fin de chaîne ch.
if((strlen(ch)==0) && (strlen(ch2)==0)) return NULL;
else {
	ch[i]=' ';	//On ajoute un espace entre les deux mots.
	i++;		//Et on n'oublie pas d'incrémenter i !
	while((strlen(ch)<=MAXCAR-2)&&(ch2[j]!='\0')) {
		ch[i]=ch2[j];
		i++;j++;		//Ne pas oublier l'incrémentation des 2 variables changeantes.
		}
	ch[i]='\0'; //Quelquesoit la raison de l'arrêt de la boucle précédente, on affecte à ch[i] la même valeur.
	return ch;
	}
}

/* Partie 3 */

/***************************************************************************/
/* NOM FONCTION : dernier						   */
/* DESCRIPTION : Renvoie le dernier mot de la chaine ch                    */
/* Retourne : Retourne un pointeur sur une chaine contenant le dernier mot */
/* ou NULL si ch est vide                                                  */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch                                               */
/* Paramètres en sortie : mot qui contient le dernier mot de ch            */
/***************************************************************************/
char* dernier(const char * ch, char * mot)
{int i=0,nmots=0,n;
Tchaine aux;
nmots=nombremots(ch); //On compte d'abord le nombre de mots dans la chaine.
strcpy(mot,ch);
if(nmots>1) {
	for(n=1;n<nmots;n++) {
	saufpremier(mot,aux);
	strcpy(mot,aux);
	}
	return mot;
	}
else { if(n==1) {return mot;}	//S'il y a un mot, on retourne ce même mot.
       else {return NULL;};		//S'il n'y a aucun mot, on retourne NULL.
     }
}

/***************************************************************************/
/* NOM FONCTION : saufdernier						   */
/* DESCRIPTION : Renvoie une chaine constituees des mots de ch sauf        */
/* le dernier                                                              */
/* Retourne : Retourne un pointeur sur une chaine contenant le debur       */
/* de ch sauf le le dernier ou NULL si ch est vide                         */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch                                               */
/* Paramètres en sortie : deb qui contient la chaine ch sauf le dernier mot*/
/***************************************************************************/
char* saufdernier(const char * ch, char *deb)
{int i=strlen(ch)-2;
if (i!=-1) {	//si strlen(ch)=0 alors i=-1
	strcpy(deb,ch);
	while((deb[i]!=' ')&&(i>0)) {
		i--;
		}
	if(i==0) {return deb;}	//Cas où il n'y a qu'un seul mot.
	if(deb[i]==' ') {	//Cas où il y a plusieurs mots
		deb[i]='\0';
		return deb;
		}
	}
else {return NULL;}		//Cas où il y a aucun mot.
}




// On introduit la fonction suivante, dont on se servira pour la fonction efface et miroir
/***************************************************************************/
/* NOM FONCTION : supprespace						   */
/* DESCRIPTION : modifie une chaine de façon à ce qu'il n'y ait plus       */
/* d'espaces au début et à la fin de la chaine.                            */
/* le dernier                                                              */
/* Retourne : rien				                           */
/* Effets de bords :                                    		   */
/* Paramètres en entree : chaine			                   */
/* Paramètres en sortie : chaine                                           */
/***************************************************************************/ 
//On considère que la chaine est constituée que de lettres et d'espaces.
void supprespace(char* chaine) {
int i,j,place=1,nbmots;
while(chaine[0]==' ') {		//On supprime d'abord les espaces au début de la chaine.
	for(i=0;i<strlen(chaine);i++) {
		chaine[i]=chaine[i+1];
		}
	}
//On supprime les espaces en trop entre les mots
nbmots=nombremots(chaine);
for(i=1;i<nbmots;i++) {
	while(chaine[place]!=' ') place++;	//A la fin, on se trouve sur le 1er espace
	while(chaine[place+1]==' ') {		//On supprime les espaces en trop
		for(j=place+1;j<strlen(chaine);j++) {
			chaine[j]=chaine[j+1];
			}
		}
	place++;			//On incrémente place pr se retrouver sur une lettre.
	}
while(chaine[strlen(chaine)-1]==' ') {	//On supprime ensuite les espaces à la fin de la chaîne.
	chaine[strlen(chaine)-1]='\0';
	}	
}


/***************************************************************************/
/* NOM FONCTION : miroir						   */
/* DESCRIPTION : Retourne un pointeur sur une chaîne mirch contenant tous   */
/*les mots de la chaîne pointée par ch, pris dans l'ordre inverse.          */
/* Retourne : Retourne un l'adresse de mirch ou NULL si ch est vide        */
/* de ch sauf le le dernier ou NULL si ch est vide                         */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch                                               */
/* Paramètres en sortie : mirch qui contient la chaine miroir ce ch         */
/***************************************************************************/    
char * miroir(const char * ch, char * mirch) 
{int nmots,i;
Tchaine d,sd,aux;
nmots=nombremots(ch);
if(nmots>1) {
	mirch[0]='\0';		//Si jamais on utilise plusieurs fois cette fonction dans le programme.
	strcpy(aux,ch);		//Puisque l'on ne peut pas modifier ch, on utilise une chaine auxiliaire.
	for(i=1;i<=nmots;i++) {	// n étapes <=> n mots
		dernier(aux,d);	// On récupère le dernier mot de la chaine dans une autre chaine.
		saufdernier(aux,sd);	// sd contient tout sauf le dernier mot de aux.
		phrase(mirch,d);	// On concatène la chaine miroir et d.
		strcpy(aux,sd);		// On supprime définitivement le dernier mot de la chaine aux.
		}
	mirch[strlen(mirch)]='\0'; 	// On n'oublie pas de mettre la variable de fin de chaine.
	supprespace(mirch);
	return  mirch;
	}
else {return NULL;}
}
  
  
/***************************************************************************/
/* NOM FONCTION : member						   */
/* DESCRIPTION : Retourne un pointeur sur une chaîne mirch contenant tous   */
/* les mots de la chaîne pointée par ch, pris dans l'ordre inverse.        */
/* le dernier                                                              */
/* Retourne : Retourne 1 si le mot est trouve sinon 0                      */
/* de ch sauf le le dernier ou NULL si ch est vide                         */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (chaine) et m (le mot recherche)              */
/* Paramètres en sortie :                                                   */
/***************************************************************************/ 
int member(char *m, char *ch)  {
if (strpos(m,ch)==-1) {
	return 0;
	}
else {return 1;}
}




/***************************************************************************/
/* NOM FONCTION : efface						   */
/* DESCRIPTION : Efface dans ch toutes les occurences de m                 */
/* Retourne : Retourne l'adresse de la chaine ch modifiee                  */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (chaine) et m (le mot recherche)              */
/* Paramètres en sortie : ch (chaine modifie avec les mots m effaces)      */
/***************************************************************************/ 
char * efface(const char * m, char * ch) 	//On suppose que la chaine m ne contient pas d'espaces
{int i,longueur;
Tchaine aux;
strcpy(aux,m);
if(member(aux,ch)==1) {		//Si m est contenu dans ch alors
	longueur=strlen(m);	//On évite les appels de fonctions inutiles (cf lignes suivantes)
	while(strpos(m,ch)!=-1) {
		for(i=strpos(m,ch);i<= strlen(ch)-longueur;i++) {	//On évite un appel à la fonction strlen
			ch[i]=ch[i+longueur];	//On évite encore un autre appel
			}
		}
	}
supprespace(ch);
return ch;
}





