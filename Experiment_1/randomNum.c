#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void randomNum(int range,int n,int random[]){
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++){
        random[i]=rand()%range+1;
    }
}

int main(){
    int i,a[10];
    for(i=0;i<10;i++){
        randomNum(50,10,a);
    }
    printf("\n");
    for(i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}