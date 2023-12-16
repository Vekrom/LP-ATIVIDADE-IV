#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


struct conta
{
    char nomeTitular[333];
    char tipoConta[333];
    int numeroConta;
    float saldo;
};



void depositar(struct conta *conta, float valor)
{
      
    conta->saldo += valor;
    printf("\n\tDepósito de R$ %.2f realizado com sucesso.\n", valor);
}

void sacar(struct conta *conta, float valor)
{
    if (valor > 0 && valor <= conta->saldo)
    {
        conta->saldo -= valor;
        printf("\n\tSaque no valor de R$ %.2f.\n", valor);
        printf("\n\tRealizado com Sucesso!\n");
    }
    else
    {
        printf("\n\tSaldo insuficiente ou valor ditado inv lido.\n");
        printf("\n\tPor favor tente novamente.\n");
    }
}

void imprimirSaldo(struct conta *conta)
{
    printf("\n\tSaldo atual: R$ %.2f\n", conta->saldo);
}

int main(){
setlocale(LC_ALL, "");
    struct conta minhaConta = {123456, 200.0, "Vekrom", "corrente"};
    int opcao;
    float valor;
  



    do
    {

      

        printf("\t\nSelecione uma opção: \n");
        printf("\t\n1. Depositar\n");
        printf("\t\n2. Sacar\n");
        printf("\t\n3. Consultar saldo\n");
        printf("\t\n4. Sair do aplicativo\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\tValor para depósito: \n");
            scanf("%f", &valor);
            depositar(&minhaConta, valor);
            break;
        case 2:
            printf("\t\nInforme o valor para saque: \n");
            scanf("%f", &valor);
            sacar(&minhaConta, valor);
            break;
        case 3:
            imprimirSaldo(&minhaConta);
            break;
        case 4:
            printf("\t\nSaindo do programa...\n");
            break;
        default:
            printf("\t\nOpção inválida!\n");
            printf("\t\nTente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}


void depositar(struct conta *conta, float valor);
void sacar(struct conta *conta, float valor);
void imprimirSaldo(struct conta *conta);
