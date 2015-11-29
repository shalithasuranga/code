#include <bits/stdc++.h>
using namespace std;
int f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 40320};
vector<vector<int> > dir={
    {1, 3}, 
    {0, 2, 3, 4},
    {1, 4, 5},
    {0, 4, 6},
    {1, 3, 5, 6, 7},
    {2, 4, 7, 8},
    {3, 7},
    {4, 6, 8},
    {5, 7}};

int find_zero(const vector<int> &b){
    for(int i=0;i<(int)b.size();i++)
        if(b[i]==0)return i;
    return -1;
}
vector<int> decode(int value){
    vector<int> res(9);
    int use[9] = {};
    for(int i = 0 ; i < 9 ; i++){
        int now = value / f[9-i-1];
        int t = -1, j = 0;
        while(1){
            t += !use[j];
            if(t == now)break;
            else j++;
        }
        use[j] = 1;
        res[i] = j;
        value %= f[9-i-1];
    }
    return res;
}
int encode(const vector<int> &board){
    int use[9] = {};
    int re = 0;
    for(int i = 0 ; i < 9 ; i++){
        int now = board[i];
        int t = 0;
        for(int j = 0 ; j < now ; j++)
            t += !use[j];
        re += t * f[9-i-1];
        use[now] = 1;
    }
    return re;
}
void print(int v){
    vector<int> b=decode(v);
    for(int v:b)
        printf("%d ", v);
    puts("");
}

int dis[2][362880+20];
const int INF=0x3f3f3f3f;
typedef pair<int,int> PI;
#define f first
#define s second 
int Solve(){
    vector<int> b[2];
    int e[2];
    b[0]=b[1]=vector<int>(9);
    for(int i=0;i<2;e[i]=encode(b[i]),i++)
        for(int j=0;j<9;j++)
            scanf("%d",&b[i][j]);
    memset(dis,0x3f,sizeof(dis));
    dis[0][e[0]]=dis[1][e[1]]=0;
    priority_queue<PI, vector<PI>, greater<PI>> pq[2];
    pq[0].push({0,e[0]});
    pq[1].push({0,e[1]});
    int ans=-1;
    while(pq[0].size()&&pq[1].size()){
        for(int i=0;i<2;i++){
            PI now=pq[i].top();pq[i].pop();
            //printf("%d %d %d %d\n", i, now.f, now.s, dis[i^1][now.s]);
            //print(now.s);
            //if(now.f>2)return -1;
            if(dis[i^1][now.s]!=INF){
                ans=dis[i][now.s]+dis[i^1][now.s];
                return ans;
            }
            vector<int> b=decode(now.s);
            int zero=find_zero(b);
            vector<int>w=b;
            for(int j=0;j<(int)dir[zero].size();j++){
                swap(w[zero], w[dir[zero][j]]);
                int ew=encode(w);
                if(dis[i][ew]>dis[i][now.s]+1){
                    dis[i][ew]=dis[i][now.s]+1;
                    pq[i].push({dis[i][ew],ew});
                }
                swap(w[zero], w[dir[zero][j]]);
            }
        }
    }
    return ans;

}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        printf("%d\n", Solve());
    }
    return 0;
}
