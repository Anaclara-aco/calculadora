import java.util.Scanner;

class SistemaNotas {

    public static float mediaNotas(int[] notas) {
        float soma = 0;
        for (int n : notas) {
            soma += n;
        }
        return soma / 4f;
    }

    public static void verificaAprovacao(int[][] notas, float notaMedia) {
        for (int i = 0; i < notas.length; i++) {
            float media = mediaNotas(notas[i]);
            System.out.printf("Aluno %d - Média: %.2f - ", i + 1, media);
            
            if (media >= notaMedia)
                System.out.println("APROVADO ✅");
            else
                System.out.println("REPROVADO ❌");
        }
    }

    public static void printaNotas(int[][] notas) {
        for (int i = 0; i < notas.length; i++) {
            System.out.print("Aluno " + (i + 1) + " - Notas: ");
            for (int j = 0; j < 4; j++) {
                System.out.print(notas[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int[][] pegaNotas(int qtdAlunos, Scanner sc) {
        int[][] notas = new int[qtdAlunos][4];

        for (int i = 0; i < qtdAlunos; i++) {
            System.out.println("Digite as 4 notas do aluno " + (i + 1) + ":");

            for (int j = 0; j < 4; j++) {
                while (true) {
                    System.out.print("Nota " + (j + 1) + ": ");
                    int valor = sc.nextInt();

                    if (valor >= 0 && valor <= 10) {
                        notas[i][j] = valor;
                        break;
                    }

                    System.out.println("A nota deve estar entre 0 e 10.");
                }
            }
        }
        return notas;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int qtdAlunos;
        while (true) {
            System.out.print("Digite a quantidade de alunos: ");
            qtdAlunos = sc.nextInt();

            if (qtdAlunos > 0) break;
            System.out.println("Quantidade deve ser positiva.");
        }

        int[][] notas = pegaNotas(qtdAlunos, sc);

        while (true) {
            System.out.println("\nMENU");
            System.out.println("1: Mostrar alunos e notas.");
            System.out.println("2: Mostrar aprovados e reprovados.");
            System.out.println("3: Sair");
            System.out.print("Opção: ");

            int opcao = sc.nextInt();

            switch (opcao) {
                case 1:
                    printaNotas(notas);
                    break;

                case 2:
                    float media;
                    while (true) {
                        System.out.print("Digite a média necessária para aprovação: ");
                        media = sc.nextFloat();
                        if (media >= 0 && media <= 10) break;
                        System.out.println("Valor inválido.");
                    }
                    verificaAprovacao(notas, media);
                    break;

                case 3:
                    System.out.println("Saindo...");
                    sc.close();
                    return;

                default:
                    System.out.println("Opção inválida!");
            }
        }
    }
}
