/************************************************************************/
/* AUTEUR : A. TOGUYENI							*/
/* DATE : 26/11/2017							*/
/* FICHIER : chaineplus.h						*/
/* DESCRIPTION : Entetet de la bibliotheque de fonctions avancee de     */
/* traitement des chaines de caracteres                                 */
/************************************************************************/

#ifndef chaineplus_h
#define chaineplus_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAXCAR 	81

//Macro fonction : retourne 1 si vraie, sinon 0
#define VIDE(ch) (strlen(ch)==0 ? 1 : 0)		
#define EGAL(ch1,ch2) (strcmp(ch1,ch2)==0 ? 1 : 0)

typedef char Tchaine[MAXCAR+1];
typedef enum{debut,inmot,outmot,fin}Tstate;



/***************************************************************************/
/* NOM FONCTION : lire						  	   */
/* DESCRIPTION :  réalise la saisie d'une chaine et la formate de manière a*/
/* ce qu'elle respecte les spécifications imposées au début de cet énoncé. */
/* Retourne :un pointeur sur la chaine lue			   	   */
/* Effets de bords : 			                                   */
/* Paramètres en entree : une variable pour recupere la chaine saisie	   */
/* Paramètres en sortie : la chaine modifiee    			   */
/***************************************************************************/
char *lire (char * ch);


/***************************************************************************/
/* NOM FONCTION : strmot						   */
/* DESCRIPTION :  retourne 1 si la chaine source contient un seul mot,     */ 
/* 0 sinon.	                                                           */
/* Retourne : 1 ou 0 (cf ligne au dessus			   	   */
/* Effets de bords :                                    		   */
/* Paramètres en entree :  mot	                                           */
/* Paramètres en sortie :                                  		   */
/***************************************************************************/
int strmot(const char* mot); // Fonction ajoutée


/***************************************************************************/
/* NOM FONCTION : strpos						   */
/* DESCRIPTION :  retourne la position du mot pointe par mot dans la chaine*/ 
/* pointee par ch                                                          */
/* Retourne : la position de mot 			   	           */
/* Effets de bords :                                    		   */
/* Paramètres en entree :  mot et ch                                       */
/* Paramètres en sortie :                                  		   */
/***************************************************************************/
int strpos(const char * mot, const char *ch);


/* Elle convertit en miniscule les caracteres de la chaine pointée par ch.
Retourne un pointeur sur le début de cette chaine.*/  
char * strmin(char * ch);


/* Partie 2 */
/***************************************************************************/
/* NOM FONCTION : premier						   */
/* DESCRIPTION : Crée une chaine avec le premier mot de ch qui ne doit pas */
/* modifie.                                                                */
/* Retourne : Retourne un pointeur sur une chaine contenant le premier mot */
/* ou NULL si la chaine ch est vide                                        */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch chaine dont on veut extraire le premier mot   */
/* Paramètres en sortie : mot (chaine contenant le premier mot)                                		   */
/***************************************************************************/
char *premier(const char *ch, char *mot);

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
char *saufpremier(const char *ch, char *restch);

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
char *phrase (char * ch, const char * ch2);


/* Partie 3*/

/***************************************************************************/
/* NOM FONCTION : nombremots						   */
/* DESCRIPTION : Renvoie le nombre de mots dans le chaine ch               */
/* Retourne : le nombre de mots dans la chaine ch			   */
/* ou NULL si ch est vide                                                  */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch                                               */
/* Paramètres en sortie : nombre de mots dans ch	                   */
/***************************************************************************/
int nombremots(const char* ch);	// Fonction ajoutée

/***************************************************************************/
/* NOM FONCTION : dernier						   */
/* DESCRIPTION : Renvoie le dernier mot de la chaine ch                    */
/* Retourne : Retourne un pointeur sur une chaine contenant le dernier mot */
/* ou NULL si ch est vide                                                  */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch                                               */
/* Paramètres en sortie : mot qui contient le dernier mot de ch            */
/***************************************************************************/
char * dernier(const char * ch, char * mot);


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
char * saufdernier(const char * ch, char *deb);


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
char * miroir(const char * ch, char * mirch); 



/***************************************************************************/
/* NOM FONCTION : menber						   */
/* DESCRIPTION : Retourne un pointeur sur une chaîne mirch contenant tous   */
/* les mots de la chaîne pointée par ch, pris dans l'ordre inverse.        */
/* le dernier                                                              */
/* Retourne : Retourne 1 si le mot est trouve sinon 0                      */
/* de ch sauf le le dernier ou NULL si ch est vide                         */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (chaine) et m (le mot recherche)              */
/* Paramètres en sortie :                                                   */
/***************************************************************************/ 
int member(char *m, char *ch); 

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
void supprespace(char* chaine);	// Fonction ajoutée

/***************************************************************************/
/* NOM FONCTION : efface						   */
/* DESCRIPTION : Efface dans ch toutes les occurences de m                 */
/* Retourne : Retourne l'adresse de la chaine ch modifiee                  */
/* Effets de bords :                                    		   */
/* Paramètres en entree : ch (chaine) et m (le mot recherche)              */
/* Paramètres en sortie : ch (chaine modifie avec les mots m effaces)      */
/***************************************************************************/ 
char * efface(const char * m, char * ch); 


#endif
