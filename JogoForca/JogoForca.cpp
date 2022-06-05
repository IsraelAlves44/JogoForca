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

void showStatus(string maskedWord, int wordSize, int remainingAttempts, string crossedOutLetters, string messages) {

    cout << messages;
    cout << "\nPalavra " << maskedWord << " (Tamanho: " << wordSize << ")";
    cout << "\nTentativas restantes:" << remainingAttempts;

    int cont;
    cout << "\nLetras arriscadas: ";

    for (cont = 0; cont < crossedOutLetters.size(); cont++)
    {
        cout << crossedOutLetters[cont] << ", ";
    }
}

int playAlone() {
   
    string word = randomWord();

    int wordSize = word.size();

    string maskedWord = returnMaskedWord(word, wordSize);

    int attempts = 0, maximumAttempts =  10;
    int cont = 0;
    char letter{};
    string crossedOutLetters;
    bool typedLetter{};
    string messages = "Bem-vindo ao jogo";
    bool rightLetter{};
    string wordTry;
    int option;

    while (word != maskedWord && maximumAttempts - attempts > 0)
    {
        screenCleaner();
    
        showStatus(maskedWord, wordSize, maximumAttempts - attempts, crossedOutLetters, messages);
        
        cout << "\nDigite uma letra: (ou digite 1 para arriscar a palavra): ";
        cin >> letter;

        if (letter == '1') {
            cin >> wordTry;
            if (wordTry == word) {
                maskedWord = wordTry;
            }
            else {
                attempts = maximumAttempts;
            }
        }

        // Se for a mesma letra já digitada
        for (cont = 0; cont < attempts; cont++)
        {
            if (crossedOutLetters[cont] == letter)
            {
                messages = "Essa letra já foi digitada!";
                typedLetter = true;
            }
        }

        if (typedLetter == false)
        {

            
            crossedOutLetters += tolower(letter);

            for (cont = 0; cont < wordSize; cont++)
            {
                if (word[cont] == tolower(letter)) {
                    maskedWord[cont] = word[cont];
                    rightLetter = true;
                }
            }
            

            if (rightLetter == false) {
                messages = "Você errou uma letra!";
            }
            else {
                messages = "Você acertou uma letra!";
                rightLetter = false;
            }

            attempts++;
        }

        typedLetter = false;
        rightLetter = false;
    }

    

    if (word == maskedWord)
    {
        screenCleaner();
        cout << "Parabéns, você venceu!";
        cout << "Deseja reiniciar?";

        cout << "\n1 - Sim";
        cout << "\n2 - Não\n";
        cin >> option;
        return option;
    }
    else {
        screenCleaner();
        cout << "O número de tentativas foi estourado, você perdeu! :(";
        cout << "\nDesenja reiniciar?";
        cout << "\n1 - Sim";
        cout << "\n2 - Não\n";
        cin >> option;

        return option;
    }
}

void menuInicial() {

    int option = 0;

    while (option < 1 || option > 3)
    {
        screenCleaner();
        cout << "Bem-vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\n1 - Escolha uma opcao e tecle ENTER: ";

        cin >> option;

        switch (option)
        {
        case 1:
            if (playAlone() == 1) {
                menuInicial();
            }
            else {
                cout << "Até mais :)";
            }
            break;
        case 2:

            
            screenCleaner();
            cout << "*****Informações*****";
            cout << "Featured by Israel Alves em 2022";
            cout << "\n1 - Voltar";
            cout << "\n2 - Sair\n: ";
            cin >> option;

            if (option == 1) {
                menuInicial();
            }
            else {
                cout << "Até mais :)";
            }
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