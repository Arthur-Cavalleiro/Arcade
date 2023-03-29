#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{

    char check = 'n';

    while (check != 'y')
    {

        //CHEKAGEM SE O USUARIO QUER SAIR DO APP
        printf("\nVoce deseja continuar? y/n\n");
        check = getche(); //Pega o input do usuario no terminal;
    }

}


    //rand() FUNÇÃO PARA GERAR UM NUMERO ALEATORIO
    //printf("%d ", rand() % 100);


    //Pega o input do usuario no terminal;
    //getche(); // mostra o input do usuario
    //getch(); // não mostra o input do usuario