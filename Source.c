#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element{
int numer;
int przebieg;
int KM;
char *nazwa;
char *rejestracja;
char *model;
char *wlasciciel;

struct element *nast;
struct element *poprz;
};
struct element *pierwszy=NULL;
struct element *ostatni=NULL;
int dodaj(int);
void wyswietl();
void Skokowo();
void wyswietlskok();
struct element *szukaj(int);
struct element *szukajstring(char*);
void Zapis();
void gcharts();
int usun(struct element*);
void usunliste();
struct element **zamiana(struct element*);
void Sortuj(struct element*);
void Sortujstr(struct element*);
struct element ** Odczyt();

int main(){
char ks[100];
int l=1, i, j, rek, element_do_usu;

while(1){
	printf("\nMENU:\n");
	printf("1. Dodaj rekord\n");
	printf("2. Pokaz dane\n");
	printf("3. Szukaj (wyswietl jeden element)\n");
	printf("4. Zapisz do pliku txt\n");
	printf("5. Wyœwietlanie rekordow jeden po drugim (klawiszem)\n");
	printf("6. Utworzenie Google Charts\n");
	printf("7. Odczyt\n");
	printf("8. Usuwanie elementu\n");
	printf("9. Sortowanie po KM\n");  //nie dzia³a
	printf("10. Sortowanie po stringach\n");  //nie dzia³a
	printf("11. Zamiana poczatek-koniec\n");
	printf("12. Usuwanie calej listy\n");
	printf("13. Szukaj po nazwach (stringi)\n");
	printf("14. Wyswietl od konca\n");

scanf("%d", &i);
	switch (i){
case 1:
	system("cls");
	dodaj(l);
	l = l + 1;

	break;
case 2:
	system("cls");
	wyswietl();

	break;
case 3:
	system("cls");
	printf("podaj numer rekordu\n");
	scanf("%d", &rek);
	if (szukaj(rek) == 0) {
		printf("nie znaleziono\n");
		break;
	}
	else {
		printf("indeks: %d\n KM: %d\n Przebieg: %d\n Producent: %s\n Model: %s\n Rejestracja: %s\n Wlasciciel: %s\n\n", szukaj(rek)->numer, szukaj(rek)->KM, szukaj(rek)->przebieg, szukaj(rek)->nazwa, szukaj(rek)->model, szukaj(rek)->rejestracja, szukaj(rek)->wlasciciel);
		break;
	}
case 4:
	system("cls");
	Zapis();
	break;
case 5:
	system("cls");
	Skokowo();
	break;
case 6:
	system("cls");
	gcharts();
	break;
case 7:
	system("cls");
	Odczyt();
	break;
case 8:
	printf("\npodaj element do usuniêcia\n");
	scanf("%d", &element_do_usu);
	usun(szukaj(element_do_usu));
	break;
case 9:
	Sortuj(pierwszy);
	break;
case 10:
	Sortujstr(pierwszy);
	break;
case 11:
	zamiana(pierwszy);
	break;
case 12:
	usunliste();
	break;
case 13:
	system("cls");
	printf("podaj nazwê rekordu\n");
	scanf("%s", ks);
	if (szukajstring(ks) == 0)
	{
		printf("nie znaleziono\n");
		break;
	}
	else {
		printf("indeks: %d\n KM: %d\n Przebieg: %d\n Producent: %s\n Model: %s\n Rejestracja: %s\n Wlasciciel: %s\n\n", szukajstring(ks)->numer, szukajstring(ks)->KM, szukajstring(ks)->przebieg, szukajstring(ks)->nazwa, szukajstring(ks)->model, szukajstring(ks)->rejestracja, szukajstring(ks)->wlasciciel);
		break;
	}
case 14:
	system("cls");
	zamiana(pierwszy);
	wyswietl();
	zamiana(pierwszy);
	break;
}
}

return 0;
}

