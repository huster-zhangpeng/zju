#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
//#define LOCAL

using namespace std;

typedef struct{
    int length, top, path[21];
}Trip;
Trip temp;
vector<Trip> ret;
int G[21][21];
bool mark[21];
int NV, NR, SV, DV, MAXDIST;
int path[21];

bool cmp(const Trip& t1, const Trip& t2){
    if(t1.length == t2.length){
        for(int i = 0; i < ret.size(); i++){
            if(t1.path[i] < t2.path[i])
                return true;
        }
    }
    return t1.length < t2.length;
}

void dfs(int u, int n, int dist){
    if(u == DV){
        memcpy(temp.path, path, n*sizeof(int));
        temp.length = dist;
        temp.top = n;
        ret.push_back(temp);
        return;
    }
    for(int v = 1; v <= NV; v++)if(G[u][v] && !mark[v]){
        if(dist + G[u][v] <= MAXDIST){
            mark[v] = true;
            path[n] = v;
            dfs(v, n+1, dist+G[u][v]);
            mark[v] = false;
        }
    }
}

int main(){
    int u, v, dist, t = 1;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>NV && NV != -1){
        cin>>NR;
        ret.clear();
        memset(G, 0, sizeof(G));
        memset(mark, 0, sizeof(mark));
        for(int i = 0; i < NR; i++){
            cin>>u>>v>>dist;
            G[u][v] = G[v][u] = dist;
        }
        cin>>SV>>DV>>MAXDIST;
        mark[SV] = true;
        dfs(SV, 0, 0);
        sort(ret.begin(), ret.end(), cmp);
        cout<<"Case "<<t<<":"<<endl;
        for(int i = 0; i < ret.size(); i++){
            cout<<ret[i].length<<": "<<SV;
            for(int j = 0; j < ret[i].top; j++){
                cout<<' '<<ret[i].path[j];
            }
            cout<<endl;
        }
        cout<<endl;
        t++;
    }
    return 0;
}
