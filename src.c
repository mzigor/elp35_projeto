/*
** DISCI | ELP35-S12: Aplicações de Estruturas de Dados e Algoritmos
** ALUNO | Igor Maestrelli Zarnicinski
** MATRI | a1236784
** EXERC | Projeto final
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
** ░▒▓████████▓▒░▒▓█▓▒░░▒▓██████▓▒░▒▓████████▓▒░▒▓██████▓▒░ 
** ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░
** ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░
** ░▒▓██████▓▒░ ░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓████████▓▒░
** ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░
** ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░
** ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓██████▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░
** Ferramenta Interativa para Controle de Tráfego em Aeroportos
*/

// User interaction-------------------------------------------------------------

char *
io_str_input(){
    char *p_input = (char *)malloc(sizeof(char)*100);

    fgets(p_input, (sizeof(p_input)), stdin);

    // Finding out the received string's size
    size_t len = strlen(p_input);

    // Removing an eventual newline at the end of `p_input`
    if (len > 0 && p_input[len - 1] == '\n') {
        p_input[len - 1] = '\0';
    }

    // Cleaning up any remaining input in `stdin`
    // int c;
    // while ((c = getchar()) != '\n' && c != EOF){}

    return p_input;
}

void
io_startup(void)
{
    printf("\t░▒▓████████▓▒░▒▓█▓▒░░▒▓██████▓▒░▒▓████████▓▒░▒▓██████▓▒░ \n");
    printf("\t░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░\n");
    printf("\t░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░\n");
    printf("\t░▒▓██████▓▒░ ░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓████████▓▒░\n");
    printf("\t░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░        ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░\n");
    printf("\t░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░\n");
    printf("\t░▒▓█▓▒░      ░▒▓█▓▒░░▒▓██████▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░\n");
    printf("\tFerramenta Interativa para Controle de Trafego em Aeroportos\n");
    printf("\n");
}

void
io_menu(void)
{
    printf("\nEscolha uma das seguintes opcoes:\n\n");
    printf("a\tCadastrar um novo voo na fila de espera\n");
    printf("b\tCadastrar um passageiro em um voo\n");
    printf("c\tRemover um passageiro de um voo\n");
    printf("d\tVer detalhes do proximo aviao a decolar\n");
    printf("e\tAutorizar o proximo aviao a decolar\n");
    printf("f\tVerificar numero de avioes aguardando decolagem\n");
    printf("g\tListar todos os avioes aguardando decolagem\n");
    printf("h\tListar todos os passageiros de um voo\n");
    printf("q\tSair do voo\n\n");
    printf("> ");
}

// Binary tree functions--------------------------------------------------------

struct btree
{
    char p_name[40];
    struct btree *p_l;
    struct btree *p_r;
};

struct btree *
bt_cr_leaf(char *p_name_new)
{
    struct btree *p_new = malloc(sizeof(struct btree));
    if (p_name_new == NULL)
    {
        printf("\nSem memoria\n");
        system("pause");
        exit(1);
    }

    strcpy(p_new->p_name, p_name_new);

    p_new->p_l = NULL;
    p_new->p_r = NULL;

    return p_new;
}

int
bt_rec_insert(struct btree **p_root, char *p_name_new)
{
    // First node ever
    if (*p_root == NULL)
    {
        *p_root = bt_cr_leaf(p_name_new);
        return 0;
    }
    // Recursive insert to LEFT if new name comes BEFORE name in root
    else if (strcmp((*p_root)->p_name, p_name_new) > 0)
    {
        return bt_rec_insert(&((*p_root)->p_l), p_name_new);
    }
    // Recursive insert to RIGHT if new name comes AFTER name in root
    else if (strcmp((*p_root)->p_name, p_name_new) < 0)
    {
        return bt_rec_insert(&((*p_root)->p_r), p_name_new);
    }
    // Print to screen if name to be inserted already exists, return 1
    else
    {
        printf("Nome ja inserido\n");
        return 1;
    }
}

// List functions---------------------------------------------------------------

struct node
{
    struct node *p_nxt;   // Next element in queue
    char p_pid[8];        // Plane ID
    char p_dst[4];        // Flight DesTiNation
    char p_cmp[20];       // Flight CoMPany
    char p_reg[9];        // Plane REGister
    char p_mdl[20];       // Plane MoDeL
    int  nst;             // Number os SeaTs
    struct btree *p_pal;   // Pointer to the Passenger List
};

struct queue
{
    struct node *p_h; // Pointer to queue Head
    struct node *p_t; // Pointer to queue Tail
};

struct node *
qu_cr_node()
{
    struct node *p_new_nd = (struct node *)malloc(sizeof(struct node));
    if (p_new_nd == NULL)
    {
        printf("\nSem memoria\n");
        system("pause");
        exit(1);
    }

    p_new_nd->p_nxt = NULL;
    strcpy(p_new_nd->p_pid, "0000000");
    strcpy(p_new_nd->p_dst, "000");
    strcpy(p_new_nd->p_cmp, "0000000000000000000");
    strcpy(p_new_nd->p_reg, "00000000");
    strcpy(p_new_nd->p_mdl, "0000000000000000000");
    p_new_nd->nst = 0;
    p_new_nd->p_pal = NULL;

    return 0;
}

struct queue *
qu_cr_queue()
{
    struct queue *p_new_qu = (struct queue *)calloc(1, sizeof(struct queue));
    if (p_new_qu == NULL)
    {
        printf("\nSem memoria\n");
        exit(1);
    }

    return p_new_qu;
}

int
main(void)
{
    io_startup();
    io_menu();
    io_str_input();
    // printf("Inicio do teste\n");
    // struct node teste;

    // teste.p_nxt = NULL;
    // strcpy(teste.p_pid, "GLO1123");
    // strcpy(teste.p_dst, "CGH");
    // strcpy(teste.p_cmp, "GOL");
    // strcpy(teste.p_reg, "PR-XMW");
    // strcpy(teste.p_mdl, "Boeing 737-7K5");
    // teste.nst = 138;
    // teste.p_pal = NULL;

    // char n1[] = "Igor";
    // char n2[] = "Marina";

    // bt_rec_insert(&(teste.p_pal), n1);
    // bt_rec_insert(&(teste.p_pal), n2);
    // bt_rec_insert(&(teste.p_pal), n1);

    // return 0;
}