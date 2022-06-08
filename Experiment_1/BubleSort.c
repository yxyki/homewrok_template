#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true 1
#define false 0
typedef int Bool;
long count=0;

void LineModRandom(int range,int n,int random[]){
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++){
        random[i]=rand()%range+1;
    }
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
    int n,i,max;
    printf("请输入排序的元素个数:");
    scanf("%d",&n);
    int x[n];
    printf("请输入元素的最大值（取值范围）:");
    scanf("%d",&max);
    LineModRandom(max,n,x);
    printf("生成的随机序列为:");
    for(i=0;i<n;i++)
      printf("%d ",x[i]);
    BubleSort(x,n);
    printf("\n排序之后为:");
    for(i=0;i<n;i++)
      printf("%d ",x[i]);
    printf("\n规模为%d的数据比较次数为%ld\n",n,count);
}