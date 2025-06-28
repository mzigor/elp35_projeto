/*
** DISCI | ELP35-S12: Aplicações de Estruturas de Dados e Algoritmos
** ALUNO | Igor Maestrelli Zarnicinski
** MATRI | a1236784
** EXERC | Projeto final
*/

#include <stdlib.h>
#include <stddef.h>
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

// Prints startup splash text
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

char *
io_str_input(){
    int input_size = 100;
    char *p_input = (char *)malloc(input_size);
    if (p_input == NULL)
    {
        printf("\nSem memoria\n");
        exit(1);
    }

    fgets(p_input, input_size, stdin);

    // Finding out the received string's size
    size_t len = strlen(p_input);

    // Removing an eventual newline at the end of `p_input`
    if (len > 0 && p_input[len - 1] == '\n')
    {
        p_input[len - 1] = '\0';  // Remove newline
    }
    // Cleaning up possible remaining input in `stdin`, preventing overflow
    else if (len == input_size - 1)
    {
        // Flush remaining input from stdin
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            // Do nothing, discard character
        }
    }

    return p_input;
}

// Prints possible user actions
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
    printf("q\tSair do programa\n\n");
    printf("> ");
}

// Checks if menu choice is valid (0 if valid, 1 if not)
int io_menu_valid(char *p_in)
{
    if (   
        strcmp(p_in, "a") == 0
     || strcmp(p_in, "b") == 0
     || strcmp(p_in, "c") == 0 
     || strcmp(p_in, "d") == 0
     || strcmp(p_in, "e") == 0 
     || strcmp(p_in, "f") == 0
     || strcmp(p_in, "g") == 0 
     || strcmp(p_in, "h") == 0
     || strcmp(p_in, "q") == 0
    )
    {return 0;}
    
    else
    {return 1;}
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
    if (p_new == NULL)
    {
        printf("\nSem memoria\n");
        exit(1);
    }

    strcpy(p_new->p_name, p_name_new);

    p_new->p_l = NULL;
    p_new->p_r = NULL;

    return p_new;
}

// Inserts a new element into the binary tree (or creates a new tree if empty)
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
    char p_dst[4];        // Flight destination
    char p_cmp[20];       // Flight company
    char p_reg[9];        // Plane register
    char p_mdl[20];       // Plane model
    int  nst;             // Number of seats
    struct btree *p_pal;  // Pointer to the passenger list
};

struct queue
{
    struct node *p_h; // Pointer to queue head
    struct node *p_t; // Pointer to queue tail
};

// Sets all characters in an array to zero and null-terminates the array
void qu_str_zero_null_term(char *p_arr, size_t size)
{
    memset(p_arr, '0', (size-1));
    p_arr[(size-1)] = '\0';
}

// Creates a new node (i.e. a new plane) to form the queue
struct node *
qu_cr_node()
{
    struct node *p_new_nd = (struct node *)malloc(sizeof(struct node));
    if (p_new_nd == NULL)
    {
        printf("\nSem memoria\n");
        exit(1);
    }

    p_new_nd->p_nxt = NULL;
    // Setting all array characters to '0', putting null-terminating char at end
    qu_str_zero_null_term(p_new_nd->p_pid, sizeof(p_new_nd->p_pid));
    qu_str_zero_null_term(p_new_nd->p_dst, sizeof(p_new_nd->p_dst));
    qu_str_zero_null_term(p_new_nd->p_cmp, sizeof(p_new_nd->p_cmp));
    qu_str_zero_null_term(p_new_nd->p_reg, sizeof(p_new_nd->p_reg));
    qu_str_zero_null_term(p_new_nd->p_mdl, sizeof(p_new_nd->p_mdl));
    p_new_nd->nst = 0;
    p_new_nd->p_pal = NULL;

    return p_new_nd;
}

void
qu_fill_node(struct node *p_nd)
{
    printf("Qual o ID do voo?\n> ");
    char *pid = io_str_input();
    strcpy(p_nd->p_pid, pid);
    free(pid);

    printf("Qual o destino do voo?\n> ");
    char *dst = io_str_input();
    strcpy(p_nd->p_dst, dst);
    free(dst);

    printf("Qual a empresa do voo?\n> ");
    char *cmp = io_str_input();
    strcpy(p_nd->p_cmp, cmp);
    free(cmp);

    printf("Qual o registro do voo?\n> ");
    char *reg = io_str_input();
    strcpy(p_nd->p_reg, reg);
    free(reg);

    printf("Qual o modelo do voo?\n> ");
    char *mdl = io_str_input();
    strcpy(p_nd->p_mdl, mdl);
    free(mdl);

    p_nd->nst = 100;
}

