# Tema-2-PCLP

>Task 1
Incepem prin a citi variabilele de intrare, respectiv nr de coloane si linii si cuvintele. Separam stringul ce contine cuvintele in cuvinte individuale pe care le stocam in vectorul de stringuri cuvinte_2d[][]. Initializam nr. pasului curent cu 1 si toate pozitiile matricei cu 0. Verificam fiecare cuvant, si, in functie de litera de inceput, facem operatiile corespunzatoare din cerinta, si ne mutam pozitia in matrice in mod corespunzator. La final, afisam matricea.

>Task 2
Citim stringul ce determina taskul ce trebuie efectuat. In cazul taskului 2.1, descifram stringul primit in functie de cheie cu ajutorul algoritmului, care scade valoare ASCII a cheii din fiecare caracter al codului. In cazul taskului 2.2, intai prelungim cheia primita pentru a avea aceeasi lungime cu codul, iar apoi, in mod asemenator ca in cazul taskului 2.1, descifram codul, dar de data asta cheia ia valoare caracterului corespunzator pozitiiei curente din stringul cheie_prelungita. In cazul taskului 2.3, descifram mai intai cele 2 numere stocate in stringuri folosing acelasi algoritm ca mai devreme, aducem stringurile la aceeasi lungime si in final le adunam cifra cu cifra, tinand cont de carry. La final afisam suma rezultata, stocata in tringul summa[].

>Task 3
Citim fiecare linie din textul de input si le concatenam in stringul str[]. iar apoi eliminam punctuatia. Impartim stringul in cuvinte individuale pe care le stocam in vectorul de stringuri cuvinte_2d[][]. Apoi, in mod succesiv, concatenam 2 cate 2 cuvinte, si stocam aceste grupuri in vectorul de stringuri tablou_ngrame. Ii asociem acestuia vectorul tablou_aparitii_ngrame[], in care numaram de cate ori apare gruparea respectiva de 2 cuvinte de pe pozitia corespunzatoare. Apoi verificam daca se repeta pe parcursul tabloului grupari de 2 cuvinte identice, iar daca da eliminam duplicatele din tablou si incrementam nr de aparitii. In final, afisam in paralele cele 2 tablouri.
