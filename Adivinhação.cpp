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
        wcout << L"\nEscolha o nível de dificuldade:" << endl;
        wcout << L"1 - Fácil (1-50, 15 tentativas)" << endl;
        wcout << L"2 - Médio (1-100, 10 tentativas)" << endl;
        wcout << L"3 - Difícil (1-200, 5 tentativas)" << endl;
        wcout << L"Escolha: ";

        while (!(wcin >> nivel) || nivel < 1 || nivel > 3)
        {
            wcout << L"Opção inválida! Escolha entre 1 e 3: ";
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

        wcout << L"\nBem-vindo ao Jogo de Adivinhação!" << endl;
        wcout << L"Tente adivinhar o número entre " << minNumero << L" e " << maxNumero << endl;
        wcout << L"Você tem " << maxTentativas << L" tentativas." << endl;

        while (tentativas < maxTentativas)
        {
            wcout << L"\nTentativa " << tentativas + 1 << L"/" << maxTentativas << endl;
            wcout << L"Digite seu palpite: ";

            while (!(wcin >> palpite))
            {
                wcout << L"Por favor, digite um número válido: ";
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
            wcout << L"\nParabéns! Você venceu!" << endl;
            wcout << L"Número de tentativas: " << tentativas << endl;
            wcout << L"Pontuação final: " << max(0, pontuacao) << endl;
        }
        else
        {
            wcout << L"\nGame Over! O número era: " << numeroSecreto << endl;
            wcout << L"Pontuação final: 0" << endl;
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