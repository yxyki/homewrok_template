#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int length,count=0;

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
    int i,max;
    printf("请输入排序的元素个数:");
    scanf("%d",&length);
    printf("请输入最大元素(取值范围):");
    scanf("%d",&max);
    int x[length];
    LineModRandom(max,length,x);
    printf("生成的随机序列为:");
    for(i=0;i<length;i++)
      printf("%d ",x[i]);
    QuickSort(x,0,length-1);
    printf("\n排序之后为:");
    for(i=0;i<length;i++)
      printf("%d ",x[i]);
    printf("\n规模为%d的序列的比较次数为:%d\n",length,count);
}