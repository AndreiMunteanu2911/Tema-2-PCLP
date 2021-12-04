#include "utils.h"
#define MAX_STRING 200
int verifica_palindrom(int n)
//daca functia intoarce 0 inseamna palindrom
//daca functia intoarce 1 inseamna nu palindrom
{
	int reversed = 0, remainder, original;
	original = n;
	// reversed integer is stored in reversed variable
	while (n != 0) {
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	// palindrome if orignal and reversed are equal
	if (original == reversed)
		return 0;
	else
		return 1;
}
int verifica_prim(int n)
//daca functia intoarce 0 inseamna prim
//daca functia intoarce 1 inseamna nu prim
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
	scanf("%d %d\n", &N, &M);
	fgets(string_input, MAX_STRING, stdin);
	char cuvinte_2d[MAX_STRING][MAX_STRING];
	int j = 0, contor = 0;
	for (int i = 0; i <= (strlen(string_input)); i++)
	{
		// if space or NULL found, assign NULL into newString[ctr]
		if (string_input[i] == ' ' || string_input[i] == '\0')
		{
			cuvinte_2d[contor][j] = '\0';
			contor++;  //for next word
			j = 0;    //for next word, init index to 0
		}
		else
		{
			cuvinte_2d[contor][j] = string_input[i];
			j++;
		}
	}
	int nr_pas = 1;
	for (int i = 0; i < MAX_STRING; i++)
	{
		for (int j = 0; j < MAX_STRING; j++)
		{
			matrice[i][j] = 0;
		}
	}
	matrice[0][0] = nr_pas;
	int linie_curenta = 0;
	int coloana_curenta = 0;
	for (int i = 0; i < contor; i++)
	{
		switch (cuvinte_2d[i][0])
		{
		case 'a':
		{
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
			int x = cuvinte_2d[i][(strlen(cuvinte_2d[i])) - 2] - '0';
			int z = cuvinte_2d[i][(strlen(cuvinte_2d[i])) - 1] - '0';
			x = x * 10 + z;
			int k = 0;
			for (int c = 1; c < strlen(cuvinte_2d[i]); c++)
			{
				k = k * 10;
				int t = cuvinte_2d[i][c] - '0';
				k = k + t;
			}
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
			int n = cuvinte_2d[i][1] - '0';
			int k = cuvinte_2d[i][2] - '0';
			int S = 0;
			int g = 0;
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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}