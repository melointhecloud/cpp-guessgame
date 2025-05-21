# Jogo de Adivinhação em C++

Este é um projeto de um jogo de adivinhação de números desenvolvido em C++. O jogo gera um número aleatório e o jogador deve adivinhar qual é esse número dentro de um número limitado de tentativas.

## ⚙️ Funcionalidades

*   **Níveis de Dificuldade:** Fácil, Médio e Difícil, cada um com um intervalo de números e número de tentativas diferentes.
*   **Pontuação:** O jogador começa com uma pontuação inicial e perde pontos com base na proximidade do palpite em relação ao número secreto.
*   **Interface Amigável:** Mensagens claras e prompts para guiar o jogador durante o jogo.
*   **Suporte a UTF-8:** Exibe corretamente caracteres acentuados e outros símbolos da língua portuguesa.

## 📋 Pré-requisitos

Para executar este projeto, você precisará de:

*   **Compilador C++:**
    *   Certifique-se de ter um compilador C++ instalado (como g++ ou Visual Studio).
*   **Git (opcional, para clonar o repositório):**
    *   Baixe e instale o Git a partir do [site oficial](https://git-scm.com/downloads).

## 🚀 Como usar

Siga os passos abaixo para clonar, compilar e executar o projeto:

1.  **Clonar o Repositório**

    Abra o terminal (Git Bash, CMD ou PowerShell) e execute o comando abaixo para clonar o repositório para o seu computador:

    ```bash
    git clone https://github.com/melointhecloud/guess-game.git
    ```

    Isso criará uma pasta chamada `guess-game` com todos os arquivos do projeto.

2.  **Compilar o Código**

    *   **Usando g++ (Linux, macOS ou MinGW no Windows)**

        Navegue até a pasta do projeto:

        ```bash
        cd guess-game
        ```

        Compile o código com o comando:

        ```bash
        g++ -o guessgame main.cpp -fexec-charset=UTF-8
        ```

    *   **Usando o Visual Studio (Windows)**

        1.  Abra o Visual Studio.
        2.  Clique em `Arquivo` > `Abrir` > `Projeto/Solução`.
        3.  Navegue até a pasta onde você clonou o repositório e selecione o arquivo de projeto (se houver) ou crie um novo projeto console e adicione o arquivo `main.cpp`.
        4.  Compile o projeto clicando em `Build` > `Build Solution` (ou pressione `Ctrl+Shift+B`).

3.  **Executar o Jogo**

    *   **No Linux/macOS**

        ```bash
        ./guessgame
        ```

    *   **No Windows**

        ```bash
        guessgame.exe
        ```

4.  **Jogar**

    *   O jogo irá pedir para escolher um nível de dificuldade.
    *   Tente adivinhar o número secreto dentro do número de tentativas permitidas.
    *   Siga as instruções na tela para jogar.

## 🧪 Testando o Projeto

Se você não quiser usar o Visual Studio, pode compilar o código manualmente usando o g++ (GNU Compiler Collection). Siga os passos abaixo:

1.  Certifique-se de que o g++ está instalado no seu sistema.
2.  Compile o código com o comando:

    ```bash
    g++ -o guessgame main.cpp -fexec-charset=UTF-8
    ```
3.  Execute o programa:

    ```bash
    ./guessgame
    ```

## 📂 Estrutura do Projeto

A estrutura do projeto é a seguinte:

guess-game/
├── main.cpp # Código-fonte principal do jogo
├── README.md # Documentação do projeto
└── LICENSE # Licença do projeto (se houver)
└── .gitignore # Arquivo para ignorar arquivos desnecessários


## 📝 Licença

Este projeto está licenciado sob a licença MIT. Isso significa que você pode usá-lo, modificá-lo e distribuí-lo livremente, desde que mantenha os créditos ao autor original. Consulte o arquivo `LICENSE` para mais detalhes.

## 🤝 Contribuindo

Contribuições são bem-vindas! Se você quiser melhorar este projeto, siga os passos abaixo:

1.  Faça um fork do repositório.
2.  Crie um branch para sua feature:

    ```bash
    git checkout -b minha-feature
    ```
3.  Faça suas alterações e commit:

    ```bash
    git commit -m "Adiciona minha nova feature"
    ```
4.  Envie para o branch principal:

    ```bash
    git push origin minha-feature
    ```
5.  Abra um Pull Request no GitHub.

## 📞 Suporte

Se você tiver dúvidas ou problemas, sinta-se à vontade para abrir uma issue no repositório.

## 🌟 Agradecimentos

Obrigado por conferir este projeto! Se você gostou, não se esqueça de dar uma ⭐ no repositório. 😊