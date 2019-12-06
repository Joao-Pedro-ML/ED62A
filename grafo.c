#include "graf.h"




int main(int argc, char** argv) {

    filaDin f;
    obj o;
    obj Fila;
    int **auxiliar;
    obj i;
    obj j;
    obj ver;
    iniciaFilaDin(&f);
    int tamanho = 0;
    vertice *G;
    FILE *arq1 = NULL;
    arq1 = fopen("entrada.txt", "a");
    if(arq1 == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
        exit(1);
    }
    char metodo, percurso;
    fscanf(arq1, "%c\n", &metodo);
    fscanf(arq1, "%c\n", &percurso);
    //pegar vertices do arquivo
    char c[100];
    char *aux;
    fgets(c,100,arq1);
    aux = strtok(c,"(,)\n");
    while(aux != NULL){
        Fila.key = atoi(aux);
        if(tamanho < Fila.key){
            tamanho = Fila.key;
        }
        enqueue(&f,Fila);
        aux = strtok(NULL,"(,)\n");
    }
    printf("%i", tamanho);
    int inicial;
    if(metodo == 'M' || metodo == 'm') {

        G = (vertice *) malloc(tamanho * sizeof(vertice));
        int **auxiliar;
        auxiliar = (int **) malloc(tamanho * sizeof(int *));
        for (int i = 0; i < tamanho; i++) {
            auxiliar[i] = (int *) malloc(tamanho * sizeof(int));
        }

        iniciaVertice(G, tamanho);
        while (!estaVazia(&f)) {
            i = dequeue(&f, o);
            j = dequeue(&f, o);
            auxiliar[i.key - 1][j.key - 1] = 1;
        }
        if (percurso == 'B' || percurso == 'b') {
            fscanf(arq1, "%i", &inicial);

            FILE *arq2 = NULL;
            arq2 = fopen("saida.txt", "w");
            if(arq2 == NULL){
                printf("Erro ao abrir o arquivo de saída!\n");
            }
            G[inicial - 1].cor = 'c';
            G[inicial - 1].d = 0;
            G[inicial - 1].pai = -1;
            fprintf(arq2, "%i[d=%i]\n", inicial, G[inicial-1].d);
            iniciaFilaDin(&f);
            o.key = inicial;
            enqueue(&f, o);
            while (!estaVazia(&f)) {
                o = dequeue(&f, o);
                for (ver.key = 0; ver.key < tamanho; ver.key++) {
                    if (auxiliar[o.key][ver.key] == 1) {
                        if (G[ver.key].cor == 'b') {
                            G[ver.key].cor = 'c';
                            G[ver.key].d = G[o.key].d + 1;
                            G[ver.key].pai = o.key;
                            fprintf(arq2, "%i[d=%i]\n", ver.key + 1, G[ver.key+1].d);
                            enqueue(&f, ver);
                        }
                    }
                }
                G[o.key].cor = 'p';
            }
        }
        if(percurso == 'D' || percurso == 'd'){

        }

    }
    return (EXIT_SUCCESS);
}
