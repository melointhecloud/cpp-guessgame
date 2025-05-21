#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <locale>
#include <clocale>

using namespace std;

class JogoAdivinhacao
{
private:
    int numeroSecreto;
    int tentativas;
    int maxTentativas;
    int minNumero;
    int maxNumero;
    int pontuacao;

public:
    JogoAdivinhacao() : tentativas(0), pontuacao(100) {}

    void configurarDificuldade()
    {
        int nivel;
        wcout << L"\nEscolha o n�vel de dificuldade:" << endl;
        wcout << L"1 - F�cil (1-50, 15 tentativas)" << endl;
        wcout << L"2 - M�dio (1-100, 10 tentativas)" << endl;
        wcout << L"3 - Dif�cil (1-200, 5 tentativas)" << endl;
        wcout << L"Escolha: ";

        while (!(wcin >> nivel) || nivel < 1 || nivel > 3)
        {
            wcout << L"Op��o inv�lida! Escolha entre 1 e 3: ";
            wcin.clear();
            wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
        }

        switch (nivel)
        {
        case 1:
            minNumero = 1;
            maxNumero = 50;
            maxTentativas = 15;
            break;
        case 2:
            minNumero = 1;
            maxNumero = 100;
            maxTentativas = 10;
            break;
        case 3:
            minNumero = 1;
            maxNumero = 200;
            maxTentativas = 5;
            break;
        }

        numeroSecreto = rand() % (maxNumero - minNumero + 1) + minNumero;
    }

    void jogar()
    {
        int palpite;
        bool ganhou = false;

        wcout << L"\nBem-vindo ao Jogo de Adivinha��o!" << endl;
        wcout << L"Tente adivinhar o n�mero entre " << minNumero << L" e " << maxNumero << endl;
        wcout << L"Voc� tem " << maxTentativas << L" tentativas." << endl;

        while (tentativas < maxTentativas)
        {
            wcout << L"\nTentativa " << tentativas + 1 << L"/" << maxTentativas << endl;
            wcout << L"Digite seu palpite: ";

            while (!(wcin >> palpite))
            {
                wcout << L"Por favor, digite um n�mero v�lido: ";
                wcin.clear();
                wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
            }

            tentativas++;

            if (palpite == numeroSecreto)
            {
                ganhou = true;
                break;
            }
            else
            {
                if (palpite > numeroSecreto)
                {
                    wcout << L"Muito alto!" << endl;
                }
                else
                {
                    wcout << L"Muito baixo!" << endl;
                }

                pontuacao -= abs(palpite - numeroSecreto) / 2;
            }
        }

        mostrarResultado(ganhou);
    }

    void mostrarResultado(bool ganhou)
    {
        if (ganhou)
        {
            wcout << L"\nParab�ns! Voc� venceu!" << endl;
            wcout << L"N�mero de tentativas: " << tentativas << endl;
            wcout << L"Pontua��o final: " << max(0, pontuacao) << endl;
        }
        else
        {
            wcout << L"\nGame Over! O n�mero era: " << numeroSecreto << endl;
            wcout << L"Pontua��o final: 0" << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    locale::global(locale("pt_BR.UTF-8"));
    wcout.imbue(locale("pt_BR.UTF-8"));

    srand(time(0));
    wchar_t jogarNovamente;

    do
    {
        JogoAdivinhacao jogo;
        jogo.configurarDificuldade();
        jogo.jogar();

        wcout << L"\nDeseja jogar novamente? (s/n): ";
        wcin >> jogarNovamente;
    } while (tolower(jogarNovamente) == 's');

    wcout << L"\nObrigado por jogar!" << endl;
    return 0;
}