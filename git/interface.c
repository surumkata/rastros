#define BUF_SIZE 1024

#include <stdio.h>
#include <string.h>
#include "logica.h"
#include "dados.h"
#include "listas.h"

void mostrar_prompt (ESTADO *e){
    int num_comandos = obter_num_comandos(e);
    int num_jogadas = obter_numero_de_jogadas(e);
    int jogador = obter_jogador_atual(e);
    printf("# %d JOG%d N%d\n",num_comandos,jogador,num_jogadas);
}

void mostrar_tabuleiro(ESTADO *e) {
    printf("==========\n");
    for (int lin = 0; lin <= 7; lin++) {
        printf("|");
        for (int col = 0; col <= 7; col++) {
            COORDENADA c;
            c.linha = lin;
            c.coluna = col;
            if (obter_estado_casa(e,c)==BRANCA) putchar ('*') ;
            else if (col==7 && lin==0) putchar ('2');
            else if (col==0 && lin==7) putchar ('1');
            else if (obter_estado_casa(e,c)==PRETA) putchar ('#') ;
            else putchar ('.');
        }
        printf("| %d\n",8-lin);
    }
    printf("==========\n ABCDEFGH\n");
    mostrar_prompt(e);
}

void movs (ESTADO *e){
    int n = obter_numero_de_jogadas(e);
    int j = obter_jogador_atual(e);
    for (int i = 0; i<n; i++){
        JOGADA jgd = obter_jogada(e,i);
        COORDENADA c1 = jgd.jogador1;
        COORDENADA c2 = jgd.jogador2;
        int a = 97;
        char col1 = (char) (a + c1.coluna);
        char col2 = (char) (a + c2.coluna);
        if (i < 9) printf("0%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
        else printf("%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
    }
    if (j == 2) {
        JOGADA jgd = obter_jogada(e, n);
        COORDENADA c1 = jgd.jogador1;
        if (n < 9) printf("0%d: %c%d \n", n+1, (char) (97+c1.coluna), (8 - c1.linha));
        else printf("%d: %c%d \n", n+1, (char) (97+c1.coluna), (8 - c1.linha));
    }
}

void gravar_movs (ESTADO *e, FILE *filename){
    int n = obter_numero_de_jogadas(e);
    int j = obter_jogador_atual(e);
    for (int i = 0; i<n; i++){
        JOGADA jgd = obter_jogada(e,i);
        COORDENADA c1 = jgd.jogador1;
        COORDENADA c2 = jgd.jogador2;
        int a = 97;
        char col1 = (char) (a + c1.coluna);
        char col2 = (char) (a + c2.coluna);
        if (i < 9) fprintf(filename,"0%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
        else fprintf(filename,"%d: %c%d %c%d\n", i+1, col1, (8 - c1.linha), col2, (8 - c2.linha));
    }
    if (j == 2) {
        JOGADA jgd = obter_jogada(e, n);
        COORDENADA c1 = jgd.jogador1;
        if (n < 9) fprintf(filename,"0%d: %c%d \n", n+1, (char) (97+c1.coluna), (8 - c1.linha));
        else fprintf(filename,"%d: %c%d \n", n+1, (char) (97+c1.coluna), (8 - c1.linha));
    }
}

void gravar_tabuleiro(ESTADO *e,FILE *filename) {
    for (int lin = 0; lin <= 7; lin++) {
        for (int col = 0; col <= 7; col++) {
            COORDENADA c;
            c.linha = lin;
            c.coluna = col;
            if (obter_estado_casa(e,c)==BRANCA) fprintf (filename,"*") ;
            else if (col==7 && lin==0) fprintf (filename,"2");
            else if (col==0 && lin==7) fprintf (filename,"1");
            else if (obter_estado_casa(e,c)==PRETA) fprintf (filename,"#") ;
            else fprintf (filename,".");
        }
        fprintf(filename, "\n");
    }
    fprintf(filename, "\n");
}

void gravar (ESTADO *e, const char *filename, const char *mode){
    FILE *ficheiro;
    ficheiro = fopen(filename,mode);
    gravar_tabuleiro(e,ficheiro);
    gravar_movs (e,ficheiro);
    fclose(ficheiro);
}

void ler (ESTADO *e, const char *filename, const char *mode) {
    FILE *ficheiro;
    ficheiro = fopen(filename,mode);
    char d;
    COORDENADA cord;
    int p=0;
    for (int lin = 0; lin <=7 ; lin++ ) {
        cord.linha=lin;
        for (int col = 0; col <=8 ; col++) {
            cord.coluna = col;
            fscanf(ficheiro,"%c",&d);
            if (d != '\n') {
                   altera_tabuleiro(e,d,cord);
                   if (d=='#') p++;
            }
        }
    }
    fscanf (ficheiro, "\n");
    start_num_jogadas (e);
    start_jogador (e);
    for (int i=0; i<p/2; i++){
        int c1l, c2l;
        char n1, n2, c1c, c2c;
        fscanf (ficheiro, "%c%c: %c%d %c%d\n", &n1, &n2, &c1c, &c1l, &c2c, &c2l);
        COORDENADA cord1, cord2;
        cord1.linha=8-c1l;
        cord2.linha=8-c2l;
        cord1.coluna=(int) c1c-97;
        adic_jogadas (e, cord1);
        atualiza_jog_atual(e);
        cord2.coluna=(int) c2c-97;
        adic_jogadas (e, cord2);
        adic_num_jogadas(e);
        atualiza_jog_atual(e);
    }
    if (p%2!=0){
        char n1, n2, c1c;
        int c1l;
        fscanf (ficheiro, "%c%c: %c%d", &n1, &n2, &c1c, &c1l);
        COORDENADA cord1;
        cord1.linha=8-c1l;
        cord1.coluna=(int)c1c-97;
        adic_jogadas(e, cord1);
        atualiza_jog_atual(e);
    }
    mostrar_tabuleiro(e);
    fclose(ficheiro);
}

void regressa_pos (ESTADO *e, int p) {
     int nj = obter_numero_de_jogadas(e);
     if (p <= nj){
         COORDENADA uc = obter_ultima_jogada(e);
         altera_para_vazio(e,uc);
         if (obter_jogador_atual(e) == 2) atualiza_jog_atual(e);
         for (; nj >= p; nj--) {
             JOGADA j = obter_jogada(e, nj-1);
             COORDENADA j1 = j.jogador1;
             COORDENADA j2 = j.jogador2;
             if (nj == p) {
                 if (nj == 0) {
                     COORDENADA inicial;
                     inicial.linha = 3;
                     inicial.coluna = 4;
                     altera_para_branca(e,inicial);
                     altera_para_vazio(e, j1);
                     altera_para_vazio(e, j2);
                 }
                 else {
                     altera_para_branca(e, j2);
                     atualiza_ultima_jogada(e, j2);
                 }
             } else {
                 subt_num_jogadas(e);
                 altera_para_vazio(e, j1);
                 altera_para_vazio(e, j2);
             }
         }
     }
     else if (p > nj){
         for (;nj < p;nj++){
             JOGADA j = obter_jogada(e, nj);
             COORDENADA j1 = j.jogador1;
             COORDENADA j2 = j.jogador2;
             jogar(e,j1);
             jogar(e,j2);
         }
     }
}



int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2], a, b, c, d;
    char filename[50];
    int numj;
    mostrar_tabuleiro(e);
    while (acabou(e) != 1) {
        if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
        if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', '8' - *lin};
            jogar(e, coord);
            adic_num_comandos(e);
            mostrar_tabuleiro(e);
        }
        else if (sscanf(linha,"%c%c%c%[^\n]",&a,&b,&c,filename)==4 && a == 'g' && b == 'r' && c == ' ') {
            gravar(e,filename,"w+");
            printf("Gravado com sucesso.\n");
            adic_num_comandos(e);
        }
        else if (sscanf(linha,"%c%c%c%c%[^\n]",&a,&b,&c,&d,filename)==5 && a == 'l' && b == 'e' && c == 'r' && d == ' '){
            ler(e,filename,"r");
            adic_num_comandos(e);
        }
        else if (strlen(linha) == 5 && sscanf(linha,"%c%c%c%c",&a,&b,&c,&d)==4 && a == 'm' && b == 'o' && c == 'v' && d == 's'){
            adic_num_comandos(e);
            movs(e);
        }
        else if (sscanf(linha,"%c%c%c%c%d",&a,&b,&c,&d,&numj) && a == 'p' && b == 'o' && c == 's' && d == ' ') {
            regressa_pos(e,numj);
            adic_num_comandos(e);
            mostrar_tabuleiro(e);
            }
        else if (strlen(linha) == 4 && sscanf(linha,"%c%c%c",&a,&b,&c)==3 && a == 'j' && b == 'o' && c == 'g'){
            LISTA l = obtem_jogadas_possiveis(e);
            COORDENADA c = heuristica_aleatoria(l);
            jogar(e,c);
            adic_num_comandos(e);
            mostrar_tabuleiro(e);
        }
        else if (strlen(linha) == 2 && sscanf(linha,"%c",&a)==1 && a == 'Q') return 1;
        }


    if (quem_ganhou(e) == 1)
        printf("Parabéns jogador 1, és o grande vencedor!\n");
    else
        printf("Parabéns jogador 2, és o grande vencedor!\n");
    return 1;
}

