/*
 * CODING STYLE
 *
 * Voilà quelque chose d'important : les conventions de codage. Pour ceux qui
 * douteraient de l'intérêt, un petit tour ici ioccc.org/2000/anderson.c vous
 * éclairera.
 *
 * Maintenant que vous avez pris conscience de l'intérêt de coder proprement,
 * nous pouvons commencer.
 *
 * Tout d'abord, je ne saurais que trop vous conseiller d'aller lire les
 * kernel coding guidelines. Les indications présentes ici les reprennent,
 * non pas en intégralité, mais dans les parties les plus importantes. La
 * concision apportée par cette fiche sacrifie les nombreuses, et surtout
 * très drôles, prises de partie de Linux Torvalds (qui n'a d'ailleurs pas
 * tord...)
 *
 * Allez, prenez un siège, nous commençons.
 */

#include <stdio.h>
#define MULT(a, b) (a) * (b)

int main(void)
{

	/*
	 * Les indentations :
	 *
	 * 8 caractères. Point. Pas plus, pas moins. Cela aère bien votre
	 * code et, couplé aux 3 niveaux d'indentation maximal, vous oblige
	 * à coder efficacement, ce qui est primordial.
	 */
	int a = 0;

	if (!a) {
		printf("8 espaces, c'est quand même le top !\n");

		if (1) {
			printf("De plus, plus de 4 niveaux d'indentation,\
ce serait du gâchis, n'est-ce pas ?\n");
		}
	}

	/*
	 * Longueur des lignes et strings :
	 *
	 * Les lignes doivent faire 80 caractères de long, pratique pour les
	 * gros barbus développeurs kernel dont la console ne fait que 80
	 * caractères de large. Pratique également pour vous, cela donnera
	 * à votre code un certain style kytsch, plutôt apprécié par la
	 * gente féminine ;)
	 * Autrement, d'aucun diront que cela améliore la lisibilité, ce qui
	 * n'est pas faux
	 */

	printf("Cette lignes est de longueur suffisante\n");
	printf("Cette ligne ci est beaucoup trop longue, enfin, elle ne l'aurait pas été si je m'étais arrêté après la virgule...\n");
	printf("Ou alors, l'astuce tout simple consiste à séparer la ligne sur\
plusieurs autres lignes, mais seulement dans le cas d'un printf.\n");

	/*
	 * Accolades et espaces
	 *
	 * Et voilà, voilà un sujet qui fait débat, nous y venont, car oui, cette
	 * fiche dénonce ! Alors, les accolades. Le kernel veut, et par "Le kernel"
	 * j'entends Linus Torvalds, que vous placiez vos accolades ouvrantes sur la
	 * première ligne de votre bloc, dans le cas où ce bloc n'est pas une
	 * fonction. Exemple :
	 */

	if (a == 0) { /* Accolade ouvrante sur la première ligne du bloc */
		printf("En voilà une accolade bien placée !\n");
	}

	/*
	 * Dans le cas d'une fonction, nous placeront l'accoalde ouvrante telle
	 * qu'elle se trouve pour la fonction main dans laquelle nous nous trouvons.
	 *
	 * Pour ce qui est des espaces, il faut en placer un après (presque) tous les
	 * mots-clés (sauf sizeof, typeof, alignof, ...). Notamment après if, while
	 * et tous ses copains.
	 * Pas d'espace à l'intérieur de parenthèses :
	 */

	int tmpMoche = sizeof( int ); /* Ca, c'est moche */
	int tmpOp = sizeof(int); /* Ca, non. */

	/*
	 * De même, pour les opérateurs, toujours placer un espace de chaque côté
	 * d'un opérateur binaire ou ternaire. Mais pas pour les opérateurs unaires.
	 */

	int q = 3;
	int m = 4;

	int flagsRate = q&&m; /* On évite */
	int flag = q && m; /* Voilà qui est bien fait ! */

	/*
	 * Evidemment, pas d'espace avant / après les opérateurs d'incrémentation
	 * et de décrémentation. Ni autour des opérateurs de structure '.' et '->'
	 */

	int incremente = 0;
	incremente++;

	struct tmp {
		int field;
	};

	struct tmp mon_tmp;
	mon_tmp.field = 0; /* En voilà une structure bien remplie ! */

	/* JAMAIS D'ESPACES QUI TRAINENT A LA FIN D'UNE LIGNE OU D'UN FICHIER ! */

	/*
	 * Nommage des variables / fonctions
	 *
	 * Pour reprendre la phrase de Linus Torvalds, les développeurs C n'utilisent
	 * pas de noms mignons pour leurs variables.
	 * De plus, le camelCase n'est pas très apprécié.
	 *
	 * Le nom des variables globales doit être clair et descriptif.
	 * Pour ce qui est des variables locales, il doit être court.
	 */

	for (int compteur_for = 0; compteur_for < 10; compteur_for++) /* Non. */
		;

	for (int i = 0; i < 10; i++) /* C'est quand même plus simple ainsi ! */
		;

	/*
	 * Les typedef
	 *
	 * On évite. Point. Si jamais vous avez un objet opaque (et qui doit le
	 * rester), un type similaire à un type existant et que vous voulez éviter
	 * la confusion, ou une vraiment bonne raison, vous pouvez.
	 *
	 * En dehors de ces cas, ne JAMAIS Ô GRAND JAMAIS UTILISER DE TYPEDEF
	 */

	typedef int entier; /* Là, c'est du foutage de gueule, avec un grand F */
	typedef unsigned char u8_int; /* Ok, ça passe */

	/*
	 * Les fonctions
	 *
	 * En trois mots : court, agréable et efficace. En gros, si votre fonction
	 * fait 80 lignes, vous pouvez la splitter. Si elle fait plusieurs choses à
	 * le fois, vous DEVEZ la splitter
	 *
	 * La longueur maximale d'une fonction est inversement proportionnelle à son
	 * indentation maximale : si votre fonction possède trois niveaux
	 * d'indentation, ne la faite pas trop longue.
	 *
	 * Le nombre de variables locales ne doit pas dépasser 5 à 10. Quelqu'un
	 * lisant votre code peut le comprendre si vous ne créez pas plus de 10
	 * variables locales, autrement c'est beaucoup plus difficile, et ce n'est
	 * pas ce que nous cherchons.
	 */

	/*
	 * Les goto
	 *
	 * Vous devriez entendre que c'est sale. Martin lui même criera au loup en
	 * lisant ces lignes, mais je prends le risque, je dénonce moi !
	 *
	 * Alors les gotos, en vrai, c'est bien. A condition que ça ne vous pète pas
	 * à la gueule. Quelques règles à respecter avant de s'en servir :
	 *  - Devoir gérer des erreurs
	 *  - Devoir gérer des erreurs
	 *  - Avoir à gérer des erreurs
	 */

	/*
	 * Les commentaires
	 *
	 * Toujours commenter ses fonctions. Mais pas ce qui se trouve à l'intérieur.
	 * Le but est d'expliquer ce que la fonction fait, mais pas comment.
	 *
	 * Pour le style, logiquement, cette fiche parle d'elle même.
	 * Les commentaires C89 sont encouragés (ceux présent dans cette fiche),
	 * tandis que les commentaires C99 '//' sont poussés vers la falaise.
	 * Que le commentaire soit sur un seule ligne ou non.
	 *
	 * De plus, pour commenter sur plusieurs lignes, placez une colonne d'étoiles
	 * sur la gauche, c'est plus beau. Avec le première ligne vide.
	 */

	/*
	 * Macros, enums et Cie
	 *
	 * Les macros définissant des constantes sont en majuscules, tout comme
	 * pour les labels des enums
	 * Dans le cas de la création de plusieurs constantes ayant un lien les
	 * unes aux autres, créer un enum
	 *
	 * Les macros représentant des fonctions sur plusieurs lignes doivent être
	 * placées dans des blocs do... while() :
	 *
	 * #define swap(a, b)                                                        \
	 *         do {
	 *                 typeof(a) __tmp = a;
	 *                 a = b;
	 *                 b = __tmp;
	 *         } while (0);
	 *
	 * Ne pas oublier de placer des parenthès autour des variables lors de
	 * calculs dans une macro. Car, une variable peut être remplacée par un
	 * nombre, ou par une opération, la précédence sera alors altérée :
	 */

	/*
	 * Pour la macro :
	 * #define MULT(a, b) a * b
	 */
	int x = MULT(3 + 2, 3); /* x vaut 9 */

	/*
	 * Tandis que pour :
	 * #define MULT(a, b) (a) * (b)
	 */
	int y = MULT(3 + 2, 3); /* x vaut 15 */

	/*
	 * Les pointeurs
	 *
	 * L'étoile, lors de la création d'un pointeur, se place à côté du nom de
	 * la variable, et non pas à côté du type.
	 */

	int* bp = NULL; /* Mauvais pointeur */
	int *pt = NULL; /* Beau pointeur ! */

	/*
	 * De plus, il n'est pas indispensable de caster un type void * vers un
	 * autre type de pointeur. Ce cast est implicite et garantit par le
	 * langage.
	 */

	/*
	 * Cette liste non exhaustive des convention du kernel contient les grandes
	 * lignes des normes de codage. N'hésitez pas à lire le document original
	 * pour plus d'informations (pour les fonctions inline par exemple.
	 */

	return 0;
}

