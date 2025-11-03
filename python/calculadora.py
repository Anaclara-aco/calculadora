def media_notas(notas):
    return sum(notas) / 4

def verifica_aprovacao(notas, nota_media):
    for i, notas_aluno in enumerate(notas, start=1):
        media = media_notas(notas_aluno)
        print(f"Aluno {i} - Média: {media:.2f} - ", end="")
        if media >= nota_media:
            print("APROVADO ✅")
        else:
            print("REPROVADO ❌")

def printa_notas(notas):
    for i, notas_aluno in enumerate(notas, start=1):
        print(f"Aluno {i} - Notas:", notas_aluno)

def pega_notas(qtd_alunos):
    notas = []
    for i in range(qtd_alunos):
        print(f"\nDigite as 4 notas do aluno {i + 1}:")
        notas_aluno = []
        for j in range(4):
            while True:
                valor = int(input(f"Nota {j + 1}: "))
                if 0 <= valor <= 10:
                    break
                print("A nota deve ser entre 0 e 10.")
            notas_aluno.append(valor)
        notas.append(notas_aluno)
    return notas

def main():
    while True:
        qtd_alunos = int(input("Digite a quantidade de alunos: "))
        if qtd_alunos > 0:
            break
        print("Quantidade deve ser positiva e não nula.")

    notas = pega_notas(qtd_alunos)

    while True:
        print("\nMENU")
        print("1: Mostrar alunos e notas.")
        print("2: Mostrar aprovados e reprovados.")
        print("3: Sair")

        opcao = int(input("Digite a opção: "))

        if opcao == 1:
            printa_notas(notas)
        elif opcao == 2:
            while True:
                nota_media = float(input("Digite a média necessária para aprovação: "))
                if 0 <= nota_media <= 10:
                    break
                print("Digite um valor válido.")
            verifica_aprovacao(notas, nota_media)
        elif opcao == 3:
            print("Saindo...")
            break
        else:
            print("Opção inválida.")

main()
