#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <map>
#include <complex>
#include <time.h>
#ifdef __WINDOWS__
#define __I64d "%I64d"
#define __I64u "%I64u"
#else
#define __I64d "%lld"
#define __I64u "%llu"
#endif
#ifndef _PUSH_POP_
#define _PUSH_POP_
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#endif
#ifndef _MS_
#define _MS_
#define MS(s,v) memset(s,v,sizeof(s))
#endif
#ifndef _PAIR_
#define _PAIR_
#define PI pair<int,int>
#define PD pair<double,double>
#define PL pair<long long,long long>
#define MP(a,b) make_pair(a,b)
#define FF first
#define SS second
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
bool con[300000];
int main()
{
	MS(con,false);
	for(int i=1;i<=60;i++)
	{
		for(int j=i+1;j<=60;j++)
		{
			for(int k=j+1;k<=60;k++)
			{
				con[i*j+j*k+k*i]=true;
			}
		}
	}
	int K;
	while(~scanf("%d",&K))
	{
		int k=0,i=1;
		while(true)
		{
			if(!con[i])k++;
			if(k==K)break;
			i++;
		}
		printf("%d\n",i);
	}
 	return 0;
}

