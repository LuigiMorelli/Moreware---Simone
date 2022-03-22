#define inputtext "../input0.txt"
#include <stdio.h>

int somma(int d0,int d1,int d2);
int prodotto(int d0,int d1,int d2);
int divisione(int d0,int d1,int d2);
int sottrazione(int d0, int d1,int d2);
int operation(int d0,int d1,int d2);

int main(){
FILE *fp_read;
int d0,d1,d2;
int checkoperation;
int countscartati =0;
fp_read=fopen(inputtext,"r");

if(fp_read!=NULL){
    fscanf(fp_read,"%d%d%d",&d0,&d1,&d2);
    while(!feof(fp_read)) {
        checkoperation=operation(d0,d1,d2);
        //printf("%d",checkoperation);
        if(checkoperation==0){
            fscanf(fp_read,"%d",&d2);
            countscartati++;
        }else{
            d0=d1;
            d1=d2;
            fscanf(fp_read,"%d",&d2);

        }


    }
}
if (countscartati==0){
    printf("tutti i dati rispettano la condizione");
}else{
    printf("Numeri scarati: %d",countscartati);

}
fclose(fp_read);
return 0;

}

int operation(int d0,int d1,int d2){
    if(somma(d0,d1,d2)==1){
        return 1;
    }else if (prodotto(d0,d1,d2)==1){
        return 1;
    }else if (sottrazione(d0,d1,d2)==1){
        return 1;
    }else if (divisione(d0,d1,d2)==1){
        return 1;
    }else{
        return 0;
    }
}

int somma(int d0,int d1,int d2){
    int sum;
    sum = d0+d1;
    if (sum==d2){
        return 1;
    }else{
        return 0;
    }
}

int prodotto(int d0,int d1,int d2){
    int product;
    product = d0*d1;
    if (product==d2){
        return 1;
    }else{
        return 0;
    }
}

int sottrazione(int d0,int d1, int d2){
    int sottrazione;
    sottrazione = d0-d1;
    if(sottrazione==d2){
        return 1;
    }else{
        return 0;
    }
}

int divisione(int d0,int d1,int d2){
    int divisione;
    if(d1!=0){
        divisione=d0/d1;
        if(divisione==d2){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}
