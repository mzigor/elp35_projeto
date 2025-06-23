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

struct btree
{
    char p_name[40];
    struct btree *p_l;
    struct btree *p_r;
};

struct btree *bt_cr_leaf(char *p_name_new)
{
    struct btree *p_new = malloc(sizeof(struct btree));

    strcpy(p_new->p_name, p_name_new);

    p_new->p_l = NULL;
    p_new->p_r = NULL;

    return p_new;
}

int bt_rec_insert(struct btree **p_root, char *p_name_new)
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
    else
    {
        printf("Nome ja inserido\n");
        return 1;
    }
}

struct node
{
    struct node *p_nxt;   // Next element in queue
    char p_pid[8];        // Plane ID
    char p_dtn[4];        // Flight DesTiNation
    char p_cmp[20];       // Flight CoMPany
    char p_reg[9];        // Plane REGister
    char p_mdl[20];       // Plane MoDeL
    int  nst;             // Number os SeaTs
    struct btree *p_pl;   // Pointer to the Passenger List
};

struct queue
{
    struct node *p_h; // Pointer to queue Head
    struct node *p_t; // Pointer to queue Tail
};

int main(void)
{
    printf("Inicio do teste\n");
    struct node teste;

    teste.p_nxt = NULL;
    strcpy(teste.p_pid, "GLO1123");
    strcpy(teste.p_dtn, "CGH");
    strcpy(teste.p_cmp, "GOL");
    strcpy(teste.p_reg, "PR-XMW");
    strcpy(teste.p_mdl, "Boeing 737-7K5");
    teste.nst = 138;
    teste.p_pl = NULL;

    char n1[] = "Igor";
    char n2[] = "Marina";

    bt_rec_insert(&(teste.p_pl), n1);
    bt_rec_insert(&(teste.p_pl), n2);
    bt_rec_insert(&(teste.p_pl), n1);

    return 0;
}