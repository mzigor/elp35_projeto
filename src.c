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
    printf("f\tExibir numero de avioes aguardando decolagem\n");
    printf("g\tListar todos os avioes aguardando decolagem\n");
    printf("h\tListar todos os passageiros de um voo\n");
    printf("q\tSair do programa\n\n");
    printf("> ");
}

// Checks if menu choice is valid (0 if valid, 1 if not)
int
io_menu_valid(char *p_in)
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

// Checks if p_in is "s" (sim/yes, returns 0) or "n" (não/no, returns 1)
int
io_yes_no(char *p_in)
{
    if (   
        strcmp(p_in, "s") == 0
     || strcmp(p_in, "n") == 0
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

// Inserts a new element into the binary tree (or creates a new tree if empty),
// returns 0 if successful, 1 otherwise
int
bt_rec_insert(struct btree **pp_root, char *p_name_new)
{
    // Found NULL node, create new leaf and return 0
    if (*pp_root == NULL)
    {
        *pp_root = bt_cr_leaf(p_name_new);
        return 0;
    }
    // Recursive insert to LEFT if new name comes BEFORE name in root
    else if (strcmp((*pp_root)->p_name, p_name_new) > 0)
    {
        return bt_rec_insert(&((*pp_root)->p_l), p_name_new);
    }
    // Recursive insert to RIGHT if new name comes AFTER name in root
    else if (strcmp((*pp_root)->p_name, p_name_new) < 0)
    {
        return bt_rec_insert(&((*pp_root)->p_r), p_name_new);
    }
    // Print to screen if name to be inserted already exists, return 1
    else
    {
        printf("Nome ja inserido\n");
        return 1;
    }
}

// Inserts an existant node into the binary tree
int
bt_rec_insert_exs(struct btree **pp_root, struct btree **pp_new)
{
    if (*pp_root == NULL)
    {
        *pp_root = *pp_new;
        return 0;
    }
    else
    {
        int cmp = strcmp((*pp_root)->p_name, (*pp_new)->p_name);

        if (cmp == 0)
        {
            printf("Nome ja inserido\n");
            return 1;
        }
        else if (cmp < 0)
        {
            int ret = bt_rec_insert_exs(&((*pp_root)->p_l), pp_new);
            return ret;
        }
        else if (cmp > 0)
        {
            int ret = bt_rec_insert_exs(&((*pp_root)->p_r), pp_new);
            return ret;
        }
    }
}

// Asks for a new passenger name and inserts it into the binary tree, returns 0
// if successful, returns 1 if not successful (based on bt_rec_insert())
int
bt_fill_name(struct btree **pp_root)
{
    printf("Qual o nome do novo passageiro? > ");
    char *p_in = io_str_input();

    int ret = bt_rec_insert(pp_root, p_in);

    free(p_in);

    return ret;
}

// Prints the names of all passengers in flight
int
bt_print_names_inord(struct btree *p_root)
{
    if (p_root == NULL)
    {
        return 0;
    }
    
    bt_print_names_inord(p_root->p_l);
    printf("%s;\n", p_root->p_name);
    bt_print_names_inord(p_root->p_r);

    return 0;
}

// Returns count of passengers in flight as int
int
bt_count(struct btree *p_root)
{
    int cnt = 0;

    if (p_root == NULL)
    {
        return cnt;
    }

    ++cnt;

    return (bt_count(p_root->p_l) + bt_count(p_root->p_r) + cnt);
}

int
bt_pretty_print(struct btree *p_root)
{
    printf("\nLista de passageiros;\n");
    bt_print_names_inord(p_root);

    printf("\nHa %d passageiros no voo\n", bt_count(p_root));
    return 0;
}

// Recursively searches for a given name. Returns pointer-to-pointer to node if
// name is found, NULL otherwise
struct btree **
bt_search_node(struct btree **pp_root, char *p_sch)
{
    if ((*pp_root)->p_name == NULL)
    {
        return NULL;
    }

    int cmp = strcmp((*pp_root)->p_name, p_sch);

    if (cmp == 0)
    {
        return pp_root;
    }
    else if (cmp < 0)
    {
        struct btree **pp_l_res;
        pp_l_res = bt_search_node(&((*pp_root)->p_l), p_sch);
        return pp_l_res;
    }
    else
    {
        struct btree **pp_r_res;
        pp_r_res = bt_search_node(&((*pp_root)->p_r), p_sch);
        return pp_r_res;
    }
}

// Deletes a given node
int
bt_del_node(struct btree **pp_root)
{
    // Node is NULL
    if (*pp_root == NULL)
    {
        return 0;
    }
    else
    {
        // Node has no children
        if ((*pp_root)->p_l == NULL && (*pp_root)->p_r == NULL)
        {
            free(*pp_root);
            *pp_root = NULL;
            return 0;
        }
        // Node has left child only
        else if ((*pp_root)->p_l != NULL && (*pp_root)->p_r == NULL)
        {
            strcpy((*pp_root)->p_name, (*pp_root)->p_l->p_name);
            return bt_del_node(&((*pp_root)->p_l));
        }
        // Node has right child only
        else if ((*pp_root)->p_l == NULL && (*pp_root)->p_r != NULL)
        {
            strcpy((*pp_root)->p_name, (*pp_root)->p_r->p_name);
            return bt_del_node(&((*pp_root)->p_r));
        }
        // Node has both children
        else if ((*pp_root)->p_l != NULL && (*pp_root)->p_r != NULL)
        {
            struct btree **pp_l_max = &((*pp_root)->p_l);
            while ((*pp_l_max)->p_r != NULL)
            {
                pp_l_max = &((*pp_l_max)->p_r);
            }

            strcpy((*pp_root)->p_name, (*pp_l_max)->p_name);
            return bt_del_node(pp_l_max);
        }
        else
        {
            return 1;
        }
    }
}

// Deletes node containing given name
int
bt_del_by_name(struct btree **pp_root, char *p_sch)
{
    struct btree **p_sch_res = bt_search_node(pp_root, p_sch);

    if (p_sch_res == NULL)
    {
        printf("Nome nao encontrado\n");
        return 1;
    }
    else
    {
        int d = bt_del_node(p_sch_res);

        if (d == 0)
        {
            printf("Passageiro removido\n");
        }
        else
        {
            printf("Remocao malsucedida");
        }
        return d;
    }
}

// Destroys the entire binary tree
void
bt_destroy(struct btree *p_root)
{
    if (p_root == NULL)
    {
        return;
    }

    if (p_root->p_l != NULL)
    {
        bt_destroy(p_root->p_l);
    }

    if (p_root->p_r != NULL)
    {
        bt_destroy(p_root->p_r);
    }
    
    free(p_root);

    return;
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
void
qu_str_zero_null_term(char *p_arr, size_t size)
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

// Fills a node with information retrieved from the user
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

// Deletes a single node/flight
void
qu_del_node(struct node *p_nd)
{
    // Passenger list must be specially destroyed/freed
    bt_destroy(p_nd->p_pal);
    
    free(p_nd);

    return;
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

// Searches for a specific node by its flight id p_id, returns pointer to the
// node if successful, NULL otherwise
struct node *
qu_search_node_id(struct queue *p_qu, char *p_id)
{
    if (p_qu->p_h == NULL)
    {
        return NULL;
    }

    struct node *p_aux = p_qu->p_h;
    do
    {
        if (strcmp(p_id, p_aux->p_pid) == 0)
        {
            return p_aux;
        }

        p_aux = p_aux->p_nxt;
    } while (p_aux != NULL);
    
    return NULL;
}

// Delete the first node/flight from the queue
int
qu_del_first(struct queue *p_qu)
{
    if (p_qu->p_h == NULL)
    {
        return 1;
    }

    if (p_qu->p_h == p_qu->p_t)
    {
        qu_del_node(p_qu->p_h);

        p_qu->p_h = NULL;
        p_qu->p_t = NULL;

        return 0;
    }

    struct node *p_aux = p_qu->p_h->p_nxt;

    qu_del_node(p_qu->p_h);

    p_qu->p_h = p_aux;

    return 0;
}

// Destroys the entire queue, its nodes, and its nodes' binary trees
void
qu_destroy(struct queue *p_qu)
{
    do
    {
        qu_del_first(p_qu);
    } while (p_qu->p_h != NULL);

    free(p_qu);

    return;
}

// Flight specific functions----------------------------------------------------

// Adds a new flight to the queue
void
qu_new_flight(struct queue *p_qu)
{
    printf("Registrando novo voo\n\n");
    struct node * p_nf = qu_cr_node();
    qu_fill_node(p_nf);

    if (p_qu->p_h == NULL && p_qu->p_t == NULL)
    {
        p_qu->p_h = p_nf;
        p_qu->p_t = p_nf;
    }
    else
    {
        p_qu->p_t->p_nxt = p_nf;
        p_qu->p_t = p_nf;
    }

    return;
}

// Return an int with the number of nodes/flights in queue
int
qu_count(struct queue *p_qu)
{
    if (p_qu->p_h == NULL)
    {
        return 0;
    }
    else
    {
        int cnt = 0;
        struct node *p_aux = p_qu->p_h;

        // Do-while ensuring at least one flight is counted
        do
        {
            ++cnt;
            p_aux = p_aux->p_nxt;
        } while (p_aux != NULL);

        return cnt;
    }
}

// Print message stating number of flights in queue
void
qu_print_count(struct queue *p_qu)
{
    int cnt = qu_count(p_qu);

    printf("Ha %d avioes aguardando para decolar\n", cnt);

    return;
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

// Flight details header printout
void
qu_print_header(void)
{
    // printf("\n");
    qu_print_align(10, "ID do voo", "; ");
    qu_print_align(8,  "Destino",   "; ");
    qu_print_align(20, "Empresa",   "; ");
    qu_print_align(9,  "Registro",  "; ");
    qu_print_align(20, "Modelo",    "; ");
    qu_print_align(9,  "Assentos",  "\n");
    return;
}

// Print flight details in aligned formatting
void
qu_print_f_flight(struct node *p_nd)
{
    qu_print_align(10, p_nd->p_pid, "; ");
    qu_print_align(8,  p_nd->p_dst, "; ");
    qu_print_align(20, p_nd->p_cmp, "; ");
    qu_print_align(9,  p_nd->p_reg, "; ");
    qu_print_align(20, p_nd->p_mdl, "; ");
    
    // Special treatment for seat count which is stored as int
    char p_buf[5];
    sprintf(p_buf, "%d", p_nd->nst);
    char p_seats[5];
    strcpy(p_seats, p_buf);
    
    qu_print_align(9,  p_seats,   "\n");

    return;
}

// Print details of a single flight -- REMOVED, later adjust to simple csv print
// void
// qu_print_flight(struct node *p_nd)
// {
//     printf("%s\t\t",    p_nd->p_pid);
//     printf("%s\t",      p_nd->p_dst);
//     printf("%s\t",      p_nd->p_cmp);
//     printf("%s\t\t",    p_nd->p_reg);

//     int mdl_chars = strlen(p_nd->p_mdl);
//     int mdl_lacks = (24 - mdl_chars);
//     printf("%s",        p_nd->p_mdl);
//     if (mdl_lacks > 0)
//     {
//         for (int m = mdl_lacks; m > 0; --m)
//         {
//             printf(" ");
//         }
//     }

//     printf("%d\n",      p_nd->nst);
//     return;
// }

// Print first flight in queue
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

// Print all flights in queue
void
qu_print_all(struct queue *p_qu)
{
    struct node *p_nd = p_qu->p_h;
    if (p_nd == NULL)
    {
        printf("Fila vazia, sem avioes a decolar\n");
        return;
    }

    qu_print_header();
    struct node *p_aux = p_qu->p_h;
    while(1)
    {
        qu_print_f_flight(p_aux);
        if (p_aux->p_nxt == NULL) {break;}
        else {p_aux = p_aux->p_nxt;}
    }

    return;
}

// Allows first flight in queue to fly, deleting its record
void
qu_allow_flight(struct queue *p_qu)
{
    if (p_qu->p_h == NULL)
    {
        printf("Sem voos aguardando\n");
        return;
    }

    printf("Proximo voo:\n\n");
    qu_print_first(p_qu);

    while(1)
    {
        printf("\nPermitir decolagem? s/n > ");

        char *p_in = io_str_input();

        if (io_yes_no(p_in) == 0)
        {
            if (p_in[0] == 's')
            {
                qu_del_first(p_qu);
                printf("Decolagem autorizada\n");
                free(p_in);
                return;
            }
            else
            {
                printf("Decolagem nao autorizada\n");
                free(p_in);
                return;
            }
        }
        else
        {
            printf("Input invalido!\n");
            free(p_in);
        }
    }
}

// Register new passenger to specific flight
int
fl_new_pass(struct queue *p_qu)
{
    printf("Iniciando cadastro de novo passageiro\n");
    printf("Qual o ID do voo do novo passageiro? > ");

    char *p_in = io_str_input();

    struct node *p_res = qu_search_node_id(p_qu, p_in);

    if (p_res == NULL)
    {
        printf("Voo nao encontrado\n");
        free(p_in);
        return 1;
    }

    int ins = bt_fill_name(&(p_res->p_pal));

    free(p_in);
    return ins;
}

// Print all passengers from given flight specified by user, returns 0 if
// successful, 1 otherwise
int
fl_list_pass(struct queue *p_qu)
{
    printf("Conferir a lista de passageiros do voo com ID > ");

    char *p_in = io_str_input();

    struct node *p_nd = qu_search_node_id(p_qu, p_in);

    if (p_nd == NULL)
    {
        printf("Voo nao encontrado\n");
        free(p_in);
        return 1;
    }

    bt_pretty_print(p_nd->p_pal);
    return 0;
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

                case 'b': fl_new_pass(p_fq);
                break;

                case 'd': qu_print_first(p_fq);
                break;

                case 'e': qu_allow_flight(p_fq);
                break;

                case 'f': qu_print_count(p_fq);
                break;

                case 'g': qu_print_all(p_fq);
                break;

                case 'h': fl_list_pass(p_fq);
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
        }

        free(p_in);
    }

    qu_destroy(p_fq);
    p_fq = NULL;

    return 0;
}