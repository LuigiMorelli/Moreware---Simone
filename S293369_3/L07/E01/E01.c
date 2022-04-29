//0 bianco 1 nero

#include <stdio.h>
#define MAXN 50

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin);
void caricamatrice(int mappa[][MAXN],  int dimrighe,int dimcolonne,FILE *fpin);
void altezza(int mappa[][MAXN], int dimrighe,int dimcolonne);
void larghezza(int mappa[][MAXN], int dimrighe,int dimcolonne);


int main(){
    FILE *fpin;
    int dimrighe,dimcolonne;
    int mappa[MAXN][MAXN];
    fpin=fopen("../input0.txt","r");

    if(fpin!=NULL){
        leggi_dim(&dimrighe,&dimcolonne,fpin);
        caricamatrice(mappa,dimrighe,dimcolonne,fpin);
        altezza(mappa,dimrighe,dimcolonne);
        larghezza(mappa,dimrighe,dimcolonne);
    }else{
        printf("errore file");
    }

    fclose(fpin);
    return 0;
}

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin){
    do{
        fscanf(fpin,"%d %d",dimrighe,dimcolonne);
    }while(*dimrighe>MAXN && *dimcolonne>MAXN);
}

void caricamatrice(int mappa[][MAXN], int dimrighe,int dimcolonne,FILE *fpin){
    int i,j;
    for(i=0;i<dimrighe;i++){
        for(j=0;j<dimcolonne;j++){
            fscanf(fpin,"%d",&mappa[i][j]);
        }
    }
}

void altezza(int mappa[][MAXN], int dimrighe,int dimcolonne){
    int ricordariga,ricordacolonna,i,j;
    int hmax=0;
    int h=0;

    for(j=0;j<dimcolonne;j++){
        h=0;
        for(i=0;i<dimrighe;i++){
            if(mappa[i][j]==1){
                h++;
                if(h>=hmax){
                    hmax=h;
                    ricordariga=i;
                    ricordacolonna=j;
                }
            }else{
                h=0;
            }
        }
    }
    printf("Max Altezza: estremo(%d,%d), altezza=%d \n",ricordariga-hmax+1,ricordacolonna,hmax);
}

void larghezza(int mappa[][MAXN], int dimrighe,int dimcolonne) {
    int ricordariga, ricordacolonna, i, j;
    int lmax = 0;
    int l = 0;

    for (i = 0; i < dimrighe; i++) {
        l=0;
        for (j = 0; j < dimcolonne; j++) {
            if (mappa[i][j] == 1) {
                l++;
                if(l>lmax){
                    lmax=l;
                    ricordariga=i;
                    ricordacolonna=j;
                }
            }else{
                l=0;
            }
        }
    }
    printf("Max Larghezza: estremo=(%d,%d), larghezza=%d", ricordariga, ricordacolonna-lmax+1,lmax);
}
