# Sistema de Heap Máximo
[Descrição](#descrição) | [Funcionalidades](#funcionalidades) | [Limitações](#limitações) | [Instruções para Uso](#instruções-para-uso)

## Descrição
Este projeto implementa um sistema de **heap máximo** que aceita e manipula números inteiros. Ele oferece funcionalidades de adição, remoção e busca de valores no heap, além de permitir a exclusão completa da estrutura.

## Funcionalidades
- **Adicionar Valor:**
  - O sistema permite a inserção de números inteiros na estrutura de heap máximo. Cada valor adicionado mantém a propriedade de heap máximo, onde cada nó pai é maior ou igual aos seus nós filhos.
  - A adição de valores continua até que o usuário digite '!' para finalizar a inserção.

- **Remover Valor:**
  - O usuário pode remover qualquer valor do heap. A estrutura é reorganizada automaticamente para manter as propriedades do heap após a remoção. Para parar a remoção deve digitar '!' tambem.

- **Buscar Valor:**
  - O sistema permite ao usuário buscar um valor específico no heap, indicando se o valor está presente ou não e mostra qual valor é o pai e quais são os filhos (se tiver).

- **Deletar Árvore:**
  - O usuário pode optar por deletar toda a estrutura de heap, removendo todos os valores e liberando a memória alocada.

## Limitações
- O heap atualmente aceita apenas números inteiros.
- A estrutura mantém apenas as propriedades de um heap máximo, sem suporte para estruturas de heap mínimo ou heaps de outros tipos.
- Não há suporte para valores não numéricos ou tipos complexos de dados.

## Instruções para Uso
1. **Compilação**: Compile o código-fonte usando um compilador C padrão.
2. **Execução**: Execute o programa e siga as instruções no console para adicionar, remover, buscar ou deletar valores do heap. 

### Como Compilar
Para compilar o programa, use o seguinte comando no terminal:
```bash
gcc main.c bibliotecas/*.c -I"bibliotecas" -o main
```
Esse comando compila o main.c e as bibliotecas associadas e gera o executável main.

Como Executar
Após a compilação, execute o programa com o seguinte comando:

```
./main
```
Isso iniciará o menu interativo, onde você poderá adicionar, remover, buscar valores ou apagar a estrutura completa do heap máximo.



