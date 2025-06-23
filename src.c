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
    struct tree *p_l;
    struct tree *p_r;
};

struct btree *bt_cr_leaf(char *p_name_new)
{
    struct btree *p_new = malloc(sizeof(struct btree));

    strcpy(p_new->p_name, p_name_new);

    p_new->p_l = NULL;
    p_new->p_r = NULL;

    return p_new;
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
    struct node teste;

    teste.p_nxt = NULL;
    strcpy(teste.p_pid, "GLO1123");
    strcpy(teste.p_dtn, "CGH");
    strcpy(teste.p_cmp, "GOL");
    strcpy(teste.p_reg, "PR-XMW");
    strcpy(teste.p_mdl, "Boeing 737-7K5");
    teste.nst = 138;
    teste.p_pl = NULL;

    return 0;
}