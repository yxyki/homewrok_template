#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int n,C;   //物品数量及背包容量
int option;
int dp[n][C];

void LineModRandom(int range,int n,int random[]){
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++){
        random[i]=rand()%range+1;
    }
}

int KnapsackDP(int w[],int v[],int C){
    int i,j;
    for(i=0;i<n;i++)
        dp[i][0];
    for(i=0;i<C;i++)
        dp[0][i]=0;
    for(i=0;i<n;i++){
        for(j=0;j<C;j++){
            dp[i][j]=dp[i-1][j];
        }
    }
    
}

int main(){
    int i;
    printf("请输入物品的个数:");
    scanf("%d",&n);
    printf("请输入背包容量:");
    scanf("%d",&C);
    int w[n],v[n];  //物品的重量与价值
    printf("1.手动输入数据\n2.生成随机数\n");
    scanf("%d",&option);
    switch(option){
        case 1:
        for(i=0;i<n;i++){
            printf("请输入第%d个商品的质量和价值:",i+1);
            scanf("%d %d",&w[i],&v[i]);  
        }
        break;
        case 2:
        LineModRandom(C,n,w);
        LineModRandom(100,n,v);
        break;
    }
    for(i=0;i<n;i++){
        printf("第%d个物品的重量为%d,价值为%d\n",i+1,w[i],v[i]);
    }
    return 0;
}