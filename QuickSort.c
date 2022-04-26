#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int length,count=0;

void LineModRandom(int n,int ranNum[]){
    int i;
    int max=2000+n;
    srand((unsigned)(time(NULL)));
    int m=rand()%max;
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

int PivotList(int List[],int first,int last){
    int PivotValue=List[first];
    int PivotPoint=first;
    int i,temp;
    for(i=first+1;i<=last;i++){
        count++;
        if(List[i]<PivotValue){
            PivotPoint++;
            swap(&List[PivotPoint],&List[i]);
        }
    }
    swap(&List[first],&List[PivotPoint]);

    return PivotPoint;
}

void QuickSort(int List[],int first,int last){
    
    if(first<last){
        int pivot=PivotList(List,first,last);
        QuickSort(List,first,pivot-1);
        QuickSort(List,pivot+1,last);
    }
    else return;
}

int main(){
    int i;
    printf("请输入排序的元素个数:");
    scanf("%d",&length);
    int x[length];
    LineModRandom(length,x);
    printf("生成的随机序列为:");
    for(i=0;i<length;i++)
      printf("%d ",x[i]);
    QuickSort(x,0,length-1);
    printf("\n排序之后为:");
    for(i=0;i<length;i++)
      printf("%d ",x[i]);
    printf("\n规模为%d的序列的比较次数为:%d\n",length,count);
}