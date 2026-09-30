// 10. Conta bancaria: as funcoes alteram a conta por ponteiro.
#include <cstdio>
#include <cmath>

struct ContaBancaria {
    char Nome[51];
    int Numero;
    float Saldo;
};

bool depositar(ContaBancaria* conta, float valor) {
    if (!std::isfinite(valor) || valor <= 0 || !std::isfinite(conta->Saldo + valor)) return false;
    conta->Saldo += valor;
    return true;
}

bool sacar(ContaBancaria* conta, float valor) {
    if (!std::isfinite(valor) || valor <= 0 || valor > conta->Saldo) return false;
    conta->Saldo -= valor;
    return true;
}

void exibirSaldo(ContaBancaria conta) {
    std::printf("Titular: %s | Conta: %d | Saldo: R$ %.2f\n",
                conta.Nome, conta.Numero, conta.Saldo);
}

int main() {
    ContaBancaria conta;
    conta.Saldo = 0;
    std::printf("Nome do titular: ");
    if (std::scanf(" %50[^\n]", conta.Nome) != 1) return 1;
    std::printf("Numero da conta: ");
    if (std::scanf("%d", &conta.Numero) != 1) return 1;
    while (true) {
        int opcao;
        float valor;
        std::printf("\n1 - Depositar\n2 - Sacar\n3 - Exibir saldo\n0 - Sair\nOpcao: ");
        if (std::scanf("%d", &opcao) != 1) return 1;
        if (opcao == 0) break;
        if (opcao == 1 || opcao == 2) {
            std::printf("Valor: ");
            if (std::scanf("%f", &valor) != 1) return 1;
            bool sucesso = opcao == 1 ? depositar(&conta, valor) : sacar(&conta, valor);
            if (sucesso) exibirSaldo(conta);
            else std::printf("Operacao recusada: valor invalido ou saldo insuficiente.\n");
        } else if (opcao == 3) {
            exibirSaldo(conta);
        } else {
            std::printf("Opcao invalida.\n");
        }
    }
    return 0;
}
