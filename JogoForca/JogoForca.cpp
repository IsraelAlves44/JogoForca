#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

void limpatela() {
    system("CLS");
}

string randomword() {
    string palavras[3] = { "arroz","pera","feijao" };

    int indicealatorio = rand() % 3;

    return palavras[indicealatorio];
    
}

void playalone() {
   
    string palavra = randomword();
    cout << "A palavra secreta é " << palavra;
}

void menuInicial() {

    int opcao = 0;

    while (opcao < 1 || opcao > 3)
    {
        limpatela();
        cout << "Bem-vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\n1 - Escolha uma opcao e tecle ENTER: ";

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            playalone();
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
    setlocale(LC_ALL, "Portuguese");
    srand((unsigned)time(NULL));

    menuInicial();
    

    return 0;
}