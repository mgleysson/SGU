/* Arquivo responsável por declarar e definir as entidades constituintes do sistema */


#define maxAlunos 15
#define maxProfessores 1
#define maxDisciplinas 1
#define maxAdministradores 1

typedef struct Disciplinas{
    int id;
    char nome_disciplina[20];
} Disciplina;

typedef struct Alunos{
    int id;
    char primeiro_nome_aluno[15];
    char segundo_nome_aluno[15];
    char sobrenome_aluno[30];
    float ab1;
    float ab2;
    float media;
    char situacao[20];
    int cod_turma;
    char usuario[15];
    char senha[15];
} Aluno;

typedef struct Professores{
    int id;
    char nome_professor[30];
    Disciplina disciplina;
    char usuario[15];
    char senha[15];
} Professor;

typedef struct Admin{
    char usuario[20];
    char senha[20];
} Administrador;
