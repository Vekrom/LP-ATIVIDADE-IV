#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

struct meusprodutos {
char nome[333];
float preco;    
int quantidade;
};

float calcularTotal (struct meusprodutos *produto){
      return produto->preco * produto->quantidade;
}


void realizarCompra(struct meusprodutos *produto) {
    int quantidade_vendas;
    printf("Quantidade de produtos: ");
    scanf("%d", &quantidade_vendas);

    if (quantidade_vendas > 0 && quantidade_vendas <= produto->quantidade) {
        produto->quantidade -= quantidade_vendas;
        printf("Compra realizada\n");
    } else {
        printf("Quantidade inválida\nVerifique o estoque.\n");
    }
}



int main() {
   
    struct meusprodutos meuproduto = {"Produto A", 10.0, 50};
    int opcao;
    
    do {
        
        printf("\nMenu:\n");
        printf("Escolha uma opção: ");
        printf("1. Realizar uma compra\n");
        printf("2. Consultar estoque\n");
        printf("3. Sair do programa\n");
        scanf("%d", &opcao);

        // Realizar ações com base na opção escolhida
        switch (opcao) {
            case 1:
                realizarCompra(&meuproduto);
                break;
            case 2:
                printf("Estoque disponível: %d unidades\n", meuproduto.quantidade);
                printf("Valor total em estoque: R$ %.2f\n", calcularTotal(&meuproduto));
                break;
            case 3:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
