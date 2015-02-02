// /!\ Les parties du code non commentés sont expliqués dans d'autres tutoriels !

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	printf(" * First  example :\n");

	/*
	 * Le "if" permet de moduler le code et de donner des instruction en fonction
	   d'un choix défini au préalable
	 * La façon de faire est simple : si (if) ma condition se réalise (est vraie),
	   lance les instructions en conséquences
	 */

	int my_var = 10; // On déclare la variable
	if (my_var == 10) { // Si myVar est égal à 10 on exécute la condition
		// Ma condition est vraie, on passera ici
		printf("True statement !\n");
	} // On n'oubile pas les accolades !

	/*
	 * Comment cela marche-il ?
		* Pour commencer il nous faut une condition qui retournera un true ou false
		* Si ma condition est vraie (true), on exécutera la condition
		* Sinon (false), on ne passera pas dans la condition

	 * Il existe plusieurs "tests" pour ma condition :
		* (a == b) -> a est égal à b
		* (a != b) -> a est différent de b
		* (a > b)  -> a est strictement supérieur à b
		* (a < b)  -> a est strictement inférieur à b
		* (a >= b) -> a est supérieur ou égal à b
		* (a <= b) -> a est inférieur ou égal à b

	  * Il est aussi possible d'inverser les conditions avec "!" exemple :
		* !(a < b)  -> a n'est pas inférieur à b
		* !(a == b) -> a est différent de b
	  */

	// -------------------------------------------
	printf("\n");
	// -------------------------------------------

	printf(" * Second example :\n");

	/*
	 * combinaison de conditions :
	 * Il est possible de combiner des conditions avec l'algèbre de Boole :
		* && équivaut à ET
		* || équivaut à OU
	 */

	int another_var = 10;
	int other_var = 3;
	if((another_var > other_var) || (other_var == 4)) { // On combine les conditions
		// On affiche le résultat si la totalité des conditions est vraie
		printf("true statement !\n");
	}

	// -------------------------------------------
	printf("\n");
	// -------------------------------------------

	printf(" * Third example :\n");

	// Il est aussi possible de combiner plusieurs conditions :
	int your_age;
	printf("How old are you ? ");
	scanf("%d", &your_age);

	if (your_age >= 18) { // On vérifie la condition
		printf("Welcome in my bar!\n");
	}

	// Si la première condition ne s'est pas réalisé on lance une nouvelle condition
	else if ((your_age < 18) && (your_age >= 16)) {
		printf("It's okay, you could stay!\n");
	}

	// Si aucune condition n'est vraie, on lance une condition par défaut
	else {
		printf("Get out!\n");
	}


	// -------------------------------------------
	printf("\n");
	// -------------------------------------------

	printf(" * Fourth example :\n");

	/*
	 * Vu qu'il n'y a QU'UNE SEULE instruction dans chaque condition,
	   il est aussi possible de synthétiser le code de la sorte :
	 */
	printf("How old are you ? ");
	scanf("%d", &your_age); // La valeur de yourAge sera écrasée

	if (your_age >= 18)
		printf("Welcome in my bar!\n");
	else if ((your_age < 18) && (your_age >= 16))
		printf("It's okay, you could stay!\n");
	else
		printf("Get out!i\n");

	return 0;
}
