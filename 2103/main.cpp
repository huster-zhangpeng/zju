#include <iostream>
#include <cstring>
#include <stdio.h>
//#define LOCAL

using namespace std;

int G[10][10];
bool mark[10][10];
int N, C, H, minTimes;
bool ok;

void dfs(int u, int h, int c, int t){
    if(h == H){
        ok = true;
        minTimes = t < minTimes ? t : minTimes;
        return;
    }
    int tmp;
    for(int v = 0; v < N; v++)if(G[u][v] >= 0 && !mark[u][v]){
        mark[u][v] = mark[v][u] = true;
        tmp = t;
        if(G[u][v] != c)
            tmp++;
        dfs(v, h+1, G[u][v], tmp);
        mark[u][v] = mark[v][u] = false;
    }
}

int main(){
    int u, v, e, c, start, size;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>N>>C>>H && N && C && H){
        for(u = 0; u < N; u++)
            for(v = 0; v < N; v++)
                G[u][v] = -1;
        memset(mark, 0, sizeof(mark));
        for(e = 0; e < H; e++){
            cin>>u>>v>>c;
            G[u][v] = c;
            G[v][u] = c;
        }
        start = 0;
        ok = false;
        minTimes = 20;
        for(u = 0; u < N; u++){
            size = 0;
            for(v = 0; v < N; v++) if(G[u][v] >= 0)size ++;
            start ++;
            if(size & 1)dfs(u, 0, -1, -1);
        }
        if(!start){
            for(u = 0; u < N; u++){
                dfs(u, 0, -1, -1);
            }
        }
        if(ok) cout<<minTimes<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
