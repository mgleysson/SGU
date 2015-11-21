/* Arquivo que contém o menu responsável por fornecer acesso ao sistema no modo professor */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidades.c"
#include "arquivos_gerados.c"


void menu_professor(){
   char opc_prof[2];

    do{
        printf("MENU PROFESSOR\n");
        printf("--------------\n\n");
        printf("1 - Listar todos os alunos\n");
        printf("2 - Buscar/Filtrar registros de alunos\n");
        printf("3 - Ordenar registros de alunos\n");
        printf("4 - Buscar e ordenar registros\n");
        printf("5 - Cadastrar notas\n");
        printf("6 - Consultar boletim dos alunos\n");
        printf("7 - Voltar\n\n");
        printf("Escolha sua opção: ");
        scanf("%s", opc_prof);
        system("cls");
        fflush(stdin);
    }while(strlen(opc_prof)>1 || (opc_prof[0]<49 || opc_prof[0]>55));


    switch (opc_prof[0]){
        case 49: listar_alunos(); break;
        case 50: filtrar_registros(); break;
        case 51: ordenar_registros(); break;
        case 52: filtrar_ordenar_registros(); break;
        case 53: cadastrar_notas(); break;
        case 54: consultar_boletim_professor(); break;
        case 55: menu_principal();
    }
}
