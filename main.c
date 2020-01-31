#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Type structurés
typedef struct ELEMENT
{
	int value;
	struct ELEMENT *prev;
	struct ELEMENT *next;
}ELEMENT;

typedef struct dbLIST
{
	ELEMENT *first;
	ELEMENT *last;
}dbLIST;

//Prototype de fonction
void clear(dbLIST *);
void afficheListe_ModeFile(dbLIST);
void afficheListe_ModePile(dbLIST);
void Initialisation(dbLIST *);
void ajouterFin(dbLIST *, int);
void ajouterDebut(dbLIST *, int);
int retirerFin(dbLIST *);
int retirerDebut(dbLIST *);
int retirerMilieu(dbLIST *, int);

int main()
{
	dbLIST maListe;

	Initialisation(&maListe);
	printf("Initialisation ...\n");

	ajouterFin(&maListe, 4);
	ajouterFin(&maListe, 6);
	ajouterFin(&maListe, 8);
	ajouterFin(&maListe, 1);
	ajouterFin(&maListe, 7);

	printf("Fin initialisation. Appuyez sur 'enter' pour continuer\n");

	fflush(stdin);
	getchar();
	system("cls");

	afficheListe_ModeFile(maListe);

	afficheListe_ModePile(maListe);

	printf("Fin affichage. Appuyez sur 'enter' pour continuer\n");

	fflush(stdin);
	getchar();
	system("cls");

	printf("Ajout du nombre 10 en tête de liste ...\n");

	ajouterDebut(&maListe, 10);

	printf("Operation termine. Appuyez sur 'enter' pour continuer\n");

	fflush(stdin);
	getchar();
	system("cls");

	afficheListe_ModeFile(maListe);

	printf("Fin affichage. Appuyez sur 'enter' pour continuer\n");

	fflush(stdin);
	getchar();
	system("cls");

	printf("Retrait du dernier nombre de la liste ...\n");

	retirerFin(&maListe);

	printf("Operation termine. Appuyez sur 'enter' pour continuer\n");

	fflush(stdin);
	getchar();
	system("cls");

	afficheListe_ModeFile(maListe);

	printf("Fin affichage. Appuyez sur 'enter' pour continuer\n");

	fflush(stdin);
	getchar();
	system("cls");

	printf("Retrait d'un chiffre au milieu...\n");

	retirerMilieu(&maListe, 2);

	printf("Fin du retrait au milieu. Appuyez sur 'enter' pour continuer\n");

	printf("Effacage de la liste ...\n");

	clear(&maListe);

	printf("Operation termine. Appuyez sur 'enter' pour continuer\n");

	fflush(stdin);
	getchar();
	system("cls");

	printf("Fermeture du programme. Aurevoir\n");

	return 0;
}

void clear(dbLIST *x)
{
	ELEMENT *tmp;
	ELEMENT *pElement = x->first;

	while(pElement)
	{
		tmp = pElement;
		pElement = pElement->next;
		free(tmp);
	}

	x->first = NULL;
	x->last = NULL;
}

void afficheListe_ModeFile(dbLIST x)
{
	printf("Affichage de la liste en mode file :\n");
	ELEMENT *pElement = x.first; //Ce n'est pas un pointeur
	while(pElement)
	{
		printf("%d ", pElement->value);
		pElement = pElement->next; //C'est un pointeur
	}
	printf("\n");
}

void afficheListe_ModePile(dbLIST x)
{
	printf("Affichage de la liste en mode pile :\n");
	ELEMENT *pElement = x.last; //Ce n'est pas un pointeur
	while(pElement)
	{
		printf("%d ", pElement->value);
		pElement = pElement->prev; //C'est un pointeur
	}
	printf("\n");
}

void Initialisation(dbLIST *x)
{
	x->first = NULL;
	x->last = NULL;
}

void ajouterFin(dbLIST *x, int nVal)
{
	ELEMENT *nouv = malloc(sizeof(ELEMENT));
	if(!nouv)
	{
		exit(EXIT_FAILURE);
	}

	nouv->value = nVal;
	nouv->prev = x->last;
	nouv->next = NULL;

	if(x->last)
	{
		x->last->next = nouv;
	}
	else{
		x->first = nouv;
	}

	x->last = nouv;
}

void ajouterDebut(dbLIST *x, int nVal)
{
	ELEMENT *nouv = malloc(sizeof(ELEMENT));
	if(!nouv)
	{
		exit(EXIT_FAILURE);
	}

	nouv->value = nVal;
	nouv->next = x->first;
	nouv->prev = NULL;

	if(x->first)
	{
		x->first->prev = nouv;
	}
	else{
		x->last = nouv;
	}

	x->first = nouv;
}

int retirerFin(dbLIST *x)
{
	int nVal;
	ELEMENT *tmp = x->last;
	if(!tmp)
	{
		return -1;
	}

	nVal = tmp->value;
	x->last = tmp->prev;
	if(x->last)
	{
		x->last->next = NULL;
	}else{
		x->first = NULL;
	}

	free(tmp);
	return nVal;
}

int retirerDebut(dbLIST *x)
{
	int nVal;
	ELEMENT *tmp = x->first;
	if(!tmp)
	{
		return -1;
	}

	nVal = tmp->value;
	x->first = tmp->next;
	if(x->first)
	{
		x->first->prev = NULL;
	}else{
		x->last = NULL;
	}

	free(tmp);

	return nVal;
}

int retirerMilieu(dbLIST *x, int rang)
{
	int nVal, i = 1;
	ELEMENT *tmp = x->first;
	if(!tmp)
	{
		return -1;
	}

	while(tmp && i<rang) {
		tmp = tmp->next;
		i++;
	}

	if(tmp)
	{
		nVal = tmp->value;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}else{
		return -1;
	}

	free(tmp);
	return nVal;
}
