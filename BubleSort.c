#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true 1
#define false 0
typedef int Bool;
int count=0;

void LineModRandom(int n,int ranNum[]){
    int i;
    int max=2000;
    srand((unsigned)(time(NULL)));
    int m=rand()%(max+100);
    int a=rand()%m-1;
    int c=rand()%m-1;
    ranNum[0]=rand()%(max+1)-1;
    for(i=1;i<n;i++)
      ranNum[i]=(a*ranNum[i-1]+c)%m;
}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void BubleSort(int List[],int n){
  int numberOfPairs=n,i,temp;
  Bool swappedElements=true;
  while(swappedElements){
      numberOfPairs--;
      swappedElements=false;
      for(i=0;i<numberOfPairs;i++){
          count++;
          if(List[i]>List[i+1]){
              swap(&List[i],&List[i+1]);
              swappedElements=true;
          }
      }
  }
}

int main(){
    int n,i;
    printf("请输入排序的元素个数:");
    scanf("%d",&n);
    int x[n];
    LineModRandom(n,x);
    printf("生成的随机序列为:");
    for(i=0;i<n;i++)
      printf("%d ",x[i]);
    BubleSort(x,n);
    printf("\n排序之后为:");
    for(i=0;i<n;i++)
      printf("%d ",x[i]);
    printf("\n规模为%d的数据比较次数为%d\n",n,count);
}