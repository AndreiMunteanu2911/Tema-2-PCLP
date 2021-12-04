#include "utils.h"
#define MAX_STRING 101
#define MAX_MARE 1001
void SolveTask2()
{
	char metoda_criptaj[MAX_STRING];
	fgets(metoda_criptaj, MAX_STRING, stdin);
	if (strcmp(metoda_criptaj, "caesar\n") == 0)
	{
		int cheie;
		char ch;
		char cod[MAX_STRING];
		scanf("%d\n", &cheie);
		fgets(cod, MAX_STRING, stdin);
		for (int i = 0; cod[i] != '\0'; i++)
		{
			ch = cod[i];
			if (ch >= 'a' && ch <= 'z')
			{
				ch = ch - cheie;
				while (ch < 'a')
				{
					ch = ch + 'z' - 'a' + 1;
				}
				cod[i] = ch;
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				ch = ch - cheie;
				while (ch < 'A') {
					ch = ch + 'Z' - 'A' + 1;
				}
				cod[i] = ch;
			}
			if (ch >= '0' && ch <= '9')
			{
				ch = ch - cheie;
				while (ch < '0')
				{
					ch = ch + '9' - '0' + 1;
				}
				cod[i] = ch;
			}
		}
		printf("%s", cod);
	}
	if (strcmp(metoda_criptaj, "vigenere\n") == 0)
	{
		char cheie_vig[MAX_MARE];
		char cod[MAX_MARE];
		char cheie_prelungita[MAX_MARE] = "";
		fgets(cheie_vig, MAX_MARE, stdin);
		fgets(cod, MAX_MARE, stdin);
		int ch;
		cheie_vig[strlen(cheie_vig) - 1] = '\0';
		for (int i = 1; i <= ((strlen(cod) / strlen(cheie_vig) + 1)); i++)
		{
			strcat(cheie_prelungita, cheie_vig);
		}
		for (int i = 0; cod[i] != '\0'; i++)
		{
			ch = cod[i];
			int cheie = cheie_prelungita[i] - 65;
			if (ch >= 'a' && ch <= 'z')
			{
				ch = ch - cheie;
				while (ch < 'a')
				{
					ch = ch + 'z' - 'a' + 1;
				}
				cod[i] = ch;
			}
			else
				if (ch >= 'A' && ch <= 'Z')
				{
					ch = ch - cheie;
					while (ch < 'A')
					{
						ch = ch + 'Z' - 'A' + 1;
					}
					cod[i] = ch;
				}
			if (ch >= '0' && ch <= '9')
			{
				ch = ch - cheie;
				while (ch < '0')
				{
					ch = ch + '9' - '0' + 1;
				}
				cod[i] = ch;
			}
		}
		printf("%s", cod);
	}
	if (strcmp(metoda_criptaj, "addition\n") == 0)
	{
		int cheie = 0;
		char ch;
		char cod1[MAX_MARE], cod2[MAX_MARE];
		scanf("%d\n", &cheie);
		//fscanf(stdin, "%s", cod1);
		//fscanf(stdin, "%s", cod2);
		//printf("%s\n%s\n", cod1, cod2);
		//getline(&cod1, MAX_MARE, stdin);
		//getline(&cod1, MAX_MARE, stdin);
		fgets(cod1, MAX_MARE, stdin);
		fgets(cod2, MAX_MARE, stdin);
		strcat (cod2, "\n");
		for (int i = 0; cod1[i] != '\0'; i++)
		{
			ch = cod1[i];
			if (ch >= 'a' && ch <= 'z')
			{
				ch = ch - cheie;
				if (ch < 'a')
				{
					ch = ch + 'z' - 'a' + 1;
				}
				cod1[i] = ch;
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				ch = ch - cheie;
				if (ch < 'A') {
					ch = ch + 'Z' - 'A' + 1;
				}
				cod1[i] = ch;
			}
			if (ch >= '0' && ch <= '9')
			{
				ch = ch - cheie;
				if (ch < '0')
				{
					ch = ch + '9' - '0' + 1;
				}
				cod1[i] = ch;
			}
		}
		for (int i = 0; cod2[i] != '\0'; i++)
		{
			ch = cod2[i];
			if (ch >= 'a' && ch <= 'z')
			{
				ch = ch - cheie;
				if (ch < 'a')
				{
					ch = ch + 'z' - 'a' + 1;
				}
				cod2[i] = ch;
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				ch = ch - cheie;
				if (ch < 'A') {
					ch = ch + 'Z' - 'A' + 1;
				}
				cod2[i] = ch;
			}
			if (ch >= '0' && ch <= '9')
			{
				ch = ch - cheie;
				if (ch < '0')
				{
					ch = ch + '9' - '0' + 1;
				}
				cod2[i] = ch;
			}
		}
		char cod_temp[MAX_MARE];
		if (strlen(cod1) > strlen(cod2))
		{
			int dif = strlen(cod1) - strlen(cod2);
			for (int i = 0; i < dif; i++)
			{
				cod_temp[i] = '0';
			}
			cod_temp[dif] = '\0';
			strcat(cod_temp, cod2);
			strcpy(cod2, cod_temp);
		}
		else
		{
			if (strlen(cod2) > strlen(cod1))
			{
				int dif = strlen(cod2) - strlen(cod1);
				for (int i = 0; i < dif; i++)
				{
					cod_temp[i] = '0';
				}
				cod_temp[dif] = '\0';
				strcat(cod_temp, cod1);
				strcpy(cod1, cod_temp);
			}
		}
		int lungime_finala = strlen(cod1);
		cod1[(strlen(cod1) + 1)] = '\0';
		cod2[(strlen(cod2) + 1)] = '\0';
		for (int i = 0; i < lungime_finala; i++)
		{
			cod1[lungime_finala - i] = cod1[lungime_finala - i - 1];
			cod2[lungime_finala - i] = cod2[lungime_finala - i - 1];
		}
		cod1[0] = '0';
		cod2[0] = '0';
		char suma[MAX_MARE];
		suma[strlen(cod1) - 1] = "\0";
		char s;
		char carry = '0';
		for (int i = (strlen(cod1) - 1); i >= 0; i--)
		{
			s = (carry + cod1[i] + cod2[i]) - 2 * 48;
			carry = '0';
			if (s > '9')
			{
				carry = '1';
				s = (s - (('9' + '0' - '1') - 2 * 48)) - 48 - 2;
			}
			suma[i] = s;
		}
		suma[strlen(cod1)] = '\0';
		while (suma[0] == '0')
		{
			int lungime = strlen(suma);
			for (int i = 0; i < lungime; i++)
			{
				suma[i] = suma[i + 1];
			}
			suma[lungime - 1] = '\0';
		}
		suma[strlen(suma) - 1] = '\0';
		printf("%s\n", suma);
	}
}