#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print.h"

#define max 100

void trocar(int * heap,int primeiro, int segundo){
    int aux = heap[primeiro];
    heap[primeiro] = heap[segundo];
    heap[segundo] = aux;
}

int pai(int filho){
    return (filho-1)/2;
}

int filhoEsq(int pai){
    return pai*2+1;
}

int filhoDir(int pai){
    return pai*2+2;
}

void inserir(int valor, int * heap,int tamanho){
    heap[tamanho] = valor;
    if(tamanho == 0 ) return;
    int indice = tamanho;

    while(indice > 0){
        if(heap[pai(indice)] < heap[indice] ){
            trocar(heap,pai(indice),indice);
            indice = pai(indice);
        }else break;
    }

    return;
}

int busca(int * heap,int valor,int tamanho){
    for(int i =0; i < tamanho;i++){
        if(heap[i] == valor) return i;
    }

    return -1;

}

void organizarBaixo(int * heap,int indice,int indiceMaior,int tamanho){
    if(indice < 0 || indiceMaior >= tamanho) return;
    trocar(heap,indice,indiceMaior);

    indice = indiceMaior;

    if(heap[indice] < heap[filhoDir(indice)] || heap[indice] < heap[filhoEsq(indice)]){
        if(heap[filhoDir(indice)] > heap[filhoEsq(indice)] ){
            organizarBaixo(heap,indice,filhoDir(indice),tamanho);
        }else{
            organizarBaixo(heap,indice,filhoEsq(indice),tamanho);
        }
    }
    return;
}

void organizarCima(int * heap,int indice, int indiceMenor,int tamanho){
    if(indice < 0 || indiceMenor < 0) return;
    trocar(heap,indice,indiceMenor);
    inserir(heap[indice],heap,indice);

    indice = indiceMenor;    

    if(heap[pai(indice)] < heap[indice]){
        organizarCima(heap,indice,pai(indice),tamanho);
    }
    return;
}

int remover(int valor, int * heap,int *tamanho){
    int tamanhos = *tamanho;
    if(tamanhos == 0 ) return 0;
    int indice = busca(heap,valor,tamanhos);

    if(indice == -1) return 0;

    trocar(heap,indice,--tamanhos);

    if(heap[pai(indice)] < heap[indice]){
        organizarCima(heap,indice,pai(indice),tamanhos);
    }else if( heap[indice] < heap[filhoDir(indice)] || heap[indice] < heap[filhoEsq(indice)]){
        if(heap[filhoDir(indice)] > heap[filhoEsq(indice)] ){
            organizarBaixo(heap,indice,filhoDir(indice),tamanhos);
        }else{
            organizarBaixo(heap,indice,filhoEsq(indice),tamanhos);
        }
        
    }

    *tamanho = tamanhos;

    return 1;
}

void mostrarRelacoes(int * heap,int valor,int tamanho){
    int indice = busca(heap,valor,tamanho);
    if(indice != -1){
        printf("\nAs relações do %d são : \n\n",heap[indice]);
        if(indice > 0 ) printf("Pai -> %d\n",heap[pai(indice)]);
        if(filhoEsq(indice) < tamanho) printf("Filho esquerdo -> %d\n",heap[filhoEsq(indice)]);
        if(filhoDir(indice) < tamanho) printf("Filho direito -> %d",heap[filhoDir(indice)]);
    }else{
        printf("\nO valor %d não se encontra na arvore\n",valor);
    }
}
