#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ZAZNAM// vytvorenie struktury
 {
 char kategoria[51];
 char znacka[51];
 char predajca[101];
 int cena;
 int rok_vyroby;
 char stav[201];
 struct ZAZNAM *dalsi;
} ZAZNAM; //struktura s nazvom zaznam

//*************************************************************

int pocet_zaznamov(FILE *subor) // funkcia ktora zistuje pocet riadkov vo vstupnom subore
{
int c;
int zaznamy= 0;

subor = fopen("auta.txt", "r"); //otvori subor

while ((c = fgetc(subor)) != EOF)
  {
    if (c == '$')  zaznamy++; //pri kazdom konci riadku zvacsi pocet riadkov

  }

return zaznamy;
}

//**************************************************************//

void vytvorit(FILE *subor, ZAZNAM **prvy, int *p)
{
ZAZNAM *aktualny = NULL;
ZAZNAM *temp = NULL;
int i,val;
char buff[201];
subor = fopen("auta.txt", "r"); //otvori subor
int pocet = pocet_zaznamov(subor);
*p= pocet;
if (subor == NULL)
    printf("Zaznamy neboli nacitane\n");
  else
    printf("Nacitalo sa %d zaznamov\n",pocet);
if (*prvy != NULL) free(*prvy);
*prvy = (ZAZNAM*) malloc(sizeof(ZAZNAM));
aktualny = (ZAZNAM*) malloc(sizeof(ZAZNAM));
temp = (ZAZNAM*) malloc(sizeof(ZAZNAM));
//aktualny = NULL;
//prvy = NULL;
 for(i=0; i<*p;i++)
 {
   temp = (ZAZNAM*) malloc(sizeof(ZAZNAM));
   fgets(buff, 51, (FILE* )subor);
   fgets(buff, 51, (FILE* )subor);
   buff[strlen(buff)-1]='\0';
   strncpy(temp->kategoria, buff,50);
   fgets(buff, 51, (FILE* )subor);
   buff[strlen(buff)-1]='\0';
   strncpy(temp->znacka, buff,50);
   fgets(buff, 101, (FILE* )subor);
   buff[strlen(buff)-1]='\0';
   strncpy(temp->predajca, buff,100);
   fgets(buff, 51, (FILE* )subor);
   val = atoi(buff);
   temp->cena = val;
   fgets(buff, 51, (FILE* )subor);
   val = atoi(buff);
   temp->rok_vyroby = val;
   fgets(buff, 201, (FILE* )subor);
   buff[strlen(buff)-1]='\0';
   strncpy(temp->stav, buff,200);
   //temp->dalsi = NULL;
   if (prvy == NULL)
   {
     *prvy = temp;
   }
   else
    {
      aktualny = *prvy;
      while(aktualny->dalsi != NULL)
          aktualny = aktualny->dalsi;
      aktualny->dalsi = temp;
    }
 }
aktualny = *prvy;
i=1;
 while (aktualny != NULL)
    {
      printf("%d\n",i++);
      printf("kategoria: %s\n",aktualny->kategoria);
      printf("znacka: %s\n",aktualny->znacka);
      printf("predajca: %s\n",aktualny->predajca);
      printf("cena: %d\n",aktualny->cena);
      printf("rok_vyroby: %d\n",aktualny->rok_vyroby);
      printf("stav_vozidla: %s\n",aktualny->stav);
      aktualny = aktualny->dalsi;
    }
}

//*******************************************************************//

void vypis(ZAZNAM **prvy,int *p)
{
  int i;
  ZAZNAM *aktualny;
  aktualny = (ZAZNAM*) malloc(sizeof(ZAZNAM));
  aktualny = *prvy;
  i=1;
   while (aktualny != NULL)
      {
        printf("%d\n",i++);
        printf("kategoria: %s\n",aktualny->kategoria);
        printf("znacka: %s\n",aktualny->znacka);
        printf("predajca: %s\n",aktualny->predajca);
        printf("cena: %d\n",aktualny->cena);
        printf("rok_vyroby: %d\n",aktualny->rok_vyroby);
        printf("stav_vozidla: %s\n",aktualny->stav);
        aktualny = aktualny->dalsi;
      }

}

//*******************************************************************//

int main() {
  ZAZNAM *prvy = NULL;
  char vyber;
  int *p,pocet;
  FILE *subor = NULL;
  p = &pocet;
  vytvorit(subor,&prvy, p);
  free(prvy);
  //vypis(&prvy,p);
  /*while(1) //nekonecny cyklus, ukonci sa zadanim K
  {
vyber=getchar();//nacitanie volby funkcie od uzivatela
//getchar();
  if (vyber == 'n') alokacia(&p_s,subor,p);

  if (vyber == 'v') vypis(&p_s,p);

  if (vyber == 'p') odnaty_vp(&p_s,p);

  if (vyber == 'z') odmeny(&p_s,p);

  if (vyber == 'h') palindromy(&p_s,p);

  if (vyber == 'a') vlozit(&p_s,p);

  if (vyber == 'k') koniec(&p_s,subor);


}*/
  return 0;
}
