#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
int N,M;
int f[110][110];
int dp1[110][110][110];
int dp2[110][110][110];
int DP1(int n,int m,int s){
    int &v=dp1[n][m][s];
    if(~v)return v;
    if(s==0)return v=0;
    if(n>=N||m>=M)return v=-INF;
    v=max(0,DP1(n+1,m+1,s-1)+f[n][m]);
    v=max(v,max(DP1(n+1,m,s),DP1(n,m+1,s)));
    return v;
}
int DP2(int n,int m,int s){
    int &v=dp2[n][m][s];
    if(~v)return v;
    if(s==0)return v=0;
    if(n>=N||m>=M)return v=INF;
    v=min(INF,DP2(n+1,m+1,s-1)+f[n][m]);
    v=min(v,min(DP2(n+1,m,s),DP2(n,m+1,s)));
    return v;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                scanf("%d",&f[i][j]);
        int ans=0;
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        for(int i=0;i<=min(N,M)/2;i++)
            ans=max(ans,DP1(0,0,i)-DP2(0,0,i*2));
        printf("%d\n",ans);
    }
    return 0;
}