// Stores queue's head and tail
struct queue *
qu_cr_queue()
{
    struct queue *p_new_qu = (struct queue *)malloc(sizeof(struct queue));
    if (p_new_qu == NULL)
    {
        printf("\nSem memoria\n");
        exit(1);
    }

    p_new_qu->p_h = NULL;
    p_new_qu->p_t = NULL;

    return p_new_qu;
}

// Flight specific functions----------------------------------------------------

// Adds a new flight to the queue
void
qu_new_flight(struct queue *qu)
{
    printf("Registrando novo voo\n\n");
    struct node * p_nf = qu_cr_node();
    qu_fill_node(p_nf);

    if (qu->p_h == NULL && qu->p_t == NULL)
    {
        qu->p_h = p_nf;
        qu->p_t = p_nf;
    }
    else
    {
        qu->p_t->p_nxt = p_nf;
        qu->p_t = p_nf;
    }
}

// Aligned print, ensuring aligned spaces and a final character at the end
void
qu_print_align(int n, char *p_s, char *p_f)
{
    int p_s_chars = strlen(p_s);
    if (p_s_chars > n)
    {
        printf("\nErro de alinhamento\n");
        return;
    }

    int p_s_lacks = (n - p_s_chars);
    
    printf("%s", p_s);
    
    if (p_s_lacks > 0)
    {
        for (int m = p_s_lacks; m > 1; --m)
        {
            printf(" ");
        }
    }

    printf("%s", p_f);
    return;
}

// Flight list printout header
void
qu_print_header(void)
{
    qu_print_align(10, "ID do voo", "; ");
    qu_print_align(8,  "Destino",   "; ");
    qu_print_align(20, "Empresa",   "; ");
    qu_print_align(9,  "Registro",  "; ");
    qu_print_align(20, "Modelo",    "; ");
    qu_print_align(9,  "Assentos",  "\n");
    return;
}

void
qu_print_f_flight(struct node *p_nd)
{
    qu_print_align(10, p_nd->p_pid, "; ");
    qu_print_align(8,  p_nd->p_dst, "; ");
    qu_print_align(20, p_nd->p_cmp, "; ");
    qu_print_align(9,  p_nd->p_reg, "; ");
    qu_print_align(20, p_nd->p_mdl, "; ");
    
    // Special case for printing the number of seats which is stored as int
    char p_buf[5];
    sprintf(p_buf, "%d", p_nd->nst);
    char p_seats[5];
    strcpy(p_seats, p_buf);
    
    qu_print_align(9,  p_seats,   "\n");

    return;
}

// Print out first flight on the list
void
qu_print_flight(struct node *p_nd)
{
    printf("%s\t\t",    p_nd->p_pid);
    printf("%s\t",      p_nd->p_dst);
    printf("%s\t",      p_nd->p_cmp);
    printf("%s\t\t",    p_nd->p_reg);

    int mdl_chars = strlen(p_nd->p_mdl);
    int mdl_lacks = (24 - mdl_chars);
    printf("%s",        p_nd->p_mdl);
    if (mdl_lacks > 0)
    {
        for (int m = mdl_lacks; m > 0; --m)
        {
            printf(" ");
        }
    }

    printf("%d\n",      p_nd->nst);
    return;
}

void
qu_print_first(struct queue *p_qu)
{
    struct node *p_nd = p_qu->p_h;
    if (p_nd == NULL)
    {
        printf("Fila vazia, sem avioes a decolar\n");
        return;
    }

    qu_print_header();
    qu_print_f_flight(p_nd);
    return;
}

// Main-------------------------------------------------------------------------

int
main(void)
{
    // Creates and initializes flight queue
    struct queue *p_fq = qu_cr_queue();

    io_startup();

    while(1)
    {
        io_menu();
        char *p_in = io_str_input();
        if (io_menu_valid(p_in) == 0)
        {
            switch(p_in[0])
            {
                case 'a': qu_new_flight(p_fq);
                break;

                case 'd': qu_print_first(p_fq);
                break;

                case 'q':
                break;

                default: printf("Funcao nao implementada\n");
                break;
            }

            if (p_in[0] == 'q')
            {
                free(p_in);
                break;
            }
        }
        else
        {
            printf("Input invalido!\n");
            free(p_in);
        }
    }
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

    return 0;
}