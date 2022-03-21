/*
 Il primo carattere alfabetico successivo a un punto, punto esclamativo o interrogativo deve essere
maiuscolo; se non lo è, trasformarlo in maiuscolo (anche se tra la punteggiatura e il carattere
alfabetico ci sono uno o più spazi o a capo).
 */
#include <stdio.h>
#include <ctype.h>
#define filein "../input0.txt"
int isnum(char c);
int isfineperiodo(char c0);

int main(){
    FILE *fp_read,*fp_write;
    int countword =2;
    char c0,c1;
    int checknum,chekcpunteggiatura,checkfineperiodo,flagfineperido;
    fp_read = fopen(filein,"r");
    fp_write = fopen("../output.txt","w");
    if (fp_read!=NULL) {
        fscanf(fp_read,"%c",&c0);
        fscanf(fp_read,"%c",&c1);
        while(!feof(fp_read)) {
            if(countword<=26){
                checkfineperiodo = isfineperiodo(c0);
                if(checkfineperiodo==1){
                    flagfineperido=1;
                }
                if(flagfineperido==1 && isalpha(c0)!=0){
                    c0=toupper(c0);
                    flagfineperido=0;
                }
                checknum = isnum(c0);
                if(checknum==1){
                    c0='*';
                }
                chekcpunteggiatura = ispunct(c0);
                if(chekcpunteggiatura!=0){
                    if(c1!=' ' && c1!='\n'){
                        fprintf(fp_write," ");
                    }
                }
                fprintf(fp_write,"%c",c0);
                c0=c1;
                fscanf(fp_read,"%c",&c1);
                countword++;
                printf("%d ",countword);
                
                if(countword>=27){
                    printf("\n");
                    fprintf(fp_write,"\n");
                    countword=0;
                }
            }
        }
    }else{
        printf("errore nei file");
    }
    fclose(fp_read);
    return 0;
}

int isnum(char c){
    char ifnumber;
    int conversioncharinint;
    ifnumber = c-'0';
    conversioncharinint = ifnumber;
    if (conversioncharinint>=0 && conversioncharinint<=9){
        return 1;
    }else{
        return 0;
    }
}
int isfineperiodo(char c0){
    if(c0=='.' ||  c0=='!' || c0=='?'){
        return 1;
    }else{
        return 0;
    }
}
