/* Arquivo que contém o menu responsável por fornecer acesso ao sistema no modo aluno */


#include <stdio.h>
#include <stdlib.h>

void menu_aluno(){

    char opc_aluno[2];

    do{
        printf("MENU ALUNO\n");
        printf("----------\n\n");
        printf("1 - Consultar boletim\n");
        printf("2 - Voltar\n\n");
        printf("Escolha sua opção: ");
        scanf("%s", opc_aluno);
        system("cls");
        fflush(stdin);
    }while(strlen(opc_aluno)>1 || (opc_aluno[0]<49 || opc_aluno[0]>50));


    switch (opc_aluno[0]){
        case 49: consultar_boletim_aluno(); break;
        case 50: menu_principal(); break;
    }
}
