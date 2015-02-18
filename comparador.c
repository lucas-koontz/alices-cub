#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in_1, *in_2;

    //in_1 = fopen("out_dijkstra.txt", "r");
    //in_2 = fopen("out_raman.txt", "r");

	in_1 = fopen("entrada.txt", "r");
    in_2 = fopen("entrada_teste.txt", "r");
    if(!in_1 || !in_2){
		puts("ERRO AO CARREGAR ARQUIVOS in_1 E/OU in_2");
        exit(EXIT_FAILURE);
	}
    char aux1[33], aux2[33];
    int dif = 0;
	int i = 1;
    while(i<=12870) {
		fgets(aux1, 31, in_1);
        fgets(aux2, 31, in_2);
        aux1[strlen(aux1)-1] = '\0';
        aux2[strlen(aux2)-1] = '\0';
        if(strcmp(aux1, aux2)){
			printf("entrada 1: %s\tentrada 2: %s\n", aux1, aux2);
            dif++;
            printf("%d\n", i);//informa a linha em que houve divergencia
		}
		i++;
    }
    printf("%d\n", dif);
    return 0;
}
