#include <stdio.h>
#include <stdlib.h>

float media_notas(int *notas)
{
    float soma = 0;
    for (int i = 0; i < 4; i++)
        soma += notas[i];
    return soma / 4.0;
}

void verifica_aprovacao(int qtd_alunos, int **notas, int nota_media)
{
    for (int i = 0; i < qtd_alunos; i++)
    {
        float media = media_notas(notas[i]);
        printf("Aluno %d - Média: %.2f - ", i + 1, media);

        if (media >= nota_media)
            printf("APROVADO ✅\n");
        else
            printf("REPROVADO ❌\n");
    }
}

void printa_notas(int qtd_alunos, int **notas)
{
    for(int i = 0; i < qtd_alunos; i++)
    {
        printf("aluno %d\n notas:", i + 1);
        for(int j = 0;j < 4; j++)
        {
            printf("%d ", notas[i][j]);
        }
        printf("\n");
    }
}

int **pega_notas(int qtd_alunos)
{
    int **notas = malloc(sizeof(int*) * qtd_alunos);
    for(int i = 0; i < qtd_alunos;i++)
        notas[i] = malloc(sizeof(int) * 4);
    int i = 0;
    while(i < qtd_alunos)
    {

        printf("insira as 4 notas do aluno %d: \n", i + 1);
        printf("Primeira nota: ");
        scanf("%d", &notas[i][0]);
        printf("Segunda nota: ");
        scanf("%d", &notas[i][1]);
        printf("Terceira nota: ");
        scanf("%d", &notas[i][2]);
        printf("Quarta nota: ");
        scanf("%d", &notas[i][3]);
        int is_ok = 1;
        for(int j = 0; j < 4; j++)
        {
            if(notas[i][j] < 0 || notas[i][j] > 10)
            {
                printf("A nota precisa ser maior ou igual a zero e menor ou igual a 10.\n");
                is_ok = 0;
                break;
            }
        }
        if(is_ok)
            i++;
        
    }
    return notas;

}

int main(void)
{ 
    //pegar a quanidade de alunos e alocar dinamicamente as notas;
    int qtd_alunos;
    int **notas;
    while(1)
    {
        printf("Digite a quantidade de alunos: ");
        scanf("%d", &qtd_alunos);
        if (qtd_alunos <= 0)
            printf("quantidade de alunos deve ser positiva e não nula\n");
        else
            break;
    }
    notas = pega_notas(qtd_alunos);

    while(1)
    {
        int opcao;
        printf("MENU\n1: Mostrar alunos e notas.\n2: Mostrar aprovados e reprovados\n3: Sair\n");
        printf("Digite o numero da sua opção: ");
        scanf("%d", &opcao);
        if(opcao == 1)
            printa_notas(qtd_alunos,notas);
        else if(opcao == 2)
        {
            int nota_media;
            while(1)
            {
                printf("Digite a media necessária para aprovação: ");
                scanf("%d", &nota_media);
                if(nota_media > 10 || nota_media < 1)
                    printf("Digite um valor válido\n");
                else
                    break;
            }
            verifica_aprovacao(qtd_alunos, notas, nota_media);
        }
        else if(opcao == 3)
        {
            for(int i = 0; i < qtd_alunos; i++)
                free(notas[i]);
            free(notas);
            exit(0);
        }
        else
            printf("Digite uma opção válida\n");
    }
    return 0;
}