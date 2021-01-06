#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Déclaration des variables

//L'agent saisie le code de la carte
int code_carte(void)
{
  int code_carte;
  printf("Saisissez le code de la carte : ");
  scanf("%d", &code_carte);
  return code_carte;
}

/*
  Une série de question est proposée à l'utilisateur
  Si il répond bien, une série de questions s'enchaîne et le coffre s'ouvre
  Si il répond mal, un message d'alerte apparaît
*/
int questions(void)
{
  int questions;
  printf("\nUne série de question est demandée :\n\n");

    int question_1;
    printf("\n 1 : 5     2 : 6\n 3 : 7     4 : 8\n\nCombien y-a-t-il de cartes ? ");
    scanf("%d", &question_1);
      if(question_1 == 4)
      {
        int question_2;
        printf("\n 1 : CIA      2 : MI7\n 3 : DGSE     4 : MOSSAD\n\nQuel est le nom de votre agence ? ");
        scanf("%d", &question_2);
          if(question_2 == 2)
          {
            int question_3;
            printf("\n 1 : 156 ohms     2 : 290 ohms\n 3 : 328 ohms     4 : 237 ohms\n\nCombien de ohms vaut la résistance R5 ? ");
            scanf("%d", &question_3);
            if(question_3 == 4)
              printf("\nLe coffre s'ouvre.");
            else
              printf("\nAlerte ! Intru !\n\nUne alarme retentit...");
          }    
          else
            printf("\nAlerte ! Intru !\n\nUne alarme retentit...");
      }
      else
        printf("\nAlerte ! Intru !\n\nUne alarme retentit...");

  return questions;
}

/*
  L'utilisateur doit saisr le code complémentaire
  Si le code est bon, le coffre s'ouvre
  Sinon, un message d'alerte apparaît
*/
int code_quotidien(void)
{
  int code_quotidien;

  #define NBVAL 100
  #define NBVAL2 10

  int temp,tmp; //pour procéder à l'échange de deux valeurs

  int i=0;
  int j=1;
  int b=0;
  int tableau[NBVAL];
  srand(time(NULL));

  //initialisation du tableau avec les valeurs de 1 à 100
  for(i=0 ; i<NBVAL ; i++)
    tableau[i]=rand()%1000+1;

  for(i=0; i<NBVAL-1; i++) //tri par insertion (à bulle)
    for(j=i+1; j<NBVAL; j++)
      if(tableau[i]>tableau[j]) 
      {
        temp = tableau[i];
        tableau[i] = tableau[j];
        tableau[j] = temp;
      }

  int tableau2[NBVAL2][NBVAL2];
  int N=0;
  int F=0;
  int M=0;

  for(M=0 ; M<NBVAL2 ; M++)
    for (N=0 ; N<NBVAL2 ;N++)
    {
      tableau2[M][N]=tableau[F];
      F++;
    }

  //affichage des valeurs triées
  printf("\n\n");

  //répéter pour i:= 1 à 100
  for(i=0 ; i<NBVAL2 ; i++)
  {
    for(j=0 ; j<NBVAL2 ;j++)
      printf("%4d", tableau2[i][j]);
    printf("\n");
  }
  
  int tableau3[1][3];
  int x;
  int y;
  int r;
  int t;
  int code_complementaire;
  bool aa=false;
  i=0;
  
  while (i<1)
  {
    x = rand()%10;
    y = rand()%10;
    if (tableau3[i][1] == x)
      if (tableau3[i][2]==y)
        aa=true;

    if (aa==false)
    {
      tableau3[i][0] = x;
      tableau3[i][1] = y;
      tableau3[i][2] = tableau2[x][y];
      i++;
    }
  }

  for(i=0; i<1; i++)
    for(j=i+1; j<1; j++)
      if(tableau3[i][2]>tableau3[j][2])
      {
        tmp = tableau3[i][2];
        tableau3[i][2] = tableau3[j][2];
        tableau3[j][2] = tmp;
      }
  
  for (t=0; t<1; t++)
    for (r=0; r<3; r++)
      code_complementaire = tableau3[t][r];
  printf("\n\n\n");
  
  printf("Coordonnées :\n");
  for (t=0; t<1; t++)
    for (r=0; r<2; r++)
      printf("%4d", tableau3[t][r]);
    printf("\n\n");

  int nombre;
  int d;
  bool ab=true;
  printf("Entrez le code complémentaire :\n");
  for (d=0; d<1; d++)
  {
    printf("%4d", tableau3[d][0]);
    printf("%4d   ", tableau3[d][1]);
    scanf("%d", &nombre);
    if(nombre != code_complementaire)
      printf("\nAlerte ! Intru !\n\nUne alarme retentit...");
    else
      printf("\nLe coffre s'ouvre.");
  }
  return  code_quotidien;
}

