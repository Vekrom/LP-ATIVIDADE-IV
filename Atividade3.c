#include <stdio.h>
#include <string.h>
#include <locale.h>


struct Produto {
    char nome[333];
    float preco;
    int quantidade_estoque;
};


float calcular_valor_total(struct Produto produto) {
    return produto.preco * produto.quantidade_estoque;
}


void realizar_compra(struct Produto *produto) {
    int quantidade_compra;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidade_compra);

    if (quantidade_compra > 0 && quantidade_compra <= produto->quantidade_estoque) {
        produto->quantidade_estoque -= quantidade_compra;
        printf("Compra realizada com sucesso. Novo estoque: %d\n", produto->quantidade_estoque);
    } else {
        printf("Quantidade inválida. Compra não realizada.\n");
    }
}


void consultar_estoque(struct Produto produto) {
    printf("Nome do produto: %s\n", produto.nome);
    printf("Quantidade do produto: %d\n", produto.quantidade_estoque);
    printf("Preço por unidade: R$ %.2f\n", produto.preco);
    printf("Valor total em estoque: R$ %.2f\n", calcular_valor_total(produto));
}


void adicionar_produto(struct Produto *produto) {
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidade_estoque);
    printf("Digite o preço por unidade: ");
    scanf("%f", &produto->preco);
}

int main() {
      setlocale(LC_ALL, "");
    struct Produto meuProduto;

    int escolha;

    do {
        printf("\t\n===== Menu =====\n");
        printf("1. Adicionar produto\n");
        printf("2. Realizar uma compra\n");
        printf("3. Consultar estoque\n");
        printf("4. Sair do programa\n");

        printf("Escolha uma opção: \n");
        scanf("%d", &escolha);
        fflush(stdin);
        switch (escolha) {
            case 1:
                adicionar_produto(&meuProduto);
                break;

            case 2:
                realizar_compra(&meuProduto);
                break;

            case 3:
                consultar_estoque(meuProduto);
                break;

            case 4:
                printf("Fechando o programa\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 4);

    return 0;
}
