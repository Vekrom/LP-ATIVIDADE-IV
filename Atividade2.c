#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


struct Aluno {
    float nota1, nota2, media;
    char nome[333];
    char data_nascimento[333];
};


float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}


void verificador(struct Aluno aluno){
    if (aluno.media >= 7.0) {
        printf("O(a) aluno(a) %s está aprovado.\n", aluno.nome);
    } else if (aluno.media >= 5.0){
        printf("O(a) aluno(a) %s está apto para recuperação.\n", aluno.nome);
    } else {
        printf("O(a) aluno(a) %s está reprovado.\n", aluno.nome);
    }
}

int main() {
    setlocale(LC_ALL, "");
    int i;
    struct Aluno alunos[5];

    
    for (i = 0; i < 2; i++) {
        printf("Informe o nome do %dº aluno: ", i + 1);
        scanf("%s", alunos[i].nome);
        printf("Informe a data de nascimento do aluno %d: ", i + 1);
        scanf("%s", alunos[i].data_nascimento);
        printf("Informe a nota 1º do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("Informe a nota 2º do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        
        alunos[i].media = calcularMedia(alunos[i]);
    }

   
    for (i = 0; i < 2; i++) {
        printf("Média do aluno: %s: %.2f\n", alunos[i].nome, alunos[i].media);
        verificador(alunos[i]);
    }

    return 0;
}
