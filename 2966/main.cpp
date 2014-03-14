#include <iostream>
#include <stdio.h>
#include <algorithm>
#define LOCAL

using namespace std;

int T, N, E;
struct _edge {
    int u, v, w;
} edge[125000];
int p[500];

bool cmp(const struct _edge &e1, const struct _edge &e2) {
    return e1.w < e2.w;
}

int father(int v) {
    if(p[v] == v) {
        return v;
    } else {
        return p[v] = father(p[v]);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>T;
    while(T--) {
        cin>>N>>E;
        for(int i = 0; i < E; i++) {
            cin>>edge[i].u>>edge[i].v>>edge[i].w;
        }

        sort(edge, edge+E, cmp);
        for(int i = 0; i < N; i++)
            p[i] = i;

        long long cost = 0;
        for(int i = 0; i < E; i++) {
            if(father(edge[i].u) != father(edge[i].v)) {
                p[edge[i].v] = edge[i].u;
                cost += edge[i].w;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
