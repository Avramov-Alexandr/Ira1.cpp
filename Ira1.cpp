#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int **dynamicmemoryINCIDENT(int dug, int ver)
{
   int **x = (int **)malloc(dug * sizeof(int *));
   for (int i = 0; i < dug; i++)
      x[i] = (int *)malloc(ver * sizeof(int));
   return x;
}

int **dynamicmemorySMEJNOSTI(int ver)
{
   int **x = (int **)malloc(ver * sizeof(int *));
   for (int i = 0; i < ver; i++)
      x[i] = (int *)malloc(ver * sizeof(int));
   return x;
}

int **dynamicmemorySPIS(int ver, int constant)
{
   int **x = (int **)malloc(ver * sizeof(int *));
   for (int i = 0; i < ver; i++)
      x[i] = (int *)malloc(constant * sizeof(int));
   return x;
}

void vivod(int **mass, int a, int b)
{
   for (int i = 0; i < a; i++)
   {
      for (int j = 0; j < b; j++)
      {
         cout << mass[i][j] << " ";
         if (j == b - 1)
            cout << endl;
      }
   }
}

void obnulenie(int **mas, int stroka, int stolb)
{
   for (int i = 0; i < stroka; i++)
   {
      for (int j = 0; j < stolb; j++)
      {
         mas[i][j] = 0;
      }
   }
}

void clean(int **masiv, int p)
{
   for (int i = 0; i < p; i++)
      free(masiv[i]);
   free(masiv);
}

int main()
{
   int **arr;
   int **arr1;
   int **arr2;
   int row = 0, col, ver, dug, count = 0, tmp = -1, tm = -1, k = 0, l = 1, n = 0, counter = 0, constant = 0;
   while (l > 0)
   {
      cout << " IF YOU WANT TO ENTER SMEJNOSTI ENTER 1 ; FOR INCEDENT ENTER 2 ; FOR SPISOK ENTER 3 ";
      cin >> l;

      if (l == 2)
      {
         cout << "vvedite versini " << endl;
         cin >> ver;
         cout << "vvedite dugi " << endl;
         cin >> dug;
         arr = dynamicmemoryINCIDENT(dug, ver);
         arr1 = dynamicmemorySMEJNOSTI(ver);
         //  OBNULENIE
         obnulenie(arr, dug, ver);
         obnulenie(arr1, ver, ver);
         while (row < dug)
         {
            cout << "Enter vershina where is begin your duga" << row << " " << endl;
            cin >> tmp; // НАЧАЛО СТРОКИ ЕСЛИ ОНА ПОВТОРЯЕТСЯ ТО НА ДАННОЙ СТРОКЕ ЕЩЁ ОДНА ЕДИНИЦА nmp - СТРОКА
            arr[row][tmp] = -1;
            cout << "Enter vershina where is end your duga " << row << " " << endl;
            cin >> tm; // TM - НАШ СТОЛБЕЦ
            arr[row][tm] = 1;
            row++;
            arr1[tmp][tm] = 1;
         }

         //cout << " bejati po SMEJNOSTI" << endl;
         for (int i = 0; i < ver; i++)
         {
            counter = 0;
            for (int j = 0; j < ver; j++)
            {
               if (arr1[i][j] == 1)
               {
                  counter++;
                  if (constant < counter)
                     constant = counter;
               }
               if (j == ver - 1)
                  cout << endl;
            }
         }
         constant++;

         arr2 = dynamicmemorySPIS(ver, constant);

         obnulenie(arr2, ver, constant);
         for (int i = 0; i < ver; i++)
         {
            int m = 0;
            for (int j = 0, m = 0; j < ver; j++)
            {
               if (arr1[i][j] == 1)
               {
                  arr2[i][m] = j;
                  if (m < constant - 1)
                     m++;
                  else
                     m = 0;
               }
            }
         }
      }

      else if (l == 3)
      {
         cout << "vvedite versini " << endl;
         cin >> ver;
         cout << "vvedite dugi " << endl;
         cin >> dug;
         cout << "VVEDITE CONSTANT ";
         cin >> constant;
         arr2 = dynamicmemorySPIS(ver, constant);
         arr1 = dynamicmemorySMEJNOSTI(ver);
         arr = dynamicmemoryINCIDENT(dug, ver);

         obnulenie(arr1, ver, ver);

         obnulenie(arr2, ver, constant);

         obnulenie(arr, dug, ver);

         for (int i = 0; i < ver; i++)
         {
            tm = 0;
            for (int j = 0; j < constant; j++)
            {
               if (tm >= 0)
               {

                  cout << "VVEDITE SPISOK DLEA STROKI " << i << " ";
                  cin >> tmp; // kaka toliko vvodim i to pisem stroku

                  arr[k][i] = -1;
                  arr[k][tmp] = 1;
                  k++;
                  arr2[i][j] = tmp;
                  arr1[i][tmp] = 1;
                  cout << "ESLI VASHA STROKA ZACONCILASI VVEDITE -1  V OBRATNOM SLUCHAE 1 ";
                  cin >> tm;
               }
            }
         }
      }

      else if (l == 1)
      {
         cout << "vvedite versini " << endl;
         cin >> ver;
         cout << "vvedite dugi " << endl;
         cin >> dug;
         arr1 = dynamicmemorySMEJNOSTI(ver);
         arr = dynamicmemoryINCIDENT(dug, ver);
         obnulenie(arr, dug, ver);
         obnulenie(arr1, ver, ver);
         for (int i = 0; i < ver; i++)
         {
            cout << "Vvedite cuda idet versina Nom " << i << " ";
            cin >> tmp;
            if (tmp >= 0)
            {
               counter++;
               if (counter > constant)
               {
                  constant = counter + 1;
                  constant++; ////////////////////////////////////////////
               }
            }

            while (k < dug)
            {
               arr[k][i] = -1;
               arr[k][tmp] = 1;
               k++;
               break;
            }

            if (tmp >= 0)
            {
               for (int j = 0; j < ver; j++)
               {
                  if (tmp == j)
                  {
                     arr1[i][j] = 1;
                     cout << "Esli hocesh dobaviti versinu enter 1 ili -1 dlea vihoda tm = ";
                     cin >> tm;
                     if (tm >= 0)
                     {
                        j = 0;
                        i -= 1;
                        break;
                     }
                     else if (tm <= -1)
                     {
                        j = 0;
                        counter = 0; //
                        break;
                     }
                  }
               }
            }
         }

         arr2 = dynamicmemorySPIS(ver, constant);
         obnulenie(arr2, ver, constant);
         // ПРОХОД ПО МАТРИЦЕ СЕЖНОСТИ И ГДЕ ЯЧЕЙКА РАВНА 1 ЕЁ СТОЛБЕЦ ЗАПИСЫВАЕТСЯ В СПИСОК
         for (int i = 0; i < ver; i++)
         {
            int m = 0;
            for (int j = 0, m = 0; j < ver; j++)
            {
               if (arr1[i][j] == 1)
               {
                  arr2[i][m] = j;
                  if (m < constant - 1)
                     m++;
                  else
                     m = 0;
               }
            }
         }
      }

      cout << "INcident" << endl;

      vivod(arr, dug, ver);
      clean(arr, dug);

      cout << "SMEJNOSTI" << endl;

      vivod(arr1, ver, ver);
      clean(arr1, ver);

      cout << "SPISOK" << endl;

      vivod(arr2, ver, constant);
      clean(arr2, ver);

      cout << "IF YOU WANT TO REPEAT YOUR ACTION ENTER 4 , ELSE ENTER -1 TO EXIT ";
      cin >> l ;
   }
   return 0;
}