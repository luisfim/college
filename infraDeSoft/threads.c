
#include <ncurses.h>
#include <stdbool.h>

char resp;
int linha, vol;
bool livre, arquivo;


void adicionarArquivo(){
    printf("Selecione o arquivo \n");
    printf("Em qual track você deseja adicionar?\n");
    scanf("%d", & linha);
    if(arquivo==livre){
        printf("Arquivo adicionado com sucesso");
    }

    else{
        printf("Este track já tem um arquivo, deseja substituir? (Y/N)\n");
        if ( resp == 'Y' || resp == 'y'){
            printf("Arquivo substituido\n");
        }
        if ( resp == 'N' || resp == 'n'){
            printf("Arquivo não substituido\n");
        }
        else{
            printf("Resposta inválida\n");
        }

    }
}

void track(){
    printf("O que você deseja fazer?\n");
    printf("V- Ajustar volume?\n");
    printf("P- Pausar track\n");
    printf("N- Mudar nome?\n");
    scanf("%c", & resp);

    if (resp == 'V' || resp == 'v'){
        printf("Digite o volume desejado (0-100)\n");
        scanf("%d", & vol);
    }
    if(resp == 'p' || resp == 'P'){
        printf("Track pausado!");
    }
    if(resp == 'N' || resp == "n"){
        printf("Digite o novo nome do track");
        scanf("%c");    //nome do track
    }
}


int main()
{
    bool tocando = false;
    int tecla;

    initscr();
    noecho();
    curs_set(0);

    while (1)
    {
        clear();

        mvprintw(2, 10, "PAINEL DJ");

        mvprintw(4, 10, "TRACK 1");
        mvprintw(5, 10, "TRACK 2");
        mvprintw(6, 10, "TRACK 3");
        mvprintw(7, 10, "TRACK 4");
        mvprintw(8, 10, "TRACK 5");


        // if (tocando)
        //     mvprintw(X, 10, "Música: [ TOCANDO ]");
        // else
        //     mvprintw(X, 10, "Música: [ PAUSADA ]");

        mvprintw(10, 10, "P - Pause/Play");
        mvprintw(11, 10, "T - Track");
        mvprintw(12, 10, "A - Adicionar Track");
        mvprintw(13, 10, "Q - Sair");

        refresh();

        tecla = getch();

        if (tecla == 'p' || tecla == 'P')
            tocando = !tocando;
        if (tecla == 't' || tecla == 'T')
            track();
        if (tecla == 'A' || tecla == 'a')
            adicionarArquivo();
        if (tecla == 'q' || tecla == 'Q')
            break;
    }

    endwin();

    return 0;
}