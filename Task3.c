#include "utils.h"
#define TEXT_MAX 10000
// functie pentru a elimina caractere dintr-un string
void removeChar(char* str, char garbage)
{
	char* src, * dst;
	for (src = dst = str; *src != '\0'; src++) {
		*dst = *src;
		if (*dst != garbage) dst++;
	}
	*dst = '\0';
}
void SolveTask3()
{
	char str[TEXT_MAX];
	char str_temp[TEXT_MAX];
	char tablou_ngrame[1000][50];
	// citim fiecare linie din text si o concatenam in str
	while ((fgets(str_temp, TEXT_MAX, stdin)) != NULL)
	{
		strcat(str, str_temp);
	}
	int i = 0;
	char c1 = '\n';
	char c2 = '\'';
	// eliminam punctuatia
	while (str[i] != '\0')
	{
		if (str[i] == c1)
		{
			str[i] = ' ';
			i--;
		}
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == c2)
		{
			str[i] = '’';
			i--;
		}
		i++;
	}
	removeChar(str, '.');
	removeChar(str, '\r');
	removeChar(str, ',');
	removeChar(str, ':');
	removeChar(str, ';');
	removeChar(str, '!');
	removeChar(str, '?');
	for (int i = 0; i < strlen(str); i++)
	{
		if (((str[i] >= 'a') && (str[i] <= 'z') && (str[i + 1] >= 'A') && (str[i + 1] <= 'Z') && (str[i + 1] != EOF)) || ((str[i] >= 'a') && (str[i] <= 'z') && (str[i + 1] == '\'') && (str[i + 2] >= 'A') && (str[i + 2] <= 'Z')))
		{
			str[(strlen(str) + 1)] = '\0';
			for (int j = strlen(str); j > i + 1; j--)
			{
				str[j] = str[j - 1];
			}
			str[i + 1] = ' ';
		}
	}
	char splitStrings[1000][50];
	int  j, cnt;
	i = 0;
	j = 0;
	cnt = 0;
	// impartim stringul in cuvinte indivudual si le stocam in vectorul de stringuri splitStrings
	for (i = 0; i <= (strlen(str)); i++) {
		// daca gasim spatiu sau NULL scriem NULL
		if (str[i] == ' ' || str[i] == '\0') {
			splitStrings[cnt][j] = '\0';
			cnt++; // numaram cate cuvinte avem in cnt
			j = 0; // trecem la urmatorul cuvant pe pozitia 0
		}
		else {
			splitStrings[cnt][j] = str[i];
			j++;
		}
	}
	// concatenam cuvintele 2 cate 2 si stocam aceste grupuri in tablout de stringuri tablou_ngrame
	for (i = 0; i < cnt - 1; i++)
	{
		strcpy(tablou_ngrame[i], splitStrings[i]);
		strcat(tablou_ngrame[i], " ");
		strcat(tablou_ngrame[i], splitStrings[i + 1]);
		strcat(tablou_ngrame[i], "\0");
	}
	// initializam tabloul tablou_apariti_ngrame cu 1
	// stocam in el nr de aparitii al fiecarui grup de 2 cuvinte
	int tablou_apariti_ngrame[1000];
	for (int i = 0; i < 1000; i++)
	{
		tablou_apariti_ngrame[i] = 1;
	}
	int cnt_gram = cnt - 1;
	// verificam daca se repeta grupuri de 2 cuvinte identice in tablou_ngrame
	for (int i = 0; i < cnt_gram - 1; i++)
	{
		for (int j = i + 1; j < cnt_gram - 2; j++)
		{
			char a[50];
			strcpy(a, tablou_ngrame[i]);
			char b[50];
			strcpy(b, tablou_ngrame[j]);
			// daca da, avansam cu o pozitie tablourile tablou_ngrame si tablou_aparitii_ngrame incepand cu pozitia curenta
			// si incrementan nr de aparitii curent
			if (strcmp(a, b) == 0)
			{
				tablou_apariti_ngrame[i]++;
				for (int k = j; k < cnt_gram - 2; k++)
				{
					strcpy(tablou_ngrame[k], tablou_ngrame[k + 1]);
					tablou_apariti_ngrame[k] = tablou_apariti_ngrame[k + 1];
				}
				// micsoram nr total de elemente in tablouri
				cnt_gram--;
			}
		}
	}
	// afisam tablourile
	printf("%d\n", (cnt_gram - 1));
	for (i = 0; i < cnt_gram - 1; i++)
	{
		printf("%s ", tablou_ngrame[i]);
		printf("%d\n", tablou_apariti_ngrame[i]);
	}
}
