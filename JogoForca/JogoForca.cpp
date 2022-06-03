#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

void screenCleaner() {
    system("CLS");
}

string randomWord() {
    string palavras[3] = { "arroz","pera","feijao" };

    int indicealatorio = rand() % 3;

    return palavras[indicealatorio];
    
}

string returnMaskedWord (string word, int wordSize) {
    int cont = 0;

    string maskedWord;

    while (cont < wordSize)
    {
        maskedWord += "_";
        cont++;
    }

    return maskedWord;
}

void showStatus(string maskedWord, int wordSize, int remainingAttempts, string crossedOutLetters) {

    cout << "Palavra " << maskedWord << " (Tamanho: " << wordSize << ")";
    cout << "\nTentativas restantes:" << remainingAttempts;

    int cont = 0;
    cout << "\nLetras Riscadas: ";

    for (cont = 0; cont < crossedOutLetters.size(); cont++)
    {
        cout << crossedOutLetters[cont] << ", ";
    }
}

void playAlone() {
   
    string word = randomWord();

    int wordSize = word.size();

    string maskedWord = returnMaskedWord(word, wordSize);

    int attempts = 0, maximumAttempts =  5;
    int cont = 0;
    char letter{};
    string crossedOutLetters;
    bool typedLetter{};

    while (maximumAttempts - attempts > 0 && word != maskedWord)
    {
        screenCleaner();
        showStatus(maskedWord, wordSize, maximumAttempts - attempts, crossedOutLetters);
        cout << "\nDigite uma letra: ";
        cin >> letter;
        crossedOutLetters += letter;
        

        for (cont = 0; cont < attempts; cont++)
        {
            if (crossedOutLetters[cont] == letter) {
                cout << "Essa letra j� foi digitada1!";
                typedLetter = true;
            }
        }

        if (typedLetter == false)
        {
            for (cont = 0; cont < wordSize; cont++)
            {
                if (word[cont] == letter) {
                    maskedWord[cont] = word[cont];
                }
            }
            attempts++;
        }
        
    }

    if (word == maskedWord)
    {
        screenCleaner();
        cout << "Parab�ns, voc� venceu!";
    }
    else {
        screenCleaner();
        cout << "O n�mero de tentativas foi estourado, voc� perdeu! :(";
    }
}

void menuInicial() {

    int opcao = 0;

    while (opcao < 1 || opcao > 3)
    {
        screenCleaner();
        cout << "Bem-vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\n1 - Escolha uma opcao e tecle ENTER: ";

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            playAlone();
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