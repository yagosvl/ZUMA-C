#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define cor1 3
#define cor2 7
#define linhas 3
#define colunas 15

typedef struct jogador{
int posicao;
char simbolo;
char tiro;
char ptiro;
} tJogador;

typedef struct cobra{
char valor;
int x, y;
struct cobra *prox, *ant;} tCobra;

void imprime_lista_teste(tCobra *inicio){
    tCobra *aux;
    system("cls");

    for(aux=inicio;aux!=NULL;aux=aux->prox){
                                            printf("\t%c\t%p\n",aux->valor, *aux);
                                            printf("\n");
                                            }
}

void imprime_first(char campo[linhas][colunas],char tiro, char ptiro){
     int i,j;
     for(i=0; i<linhas; i++){
             for(j=0; j<colunas; j++){printf("%c ", campo[i][j]);}
             printf("\n");
             }
    printf("\n\nTiro Atual: %c\nProximo Tiro: %c\n\n\n", tiro, ptiro);
}

void imprime_mangue(char campo[linhas][colunas],char tiro, char ptiro){
     int j;
     
             for(j=0; j<colunas; j++){printf("%c ", campo[0][j]);}
             printf("\n\n\n");

    printf("\n\nTiro Atual: %c\nProximo Tiro: %c\n\n\n", tiro, ptiro);
}
     
int main(void){ //jogo
    tCobra *cabeca;
    char campo[linhas][colunas];
    
    //<Inicializando a cobra>
    tCobra *aux, *pre;
    int cont;
      
    for(cont=0; cont<4; cont++){
                 aux = (tCobra*)malloc(sizeof(tCobra));
                 if(aux==NULL){
                               printf("Erro ao inicializar, o jogo sera fechado.\n");
                               system("pause");
                               exit(EXIT_FAILURE);
                               }
                 if(cont==0){
                             cabeca = aux;
                             cabeca->ant = NULL;}
                 else if(cont==1){
                                  cabeca->prox=aux;
                                  aux->ant=cabeca;
                                  pre = aux;}
                 else {
                      pre->prox = aux;
                      aux->ant = pre;
                      pre = aux;}
                 aux->x = -1;
                 aux->y = -1;
                 aux->valor=rand()%(cor2-cor1)+cor1;}
                 aux->prox=NULL;
                 //imprime_lista_teste(cabeca);
    //</Inicializando Cobra>
    
    //<Inicializando Campo>
    int i, j;
    for(i=0; i<linhas; i++){
             for(j=0; j<colunas; j++){campo[i][j] = '_';}
             }
    //</Inicializando Campo>
    
    //<Preparando o player>
    srand(time(NULL));
    tJogador play;
    play.tiro = rand()%(cor2-cor1)+cor1;
    play.simbolo = '@';
    play.posicao = colunas/2;    
    play.ptiro = rand()%(cor2-cor1)+cor1;
    campo[linhas-1][play.posicao] = play.simbolo;
    //</Preparando o player>
    
    //<Imprimindo pela primeira vez>
    
    imprime_first(campo, play.tiro, play.ptiro);    //</Imprimindo pela primeira vez>
    
    //aux = cabeca;       
    while(cabeca->y != 0 && aux != NULL){
                    //<Fazendo a bicha andar>
                                 cabeca->x = 0;
                                 cabeca->y = colunas-1;
                                 campo[0][colunas-1] = cabeca->valor;
                                 
                    /*else{aux = cabeca;
                         while(aux!= NULL){
                         (aux->prox)->x = aux->x;
                         (aux->prox)->y = aux->y;
                         campo[aux->x][(aux->y)-1]= aux->valor;
                         aux = aux->prox;
                         (aux->ant)->x = aux->x; //s� vale no deslocamento horizontal
                         (aux->ant)->y = (aux->y)-1;
                         campo[aux->x][(aux->y)]= aux->valor;}
                         }*/
                    
                    //</Fazendo a bicha andar>
                    imprime_mangue(campo, play.tiro, play.ptiro);
                    system("pause");     
                    }             
                             
    system("pause");
    return 0;
}
