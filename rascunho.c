/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
   char** nomes; // vetor de strings
   int qtd; // quantidade de strings a serem comparadas
   int i,j; // contadores

   char* temp = (char*) malloc(50*sizeof(char));

   printf("Quantos nomes deseja ordenar ? : ");
   scanf("%i",&qtd);

   nomes = (char**) malloc(qtd*sizeof(char*));
   for(i = 0; i < qtd;++i)
   {
      printf("Entre com nome %i : ",i);
      nomes[i] = (char*) malloc(50*sizeof(char));
      scanf("%s",nomes[i]);
      printf("\n");
   }


  // Rotina de ordenação
   for(i = 1; i < qtd; i++)
      for (j = 0; j < qtd -1 ; j++)
         if(strcmp(nomes[j],nomes[j+1]) > 0)
         {
            strcpy(temp,nomes[j]);
            strcpy(nomes[j],nomes[j+1]);
            strcpy(nomes[j+1],temp);
         }

     free(temp);

   printf("Imprimindo os nomes ordenados\n");
   for(i = 0; i < qtd;++i)
     printf("%s\n",nomes[i]);

  // liberando a memória alocada dinâmicamente
   for(i = 0; i < qtd;++i)
      free(nomes[i]);

     // liberando a memória alocada dinâmicamente
    free(nomes);


   return(0);

}


/*
if(i == contadorAlunos){
            printf("\n\nDeseja realizar um filtro ou ordenação de registros? 1-Sim 2-Não\n");
            scanf("%d", &op);

            if(op ==1){
                printf("\n1. Filtrar registros\n2. Ordenar registros\n");
                scanf("%d", &op2);
                if(op2 == 1){
                    printf("\nBuscar por:\n1. Turma\n2. Matrícula\n3. Nome\n");
                    scanf("%d", &filtro);
                    if(filtro == 1){
                        system("cls");
                        filtrar_alunos_turma();
                    }else{
                        if(filtro == 2){
                            system("cls");
                            filtrar_aluno_id();
                        }else{
                            system("cls");
                            filtrar_aluno_nome();
                        }
                    }
                }else{
                    printf("\nOrdenar por:\n1. Código de Matrícula\n2. Nome\n");
                    scanf("%d", &ordem);
                    if(ordem == 1){
                        system("cls");
                        ordenar_matricula();
                    }else{
                        system("cls");
                        //ordenar_nome();
                    }
                }
            }else{
                system("cls");
                menu_professor();
            }
        }
*/
