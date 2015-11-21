/* Arquivo que contém o menu responsável por fornecer acesso ao sistema no modo administrador.
   Portanto, é o arquivo que contém as implementações de todas as funcionalidades do sistema.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "entidades.c"
#include "arquivos_gerados.c"

int contadorDisciplinas = 0;
int contadorAlunos = 0, contTurma1 = 0, contTurma2 = 0;
int contadorProfessores = 0;
char login_aluno[15];

Aluno alunos[maxAlunos];
Disciplina disciplinas[maxDisciplinas];
Professor professores[maxProfessores];
Administrador adm[maxAdministradores];

void autentica_adm(){

    strcpy(adm[0].usuario, "admin");
    strcpy(adm[0].senha, "ic.ufal.br");

    char usuario[6];
    char senha[12] = {0};
    char c;
    int indice = 0;
    int i, op;

    printf("TELA DE AUTENTICAÇÃO\n");
    printf("--------------------\n\n");
    fflush(stdin);
    printf("Usuário: ");
    scanf("%[^\n]s", usuario);
    fflush(stdin);
    printf("\n");
    printf("%s", "Senha: ");
    do{
        c = getch();

        if(isprint(c)){
            senha[indice++] = c;
            printf("%c",'*');
        }else if(c == 10 && indice){
                senha[indice--] = '\0';
                printf("%s", "\b \b");
              }
    }while(c!=13);

    if(strcmp(adm[0].usuario, usuario) == 0 && strcmp(adm[0].senha, senha) == 0){
        printf("\n\nLogin efetuado com sucesso! Indo para o modo administrador ");
        for(i=1; i<=3; i++){
            if(i==1){
                sleep(1);
            }
            printf(".");
            sleep(1);
        }
        system("cls");
        menu_administrador();
    }else{
        printf("\n\n\nLogin mal-sucedido!\n\n1- Tentar novamente / 2- Voltar\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            autentica_adm();
        }else{
            system("cls");
            menu_principal();
        }
    }
}

void menu_administrador(){
    char opc_adm[2];

    do{
            printf("MENU ADMINISTRADOR\n");
            printf("------------------\n\n");
            printf("1 - Cadastrar aluno\n");
            printf("2 - Criar usuário aluno\n");
            printf("3 - Cadastrar disciplina\n");
            printf("4 - Listar disciplina\n");
            printf("5 - Cadastrar professor\n");
            printf("6 - Listar professor\n");
            printf("7 - Voltar\n\n");
            printf("Escolha sua opção: ");
            scanf("%s", opc_adm);
            system("cls");
            fflush(stdin);\
        }while(strlen(opc_adm)>1 || (opc_adm[0]<49 || opc_adm[0]>55));


        switch (opc_adm[0]){
            case 49: cadastrar_aluno(); break;
            case 50: criar_usuario_aluno(0); break;
            case 51: cadastrar_disciplina();break;
            case 52: listar_disciplina(); break;
            case 53: cadastrar_professor(); break;
            case 54: listar_professor(); break;
            case 55: menu_principal(); break;
        }
}


void cadastrar_aluno(){
    int opc_cadastro, id_unico, i, k, letra = 0;
    char testeMatricula[3];
    char caminho[] = "arquivos_gerados/cadastro_alunos.txt";

    if(contadorAlunos < maxAlunos){
        do{
            FILE *cadastro_alunos = fopen(caminho,"a");

            if(cadastro_alunos == NULL){
                printf("\nErro: não foi possível abrir o arquivo.");
            }

            system("cls");
            printf("CADASTRO DE ALUNOS\n");
            printf("------------------\n\n");
            printf("Aluno %d:\n\n", contadorAlunos+1);
            fprintf(cadastro_alunos, "Aluno %d:\n\n", contadorAlunos+1);
            do{
                letra = 0;
                fflush(stdin);
                printf("Matrícula: ");
                gets(testeMatricula);
                for(k=0; k<strlen(testeMatricula); k++){
                    if(isdigit(testeMatricula[k]) == 0){
                        letra = 1;
                    }
                }
                if(letra == 1){
                    printf("\nPor favor, digite somente números.\n\n");
                }
            }while(letra == 1);

            alunos[contadorAlunos].id = atoi(testeMatricula);
            fprintf(cadastro_alunos, "Matrícula: %d\n", alunos[contadorAlunos].id);
            if(contadorAlunos != 0){
                id_unico = alunos[contadorAlunos].id;
                for(i=0; i<contadorAlunos; i++){
                    if(alunos[i].id == id_unico){
                        printf("\n\nO código de matrícula deve ser único. Tente novamente.");
                        sleep(2);
                        system("cls");
                        cadastrar_aluno();
                    }
                }
            }
            fflush(stdin);
            printf("\nPrimeiro nome: ");
            scanf("%[^\n]s", alunos[contadorAlunos].primeiro_nome_aluno);
            fflush(stdin);
            printf("\nSegundo nome (se não possuir, tecle 0(zero)): ");
            scanf("%[^\n]s", alunos[contadorAlunos].segundo_nome_aluno);
            fflush(stdin);
            printf("\nSobrenome: ");
            scanf("%[^\n]s", alunos[contadorAlunos].sobrenome_aluno);
            if(strcmp(alunos[contadorAlunos].segundo_nome_aluno, "0") == 0){
                fprintf(cadastro_alunos,"Nome completo: %s %s\n",alunos[contadorAlunos].primeiro_nome_aluno, alunos[contadorAlunos].sobrenome_aluno);
            }else{
                fprintf(cadastro_alunos,"Nome completo: %s %s %s\n", alunos[contadorAlunos].primeiro_nome_aluno, alunos[contadorAlunos].segundo_nome_aluno, alunos[contadorAlunos].sobrenome_aluno);
            }
            printf("\nCódigo da turma:\n");
            printf("1 - CC2015.1\n2 - CC2015.2\n\n");
            scanf("%d", &alunos[contadorAlunos].cod_turma);
            if(alunos[contadorAlunos].cod_turma == 1){
                fprintf(cadastro_alunos,"Turma: CC 2015.1");
            }else{
                fprintf(cadastro_alunos,"Turma: CC 2015.2");
            }
            fprintf(cadastro_alunos,"\n------------------------------------------------------------\n\n");
            printf("\n\nAluno %d cadastrado com sucesso!",contadorAlunos+1);

            fclose(cadastro_alunos);

            if(alunos[contadorAlunos].cod_turma == 1){
                contTurma1++;
            }else{
                contTurma2++;
            }

            contadorAlunos++;

            printf("\n\nDeseja cadastrar mais um registro? 1-Sim/2-Não\n");
            scanf("%d", &opc_cadastro);

            if(opc_cadastro==2){
                system("cls");
                menu_administrador();
            }

            if(contadorAlunos == maxAlunos){
                printf("\n\n A capacidade de registros de alunos esgotou.");
                sleep(2);
                system("cls");
                menu_administrador();
            }

        }while(opc_cadastro == 1 && contadorAlunos < maxAlunos);
    }else{
        printf("\n\n A capacidade de registros de alunos esgotou.");
        sleep(2);
        system("cls");
        menu_administrador();
    }

}

void criar_usuario_aluno(int inicializador){

    int i, j, inicia;
    char caminho[] = "arquivos_gerados/login_alunos.txt";
    printf("CRIAR USUÁRIO ALUNO\n");
    printf("-------------------\n\n");

    for(i = inicializador; i<contadorAlunos; i++){
        FILE *login_alunos = fopen(caminho, "a");
        if(login_alunos == NULL){
            printf("\nErro: não foi possível abrir o arquivo.");
        }

        if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
            printf("\n-----------------------------------------------------------------\n");
            printf("Aluno %d: %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
            fprintf(login_alunos, "Aluno %d: %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
        }else{
            printf("\n-----------------------------------------------------------------\n");
            printf("Aluno %d: %s %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
            fprintf(login_alunos, "Aluno %d: %s %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
        }

        fflush(stdin);
        printf("Nome de usuário: ");
        scanf("%[^\n]s", alunos[i].usuario);
        if(i!=0){
            for(j=0; j<i; j++){
                if(strcmp(alunos[j].usuario, alunos[i].usuario) == 0){
                    inicia = i;
                    printf("\n\nO nome de usuário já existe. Tente novamente.");
                    sleep(2);
                    system("cls");
                    criar_usuario_aluno(inicia);
                }
            }
        }


        fprintf(login_alunos,"Nome de usuário: %s\n",alunos[i].usuario);
        fflush(stdin);
        printf("Senha: ");
        scanf("%[^\n]s", alunos[i].senha);
        fprintf(login_alunos,"Senha: %s\n", alunos[i].senha);
        fprintf(login_alunos,"----------------------------------------------------------\n");
        printf("\nUsuário criado com sucesso!");

        fclose(login_alunos);
    }


    printf("\n\n\nPressione qualquer tecla para voltar...");
    if(getch()){
        system("cls");
        menu_administrador();
    }

}

void autentica_aluno(){

    char usuario_aluno[15];
    char senha_aluno[15];
    int i, j, autenticou = 0, op;

    printf("TELA DE AUTENTICAÇÃO\n");
    printf("--------------------\n\n");
    fflush(stdin);
    printf("Usuário: ");
    scanf("%[^\n]s", usuario_aluno);
    fflush(stdin);
    printf("\nSenha: ");
    scanf("%[^\n]s", senha_aluno);

    for(i = 0; i<contadorAlunos; i++){
        if(strcmp(alunos[i].usuario, usuario_aluno) == 0 && strcmp(alunos[i].senha, senha_aluno) == 0){
            autenticou = 1;
            strcpy(login_aluno, usuario_aluno);
            printf("\n\nLogin efetuado com sucesso! Indo para o modo aluno ");
            for(j = 1; j <= 3; j++){
                if(j==1){
                   sleep(1);
                }
                printf(".");
                sleep(1);
            }
            system("cls");
            menu_aluno();
        }
    }

    if(autenticou == 0){
        printf("\n\n\nLogin mal-sucedido!\n\n1- Tentar novamente / 2- Voltar\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            autentica_aluno();
        }else{
            system("cls");
            menu_principal();
        }
    }

    return usuario_aluno;
}

void listar_alunos(){


    printf("RELAÇÃO DE ALUNOS\n");
    printf("-----------------\n\n");
    if(contadorAlunos==0){
        printf("Ainda não há registros de alunos no sistema.\n\n");
    }else{
        int i;
        for(i=0; i<contadorAlunos; i++){
            printf("--------------------------------------------------------------------------\n");
            printf("\nAluno %d\n\n", i+1);
            printf("Matrícula: %d\n", alunos[i].id);
            if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
            }else{
                printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
            }
            if(alunos[i].cod_turma == 1){
                printf("Turma: Ciência da Computação - 2015.1\n\n");
            }else{
                printf("Turma: Ciência da Computação - 2015.2\n\n");
            }
            printf("--------------------------------------------------------------------------\n\n");
        }
    }

    printf("Pressione qualquer tecla para voltar...\n");
    if(getch()){
        system("cls");
        menu_professor();
    }

}
void filtrar_registros(){




    int op;
    printf("BUSCAR ALUNOS\n");
    printf("-------------\n\n");

    printf("Buscar por:\n1. Turma\n2. Matrícula\n3. Nome\n4. Voltar\n\n");
    scanf("%d", &op);
    if(op == 1){
        system("cls");
        filtrar_alunos_turma();
    }else{
        if(op == 2){
            system("cls");
            filtrar_aluno_id();
        }else{
            if(op == 3){
                system("cls");
                filtrar_aluno_nome();
            }else{
                system("cls");
                menu_professor();
            }
        }
    }
}
void filtrar_alunos_turma(){

int filtro_turma;
char caminho1[] = "arquivos_gerados/CC_2015_1.txt";
char caminho2[] = "arquivos_gerados/CC_2015_2.txt";

printf("RELAÇÃO DE ALUNOS POR TURMA\n");
printf("---------------------------\n\n");
printf("Selecione a turma:\n");
printf("1 - CC2015.1\n2 - CC2015.2\n\n");
scanf("%d", &filtro_turma);

    if(filtro_turma == 1){
        if(contTurma1 == 0){
            printf("\n\nAinda não há alunos cadastrados nessa turma.");
            printf("Pressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                filtrar_registros();
            }
        }else{
            int i;
            printf("\n\nAlunos da turma de CC 2015.1 cadastrados no sistema: \n\n");
            for(i=0; i<contadorAlunos; i++){
                if(alunos[i].cod_turma == 1){
                    FILE *turma1 = fopen(caminho1, "a");
                    if(turma1 == NULL){
                        printf("\nErro: Não foi possível abrir o arquivo.");
                    }
                    printf("\nAluno %d\n\n", i+1);
                    fprintf(turma1, "Aluno %d:\n",i+1);
                    printf("Matrícula: %d\n", alunos[i].id);
                    fprintf(turma1, "Matrícula %d:\n", alunos[i].id);
                    if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                        printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                        fprintf(turma1, "Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                    }else{
                        printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                        fprintf(turma1,"Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                    }
                    printf("Turma: Ciência da Computação - 2015.1\n\n");
                    fprintf(turma1, "Turma: Ciência da Computação - 2015.1\n\n");
                    printf("-------------------------------------------------------------------------\n\n");
                    fprintf(turma1, "----------------------------------------------------------------\n\n");

                    fclose(turma1);
                }
            }
            printf("Pressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                filtrar_registros();
            }
        }
    }else{
        if(contTurma2 == 0){
            printf("\n\nAinda não há alunos cadastrados nessa turma.");
            printf("Pressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                filtrar_registros();
            }
        }else{
            int i;
            printf("\n\nAlunos da turma de CC 2015.2 cadastrados no sistema: \n\n");
            for(i=0; i<contadorAlunos; i++){
                if(alunos[i].cod_turma == 2){
                    FILE *turma2 = fopen(caminho2, "a");
                    if(turma2 == NULL){
                        printf("\nErro: Não foi possível abrir o arquivo.");
                    }
                    printf("\nAluno %d\n\n", i+1);
                    fprintf(turma2,"Aluno %d\n\n", i+1);
                    printf("Matrícula: %d\n", alunos[i].id);
                    fprintf(turma2,"Matrícula: %d\n", alunos[i].id);
                    if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                        printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                        fprintf(turma2,"Nome completo: %s %s\n",alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno );
                    }else{
                        printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                        fprintf(turma2,"Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                    }
                    printf("Turma: Ciência da Computação - 2015.2\n\n");
                    fprintf(turma2,"Turma: Ciência da Computação - 2015.2\n\n");
                    printf("------------------------------------------------------------------------\n\n");
                    fprintf(turma2,"---------------------------------------------------------------------\n\n");
                    fclose(turma2);
                }
            }
            printf("Pressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                filtrar_registros();
            }
        }
    }
}

void filtrar_aluno_id(){
    int i, filtro_id, op, id_encontrado = 0;

    printf("BUSCAR ALUNO POR CÓDIGO DE MATRÍCULA\n");
    printf("------------------------------------\n\n");
    printf("Informe o código de matrícula associado ao registro: ");
    scanf("%d", &filtro_id);

    for(i=0; i<contadorAlunos; i++){
       if(filtro_id == alunos[i].id){
            printf("\n\n---------------------------------------------------------\n");
            printf("\nAluno %d\n\n", i+1);
            printf("Matrícula: %d\n", alunos[i].id);
            if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
            }else{
                printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
            }
            if(alunos[i].cod_turma == 1){
                printf("Turma: Ciência da Computação - 2015.1\n\n");
            }else{
                printf("Turma: Ciência da Computação - 2015.2\n\n");
            }
            printf("-------------------------------------------------------------\n\n");
            id_encontrado = 1;
            printf("Pressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                filtrar_registros();;
            }
       }
    }

    if(id_encontrado == 0){
        printf("\n\nNão há registro referente ao código de matrícula informado.\nTecle 1 p/ tentar novamente ou 2 p/ voltar ao menu:\n");
            scanf("%d", &op);
            if(op == 1){
                system("cls");
                filtrar_aluno_id();
            }else{
                system("cls");
                filtrar_registros();
            }
    }
}

void filtrar_aluno_nome(){
    int filtro_nome, nome_encontrado = 0, i, op;
    char nome_filtrado[30];

    printf("BUSCAR ALUNO POR NOME\n");
    printf("---------------------\n\n");
    printf("Deseja buscar aluno por:\n");
    printf("1. Primeiro Nome\n2. Segundo nome\n3. Sobrenome\n\n");
    scanf("%d", &filtro_nome);

    if(filtro_nome == 1){
        fflush(stdin);
        printf("\n\nInforme o primeiro nome a ser buscado: ");
        scanf("%[^\n]s", nome_filtrado);
        for(i=0; i<contadorAlunos; i++){
            if(strcasecmp(nome_filtrado, alunos[i].primeiro_nome_aluno) == 0){
                printf("\nAluno %d\n\n", i+1);
                printf("Matrícula: %d\n", alunos[i].id);
                if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                    printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                }else{
                    printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                }
                if(alunos[i].cod_turma == 1){
                    printf("Turma: Ciência da Computação - 2015.1\n\n");
                }else{
                    printf("Turma: Ciência da Computação - 2015.2\n\n");
                }
                printf("-------------------------------------------------------------------------\n\n");
                nome_encontrado = 1;
            }
        }
    }

    if(filtro_nome == 2){
        fflush(stdin);
        printf("\n\nInforme o segundo nome a ser buscado: ");
        scanf("%[^\n]s", nome_filtrado);
        for(i=0; i<contadorAlunos; i++){
            if(strcasecmp(nome_filtrado, alunos[i].segundo_nome_aluno) == 0){
                printf("\nAluno %d\n\n", i+1);
                printf("Matrícula: %d\n", alunos[i].id);
                if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                    printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                    if(alunos[i].cod_turma == 1){
                        printf("Turma: Ciência da Computação - 2015.1\n\n");
                    }else{
                        printf("Turma: Ciência da Computação - 2015.2\n\n");
                    }
                }else{
                    printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                    if(alunos[i].cod_turma == 1){
                        printf("Turma: Ciência da Computação - 2015.1\n\n");
                    }else{
                        printf("Turma: Ciência da Computação - 2015.2\n\n");
                    }
                }

                printf("---------------------------------------------------------------------------\n\n");
                nome_encontrado = 1;
            }
        }
    }

    if(filtro_nome == 3){
        fflush(stdin);
        printf("\n\nInforme o sobrenome a ser buscado: ");
        scanf("%[^\n]s", nome_filtrado);
        for(i=0; i<contadorAlunos; i++){
            if(strcasecmp(nome_filtrado, alunos[i].sobrenome_aluno) == 0){
                if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                    printf("\nAluno %d\n\n", i+1);
                    printf("Matrícula: %d\n", alunos[i].id);
                    printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                    if(alunos[i].cod_turma == 1){
                        printf("Turma: Ciência da Computação - 2015.1\n\n");
                    }else{
                        printf("Turma: Ciência da Computação - 2015.2\n\n");
                    }
                }else{
                    printf("\nAluno %d\n\n", i+1);
                    printf("Matrícula: %d\n", alunos[i].id);
                    printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                    if(alunos[i].cod_turma == 1){
                        printf("Turma: Ciência da Computação - 2015.1\n\n");
                    }else{
                        printf("Turma: Ciência da Computação - 2015.2\n\n");
                    }
                }

                printf("------------------------------------------------------------------------\n\n");
                nome_encontrado = 1;
            }
        }
    }


     if(nome_encontrado == 0){
        printf("\n\nNão há registro referente ao nome informado.\nTecle 1 p/ escolher outra parte do nome ou 2 p/ voltar ao menu:\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            filtrar_aluno_nome();
        }else{
            system("cls");
            filtrar_registros();
        }
    }

    printf("Pressione qualquer tecla para voltar...\n");
    if(getch()){
        system("cls");
        filtrar_registros();
    }

}

void ordenar_registros(){
    int op;
    printf("ORDENAR ALUNOS\n");
    printf("--------------\n\n");

    printf("Ordenar por:\n1. Código de Matrícula\n2. Nome\n3. Voltar\n\n");
    scanf("%d", &op);
    if(op == 1){
        system("cls");
        ordenar_matricula();
    }else{
        if(op == 2){
           system("cls");
            ordenar_nome();
        }else{
            system("cls");
            menu_professor();
        }
    }
}

void ordenar_matricula(){
    int i, j, aux, op;

    printf("ORDENAÇÃO DE REGISTROS POR MATRÍCULA \n");
    printf("------------------------------------\n\n");
    printf("Deseja colocar os registros em:\n1. Ordem Crescente\n2. Ordem Decrescente\n\n");
    scanf("%d", &op);
    system("cls");

    if(op == 1){
        // Algoritmo de ordenação crescente: INSERTION SORT (ALGORITMO DE INSERÇÃO)
        for (j = 1; j < contadorAlunos; ++j) {
            aux = alunos[j].id;
            for (i = j-1; i >= 0 && alunos[i].id > aux; --i){
                alunos[i+1].id = alunos[i].id;
            }
            alunos[i+1].id = aux;
        }

        printf("ORDENAÇÃO CRESCENTE DE REGISTROS POR MATRÍCULA\n");
        printf("----------------------------------------------\n\n");

       for(i=0; i < contadorAlunos; i++){
            printf("\nAluno %d\n\n", i+1);
            printf("Matrícula: %d\n", alunos[i].id);
            if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
            }else{
                printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
            }
            if(alunos[i].cod_turma == 1){
                printf("Turma: Ciência da Computação - 2015.1\n\n");
            }else{
                printf("Turma: Ciência da Computação - 2015.2\n\n");
            }
            printf("----------------------------------------------------------------------\n\n");
       }
    }else{
        // Algoritmo de ordenação decrescente: INSERTION SORT (ALGORITMO DE INSERÇÃO)
        for (j = 1; j < contadorAlunos; ++j) {
            aux = alunos[j].id;
            for (i = j-1; i >= 0 && alunos[i].id < aux; --i){
                alunos[i+1].id = alunos[i].id;
            }
            alunos[i+1].id = aux;
        }

        printf("ORDENAÇÃO DECRESCENTE DE REGISTROS POR MATRÍCULA\n");
        printf("------------------------------------------------\n\n");

       for(i = 0; i < contadorAlunos; i++){
            printf("\nAluno %d\n\n", i+1);
            printf("Matrícula: %d\n", alunos[i].id);
            if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
            }else{
                printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
            }
            if(alunos[i].cod_turma == 1){
                printf("Turma: Ciência da Computação - 2015.1\n\n");
            }else{
                printf("Turma: Ciência da Computação - 2015.2\n\n");
            }
            printf("--------------------------------------------------------------------------\n\n");
       }
    }

     printf("Pressione qualquer tecla para voltar...\n");
     if(getch()){
        system("cls");
        ordenar_registros();
     }
}

void ordenar_nome(){
    int i, j;

    char **nomes_ordenados;
    char *aux;

    nomes_ordenados = (char **)malloc(contadorAlunos*sizeof(char*));
    aux = (char *)malloc(50*sizeof(char));

    printf("ORDENAR NOMES\n");
    printf("-------------\n\n");

    for(i=0; i<contadorAlunos; ++i){
        nomes_ordenados[i] = (char*) malloc(15*sizeof(char));
        strcpy(nomes_ordenados[i],alunos[i].primeiro_nome_aluno);
    }

    for(i=1; i<contadorAlunos; i++){
        for(j=0; j<contadorAlunos-1; j++){
            if(strcmp(nomes_ordenados[j], nomes_ordenados[j+1]) > 0){
                strcpy(aux, nomes_ordenados[j]);
                strcpy(nomes_ordenados[j], nomes_ordenados[j+1]);
                strcpy(nomes_ordenados[j+1], aux);
            }
        }
    }

    free(aux);

    //imprimindo os nomes ordenados
    for(i = 0; i < contadorAlunos; ++i){
        printf("\nAluno %d\n\n", i+1);
        printf("Matrícula: %d\n", alunos[i].id);
        if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
            printf("Nome completo: %s %s\n", nomes_ordenados[i], alunos[i].sobrenome_aluno);
        }else{
            printf("Nome completo: %s %s %s\n", nomes_ordenados[i], alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
        }
        if(alunos[i].cod_turma == 1){
            printf("Turma: Ciência da Computação - 2015.1\n\n");
        }else{
            printf("Turma: Ciência da Computação - 2015.2\n\n");
        }
        printf("------------------------------------------------\n\n");
    }

    //liberando a memória alocada dinamicamente
   for(i = 0; i < contadorAlunos;++i){
        free(nomes_ordenados[i]);
   }

     //liberando a memória alocada dinamicamente
    free(nomes_ordenados);

    printf("Pressione qualquer tecla para voltar...\n");
     if(getch()){
        system("cls");
        ordenar_registros();
     }

}

void filtrar_ordenar_registros(){

    int op, turma;

    printf("BUSCA E ORDENAÇÃO DE ALUNOS\n");
    printf("---------------------------\n\n");

    printf("1 - Buscar por turma e ordenar por matrícula\n");
    printf("2 - Voltar\n\n");
    scanf("%d", &op);

    if(op == 1){
        int i, j, aux;

        for (j = 1; j < contadorAlunos; ++j) {
            aux = alunos[j].id;
            for (i = j-1; i >= 0 && alunos[i].id > aux; --i){
                alunos[i+1].id = alunos[i].id;
            }
            alunos[i+1].id = aux;
        }

        printf("\nInforme o código da turma desejada para ordenação dos registros:\n");
        printf("1 - CC2015.1\n2 - CC2015.2\n\n");
        scanf("%d", &turma);

        if(turma == 1){
            if(contTurma1 == 0){
                printf("\n\nAinda não há alunos cadastrados nessa turma.\n");
                printf("Pressione qualquer tecla para voltar...\n");
                if(getch()){
                    system("cls");
                    menu_professor();
                }
            }else{
                int i;
                printf("\n\nAlunos da turma de CC 2015.1 cadastrados no sistema: \n\n");
                for(i=0; i<contadorAlunos; i++){
                    if(alunos[i].cod_turma == 1){
                        printf("\nAluno %d\n\n", i+1);
                        printf("Matrícula: %d\n", alunos[i].id);
                        if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                            printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                        }else{
                            printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                        }
                        printf("Turma: Ciência da Computação - 2015.1\n\n");
                        printf("--------------------------------------\n\n");
                    }
                }
                printf("Pressione qualquer tecla para voltar...\n");
                if(getch()){
                    system("cls");
                    filtrar_ordenar_registros();
                }
            }
        }else{
            if(contTurma2 == 0){
                printf("\n\nAinda não há alunos cadastrados nessa turma.\n");
                printf("Pressione qualquer tecla para voltar...\n");
                if(getch()){
                    system("cls");
                    menu_professor();
                }
            }else{
                int i;
                printf("\n\nAlunos da turma de CC 2015.2 cadastrados no sistema: \n\n");
                for(i=0; i<contadorAlunos; i++){
                    if(alunos[i].cod_turma == 2){
                        printf("\nAluno %d\n\n", i+1);
                        printf("Matrícula: %d\n", alunos[i].id);
                        if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                            printf("Nome completo: %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                        }else{
                            printf("Nome completo: %s %s %s\n", alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                        }
                        printf("Turma: Ciência da Computação - 2015.2\n\n");
                        printf("--------------------------------------\n\n");
                    }
                }
                printf("Pressione qualquer tecla para voltar...\n");
                if(getch()){
                    system("cls");
                    filtrar_ordenar_registros();
                }
            }
        }
    }else{
        system("cls");
        menu_professor();
    }
}

void cadastrar_disciplina(){
    int opc_cadastro;
        if(contadorDisciplinas < maxDisciplinas){
            do{
                system("cls");
                printf("CADASTRO DE DISCIPLINAS\n");
                printf("-----------------------\n\n");
                printf("Disciplina %d:\n\n", contadorDisciplinas+1);
                printf("Código da disciplina: ");
                scanf("%d", &disciplinas[contadorDisciplinas].id);
                fflush(stdin);
                printf("\nNome: ");
                scanf("%[^\n]s", disciplinas[contadorDisciplinas].nome_disciplina);

                printf("\n\nDisciplina %d cadastrada com sucesso!",contadorDisciplinas+1);
                contadorDisciplinas++;

                printf("\n\nDeseja cadastrar mais uma disciplina? 1-Sim/2-Não\n");
                scanf("%d", &opc_cadastro);

                if(opc_cadastro==2){
                    system("cls");
                    menu_administrador();
                }

                if(contadorDisciplinas == maxDisciplinas){
                    printf("\n\n A capacidade de registros de disciplinas esgotou.");
                    sleep(2);
                    system("cls");
                    menu_administrador();
                }

            }while(opc_cadastro == 1 && contadorDisciplinas <= maxDisciplinas);
        }else{
            printf("\nA capacidade de registros de disciplinas esgotou.");
            sleep(2);
            system("cls");
            menu_administrador();
        }
}

void listar_disciplina(){

    printf("RELAÇÃO DE DISCIPLINAS\n");
    printf("----------------------\n\n");
    if(contadorDisciplinas==0){
        printf("Ainda não há registros de disciplinas no sistema.\n\n");
    }else{
        int i;
        for(i=0; i<contadorDisciplinas; i++){
            printf("\nDisciplina %d\n\n", i+1);
            printf("Código da disciplina: %d\n", disciplinas[i].id);
            printf("Nome: %s\n", disciplinas[i].nome_disciplina);
            printf("--------------------------------------\n\n");
        }
    }

    printf("Pressione qualquer tecla para voltar...\n");
    if(getch()){
        system("cls");
        menu_administrador();
    }

}

void cadastrar_professor(){
    int opc_cadastro;
        if (contadorProfessores < maxProfessores){
            do{
                system("cls");
                printf("CADASTRO DE PROFESSORES\n");
                printf("-----------------------\n\n");
                printf("Professor %d:\n\n", contadorProfessores+1);
                printf("Código do professor: ");
                scanf("%d", &professores[contadorProfessores].id);
                fflush(stdin);
                printf("\nNome: ");
                scanf("%[^\n]s", professores[contadorProfessores].nome_professor);
                fflush(stdin);
                printf("\nCódigo da disciplina ministrada pelo professor: ");
                scanf("%d", &professores[contadorProfessores].disciplina.id);
                fflush(stdin);
                printf("\nLogin: ");
                scanf("%[^\n]s", professores[contadorProfessores].usuario);
                fflush(stdin);
                printf("\nSenha: ");
                scanf("%[^\n]s", professores[contadorProfessores].senha);
                printf("\n\nProfessor %d cadastrado com sucesso!",contadorProfessores+1);
                contadorProfessores++;

                printf("\n\nDeseja cadastrar mais um professor? 1-Sim/2-Não\n");
                scanf("%d", &opc_cadastro);

                if(opc_cadastro==2){
                    system("cls");
                    menu_administrador();
                }

                if(contadorProfessores == maxProfessores){
                    printf("\n\n A capacidade de registros de professores esgotou.");
                    sleep(2);
                    system("cls");
                    menu_administrador();
                }
            }while(opc_cadastro == 1 && contadorProfessores < maxProfessores);
        }else{
            printf("\nA capacidade de registros de professores esgotou.");
            sleep(2);
            system("cls");
            menu_administrador();
        }
    }

void autentica_professor(){
    char usuario_prof[15];
    char senha_prof[15];
    char c;
    int i, j, indice = 0, op;

    printf("TELA DE AUTENTICAÇÃO\n");
    printf("--------------------\n\n");
    printf("Seja bem vindo, professor %s\n", strupr(professores[0].nome_professor));
    printf("Disciplina: %s\n\n", disciplinas[0].nome_disciplina);
    fflush(stdin);
    printf("Usuário: ");
    scanf("%[^\n]s", usuario_prof);
    fflush(stdin);
    printf("\nSenha: ");
    scanf("%[^\n]s", senha_prof);

    if(strcmp(professores[0].usuario, usuario_prof) == 0 && strcmp(professores[0].senha, senha_prof) == 0){
        printf("\n\nLogin efetuado com sucesso! Indo para o modo professor ");
        for(j = 1; j <= 3; j++){
            if(j == 1){
                sleep(1);
            }
            printf(".");
            sleep(1);
        }
        system("cls");
        menu_professor();
    }else{
        printf("\n\nLogin mal-sucedido!\n\n1- Tentar novamente / 2- Voltar\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            autentica_professor();
        }else{
            system("cls");
            menu_principal();
        }
    }
}

void listar_professor(){
    printf("PROFESSOR CADASTRADO\n");
    printf("----------------------\n\n");
    if(contadorProfessores==0){
        printf("Ainda não há registros de professores no sistema.\n\n");
    }else{
        int i;
        for(i=0; i<contadorProfessores; i++){
            printf("\nProfessor %d\n\n", i+1);
            printf("Código do professor: %d\n", professores[i].id);
            printf("Nome: %s\n", professores[i].nome_professor);
            printf("Disciplina: %d\n", professores[i].disciplina.id);
            printf("--------------------------------------\n\n");
        }
    }

    printf("Pressione qualquer tecla para voltar...\n");
    if(getch()){
        system("cls");
        menu_administrador();
    }

}

float calcular_media(float n1, float n2){
    return (n1+n2)/2;
}

void cadastrar_notas(){

   float ab1, ab2;
   int turma;

    printf("CADASTRO DE NOTAS\n");
    printf("-----------------\n\n");
    printf("Informe o código referente a turma:\n");
    printf("1. Ciência da Computação - 2015.1\n2. Ciência da Computação - 2015.2\n\n");
    scanf("%d", &turma);

    if(turma == 1){
        if(contTurma1 == 0){
            printf("\n\nAinda não há registros de alunos nessa turma.\n\n");
            printf("Pressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                menu_professor();
            }
        }else{
            int i;
            for(i = 0; i < contadorAlunos; i++){
                if(alunos[i].cod_turma == 1){
                    printf("\n--------------------------------------------------------------------------");
                    if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                        fflush(stdin);
                        printf("\nAluno %d: %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);

                        fflush(stdin);
                        printf("Nota AB1: ");
                        scanf("%f",&alunos[i].ab1);
                        fflush(stdin);
                        printf("\nNota AB2: ");
                        scanf("%f",&alunos[i].ab2);

                    }else{
                        fflush(stdin);
                        printf("\nAluno %d: %s %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);

                        fflush(stdin);
                        printf("Nota AB1: ");
                        scanf("%f",&alunos[i].ab1);
                        fflush(stdin);
                        printf("\nNota AB2: ");
                        scanf("%f",&alunos[i].ab2);
                    }
                    fflush(stdin);
                }

                if(i == contadorAlunos-1){
                    printf("\n--------------------------------------------------------------------------");
                }
            }

            printf("\n\nCadastro de notas realizado com sucesso!");
            printf("\n\nPressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                menu_professor();
            }
        }
    }else{
        if(contTurma2 == 0){
            printf("\n\nAinda não há registros de alunos nessa turma.\n\n");
            printf("Pressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                menu_professor();
            }
        }else{
            int i;
            for(i = 0; i < contadorAlunos; i++){
                if(alunos[i].cod_turma == 2){
                    printf("\n--------------------------------------------------------------------------");
                    if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                        fflush(stdin);
                        printf("\nAluno %d: %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);

                        fflush(stdin);
                        printf("Nota AB1: ");
                        scanf("%f",&alunos[i].ab1);
                        fflush(stdin);
                        printf("\nNota AB2: ");
                        scanf("%f",&alunos[i].ab2);

                    }else{
                        fflush(stdin);
                        printf("\nAluno %d: %s %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);

                        fflush(stdin);
                        printf("Nota AB1: ");
                        scanf("%f",&alunos[i].ab1);
                        fflush(stdin);
                        printf("\nNota AB2: ");
                        scanf("%f",&alunos[i].ab2);
                    }
                }
                if(i == contadorAlunos-1){
                    printf("\n--------------------------------------------------------------------------");
                }
            }

            printf("\n\nCadastro de notas realizado com sucesso!");
            printf("\n\nPressione qualquer tecla para voltar...\n");
            if(getch()){
                system("cls");
                menu_professor();
            }
        }
    }
}

void consultar_boletim_professor(){
    int turma, i, op;
    printf("CONSULTAR BOLETIM\n");
    printf("-----------------\n\n");

    printf("Informe a turma desejada:\n");
    printf("1. Ciência da Computação 2015.1\n2. Ciência da Computação 2015.2\n\n");
    scanf("%d", &turma);


    if(turma == 1){
        for(i=0; i<contadorAlunos; i++){
            if(alunos[i].cod_turma == 1){
                printf("\n--------------------------------------------------------------------------");
                if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){

                    printf("\nAluno %d: %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                    printf("AB1: %.2f", alunos[i].ab1);
                    printf("\nAB2: %.2f", alunos[i].ab2);
                    alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                    printf("\nMédia Final: %.2f", alunos[i].media);

                    if(alunos[i].media < 7.0){
                        strcpy(alunos[i].situacao, "Reprovado");
                    }else{
                        strcpy(alunos[i].situacao, "Aprovado");
                    }

                    printf("\n\nSituação: %s", alunos[i].situacao);

                }else{

                    printf("\nAluno %d: %s %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                    printf("AB1: %.2f", alunos[i].ab1);
                    printf("\nAB2: %.2f", alunos[i].ab2);
                    alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                    printf("\nMédia Final: %.2f", alunos[i].media);

                    if(alunos[i].media < 7.0){
                        strcpy(alunos[i].situacao, "Reprovado");
                    }else{
                        strcpy(alunos[i].situacao, "Aprovado");
                    }

                    printf("\n\nSituação: %s", alunos[i].situacao);

                }
            }

             if(i == contadorAlunos-1){
                    printf("\n--------------------------------------------------------------------------");
                }
        }

        printf("\n\nDeseja realizar um filtro de alunos aprovados e reprovados? 1-Sim 2-Não\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            filtrar_situacao_turma1();
        }else{
           printf("\n\nPressione qualquer tecla para voltar...\n");
           if(getch()){
                system("cls");
                menu_professor();
            }
        }

    }else{
        for(i=0; i<contadorAlunos; i++){
            if(alunos[i].cod_turma == 2){
                printf("\n--------------------------------------------------------------------------");
                if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){

                    printf("\nAluno %d: %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                    printf("AB1: %.2f", alunos[i].ab1);
                    printf("\nAB2: %.2f", alunos[i].ab2);
                    alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                    printf("\nMédia Final: %.2f", alunos[i].media);

                    if(alunos[i].media < 7.0){
                        strcpy(alunos[i].situacao, "Reprovado");
                    }else{
                        strcpy(alunos[i].situacao, "Aprovado");
                    }

                    printf("\n\nSituação: %s", alunos[i].situacao);

                }else{

                    printf("\nAluno %d: %s %s %s\n\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                    printf("AB1: %.2f", alunos[i].ab1);
                    printf("\nAB2: %.2f", alunos[i].ab2);
                    alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                    printf("\nMédia Final: %.2f", alunos[i].media);

                    if(alunos[i].media < 7.0){
                        strcpy(alunos[i].situacao, "Reprovado");
                    }else{
                        strcpy(alunos[i].situacao, "Aprovado");
                    }

                    printf("\n\nSituação: %s", alunos[i].situacao);

                }
            }

            if(i == contadorAlunos-1){
                printf("\n--------------------------------------------------------------------------");
            }
        }

        printf("\n\nDeseja realizar um filtro de alunos aprovados e reprovados? 1-Sim 2-Não\n");
        scanf("%d", &op);
        if(op == 1){
            system("cls");
            filtrar_situacao_turma2();
        }else{
           printf("\n\nPressione qualquer tecla para voltar...\n");
           if(getch()){
                system("cls");
                menu_professor();
            }
        }
    }
}

void filtrar_situacao_turma1(){

    int op, i, aprovados = 0, reprovados = 0;
    printf("BUSCAR APROVADOS E REPROVADOS\n");
    printf("----------------------------\n\n");

    printf("Buscar por:\n1. Alunos aprovados\n2. Alunos reprovados\n3. Voltar\n\n");
    scanf("%d", &op);

    if(op == 1){
        for(i=0; i<contadorAlunos; i++){
            if(alunos[i].cod_turma == 1){
                if(strcmp(alunos[i].situacao, "Aprovado") == 0){
                    aprovados = 1;
                    printf("\n--------------------------------------------------------------------------");
                    if(strcmp(alunos[i].segundo_nome_aluno, "0") != 0){
                        printf("\nAluno %d: %s %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                        alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                        printf("\nMédia Final: %.2f", alunos[i].media);
                        printf("\nSituação: Aprovado");
                        printf("\n--------------------------------------------------------------------------");
                    }else{
                        printf("\nAluno %d: %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                        alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                        printf("\nMédia Final: %.2f", alunos[i].media);
                        printf("\nSituação: Aprovado");
                        printf("\n--------------------------------------------------------------------------");
                    }
                }
            }
        }

        if(aprovados == 0){
            printf("\n\nNão há alunos aprovados nessa turma.");
        }

        printf("\n\nPressione qualquer tecla para voltar ao menu anterior...\n");
        if(getch()){
            system("cls");
            filtrar_situacao_turma1();
        }

    }else{
        if(op==2){
                for(i=0; i<contadorAlunos; i++){
                    if(alunos[i].cod_turma == 1){
                        if(strcmp(alunos[i].situacao, "Reprovado") == 0){
                            reprovados = 1;
                            printf("\n--------------------------------------------------------------------------");
                            if(strcmp(alunos[i].segundo_nome_aluno, "0") != 0){
                                printf("\nAluno %d: %s %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                                alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                                printf("\nMédia Final: %.2f", alunos[i].media);
                                printf("\nSituação: Reprovado");
                                printf("\n--------------------------------------------------------------------------");
                            }else{
                                printf("\nAluno %d: %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                                alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                                printf("\nMédia Final: %.2f", alunos[i].media);
                                printf("\nSituação: Reprovado");
                                printf("\n--------------------------------------------------------------------------");

                            }
                        }
                    }
                }

            if(reprovados == 0){
                printf("\n\nNão há alunos reprovados nessa turma.");
            }

            printf("\n\nPressione qualquer tecla para voltar ao menu anterior...\n");
            if(getch()){
                system("cls");
                filtrar_situacao_turma1();
            }

        }else{
            system("cls");
            menu_professor();
        }
    }
}

void filtrar_situacao_turma2(){

    int op, i, aprovados = 0, reprovados = 0;
    printf("BUSCA APROVADOS E REPROVADOS\n");
    printf("----------------------------\n\n");

    printf("Buscar por:\n1. Alunos aprovados\n2. Alunos reprovados\n3. Voltar\n\n");
    scanf("%d", &op);

    if(op == 1){
        for(i=0; i<contadorAlunos; i++){
            if(alunos[i].cod_turma == 2){
                if(strcmp(alunos[i].situacao, "Aprovado") == 0){
                    aprovados = 1;
                    printf("\n--------------------------------------------------------------------------");
                    if(strcmp(alunos[i].segundo_nome_aluno, "0") != 0){
                        printf("\nAluno %d: %s %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                        alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                        printf("\nMédia Final: %.2f", alunos[i].media);
                        printf("\nSituação: Aprovado");
                        printf("\n--------------------------------------------------------------------------");
                    }else{
                        printf("\nAluno %d: %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                        alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                        printf("\nMédia Final: %.2f", alunos[i].media);
                        printf("\nSituação: Aprovado");
                        printf("\n--------------------------------------------------------------------------");
                    }
                }
            }
        }

        if(aprovados == 0){
            printf("\n\nNão há alunos aprovados nessa turma");
        }

        printf("\n\nPressione qualquer tecla para voltar ao menu anterior...\n");
        if(getch()){
            system("cls");
            filtrar_situacao_turma2();
        }

    }else{
        if(op==2){
                for(i=0; i<contadorAlunos; i++){

                    if(alunos[i].cod_turma == 2){
                        if(strcmp(alunos[i].situacao, "Reprovado") == 0){
                            reprovados = 1;
                            printf("\n--------------------------------------------------------------------------");
                                if(strcmp(alunos[i].segundo_nome_aluno, "0") != 0){
                                    printf("\nAluno %d: %s %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].segundo_nome_aluno, alunos[i].sobrenome_aluno);
                                    alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                                    printf("\nMédia Final: %.2f", alunos[i].media);
                                    printf("\nSituação: Reprovado");
                                    printf("\n--------------------------------------------------------------------------");
                                }else{
                                    printf("\nAluno %d: %s %s\n", i+1, alunos[i].primeiro_nome_aluno, alunos[i].sobrenome_aluno);
                                    alunos[i].media = calcular_media(alunos[i].ab1, alunos[i].ab2);
                                    printf("\nMédia Final: %.2f", alunos[i].media);
                                    printf("\nSituação: Reprovado");
                                    printf("\n--------------------------------------------------------------------------");
                                }
                        }
                    }
                }

            if(reprovados == 0){
                printf("\n\nNão há alunos reprovados nessa turma.");
            }

            printf("\n\nPressione qualquer tecla para voltar ao menu anterior...\n");
            if(getch()){
                system("cls");
                filtrar_situacao_turma2();
            }
        }else{
            system("cls");
            menu_professor();
        }
    }
}

void consultar_boletim_aluno(){
    printf("CONSULTAR BOLETIM\n");
    printf("-----------------\n\n");

    int i;

    for(i=0; i<contadorAlunos; i++){
        if(strcmp(login_aluno, alunos[i].usuario) == 0){
            printf("\n--------------------------------------------------------------------------");
            if(strcmp(alunos[i].segundo_nome_aluno, "0") == 0){
                printf("\nSeja bem-vindo, %s %s\n\n", strupr(alunos[i].primeiro_nome_aluno), strupr(alunos[i].sobrenome_aluno));
                printf("Notas:\n\n");
                printf("AB1: %.2f", alunos[i].ab1);
                printf("\nAB2: %.2f", alunos[i].ab2);
                printf("\nMÉDIA FINAL: %.2f", alunos[i].media);
                if(alunos[i].media >= 7.0){
                    printf("\n\nParabéns, você está aprovado na disciplina %s.", disciplinas[0].nome_disciplina);
                }else{
                    printf("\n\nInfelizmente você não conseguiu aprovação na disciplina %s.", disciplinas[0].nome_disciplina);
                }
            }else{
                printf("\nSeja bem-vindo, %s %s %s\n\n", strupr(alunos[i].primeiro_nome_aluno), strupr(alunos[i].segundo_nome_aluno), strupr(alunos[i].sobrenome_aluno));
                printf("Notas:\n\n");
                printf("AB1: %.2f", alunos[i].ab1);
                printf("\nAB2: %.2f", alunos[i].ab2);
                printf("\nMÉDIA FINAL: %.2f", alunos[i].media);
                if(alunos[i].media >= 7.0){
                    printf("\n\nParabéns, você está aprovado na disciplina %s.", disciplinas[0].nome_disciplina);
                }else{
                    printf("\n\nInfelizmente você não conseguiu aprovação na disciplina %s.", disciplinas[0].nome_disciplina);
                }
            }
            printf("\n--------------------------------------------------------------------------\n");
        }
    }

    printf("\nDigite qualquer tecla para voltar...");
    if(getch()){
        system("cls");
        menu_aluno();
    }
}
