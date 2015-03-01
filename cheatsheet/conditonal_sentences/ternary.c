#include <stdio.h>
#include <stdlib.h>

int main (void) {

	/*
	 * Le ternaire est une façon différente et condensée d'écrire la séquence
	 * d'instructions if else.
	 */

	// --------------------
	// Le if else de base :
	// --------------------

	int max = 0;
	if (3 > 2) // On teste une condition qui nous retourne un booléen (vrai ou faux)
		max = 3;
	else
		max = 2;

	printf("max = %d\n", max); // On affiche le résultat

	/*
	 * Ici pas besoin de parenthèses pour englober l'exécution des séquences du if
	 * et du else car il n'y a qu'une seule instruction (le printf). Dans le cas
	 * contraire nous aurions dû mettre des parenthèses.
	 */

	// -----------------------
	// L'expression ternaire :
	// -----------------------

	// Le code suivant donne exactement le même résultat que le précédent !
	max = 0; // On remet à zéro notre valeur
	max = (3 > 2) ? 3 : 2; // Expression ternaire de folie !
	printf("max = %d\n", max);

	/*
	 * Quelques explications :
	 * Le ternaire utilise une nouvelle opérande qui est le "?". On pourrait
	 * traduire littéralement le code çi dessous par "Est-ce que 3 est supérieur
	 * à 2 ? Si oui je met 3 dans max, sinon je change la valeur de max par 2".
	 *
	 * On va attendre un booléen en retour du code entre les parenthèses. Si cela nous
	 * retourne "true", on affectera la première valeur à la variable, sinon on lui
	 * affectera la seconde (les valeurs sont séparés par ":".
	 */

	return 0;
}