int dodaj(int e){

struct element *nowy;
nowy= (struct element*) malloc (sizeof(struct element));
nowy->nazwa=(char*)malloc(100*sizeof(char));
nowy->rejestracja = (char*)malloc(100 * sizeof(char));
nowy->model = (char*)malloc(100 * sizeof(char));
nowy->wlasciciel = (char*)malloc(100 * sizeof(char));


printf ("podaj liczbe koni \n");
scanf("%d", &nowy->KM);
printf("podaj przebieg \n");
scanf("%d", &nowy->przebieg);
printf ("podaj marke \n");
scanf("%s", nowy->nazwa);
printf("podaj rejestracje \n");
scanf("%s", nowy->rejestracja);
printf("podaj model \n");
scanf("%s", nowy->model);
printf("podaj wlasciciela \n");
scanf("%s", nowy->wlasciciel);

nowy->numer = e;

if (pierwszy == NULL){
nowy->nast=NULL;
nowy->poprz=NULL;
pierwszy=nowy;
ostatni=nowy;
}
else{
nowy->nast=NULL;
nowy->poprz=ostatni;
ostatni->nast=nowy;
ostatni=nowy;
}
return 0;
}
void wyswietl()
{
	struct element *tmp;
	tmp=pierwszy;

	if (tmp==NULL) printf("lista nie istnieje\n");

	while(tmp!=NULL){
	printf("indeks: %d\n KM: %d\n Przebieg: %d\n Producent: %s\n Model: %s\n Rejestracja: %s\n Wlasciciel: %s\n\n", tmp->numer, tmp->KM, tmp->przebieg, tmp->nazwa, tmp->model, tmp->rejestracja, tmp->wlasciciel);
	tmp=tmp->nast;
	}


}
struct element *szukaj(int szukana){
	struct element *tmp;
	tmp=pierwszy;
	while (tmp != NULL) {
		if (tmp->numer == szukana)
			return tmp;
		else tmp = tmp->nast;
		if (tmp == NULL) {

			return 0;
		}
	}
	return NULL;
}
struct element *szukajstring(char *szuk) {
	struct element *tmp;
	tmp = pierwszy;


	while (tmp != NULL) {
		if (*tmp->nazwa == *szuk)
			return tmp;
		else tmp = tmp->nast;
		{
			if (tmp == NULL) {

				return 0;
			}
		}
	}

