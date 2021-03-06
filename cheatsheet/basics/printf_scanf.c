// /!\ Les parties du code non commentés sont expliqués dans d'autres tutoriels !

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	/*
	 * Le printf permet "d'imprimer" des caractères dans la console.
	 * Le "\n" est un caractère permettant d'imprimer un retour à la ligne.
	 */
	printf("Coucou\n");

	/*
	 * Il est possible aussi d'imprimer des variables :
		* ici nous déclarons un entier que nous affichons avec un printf
		* Cela marche comme dans un texte à trou, le "%d" stipulant que cela doit être
		  un entier qui doit être retourné.
		* /!\ Ne pas oublier de préciser quel entier doit être retourné !
	 */
	int my_var = 10; // On déclare notre entier
	printf("My var is equal to %d\n", my_var); // On l'affiche avec un printf

	// On affiche plusieurs variables :
	double my_other_var = 15; // Déclaration d'un nombre à virgule
	char my_char = 'A'; // Déclaration d'un caractère
	printf("My lovely char is \"%c\" and my other var is %f\n", my_char, my_other_var);
	/*
	 * Ici nous avons affiché un caractère et un entier :
		* pour afficher un caractère nous devons utiliser "%c"
		* pour le double (nombre à virgule) nous devons utiliser le %f

	 * Il existe aussi tout un tas de possibilité d'impressions comme :
		* %o pour imprimer en octal
		* %x ou %X pour imprimer en héxadécimal
		* %e ou %E pour un affichage en scientifique
		* %s pour les tableaux de caractère termiant par /0 (nous y reviendrons)
		* ...
	 */

	/*
	 * Enfin, il est possible d'afficher une chaîne préformattée, il suffit
	 * de l'appeler en lieu et place de la chaîne de caractères de printf :
	 */

	char *age = "I am %d yo\n";
	printf(age, 19);

	// --------------------------------------------
	printf("\n"); // On espace le tout
	// --------------------------------------------

	// Récupération de la saisie d'un utilisateur

	int your_age; // On déclare une variable pour récupérer l'age de l'utilisateur
	printf("Please, give me your age : "); // On demande gentillement :)
	scanf("%d", &your_age); // Le scanf récupère l'adresse de la variable
	printf("your age : %d\n", your_age); // On affiche la variable

	/*
	 * Que se passe-il ?
		* Après avoir fait un printf nous faisons un scanf pour récupérer
		  la sasie de l'utilisateur
		* on spécifie au scanf quel type de variable récupérer (comme un printf)
		* On donne L'ADRESSE de la variable pour qu'il stocke cette donnée dedans
			* L'adresse de la variable est donné avec le & (exemple : &yourAge)
			* Cela marche comme à la poste, on spécifie une adresse ou livrer le colis !
	 */

	return 0;
}
