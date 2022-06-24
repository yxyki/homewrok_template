#include<stdio.h>

int DAC_count=0;
int DP_count=0;

int DAC_f(int n){
    if(n==1||n==2) return 1;
    DAC_count++;
    return DAC_f(n-1)+DAC_f(n-2);
}

int DP_f(int n){
    int dp[n+1],i;
    dp[0]=0;
    for(i=1;i<=n;i++){
        if(i==1||i==2) dp[i]=1;
        else {
            DP_count++;
            dp[i]=dp[i-1]+dp[i-2];
        }
    }
    return dp[n];
}

int main(){
    int n;
    printf("请输入n的值:");
    scanf("%d",&n);
    printf("分治法:n=%d时,结果为:%d\n",n,DAC_f(n));
    printf("加法次数为:%d\n",DAC_count);
    printf("动态规划法:n=%d时,结果为:%d\n",n,DP_f(n));
    printf("加法次数为:%d\n",DP_count);
}