	return NULL;
}
void Skokowo()
{
	struct element *tmp;
	char f;
	pierwszy->poprz = NULL;
	tmp = pierwszy;
	printf("indeks: %d\n KM: %d\n Przebieg: %d\n Producent: %s\n Model: %s\n Rejestracja: %s\n Wlasciciel: %s\n\n", tmp->numer, tmp->KM, tmp->przebieg, tmp->nazwa, tmp->model, tmp->rejestracja, tmp->wlasciciel);
	if (tmp == NULL) printf("lista nie istnieje\n");
	while (tmp != ostatni) {
		while (tmp != NULL) {

			printf("nastepny n, poprzedni p\n");
			f = _getch();
			if (f == 'n') {
				if (tmp == ostatni) {
					printf("koniec listy\n");
					break;
				}
				tmp = tmp->nast;
				printf("indeks: %d\n KM: %d\n Przebieg: %d\n Producent: %s\n Model: %s\n Rejestracja: %s\n Wlasciciel: %s\n\n", tmp->numer, tmp->KM, tmp->przebieg, tmp->nazwa, tmp->model, tmp->rejestracja, tmp->wlasciciel);

			}
			else {
				if (f == 'p') {
					if (tmp == pierwszy) {
						printf("poczatek listy\n");
						break;
					}
					tmp = tmp->poprz;
					printf("indeks: %d\n KM: %d\n Przebieg: %d\n Producent: %s\n Model: %s\n Rejestracja: %s\n Wlasciciel: %s\n\n", tmp->numer, tmp->KM, tmp->przebieg, tmp->nazwa, tmp->model, tmp->rejestracja, tmp->wlasciciel);
				}
				else { printf("uzyj wlasciwego przycisku\n");
				f = _getch();
				}
			}
		}
	}
}
void Zapis() {
	int i, j;
	char nazwa[100];
	FILE *wsk;

	printf("podaj nazwe pliku jaki chcesz utworzyc z rozszrzeniem txt\n");
	scanf("%s", nazwa);
	wsk = fopen(nazwa, "w");
	struct element *tmp;
	tmp=pierwszy;

	if (tmp==NULL) fprintf(wsk, "lista nie istnieje\n");

	while(tmp!=NULL){
	//fprintf(wsk, "%d   %s\n", tmp->numer, &tmp->nazwa);

	fprintf(wsk, "%d\n %d\n %d\n %s\n %s\n %s\n %s\n\n", tmp->numer, tmp->KM, tmp->przebieg, tmp->nazwa, tmp->model, tmp->rejestracja, tmp->wlasciciel);
	tmp=tmp->nast;
	}

	fclose(wsk);
	printf("zapisano do pliku o nazwie %s", nazwa);
}
void gcharts() {
	FILE *Wsk_do_pliku;
	int i;
	struct element *tmp;
	tmp = pierwszy;
	if (tmp == NULL) {
		printf("baza danych nie istnieje\n");
		return; }
	Wsk_do_pliku = fopen("gcharts.html", "w");


	fprintf(Wsk_do_pliku, "<html>\n");
	fprintf(Wsk_do_pliku, "<head>\n");
	fprintf(Wsk_do_pliku, "<script type = \"text/javascript\" src = \"https://www.gstatic.com/charts/loader.js\"></script>\n");
	fprintf(Wsk_do_pliku, "<script type = \"text/javascript\">\n");
	fprintf(Wsk_do_pliku, "google.charts.load('current', { 'packages':['table'] });\n");
	fprintf(Wsk_do_pliku, "google.charts.setOnLoadCallback(drawTable);\n");
	fprintf(Wsk_do_pliku, "function drawTable() {\n");
	fprintf(Wsk_do_pliku, "var data = new google.visualization.DataTable();\n");
	fprintf(Wsk_do_pliku, "data.addColumn('string', 'Rejestracja');\n");
	fprintf(Wsk_do_pliku, "data.addColumn('string', 'Marka');\n");
	fprintf(Wsk_do_pliku, "data.addColumn('string', 'Model');\n");
	fprintf(Wsk_do_pliku, "data.addColumn('string', 'W³aœciciel');\n");
	fprintf(Wsk_do_pliku, "data.addColumn('number', 'Moc <KM>');\n");
	fprintf(Wsk_do_pliku, "data.addColumn('number', 'Przebieg');\n");
	fprintf(Wsk_do_pliku, "data.addRows([\n");




				while (tmp != NULL) {

					fprintf(Wsk_do_pliku, "['%s',   '%s',   '%s',   '%s', {v: %d}, {v: %d}],\n", tmp->rejestracja, tmp->nazwa, tmp->model, tmp->wlasciciel, tmp->KM, tmp->przebieg);

				tmp = tmp->nast;
				}


	fprintf(Wsk_do_pliku, "]);\n");

	fprintf(Wsk_do_pliku, "var table = new google.visualization.Table(document.getElementById('table_div'));\n");

	fprintf(Wsk_do_pliku, "table.draw(data, { showRowNumber: true, width : '1000%', height : '200%' });\n");
	fprintf(Wsk_do_pliku, "}\n");
	fprintf(Wsk_do_pliku, "</script>\n");
	fprintf(Wsk_do_pliku, "</head>\n");
	fprintf(Wsk_do_pliku, "<body>\n");
	fprintf(Wsk_do_pliku, "<div id = \"table_div\"></div>\n");
	fprintf(Wsk_do_pliku, "</body>\n");
	fprintf(Wsk_do_pliku, "</html>\n");

	fclose(Wsk_do_pliku);
	printf("utworzono tabele Google Charts");
}
struct element **Odczyt() {
	char znak;
	char NazwaOdcz[100];
	int i, h=0, g, f_wyb;
	struct element *nowy;

	printf("podaj nazwe pliku z rozszerzeniem .txt\n");
	scanf("%s", NazwaOdcz);
	FILE *plik;
	plik = fopen(NazwaOdcz, "r");

	if (plik == NULL)
	{
		printf("Blad otwarcia pliku: %s\n", NazwaOdcz);
		return;
	}
	 //alokacja pamiêci

	nowy = (struct element*) malloc(sizeof(struct element));
	nowy->nazwa = (char*)malloc(100 * sizeof(char));
	nowy->rejestracja = (char*)malloc(100 * sizeof(char));
	nowy->model = (char*)malloc(100 * sizeof(char));
	nowy->wlasciciel = (char*)malloc(100 * sizeof(char));

	nowy->nast = NULL;
	nowy->poprz = NULL;

	fscanf(plik, "%d\n", &nowy->numer);
	fscanf(plik, "%d\n", &nowy->KM);
	fscanf(plik, "%d\n", &nowy->przebieg);
	fscanf(plik, "%s\n", nowy->nazwa);
	fscanf(plik, "%s\n", nowy->rejestracja);
	fscanf(plik, "%s\n", nowy->model);
	fscanf(plik, "%s\n", nowy->wlasciciel);
	pierwszy = nowy;
	ostatni = nowy;


while (!feof(plik)) {
	nowy = (struct element*) malloc(sizeof(struct element));
	nowy->nazwa = (char*)malloc(100 * sizeof(char));
	nowy->rejestracja = (char*)malloc(100 * sizeof(char));
	nowy->model = (char*)malloc(100 * sizeof(char));
	nowy->wlasciciel = (char*)malloc(100 * sizeof(char));

	fscanf(plik, "%d\n", &nowy->numer);
	fscanf(plik, "%d\n", &nowy->KM);
	fscanf(plik, "%d\n", &nowy->przebieg);
	fscanf(plik, "%s\n", nowy->nazwa);
	fscanf(plik, "%s\n", nowy->rejestracja);
	fscanf(plik, "%s\n", nowy->model);
	fscanf(plik, "%s\n", nowy->wlasciciel);

	nowy->nast = NULL;
	nowy->poprz = ostatni;
	ostatni->nast = nowy;
	ostatni = nowy;
	}

