# Projeto final de Estruturas de Dados e Algoritmos

- disciplina: ELP35
- nome: Aplicações de Estruturas de Dados e Algoritmos
- ano: 2025
- semestre: 1º
- turma: S12

## Instruções

Desenvolver um programa em C que simule o controle de uma pista de decolagem de 
aviões em um aeroporto.

No programa, o usuário deve ser capaz de realizar as seguintes tarefas:

1. Cadastrar voos na fila de espera;

2. Cadastrar nomes na lista de passageiros de um voo (o usuário deve informar o 
ID do voo desejado);

3. Remover nomes da lista de passageiros de um voo (o usuário deve informar o ID
do voo e nome desejado);

4. Listar todas as características do primeiro avião da fila (exceto a lista de 
passageiros);

5. Autorizar a decolagem do primeiro avião da fila (removendo-o da fila). Não 
esquecer de remover também a lista de passageiros;

6. Listar o número de aviões aguardando na fila de decolagem;

7. Listar os dados de todos os aviões na fila de espera (um em cada linha da 
tela, exceto a lista de passageiros), conforme modelo;

8. Listar na tela os passageiros de um determinado voo em ordem alfabética e 
informar no final a quantidade de passageiros no voo;

9. Sair do programa (liberar a lista de passageiros e voos antes de finalizar).


## Modelo para printout da lista de espera

```
ID do voo    Destino    Empresa    Registro    Modelo             Assentos
GLO1123      CGH        GOL        PR-XMW      Boeing 737-7K5     138
TAM3283      GRU        TAM        PT-MXB      Airbus A321-211    220
AZU4603      FLN        AZUL       PR-TKJ      ATR 72-600         78
```


## Struct para a árvore de passageiros

``` c
struct tree
{
    char nome[40];
    struct tree *left;
    struct tree *right;
};
```


## Struct para a fila de voos

``` c
struct node
{
    struct node *prox;
    char Id[8];
    char Destino[4];
    char Empresa[20];
    char Registro[9];
    char Modelo[20];
    int Assentos;
    struct tree *lp;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *voo;
```


## Recursos

Uma [lista de aviões comerciais](https://en.wikipedia.org/wiki/List_of_commercial_jet_airliners), com o número de aviões ainda em uso.
