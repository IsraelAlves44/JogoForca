#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

void limpatela() {
    system("CLS");
}

void menuInicial() {

    int opcao = 0;

    while (opcao < 1 || opcao > 3)
    {
        cout << "Bem-vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\n1 - Escolha uma opcao e tecle ENTER: ";

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Jogando";
            break;
        case 2:
            cout << "informacoes";
            break;
        case 3:
            cout << "saindo";
            break;
        }

    }
}

int main(void)
{

    menuInicial();
    limpatela();

    return 0;
}