	fclose(plik);
	return;
}
struct element **zamiana(struct element *dozamiany) {


	struct element *temp;
	temp = (struct element*) malloc(sizeof(struct element));
	temp->nazwa = (char*)malloc(100 * sizeof(char));
	temp->rejestracja = (char*)malloc(100 * sizeof(char));
	temp->model = (char*)malloc(100 * sizeof(char));
	temp->wlasciciel = (char*)malloc(100 * sizeof(char));

	struct element *nowypocz = NULL;
	nowypocz = (struct element*) malloc(sizeof(struct element));
	nowypocz->nazwa = (char*)malloc(100 * sizeof(char));
	nowypocz->rejestracja = (char*)malloc(100 * sizeof(char));
	nowypocz->model = (char*)malloc(100 * sizeof(char));
	nowypocz->wlasciciel = (char*)malloc(100 * sizeof(char));



	while (dozamiany != NULL)
	{
		temp = dozamiany->nast;
		dozamiany->nast = nowypocz;
		nowypocz = dozamiany;
		dozamiany = temp;
	}
	dozamiany = nowypocz;

temp = pierwszy;
	pierwszy = ostatni;
	ostatni = temp;
	pierwszy->poprz = NULL;
	ostatni->nast = NULL;


}
int usun(struct element *tmp)
{
	if (tmp==NULL) {
		printf("nie ma listy");
		return 0;
	}

	if ((tmp == ostatni) && (tmp == pierwszy)) {
		pierwszy = NULL;
		ostatni = NULL;
		free(tmp);
		return 0;
	}

	//usuwamy pierwszy element
	if (tmp==pierwszy){
		pierwszy=tmp->nast;
		pierwszy->poprz=NULL;

	}
	else
		if(tmp==ostatni) {
		ostatni=tmp->poprz;
		ostatni->nast=NULL;
	}
	else {
	tmp->poprz->nast=tmp->nast;
	tmp->nast->poprz=tmp->poprz;
	}


		free(tmp);

}  //ready
void usunliste() {

	do {
		usun(pierwszy);

	} while (ostatni!=NULL);
	//free(ostatni);
	//ostatni = NULL;
}
void Sortuj(struct element *poczatek)
{
	struct element *popmax, *max, *tmp, *nowypierwszy= NULL;

	if (poczatek==NULL) {
		printf("nie ma listy\n");
	}

	while(poczatek) {
		max = poczatek;
		popmax = NULL;
		tmp= poczatek;

		while(tmp->nast)
		{
			if(tmp->nast->KM > max->KM)
			{	popmax=tmp;
				max = tmp->nast;

		}
			tmp=tmp->nast;
		}
		if (popmax) popmax->nast= max;////////////////////
		else poczatek=max->nast;
		max->nast=nowypierwszy;
		nowypierwszy=max;

			}
	poczatek=nowypierwszy;
	return;
}
/////////////////////////////////////////////////////////////////////////////////
void Sortujstr(struct element *poczatek)
{
	struct element *popmax, *max, *tmp, *nowypierwszy = NULL;

	if (poczatek == NULL) {
		printf("nie ma listy\n");
	}

	while (poczatek) {
		tmp = pierwszy;
		max = pierwszy;
		popmax = NULL;


		while (tmp->nast)
		{
			switch (strcmp(tmp->wlasciciel, tmp->nast->wlasciciel)){
				case 0:

					tmp = tmp->nast;
					break;

				case -1:
					tmp->nast = popmax;
					tmp->nast = tmp;
					tmp = popmax;
					break;

				case 1:

					tmp = tmp->nast;
					break;
			}

		}
		if (popmax) popmax->nast = max->nast;
		else poczatek = max->nast;
		max->nast = nowypierwszy;
		nowypierwszy = max;
	}
	poczatek = nowypierwszy;
}
