#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MS(s,v) memset(s,v,sizeof(s))
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin(),eit=x.end();it!=eit;it++)
#define SIZE(x) ((int)x.size())
#define INF 0x3f3f3f3f
#ifdef __ALLEN
 #define __lld "%I64d"
#else
 #define __lld "%lld"
#endif
using namespace std;
char s1[110],s2[110];
int dp[110][110];
int main()
{
	int t=1;
	while(gets(s1+1)!=NULL&&strcmp(s1+1,"#")!=0&&gets(s2+1)!=NULL)
	{
		int l1=strlen(s1+1),l2=strlen(s2+1);
		for(int i=0;i<=l1;i++)
		{
			for(int j=0;j<=l2;j++)
			{
				if(!i||!j)dp[i][j]=0;
				else if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				//printf("%d %d %d\n",i,j,dp[i][j]);
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n",t++,dp[l1][l2]);
	}
	return 0;
}

