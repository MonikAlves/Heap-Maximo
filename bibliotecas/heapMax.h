#ifndef __HEAPMAX_H__
#define __HEAPMAX_H__

void trocar(int * heap,int primeiro, int segundo);
int pai(int filho);
int filhoEsq(int pai);
int filhoDir(int pai);
void inserir(int valor, int * heap,int tamanho);
int busca(int * heap,int valor,int tamanho);
void organizarBaixo(int * heap,int indice,int indiceMaior,int tamanho);
int remover(int valor, int * heap,int *tamanho);
void mostrarRelacoes(int * heap,int valor,int tamanho);

#endif