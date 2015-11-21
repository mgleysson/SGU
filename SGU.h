/* Arquivo que contém as assinaturas ou protótipos de todas as funções implementadas no sistema */


/*
** Função 1: Menu Principal
    - Responsável por invocar o menu principal do sistema
*/
void menu_principal();


/*
** Função 2: Autenticar Administrador
    - Responsável pela autenticação do administrador do sistema
*/
void autentica_adm();


/*
** Função 3: Menu Administrador
    - Responsável por fornecer o acesso ao sistema no modo administrador
*/
void menu_administrador();


/*
** Função 4: Cadastrar Aluno
    - Responsável por cadastrar um novo aluno no sistema
*/
void cadastrar_aluno();


/*
** Função 5: Cadastrar Disciplina
    - Responsável por cadastrar uma disciplina no sistema
*/
void cadastrar_disciplina();


/*
** Função 6: Listar Disciplina
    - Responsável por listar a disciplina cadastrada
*/
void listar_disciplina();


/*
** Função 7: Cadastrar Professor
    - Responsável por cadastrar um professor no sistema
*/
void cadastrar_professor();


/*
** Função 8: Listar Professor
    - Responsável por listar o professor cadastrado
*/
void listar_professor();


/*
** Função 9: Autenticar professor
    - Responsável pela autenticação do professor no sistema
*/
void autentica_professor();


/*
** Função 10: Menu professor
    - Responsável por fornecer o acesso ao sistema no modo professor
*/
void menu_professor();


/*
** Função 11: Listar alunos
    - Responsável por listar todos os alunos cadastrados no sistema
*/
void listar_alunos();


/*
** Função 12: Filtrar registros de alunos
    - Responsável por fornecer o menu de escolha de filtros/buscas de alunos no sistema
*/
void filtrar_registros();


/*
** Função 13: Buscar alunos por turma
    - Responsável por selecionar os alunos de uma turma específica e listá-los
*/
void filtrar_alunos_turma();


/*
** Função 14: Buscar aluno por código de matrícula (identificador)
    - Responsável por buscar um determinado aluno fornecendo a sua matrícula
*/
void filtrar_aluno_id();

/*
** Função 15: Buscar aluno/alunos por nome ou parte do nome
    - Responsável por selecionar alunos com primeiro nome ou segundo nome ou sobrenome em comum
*/
void filtrar_aluno_nome();


/*
** Função 16: Ordenar registros de alunos
    - Responsável por fornecer o menu de escolha de ordenação de registros
*/
void ordenar_registros();


/*
** Função 17: Ordenar registros de alunos por matrícula
    - Responsável por ordernar os registros por matrícula, tanto em ordem crescente quanto em ordem decrescente
*/
void ordenar_matricula();


/*
** Função 18: Buscar por turma e ordenar por matrícula
    - Responsável por buscar alunos de uma turma selecionada e listá-los em ordem crescente de matrícula
*/
void filtrar_ordenar_registros();


/*
** Função 19: Cadastrar notas
    - Responsável por cadastrar as notas (ab1 e ab2) de cada aluno cadastrado no sistema
*/
void cadastrar_notas();


/*
** Função 20: Calcular média das notas
    - Responsável por receber como parâmetro as notas de cada aluno e retornar a sua média
*/
float calcular_media(float n1, float n2);


/*
** Função 21: Consultar boletim no modo professor
    - Responsável pela consulta dos boletins de cada aluno do sistema
*/
void consultar_boletim_professor();


/*
** Função 22: Buscar alunos aprovados e reprovados
    - Responsável por buscar alunos aprovados e reprovados da primeira turma com base na média
*/
void filtrar_situacao_turma1();


/*
** Função 23: Buscar alunos aprovados e reprovados
    - Responsável por buscar alunos aprovados e reprovados da segunda turma com base na média
*/
void filtrar_situacao_turma2();


/*
** Função 24: Autenticar aluno
    - Responsável pela autenticação de um determinado aluno no sistema
*/
void autentica_aluno();


/*
** Função 25: Menu aluno
    - Responsável por fornecer acesso ao sistema no modo aluno
*/
void menu_aluno();


/*
** Função 26: Consultar boletim no modo aluno
    - Responsável pela consulta do boletim do aluno que acessou o sistema
*/
void consultar_boletim_aluno();


/*
** Função 27: Criar um usuário do tipo Aluno no sistema
    - Responsável pela criação de um usuário(único) e de uma senha para cada aluno objetivando
      o acesso ao sistema
*/
void criar_usuario_aluno(int inicializador);


/*
** Função 28: Ordenar por nome
    - Responsável pela ordenação dos registros de usuários em ordem alfabética
*/
void ordenar_nome();
