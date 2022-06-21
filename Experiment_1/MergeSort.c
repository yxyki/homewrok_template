#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int length,count=0;
int scale=0;

void LineModRandom(int range,int n,int random[]){
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++){
        random[i]=rand()%range+1;
    }
}

void MergeList(int List[],int start1,int end1,int start2,int end2){
  int sorted[length];
  int index=0,i;
  scale++;
  int finalstart=start1,finalend=end2;
  while(start1<=end1&&start2<=end2){
      if(List[start1]<List[start2]){
          sorted[index]=List[start1];
          start1++;
          count++;
      }
      else{
          sorted[index]=List[start2];
          start2++;
          count++;
      }
      index++;
  }
  if(start1<=end1){
      for(i=start1;i<=end1;i++){
          sorted[index]=List[i];
          index++;
      }
  }
  else{
      for(i=start2;i<=end2;i++){
          sorted[index]=List[i];
          index++;
      }
  }
  index=0;
  for(i=finalstart;i<=finalend;i++){
      List[i]=sorted[index];
      index++;
  }
}

void MergeSort(int List[],int first,int last){
  if(first<last){
      int mid=(last+first)/2;
      MergeSort(List,first,mid);
      MergeSort(List,mid+1,last);
      MergeList(List,first,mid,mid+1,last);
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
    MergeSort(x,0,length-1);
    printf("\n排序之后为:");
    for(i=0;i<length;i++)
      printf("%d ",x[i]);
    printf("\n规模为%d的序列的比较次数为:%d\n",length,count);
    printf("子问题规模为%d\n",scale);
}