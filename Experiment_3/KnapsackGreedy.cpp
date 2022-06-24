#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int n,C;   //物品数量及背包容量
int option;

void swap(int *a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void Sort(int n,int *w,int *v){//排序函数
    int i,j;
    float temp1,temp2;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){//冒泡排序
            temp1=(float)v[j]/(float)w[j];
            temp2=(float)v[j+1]/(float)w[j+1];
            if(temp1<temp2){
                swap(&w[j],&w[j+1]);
                swap(&v[j],&v[j+1]);
            }
        }
    }
}

void LineModRandom(int range,int n,int random[]){
    int i;
    srand((unsigned)time(NULL));
    for(i=1;i<=n;i++){
        random[i]=rand()%range+1;
    }
}

int main(){
    int i,maxv;
    double t_start,t_end;       //起始时间和结束时间

    printf("请输入物品的个数以及物品最大价值:");
    scanf("%d %d",&n,&maxv);
    printf("请输入背包容量:");
    scanf("%d",&C);
    int w[n+1],v[n+1];           //物品的重量与价值
    float c[n+1],maxVal=0;       //物品放入比例和最大价值
    for(i=0;i<=n;i++) c[i]=0;    //解向量初始化为0

    printf("1.手动输入数据\n2.生成随机数\n");
    scanf("%d",&option);
    switch(option){
        case 1:
        for(i=1;i<n+1;i++){
            printf("请输入第%d个商品的质量和价值:",i);
            scanf("%d %d",&w[i],&v[i]);
        }
        break;
        case 2:
        LineModRandom(C,n,w);
        LineModRandom(maxv,n,v);
        break;
    }
    t_start=(double)clock();
    Sort(n,w,v);
    float remain=(float)C;
    for(i=1;i<=n;i++){
        if((float)w[i]>remain) break;
        c[i]=1;
        remain-=(float)w[i];
    }
    if(i<=n) c[i]=remain/w[i];
    t_end=(double)clock();

    for(i=1;i<=n;i++){
        printf("质量为%d,价值为%d的物品放入比例为:%.3f\n",w[i],v[i],c[i]);
        maxVal+=(float)v[i]*c[i];
    }
    printf("最大价值为%.3f\n",maxVal);
    printf("程序的时间为%.4fms\n",t_end-t_start);
    return 0;
}