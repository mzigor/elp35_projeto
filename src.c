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

struct tree
{
    char name[40];
    struct tree *p_l;
    struct tree *p_r;
};

struct node
{
    struct node *p_nxt; // Next element in queue
    char pid[8];        // Plane ID
    char dtn[4];        // Flight DesTiNation
    char cmp[20];       // Flight CoMPany
    char reg[9];        // Plane REGister
    char mdl[20];       // Plane MoDeL
    int  nst;           // Number os SeaTs
    struct tree *p_pl;  // Pointer to the Passenger List
};

struct queue
{
    struct node *p_h; // Pointer to queue Head
    struct node *p_t; // Pointer to queue Tail
};