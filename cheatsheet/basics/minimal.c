/*
 * Directives de préprocesseurs permettant d'inclure les librairies.
 * Elles sont lues par le préprocesseur avant la compilation
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Déclaration du main :
	* Le main est le point d'entrée de notre programme
	* C'est une fonction demandant en retour un entier (positif ou négatif)
	* Il ne peux il n'y avoir qu'une seul fonction portant ce nom
 */
int main(void) {

	/*
	 * Deux possibilités de retour :
		* 0 : Le programme s'est exécuté correctement et que tout s'est bien passé
		* Autre valeur : Il y a eu une erreur lors de l'exécution du programme
	 */
	return 0; // Ne pas oublier le ; à la fin d'une instruction

	//ATTENTION : Après le return, aucun code ne sera exécuté
}

/*
 * ATTENTION : le comportement d'une fonction, ou d'une intération est définie entre {}
 */
