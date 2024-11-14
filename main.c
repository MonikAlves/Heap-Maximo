#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "print.h"
#include "heapMax.h"

int main() {
    int opcao;
    int heap[200];
    char valor[10000];
    int tamanho = 0;
    int numero;
    int busca = 0;
    
    while (1) {
        if (tamanho == 0) {
            limparTerminal();
            printf("Nenhum heap criado ainda. Por favor, crie um novo heap\n");
            opcao = 1;
        }else{
            limparTerminal();
            exibirMenu();   
            imprimirArvore(heap,tamanho);

            if(busca){
                mostrarRelacoes(heap,numero,tamanho);
                busca = 0;
            }


            printf("\n\nEscolha uma opção: ");
            scanf("%d%*c", &opcao);
        }
        switch(opcao) {
            case 1:
            printf("Digite os valores a serem inseridos, para finalizar digite '!':\n>> ");
                while (1){
                        scanf("%s",valor);
                        if (!strcmp(valor,"!")) break;
                        inserir(atoi(valor),heap,tamanho++);
                    }
                break;
            case 2:
                printf("Digite os valores a serem removidos, para finalizar digite '!':\n>> ");
                while (1){
                    scanf("%s",valor);
                    if (!strcmp(valor,"!")) break;
                    remover(atoi(valor),heap,&tamanho);
                    imprimirArvore(heap,tamanho);
                }
                break;
            case 3:  // Buscar vértice
                printf("Digite o numero a ser procurado:\n>> ");
                scanf("%d%*c",&numero);
                busca = 1;

                break;    
            case 4:
                if (tamanho == 0) {
                    printf("Nenhum heap criado ainda.\n");
                } else {
                    char confirmar;
                    printf("Tem certeza que deseja apagar o heap atual?\nDigite S para sim e N para não\n>> ");
                    scanf(" %c%*c",&confirmar);

                    if(confirmar == 'N' || confirmar == 'n') break;

                    tamanho = 0;
                    printf("heap apagada com sucesso!\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                return 0; 
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}