int code_quotidien_et_serie_questions(void)
{
  int code_quotidien;

  #define NBVAL 100
  #define NBVAL2 10

  int temp,tmp; //pour procéder à l'échange de deux valeurs

  int i=0;
  int j=1;
  int b=0;
  int tableau[NBVAL];
  srand(time(NULL));

  //initialisation du tableau avec les valeurs de 1 à 100
  for(i=0 ; i<NBVAL ; i++)
    tableau[i]=rand()%1000+1;

  for(i=0; i<NBVAL-1; i++) //tri par insertion
    for(j=i+1; j<NBVAL; j++)
      if(tableau[i]>tableau[j]) 
      {
        temp = tableau[i];
        tableau[i] = tableau[j];
        tableau[j] = temp;
      }

  int tableau2[NBVAL2][NBVAL2];
  int N=0;
  int F=0;
  int M=0;

  for(M=0 ; M<NBVAL2 ; M++)
    for (N=0 ; N<NBVAL2 ;N++)
    {
      tableau2[M][N]=tableau[F];
      F++;
    }

  //affichage des valeurs triées
  printf("\n\n");

  //répéter pour i:= 1 à 100
  for(i=0 ; i<NBVAL2 ; i++)
  {
    for(j=0 ; j<NBVAL2 ;j++)
      printf("%4d", tableau2[i][j]);
  printf("\n");
  }
  
  int tableau3[1][3];
  int x;
  int y;
  int r;
  int t;
  int code_complementaire;
  bool  aa=false;
  i=0;
  while (i<1)
  {
    x = rand()%10;
    y = rand()%10;
    if (tableau3[i][1] == x)
      if (tableau3[i][2]==y)
        aa=true;

    if (aa==false)
    {
      tableau3[i][0] = x;
      tableau3[i][1] = y;
      tableau3[i][2] = tableau2[x][y];
      i++;
    }
  }

  for(i=0; i<1; i++)
    for(j=i+1; j<1; j++)
      if(tableau3[i][2]>tableau3[j][2]) 
      {
        tmp = tableau3[i][2];
        tableau3[i][2] = tableau3[j][2];
        tableau3[j][2] = tmp;
      }

  for (t=0; t<1; t++)
    for (r=0; r<3; r++)
      code_complementaire = tableau3[t][r];
  printf("\n\n\n");

  printf("Coordonnées :\n");
  for (t=0; t<1; t++)
    for (r=0; r<2; r++)
      printf("%4d", tableau3[t][r]);
  printf("\n\n");

  int nombre;
  int d;
  bool ab=true;
  printf("Entrez le code complémentaire :\n");
  for (d=0; d<1; d++)
  {
    printf("%4d", tableau3[d][0]);
    printf("%4d   ", tableau3[d][1]);
    scanf("%d", &nombre);
    if(nombre != code_complementaire)
      printf("\nAlerte ! Intru !\n\nUne alarme retentit...");
    else
    {
    int questions;
    printf("\nVeuillez répondre à cette série de question :\n\n");

    int question_1;
    printf("\n 1 : 5     2 : 6\n 3 : 7     4 : 8\n\nCombien y-a-t-il de cartes ? ");
    scanf("%d", &question_1);
      if(question_1 == 4)
      {
        int question_2;
        printf("\n 1 : CIA      2 : MI7\n 3 : DGSE     4 : MOSSAD\n\nQuel est le nom de votre agence ? ");
        scanf("%d", &question_2);
          if(question_2 == 2)
          {
            int question_3;
            printf("\n 1 : 156 ohms     2 : 290 ohms\n 3 : 328 ohms     4 : 237 ohms\n\nCombien de ohms vaut la résistance R5 ? ");
            scanf("%d", &question_3);
              if(question_3 == 4)
                printf("\nLe coffre s'ouvre.");
              else
                printf("\nAlerte ! Intru !\n\nUne alarme retentit...");
          }    
          else
            printf("\nAlerte ! Intru !\n\nUne alarme retentit...");
      }
      else
        printf("\nAlerte ! Intru !\n\nUne alarme retentit...");
  }
  }
  return  0;
}


//L'agent insère la carte
int main(void)
{
  int saisie_code;
  saisie_code = code_carte();
  

    //Carte 0
    //La saisie du code de la carte suffit pour ouvrir le coffre
    if(saisie_code == 0000)
      printf("\nLe coffre s'ouvre.");


    //Carte 1
    if(saisie_code == 1111)
    {
      int serie_de_questions;
      serie_de_questions = questions();
    }


    //Carte 2
    if (saisie_code == 2222)
    {
      int code_supplementaire;
      code_supplementaire = code_quotidien();
    }


    //Carte 3
    if(saisie_code == 3333)
    {
      int code_supplementaire_et_questions;
      code_supplementaire_et_questions = code_quotidien_et_serie_questions();
    }


    //Carte 4
    if(saisie_code == 4444)
    {
      /*
        L'utilisateur doit vérifier son identité à l'aide d'un scan digital
        Si l'identité est vérifiée, le coffre s'ouvre
        Sinon, un message d'alerte apparaît
      */
      printf("\nScan digital en cours...\n");
      sleep(2); //Arrête le programme 2 secondes
      printf("\nLe coffre s'ouvre.");
    }


    //Carte 5
    if(saisie_code == 5555)
    {
      /*
        L'utilisateur doit vérifier son identité à l'aide d'un scan digital
        Si l'identité est vérifiée, une série de questions apparaît
        Sinon, un message d'alerte apparaît
      */
      printf("\nScan digital en cours...\n");
      sleep(2); //Arrête le programme 2 secondes

      int serie_de_questions;
      serie_de_questions = questions();
    }


    //Carte 6
    if(saisie_code == 6666)
    {
      /*
        L'utilisateur doit vérifier son identité à l'aide d'un scan digital
        Si l'identité est vérifiée, l'utilisateur doit saisir le code complémentaire
        Sinon, un message d'alerte apparaît
      */
      printf("\nScan digital en cours...\n");
      sleep(2); //Arrête le programme 2 secondes

      int code_supplementaire;
      code_supplementaire = code_quotidien();
    }


    //Carte 7
    if(saisie_code == 7777)
    {
      /*
        L'utilisateur doit vérifier son identité à l'aide d'un scan digital
        Si l'identité est vérifiée, l'utilisateur doit saisir le code complémentaire
        Sinon, un message d'alerte apparaît
      */
      printf("\nScan digital en cours...\n");
      sleep(2); //Arrête le programme 2 secondes

      int code_supplementaire_et_questions;
      code_supplementaire_et_questions = code_quotidien_et_serie_questions();
    }

  return 0;
}