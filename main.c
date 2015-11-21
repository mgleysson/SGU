/* Arquivo que invoca o menu principal, este que invoca as demais funcionalidades do sistema */


#include <stdio.h>
//#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "arquivos_gerados.c"
#include "SGU.h"

int main(){

    int i, j;
    setlocale(LC_ALL,"portuguese");

    printf("    SSSSSSSSSSSSSSS       GGGGGGGGGGGGGG UUUUUUU     UUUUUUU\n");
    printf(" SS:::::::::::::::S     GGG::::::::::::G U:::::U     U:::::U\n");
    printf("S:::::SSSSSS::::::S   GG:::::::::::::::G U:::::U     U:::::U\n");
    printf("S:::::S     SSSSSSS  G:::::GGGGGGGG::::G U:::::U     U:::::U\n");
    printf("S:::::S             G:::::G       GGGGGG U:::::U     U:::::U\n");
    printf("S:::::S            G:::::G               U:::::D     D:::::U\n");
    printf(" S::::SSSS         G:::::G               U:::::D     D:::::U\n");
    printf("  SS::::::SSSSS    G:::::G    GGGGGGGGGG U:::::D     D:::::U\n");
    printf("    SSS::::::::SS  G:::::G    G::::::::G U:::::D     D:::::U\n");
    printf("       SSSSSS::::S G:::::G    GGGGG::::G U:::::D     D:::::U\n");
    printf("            S:::::SG:::::G        G::::G U:::::D     D:::::U\n");
    printf("            S:::::S G:::::G       G::::G U::::::U   U::::::U\n");
    printf("SSSSSSS     S:::::S  G:::::GGGGGGGG::::G U:::::::UUU:::::::U\n");
    printf("S::::::SSSSSS:::::S   GG:::::::::::::::G  UU:::::::::::::UU\n");
    printf("S:::::::::::::::SS      GGG::::::GGG:::G    UU:::::::::UU\n");
    printf(" SSSSSSSSSSSSSSS           GGGGGG   GGGG      UUUUUUUUU\n");


    printf("\n\n\n             ..:: Sejam bem-vindos ao SGU! ::.. ");


   printf ("\n\nCarregando o sistema: \n\n");

   for (i = 1; i <= 50; i++){
      printf ("  %d%%\r", i*2);
      fflush (stdout);

      for (j = 0; j < i; j++){
         if (!j)
           printf("  ");

         printf ("%c", 2);
         Sleep(3);
      }
   }

    printf ("\n\nInicializando sistema...");
    sleep(2);
    system("cls");
    menu_principal();

return 0;
}

