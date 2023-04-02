#include <stdio.h>
#include <stdlib.h> // CHATGPT
#include <time.h> // CHATGPT



    // USADAS PARA O MENU DO ARCADE
    int check = 1;
    int escolha = 0;
    
    // USADAS PARA O QUIZ
    int certas = 0;
    int resp;

    // USADAS PARA O JOGO DAS COBRAS
    // USADAS PARA DEFINIR AS CAIXAS
    int numAleatorio;
    int gerado;
    //RESTO DO JOGO
    int qComeca;
    int playerEsc;
    int playerRound;


int main()
{

    while (check == 1)
    {


        printf("\n====== BEM-VINDO ======\n");
        printf("\n==== BOLL's ARCADE ====\n");
        printf("\nEscolha um dos dois jogos:\n\n 1 - Quiz sobre Video Games;\n-->Um jogo de 5 perguntas sobre personagens de varios titulos conhecidos pelo mundo todo; \n\n 2 - Jogo das Cobras;\n-->Este e um jogo para DOIS voce e seu amigo escolhem em turnos entre 5 caixas diferentes onde voce pode tanto ganhar ou esncontrar algo terrivel; \n\n Selecione um dos dois: \n");
        scanf("%d", &escolha);

        // SWITCH CASE PARA OS JOGOS
        switch (escolha)
        {
        case 1: // QUIZ SOBRE VIDEO GAMES
            certas = 0;

            printf("Este e um quiz basico onde vamos te mostrar as perguntas e e so voce escolher a opcao certa no final mostraremos quantas voce acertou!\n INICIO\n");

            printf("Qual e o nome do pesonagem principal de Resident Evil: 4 ?\n 1) Ashley\n 2) Leon\n 3) Chris\n 4) Ada\n");
            scanf("%d", &resp);
            if (resp == 2)
            {
                certas++;
            }
            
            resp = 0;
            printf("Qual e o nome do personagem principal de Metal Gear Solid: 5?\n 1) Solid Snake\n 2) Big Boss\n 3) Venom Snake\n 4) Raiden\n");
            scanf("%d", &resp);
            if (resp == 1)
            {
                certas++;
            }
            
            resp = 0;
            printf("Qual e o nome do personagem principal de The Legend of Zelda: Breath of the Wild?\n 1) Link\n 2) Zelda\n 3) Ganon\n 4) Sheik\n");
            scanf("%d", &resp);
            if (resp == 1)
            {
                certas++;
            }
            
            resp = 0;
            printf("Qual e o nome do personagem principal de God of War?\n 1) Kratos\n 2) Zeus\n 3) Ares\n 4) Poseidon\n");
            scanf("%d", &resp);
            if (resp == 1)
            {
                certas++;
            }
            
            resp = 0;
            printf("Qual e o nome do personagem principal de Final Fantasy VII?\n 1) Cloud\n 2) Tifa\n 3) Aerith\n 4) Barret\n");
            scanf("%d", &resp);
            if (resp == 1)
            {
                certas++;
            }

            printf("\nVoce acertou um total de %d questoes!\n", certas);
            
            resp = 0;
            certas = 0;

            break;

        case 2: //JOGO DAS COBRAS
            printf("\nvoce e seu amigo entrao em uma caverna com um tesouro porem voces sao trancados em uma sala onde tem um total de 5 caixas onde uma delas vai salvar quem achar ela primeiro e outro pode finalizar a sua vida. E baseado em turnos cada um escolha uma caixa e depois que uma caixa e escolhida ela some das opcoes;\n");

            char player1[30];
            char player2[30];
            
            printf("\nDigite o nome do player 1:\n");
            scanf("%29s", player1);
            printf("\nDigite o nome do player 2:\n");
            scanf("%29s", player2); // USAR O %S PARA PRINTAR OS NOMES
            

            int caixas[5] = {0,0,0,0,0};
            int c = 1; // VARIAVEL PARA A CONTAGEM DO WHILE

            while(c == 1 || c == 2) // DEFINIÇÃO DA POSIÇÃO DA COBRA E DO BOTÃO
            {
                srand(time(NULL)); // CHATGPT --> FUNÇÃO SERVE PARA FAZER COM QUE A FUNÇÃO RAND() SEJA ALEATORIA TODA FEZ COM QUE O PROGRAMA INICIE

                numAleatorio = rand() % 4;

                if (c == 1)
                {
                    gerado = numAleatorio;
                    caixas[numAleatorio] = 1; // CAIXA ONDE FICA A COBRA;
                    c++;
                }
                

                if(c == 2 && gerado != numAleatorio){
                    caixas[numAleatorio] = 2; // CAIXA ONDE VAI FICAR O BOTAO
                    c++;
                }
                
            }

            qComeca = rand()%100;

            int gameON = 1;

            if(qComeca%2 == 0){
                // PLAYER1 COMECA
                playerRound = 1;
                
                while (gameON == 1)
                {
                    if (playerRound == 1)
                    {
                        printf("\nVez do %s\n", player1);
                    }else
                    {
                        printf("\nVez do %s\n", player2);
                    }

                    printf("\nEscolha uma das caixas 1-5: \n");
                    scanf("%d", &playerEsc);
                    if (playerRound == 1)
                    {
                        if(caixas[playerEsc-1] == 9){
                    
                            printf("\nESSA CAIXA JA FOI ESCOLHIDA PEGUE OUTRA\n");

                        }else if (caixas[playerEsc-1] == 1)
                        {
                            printf("\nO %s PERDEU!!! (Ele escolheu a caixa com a cobra)\n", player1);
                            gameON++;
                        }else if (caixas[playerEsc-1] == 2)
                        {
                            printf("\nO %s GANHOU!!! (Ele escolheu a caixa com o botao)\n", player1);
                            gameON++;
                        }else
                        {
                            caixas[playerEsc-1] = 9;
                            printf("\nNAO ACONTECEU NADA com o %s!!! (Ele escolheu uma caixa vazia)\n", player1);
                            printf("\nAgora e a vez do %s\n",player2);
                            playerRound = 2;
                        }
                    }
                    else
                    {
                        if(caixas[playerEsc-1] == 9){
                    
                            printf("\nESSA CAIXA JA FOI ESCOLHIDA PEGUE OUTRA\n");

                        }else if (caixas[playerEsc-1] == 1)
                        {
                            printf("\nO %s PERDEU!!! (Ele escolheu a caixa com a cobra)\n", player2);
                            gameON++;
                        }else if (caixas[playerEsc-1] == 2)
                        {
                            printf("\nO %s GANHOU!!! (Ele escolheu a caixa com o botao)\n", player2);
                            gameON++;
                        }else
                        {
                            caixas[playerEsc-1] = 9;
                            printf("\nNAO ACONTECEU NADA com o %s!!! (Ele escolheu uma caixa vazia)\n", player2);
                            printf("\nAgora e a vez do %s\n",player1);
                            playerRound = 1;
                        }
                    }
                    
                }
                
                
            }else{
                //PLAYER2 COMECA
                playerRound = 2;

                while (gameON == 1)
                {
                    if (playerRound == 1)
                    {
                        printf("\nVez do %s\n", player1);
                    }else
                    {
                        printf("\nVez do %s\n", player2);
                    }
                    
                    

                    printf("Escolha uma das caixas 1-5: \n");
                    scanf("%d", &playerEsc);

                    if (playerRound == 1)
                    {
                        if(caixas[playerEsc-1] == 9){
                    
                            printf("\nESSA CAIXA JA FOI ESCOLHIDA PEGUE OUTRA\n");

                        }else if (caixas[playerEsc-1] == 1)
                        {
                            printf("\nO %s PERDEU!!! (Ele escolheu a caixa com a cobra)\n", player1);
                            gameON++;
                        }else if (caixas[playerEsc-1] == 2)
                        {
                            printf("\nO %s GANHOU!!! (Ele escolheu a caixa com o botao)\n", player1);
                            gameON++;
                        }else
                        {
                            caixas[playerEsc-1] = 9;
                            printf("\nNAO ACONTECEU NADA com o %s!!! (Ele escolheu uma caixa vazia)\n", player1);
                            printf("\nAgora e a vez do %s\n",player2);
                            playerRound = 2;
                        }
                    }
                    else
                    {
                        if(caixas[playerEsc-1] == 9){
                    
                            printf("\nESSA CAIXA JA FOI ESCOLHIDA PEGUE OUTRA\n");

                        }else if (caixas[playerEsc-1] == 1)
                        {
                            printf("\nO %s PERDEU!!! (Ele escolheu a caixa com a cobra)\n", player2);
                            gameON++;
                        }else if (caixas[playerEsc-1] == 2)
                        {
                            printf("\nO %s GANHOU!!! (Ele escolheu a caixa com o botao)\n", player2);
                            gameON++;
                        }else
                        {
                            caixas[playerEsc-1] = 9;
                            printf("\nNAO ACONTECEU NADA com o %s!!! (Ele escolheu uma caixa vazia)\n", player2);
                            printf("\nAgora e a vez do %s\n",player1);
                            playerRound = 1;
                        }
                    }
                    
                }

            }

            break;
        
        default:
            printf("\nVOCE NAO ESCOLHEU UMA OPCAO VALIDA\n");
            break;
        }


        printf("Voce gostaria de continuar no arcade? (sim = 1 / nao = 2)\n");
        scanf("%d", &check);
        

    }
    
    return 0;
}