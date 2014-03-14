#include <iostream>
#include <cstring>
#include <stdio.h>
#define LOCAL

using namespace std;

int student[500][500];
int sr[500];
int n;
bool visited[500];
int linked[500];

bool find(int v) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sr[v]; j++) {
            int s = student[v][j];
            if(!visited[s]) {
                visited[s] = true;
                if(linked[s] == -1 || find(linked[s])){
                    linked[s] = v;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int a, b;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>n) {
        for(int i = 0; i < n; i++) {
            scanf("%d: (%d)", &a, &b);
            sr[a] = b;
            for(int j = 0; j < b; j++)
                cin>>student[a][j];
        }

        int ans = 0;
        memset(linked, -1, sizeof(linked));
        for(int i = 0; i < n; i++) {
            memset(visited, 0, sizeof(visited));
            if(find(i)) ans++;
        }
        cout<<(n-ans/2)<<endl;
    }
    return 0;
}
