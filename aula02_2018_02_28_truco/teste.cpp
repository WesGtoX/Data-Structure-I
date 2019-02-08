#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARTAS 40
#define CARTAS_MAO 3
#define VIRA 1
#define SIM 1
#define NAO 0


enum NAIPES {OURO, ESPADA, COPAS, PAUS};
enum CARTAS {QUATRO, CINCO, SEIS, SETE, DAMA, VALETE, REI, AS, DOIS, TRES,};



typedef struct {
    int  naipe, carta, descartada;
}S_CARTA;

S_CARTA cartas[MAX_CARTAS], jogador01[CARTAS_MAO], vira,
jogador02[CARTAS_MAO], computador01[CARTAS_MAO], computador02[CARTAS_MAO];

void embaralha_cartas(void)
{
    int i, carta=0, naipe=0;

    for (i=0; i<MAX_CARTAS; i++) {
        cartas[i].carta = carta;
        cartas[i].naipe = naipe;
        cartas[i].descartada = NAO;

        if (carta == 9) {
            carta = 0;
            naipe++;
            if (naipe >3) break;
        } else carta++;
    }
}

void dar_cartas(void)
{
    int i, num;

    for (i=0; i<CARTAS_MAO; i++)
    {
        do {
            num = rand() % MAX_CARTAS;
            if (cartas[num].descartada == NAO)
            {
                jogador01[i].carta = cartas[num].carta;
                jogador01[i].naipe = cartas[num].naipe;
                jogador01[i].descartada = cartas[num].descartada;
                cartas[num].descartada = SIM;
                break;
            }
        } while (SIM);

        do {
            num = rand() % MAX_CARTAS;
            if (cartas[num].descartada == NAO)
            {
                jogador02[i].carta = cartas[num].carta;
                jogador02[i].naipe = cartas[num].naipe;
                jogador02[i].descartada = cartas[num].descartada;
                cartas[num].descartada = SIM;
                break;
            }
        } while (SIM);

        do {
            num = rand() % MAX_CARTAS;
            if (cartas[num].descartada == NAO)
            {
                computador01[i].carta = cartas[num].carta;
                computador01[i].naipe = cartas[num].naipe;
                computador01[i].descartada = cartas[num].descartada;
                cartas[num].descartada = SIM;
                break;
            }
        } while (SIM);
do {
            num = rand() % MAX_CARTAS;
            if (cartas[num].descartada == NAO)
            {
                computador02[i].carta = cartas[num].carta;
                computador02[i].naipe = cartas[num].naipe;
                computador02[i].descartada = cartas[num].descartada;
                cartas[num].descartada = SIM;
                break;
            }
        } while (SIM);

       }        //mudei o fim do for, vira fora do for

       // vc estava acessando além do declarado, vira[i] 0,1,2

        do {
            num = rand() % MAX_CARTAS;

            if (cartas[num].descartada == NAO)

            {
                vira.carta = cartas[num].carta;
                vira.naipe = cartas[num].naipe;
                vira.descartada = cartas[num].descartada;
                cartas[num].descartada = SIM;
                break;
            }
        } while (SIM);


}
void nome_carta(S_CARTA *s)
{
    char str[50], *str2;

    switch (s->carta) {
        case 0: strcpy(str,"QUATRO"); break;
        case 1: strcpy(str,"CINCO"); break;
        case 2: strcpy(str,"SEIS"); break;
        case 3: strcpy(str,"SETE"); break;
        case 4: strcpy(str,"DAMA"); break;
        case 5: strcpy(str,"VALETE"); break;
        case 6: strcpy(str,"REI"); break;
        case 7: strcpy(str,"AS"); break;
        case 8: strcpy(str,"DOIS"); break;
        case 9: strcpy(str,"TRES"); break;
    }

    switch (s->naipe) {
        case 0: strcat(str," DE OURO"); break;
        case 1: strcat(str," DE ESPADA"); break;
        case 2: strcat(str," DE COPAS"); break;
        case 3: strcat(str," DE PAUS"); break;
    }

    printf("%s\n",str);

    str[0] = '\0';
}

int main(int argc, char* argv[])
{
    int i;

    srand(time(NULL));

    embaralha_cartas();
    dar_cartas();

    // for (i=0; i<MAX_CARTAS; i++) nome_carta(&cartas[i]);
 printf("CARTAS DO JOGADOR 01 \n");

    for (i=0; i<3; i++)
    {
        printf("Jogador - Carta %d >> ",i+1);
        nome_carta(&jogador01[i]);
    }

   printf("\nCARTAS DO JOGADOR 02 \n");

    for (i=0; i<3; i++)
    {
        printf("Jogador - Carta %d >> ",i+1);
        nome_carta(&jogador02[i]);
    }

    printf("\nCARTAS DO COMPUTADOR 01\n");

    for (i=0; i<3; i++)
    {
        printf("Computador - Carta %d >> ",i+1);
        nome_carta(&computador01[i]);
    }

    printf("\nCARTAS DO COMPUTADOR 02\n");

    for (i=0; i<3; i++)
    {
        printf("Computador - Carta %d >> ",i+1);
        nome_carta(&computador02[i]);
    }


    {
        printf("\n VIRA - Carta >> ");
        nome_carta(&vira);  //aki tb vira[i], somente vira é o suficiente:w

    }


    return 0;

}
