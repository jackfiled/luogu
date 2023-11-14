#include<bits/stdc++.h>
using namespace std;
int s[444],f[444],dp[888888];//s,f如题意，dp数组Emm不需要解释
int n,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",s+i,f+i);//输入
    memset(dp,-0x7f,sizeof(dp));//恰放入的初始化
    dp[400000]=0;//从400000开始转移
    for(int i=1;i<=n;i++){
        if(s[i]>0)
            for(int j=800000;j>=s[i];j--)
                dp[j]=max(dp[j],dp[j-s[i]]+f[i]);//同01背包
        else
            for(int j=0;j<=800000+s[i];j++)
                dp[j]=max(dp[j],dp[j-s[i]]+f[i]);	//负数要正着做DP，因为他是从左往右进行转移的
    }
    for(int i=400000;i<=800000;i++)//因为不一定智商越大越好,所以要枚举一遍
    if(dp[i]>=0)//注意，只有能够恰放入（被更新过），以及情商非负时，才可以更新答案
    {
        printf("%d\n", dp[i]);
        ans=max(ans,i+dp[i]-400000);
    }
    printf("%d\n",ans);//输出答案，换行是个好习惯
    return 0;
}
