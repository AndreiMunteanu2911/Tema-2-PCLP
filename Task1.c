#include "utils.h"
#define MAX_STRING 200
int verifica_palindrom(int n)
// functie pentru a verifica daca n e palindrom
// daca functia intoarce 0 inseamna palindrom
// daca functia intoarce 1 inseamna nu palindrom
{
	int reversed = 0, remainder, original;
	original = n;
	// inversam numarul original si il stocam in reversed
	while (n != 0) {
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	// verificam daca original si reversed sunt egale
	if (original == reversed)
		return 0;
	else
		return 1;
}
int verifica_prim(int n)
// functie petnntru a verifica daca n e prim
// daca functia intoarce 0 inseamna prim
// daca functia intoarce 1 inseamna nu prim
{
	int i;
	for (i = 2; i <= n / 2; i++)
	{
		if (n % i != 0)
			continue;
		else
			return 1;
	}
	return 0;
}
void SolveTask1() {
	int N = 0, M = 0;
	int matrice[MAX_STRING][MAX_STRING];
	char string_input[MAX_STRING];
	// citim nr de linii si coloane
	scanf("%d %d\n", &N, &M);
	// citim stringul de cuvinte
	fgets(string_input, MAX_STRING, stdin);
	char cuvinte_2d[MAX_STRING][MAX_STRING];
	int j = 0, contor = 0;
	// in acest for separam stringul de cuvinte intr-un vector de stringuri numit cuvinte_2d
	// pe fiecare pozitie a acestuia se va afla un alt cuvant
	// numaram cate sunt in contor
	for (int i = 0; i <= (strlen(string_input)); i++)
	{
		// daca gasim NULL sau spatiu, scriem NULL la finalul cuvantului din vector
		if (string_input[i] == ' ' || string_input[i] == '\0')
		{
			cuvinte_2d[contor][j] = '\0';
			contor++;  // marim nr de cuvinte
			j = 0;    // trecem la urmatorul cuvant
		}
		else
		{
			cuvinte_2d[contor][j] = string_input[i];
			j++;
		}
	}
	// initializam nr pasului in matrice la care suntem cu 1
	int nr_pas = 1;
	// initializa toate pozitiile matricei cu 0
	for (int i = 0; i < MAX_STRING; i++)
	{
		for (int j = 0; j < MAX_STRING; j++)
		{
			matrice[i][j] = 0;
		}
	}
	matrice[0][0] = nr_pas;
	// tinem minte in ce pozitie in matrice suntem cu variabilele linie_curenta si coloana_curenta
	int linie_curenta = 0;
	int coloana_curenta = 0;
	for (int i = 0; i < contor; i++)
	{
		// verificam prima litera a fiecarui cuvant
		switch (cuvinte_2d[i][0])
		{
		case 'a':
		{
			// comparam nr din cuvant pentru a-l afla pe cel maxim si stocam indexul sau in variabila posmax
			char max = '1';
			int posmax = 0;
			for (int k = 1; k <= 4; k++)
			{
				if (max < cuvinte_2d[i][k])
				{
					posmax = k;
					max = cuvinte_2d[i][k];
				}
			}
			switch (posmax)
			{
				// ne mutam pozitia in matrice in functie de posmax
			case 1:
			{
				//dreapta
				nr_pas++;
				coloana_curenta++;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			case 2:
			{
				//sus
				nr_pas++;
				linie_curenta = linie_curenta - 1;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			case 3:
			{
				//stanga
				nr_pas++;
				coloana_curenta = coloana_curenta - 1;;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			case 4:
			{
				//jos
				nr_pas++;
				linie_curenta = linie_curenta + 1;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			}
			break;
		}
		case 'b':
		{
			// stocam x intr-o variabila int
			int x = cuvinte_2d[i][(strlen(cuvinte_2d[i])) - 2] - '0';
			int z = cuvinte_2d[i][(strlen(cuvinte_2d[i])) - 1] - '0';
			x = x * 10 + z;
			int k = 0;
			// stocam k intr-o variabila int
			for (int c = 1; c < strlen(cuvinte_2d[i]); c++)
			{
				k = k * 10;
				int t = cuvinte_2d[i][c] - '0';
				k = k + t;
			}
			// in functie de caracteristicile de palindrom, respectiv nr prim ale lui k si x, ne mutam pozitia in mod corespunzator
			if ((verifica_palindrom(k) == 0) && (verifica_prim(x) == 0))
			{
				//stanga
				nr_pas++;
				coloana_curenta = coloana_curenta - 1;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
			}
			if ((verifica_palindrom(k) == 0) && (verifica_prim(x) == 1))
			{
				//dreapta
				nr_pas++;
				coloana_curenta++;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
			}
			if ((verifica_palindrom(k) == 1) && (verifica_prim(x) == 0))
			{
				//sus
				nr_pas++;
				linie_curenta = linie_curenta - 1;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
			}
			if ((verifica_palindrom(k) == 1) && (verifica_prim(x) == 1))
			{
				//jos
				nr_pas++;
				linie_curenta = linie_curenta + 1;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
			}
			break;
		}
		case 'c':
		{
			// stocam x si k in variabile de tip int
			int n = cuvinte_2d[i][1] - '0';
			int k = cuvinte_2d[i][2] - '0';
			int S = 0;
			int g = 0;
			// facem suma ceruta
			for (int o = 1; o <= k; o++)
			{
				int h = cuvinte_2d[i][3 + g] - '0';
				S = S + h;
				g = g + k;
				while (g > n - 1)
				{
					g = g - n;
				}
			}
			// aflam restul sumei impartita la 4
			switch (S % 4)
			{
			case 0:
			{
				//stanga
				nr_pas++;
				coloana_curenta = coloana_curenta - 1;;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			case 1:
			{
				//sus
				nr_pas++;
				linie_curenta = linie_curenta - 1;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			case 2:
			{
				//dreapta
				nr_pas++;
				coloana_curenta++;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			case 3:
			{
				//jos
				nr_pas++;
				linie_curenta = linie_curenta + 1;
				matrice[linie_curenta][coloana_curenta] = nr_pas;
				break;
			}
			}
			break;
		}
		}
	}
	// afisam matricea
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}
