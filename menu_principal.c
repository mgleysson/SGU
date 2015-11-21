/* Arquivo que contém o menu principal do sistema, onde é possível escolher os modos de acesso */


#include <stdio.h>
#include <stdlib.h>

void menu_principal(){
    char opc_geral[2];

    void sair(){
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


        printf("\n\n\n          ..:: A sessão acabou. Obrigado! ::..\n\n");
        exit(0);
    }

    do{
        printf("MENU PRINCIPAL\n");
        printf("--------------\n\n");
        printf("1 - Professor\n");
        printf("2 - Aluno\n");
        printf("3 - Administrador\n");
        printf("4 - Sair\n\n");
        printf("Escolha sua opção: ");
        scanf("%s", opc_geral);
        system("cls");
        fflush(stdin);
    }while(strlen(opc_geral)>1 || (opc_geral[0]<49 || opc_geral[0]>52));


    switch (opc_geral[0]){
        case 49: autentica_professor(); break;
        case 50: autentica_aluno(); break;
        case 51: autentica_adm(); break;
        case 52: sair(); break;
    }
}
