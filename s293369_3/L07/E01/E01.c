//0 bianco 1 nero

#include <stdio.h>
#define MAXN 50

void leggi_dim(int *dimrighe, int *dimcolonne, FILE *fpin);
void caricamatrice(int mappa[][MAXN],  int dimrighe,int dimcolonne,FILE *fpin);
void altezza(int mappa[][MAXN], int dimrighe,int dimcolonne);
void larghezza(int mappa[][MAXN], int dimrighe,int dimcolonne);
void area(int mappa[][MAXN], int dimrighe,int dimcolonne);
int minimo(int a, int b, int c);


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
        area(mappa,dimrighe,dimcolonne);
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
            printf("%d ",mappa[i][j]);
        }
        printf("\n");
    }
}

void altezza(int mappa[][MAXN], int dimrighe,int dimcolonne){
    int ricordariga,ricordacolonna,i,j;
    int hmax=0;
    int h_precedente=0;
    int count,area;
    int h;

    for(j=0;j<dimcolonne;j++){
        h=0;
        count=0;
        for(i=0;i<dimrighe;i++){
            if(mappa[i][j]==1){
                h++;
                if(h>hmax){
                    hmax=h;
                    count++;
                    ricordariga=i;
                    ricordacolonna=j;
                }else{
                    count=0;
                }
            }else{
                h=0;
            }
        }
        if(hmax==h_precedente && hmax!=0){
            count++;
        }else{
            count=1;
        }
        h_precedente=hmax;
    }
    area=hmax*count;
    printf("Max Altezza: estremo(%d,%d), altezza=%d, larghezza=%d, area=%d\n",ricordariga-hmax+1,ricordacolonna-count+1,hmax,count,area);
}

void larghezza(int mappa[][MAXN], int dimrighe,int dimcolonne){
    int ricordariga,ricordacolonna,i,j;
    int lmax=0;
    int l_precedente=0;
    int count,area;
    int l;

    for(i=0;i<dimrighe;i++){
        l=0;
        count=0;
        for(j=0;j<dimcolonne;j++){
            if(mappa[i][j]==1){
                l++;
                if(l>lmax){
                    lmax=l;
                    count++;
                    ricordariga=i;
                    ricordacolonna=j;
                }else{
                    count=0;
                }
            }else{
                l=0;
            }
        }
        if(lmax==l_precedente && lmax!=0){
            count++;
        }else{
            count=1;
        }
        l_precedente=lmax;
    }
    area=lmax*count;
    printf("Max Larghezza: estremo(%d,%d), altezza=%d, larghezza=%d, area=%d\n",ricordacolonna-lmax+1,ricordariga-count+1,count,lmax,area);
}

void area(int mappa[][MAXN],int dimrighe, int dimcolonne){
    int i,j;
    int S[dimrighe][dimcolonne];
    int result,area,larghezza,altezza,estremox,estremoy;
    int max_of_s, max_i, max_j;

    //prima colonna
    for(i = 0; i < dimrighe; i++){
        S[i][0] = mappa[i][0];
        //printf("%d ",S[i][0]);
    }
    //printf("\n");
    //prima riga
    for(j = 0; j < dimcolonne; j++){
        S[0][j] = mappa[0][j];
        //printf("%d ",S[0][j ]);
    }
    //printf("\n");
    //printf("\n");

    for(i = 1; i < dimrighe; i++)
    {
        for(j = 1; j < dimcolonne; j++)
        {
            if(mappa[i][j] == 1) {
                result=minimo(S[i][j - 1], S[i - 1][j], S[i - 1][j - 1]);
                S[i][j] = result + 1;
            }else {
                S[i][j] = 0;
            }
            //printf("%d ",S[i][j]);
        }
        //printf("\n");
    }

    max_of_s = S[0][0]; max_i = 0; max_j = 0;
    for(i = 0; i < dimrighe; i++)
    {
        for(j = 0; j < dimcolonne; j++)
        {
            if(max_of_s < S[i][j])
            {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    //printf("\n\n");
    //printf("i %d j %d s %d",max_i-max_of_s+1,max_j-max_of_s+1,max_of_s);
    //printf("i %d j %d \n",max_i,max_j);
    estremox=max_i-max_of_s+1;
    estremoy=max_j-max_of_s+1;
    larghezza=max_i-max_i-max_of_s;
    altezza=max_j-max_j-max_of_s;
    area=(larghezza)*(altezza);
    printf("Max area: estremo(%d,%d), altezza=%d, larghezza=%d, area=%d\n",estremox,estremoy,altezza,larghezza,area);

}

int minimo(int a, int b, int c)
{
    int m = a;
    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return m;
}
