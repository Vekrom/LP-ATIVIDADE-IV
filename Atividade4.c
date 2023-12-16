#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct conta
{
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

int main()
{
    setlocale(LC_ALL, "");
    int opcao;
    float valor;

    struct conta minhaconta;
    char titular[333];
    int numeroconta[333];
    char titularcerto[333] = "Vekrom";
    int numerocontacorreto = 123;
  

    //do
    //{
        printf("digite o nome do Titular da conta:\n");
        scanf("%s", &titular);
        printf("digite numero da conta:\n");
        scanf("%d", &numeroconta);
        if (titular == titularcerto && numeroconta == numerocontacorreto)
        {
            printf("login ou senha inválidos");
        }
        else
        {
            printf("bem vindo! %s \n");
        }

   // } while (titular != titularcerto || numeroconta != numerocontacorreto);

    do
    {

        printf("\t\nSelecione uma opção: \n");
        printf("\t\n1. Depositar\n");
        printf("\t\n2. Sacar\n");
        printf("\t\n3. Consultar saldo\n");
        printf("\t\n4. Sair da\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\tValor para depósito: \n");
            scanf("%f", &valor);
            depositar(&minhaconta, valor);
            break;
        case 2:
            printf("\t\nInforme o valor para saque: \n");
            scanf("%f", &valor);
            sacar(&minhaconta, valor);
            break;
        case 3:
            imprimirSaldo(&minhaconta);
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

//até tarde, mas n consegui. Valeu o aprendizado

