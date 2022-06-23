#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int n,C;   //物品数量及背包容量
int option;

void LineModRandom(int range,int n,int random[]){
    int i;
    srand((unsigned)time(NULL));
    for(i=1;i<=n;i++){
        random[i]=rand()%range+1;
    }
}

int max(int x,int y){
    if(x>=y) return x;
    else return y;
}

int KnapsackDP(int w[],int v[],int C){
    int dp[n+1][C+1];
    int i,j;
    for(i=0;i<=n;i++)
        dp[i][0]=0;
    for(j=0;j<=C;j++)
        dp[0][j]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=C;j++){
            dp[i][j]=dp[i-1][j];
            if(w[i]<=j)
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    return dp[n][C];
}

int main(){
    int i,maxv;
    clock_t t_start,t_end;
    printf("请输入物品的个数以及物品最大价值:");
    scanf("%d %d",&n,&maxv);
    printf("请输入背包容量:");
    scanf("%d",&C);
    int w[n+1],v[n+1];  //物品的重量与价值
    printf("1.手动输入数据\n2.生成随机数\n");
    scanf("%d",&option);
    switch(option){
        case 1:
        for(i=1;i<=n;i++){
            printf("请输入第%d个商品的质量和价值:",i);
            scanf("%d %d",&w[i],&v[i]);  
        }
        break;
        case 2:
        LineModRandom(C,n,w);
        LineModRandom(maxv,n,v);
        break;
    }
    if(option==2){
        for(i=1;i<=n;i++){
            printf("第%d个物品的重量为%d,价值为%d\n",i,w[i],v[i]);
        }
    }
    t_start=clock();
    printf("最大价值为:%d\n",KnapsackDP(w,v,C));
    t_end=clock();
    printf("程序的时间为%ldms\n",t_end-t_start);
    return 0;
}