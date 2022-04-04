  //v vettore di n interi
#include <stdio.h>
#define MAXN 30

int main(){
    FILE *fpin;
    int v[MAXN];
    int i=0;
    int j;
    int start;
    int lunghezzasottovettore=0;
    int lenvettore=0;
    int massimo=0;
    fpin=fopen("../input0.txt","r");

    if(fpin!=NULL){
        while(!feof(fpin)) {
            fscanf(fpin,"%d",&v[i]);
            if(v[i]==0){
                if(lunghezzasottovettore>=massimo){
                    massimo=lunghezzasottovettore;
                }
                lunghezzasottovettore=0;
            }else{
                lunghezzasottovettore++;
            }
            i++;
            lenvettore++;
        }
    }
    lunghezzasottovettore=0;
    for(i=0;i<lenvettore;i++){
        if(v[i]==0){
            if(lunghezzasottovettore==massimo) {
                start = i - massimo;
                printf("[");
                for (j = start; j < i; j++) {
                    printf("%d", v[j]);
                }
                printf("] ");
            }
            lunghezzasottovettore=0;
        }else{
            lunghezzasottovettore++;
        }
    }
    fclose(fpin);
    return 0;
}
