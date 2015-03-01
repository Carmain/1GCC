#include <stdio.h>
#include <stdlib.h>

/*
 * Une structure est un assemblage de variable d'un ou plusieurs types.
 * On va pouvoir y retrouver des int, long, char... Elles sont généralement définie
 * dans les .h au même titre que les prototypes de fonction.
 *
 * On va donc les définir avec le mot clef "struct" ainsi qu'un nom (comme n'importe
 * quelle variable), puis nous y ajouterons ses éléments.
 *
 * Afin de les différencier des autres variables, on met la première lettre en majuscule.
 * Ne pas oublier de mettre un point virgule à la fin comme tout déclaration de variable !
 */


// La déclaration de notre structure se fait en dehors du main
typedef struct Coordinates Coordinates; // Alias sur notre strucutre (voir en dessous)
struct Coordinates { // Majuscule
	float latitude;
	float longitude;
}; // Le point virgule est ici obligatoire

// Déclaration de structures imbriquées
struct Line { // On déclare notre structure normalement
	Coordinates start; // On ajoute les autres structures comme de simples variables
	Coordinates end;
};

/*
 * Quelques remarques :
 * Le typedef au dessus nous permet de créer un vrai "nouveaux" type de variable,
 * via un alias. C'est un raccouçi qui permet de déclarer notre strucutre comme
 * çi dessus au lieu de "struct Coordinates point;"
 *
 * Une structure comme son nom l'indique donne un aspect "architectural" de notre
 * variable, nous ne faisons que copier son modèle pour créer une variable.
 */

int main (void) {

	Coordinates point; // Déclaration de notre première strucutre !

	// Accès aux valeurs de notre structure
	point.latitude = 49.202174;
	point.longitude = -0.392901;
	printf("The coordinates of SUPINFO are : %lf, %lf\n", point.latitude, point.longitude);

	// Il est aussi possible de raccourcir le code de la sorte :
	Coordinates point2 = {48.858352, 2.294449};
	printf("The coordinates of the Eiffel tower are : %lf, %lf\n",
			point2.latitude, point2.longitude);

	/* Nous savons que la structure end contient deux élements, nous pouvons
	 * lui passer sous forme de "liste". Il est possible par ailleurs de faire
	 * cela pour n'importe quelle structure.
	 */

	// Ici pas de typedef. La déclaration est un peu différente
	struct Line from_supinfo_to_pubs;

	// Accès aux valeurs
	from_supinfo_to_pubs.start.latitude = 49.202174;
	from_supinfo_to_pubs.start.longitude = -0.392901;
	from_supinfo_to_pubs.end.latitude = 49.181891;
	from_supinfo_to_pubs.end.latitude = -0.369380;

	// Même chose qu'au dessus pour la simplification de l'écriture :
	struct Line second_line = {
		{49.202174, -0.392901},
		{48.858352, 2.294449}
	};

	printf("\nThe coordinates of the first point is :\n"
			"\t- Latitude : %lf\n"
			"\t- Longitude : %lf\n"
			"For the second point :\n"
			"\t- Latitude : %lf\n"
			"\t- Longitude : %lf\n",
	second_line.start.latitude, second_line.start.longitude,
	second_line.end.latitude, second_line.end.longitude);

	return 0;
}
