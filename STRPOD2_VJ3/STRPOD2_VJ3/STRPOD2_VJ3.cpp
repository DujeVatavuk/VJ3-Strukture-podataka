//stog i red
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef struct Stog *PosS;
typedef struct Stog//Ubacuje na pocetak, skida sa pocetka
{
	int el;
	PosS next;
}Stog;

typedef struct Red *PosR;
typedef struct Red//Ubacuje na pocetak, skida sa kraja
{
	int el;
	PosR next;
}Red;

void push(PosS);//dodaj na pocetak
PosS pop(PosS);//izbaci sa pocetka
void ispisS(PosS);

void enqueue(PosR);//dodaj na kraj
PosR dequeue(PosR);//izbaci sa pocetka
void ispisR(PosR);

int main()
{
	Stog HeadS;
	Red HeadR;
	HeadS.next = NULL;
	HeadR.next = NULL;
	PosS S;
	PosR R;
	int izbor = 0;

	while (7 != izbor)
	{
		printf("\nOdaberite radnju");
		printf("\n\t1) PUSH");
		printf("\n\t2) ENQUEUE");
		printf("\n\t3) POP");
		printf("\n\t4) DEQUEUE");
		printf("\n\t5) Ispis STOGa");
		printf("\n\t6) Ispis REDa");
		printf("\n\t7) Kraj programa");
		printf("\nVas odabir: ");

		scanf("%d", &izbor);

		switch (izbor)
		{
		case 1:
			push(&HeadS);
			break;
		case 2:
			enqueue(&HeadR);
			break;
		case 3:
			S = pop(&HeadS);
			if (NULL != S)
			{
				printf("\nIZBACENI CLAN IZ STOGA JE: %d", S->el);
			}
			break;
		case 4:
			R = dequeue(&HeadR);
			if (NULL != R)
			{
				printf("\nIZBACENI CLAN IZ REDA JE: %d", R->el);
			}
			break;
		case 5:
			ispisS(&HeadS);
			break;
		case 6:
			ispisR(&HeadR);
			break;
		case 7:
			printf("\nKraj programa");
			break;
		default:
			printf("\nUnjeli ste krivi broj\nMolimo pokusajte ponovno");
			break;
		}
	}

	return 0;
}

void push(PosS S)
{
	PosS temp = (PosS)malloc(sizeof(Stog));

	printf("\nUnesite element u stog: ");
	scanf("%d", &temp->el);

	temp->next = S->next;
	S->next = temp;
}

PosS pop(PosS S)
{
	PosS temp = (PosS)malloc(sizeof(Stog));
	if (NULL == S->next)
	{
		printf("\nStog je prazan");
		return NULL;
	}
	temp = S->next;
	S->next = temp->next;

	return temp;
}

void ispisS(PosS S)
{
	if (NULL == S->next)
	{
		printf("\nStog je prazan");
	}
	else
	{
		S = S->next;
		while (NULL != S->next)//mozda se ovo moze bolje izvrsiti sa do while
		{
			printf("\n%d", S->el);
			S = S->next;
		}
		printf("\n%d", S->el);
	}
}

void enqueue(PosR R)
{
	PosR temp = (PosR)malloc(sizeof(Red));
	static PosR last = NULL;

	if (NULL == R->next)//ode ce last postat R samo prvi put kada se pozove funkcija
	{
		last = R;
	}

	printf("\nUnesite element u red: ");
	scanf("%d", &temp->el);

	temp->next = NULL;//mislim da bi mozda moglo i R->next
	last->next = temp;
	last = temp;//last je uvik zadnji
}

PosR dequeue(PosR R)
{
	PosR temp = (PosR)malloc(sizeof(Red));

	if (NULL == R->next)
	{
		printf("\nRed je prazan");
		return NULL;
	}
	else
	{
		temp = R->next;
		R->next = temp->next;//odnosno NULL
		return temp;
	}
}

void ispisR(PosR R)
{
	if (NULL == R->next)
	{
		printf("\nRed je prazan");
	}
	else
	{
		R = R->next;
		while (NULL != R->next)//mozda se ovo moze bolje izvrsiti sa do while
		{
			printf("\n%d", R->el);
			R = R->next;
		}
		printf("\n%d", R->el);
	}
}


