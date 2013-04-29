/**
* 超时
*/
#include <iostream>
#include <stdio.h>

using namespace std;

int n, L;
int v[100][100];
int maxValue;

void dfs(int pre, int k, int cur){
    if(k == L){
        if(cur > maxValue) maxValue = cur;
        return;
    }

    for(int i = 0; i < n; i++){
        dfs(i, k + 1, cur + v[pre][i]);
    }
}

int main(){
    int T, i, j;
    freopen("input.txt", "r", stdin);
    cin>>T;
    while(T--){
        cin>>n>>L;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                cin>>v[i][j];
        maxValue = 0;
        for(i = 0; i < n; i++){
            dfs(i, 1, 0);
        }
        cout<<maxValue<<endl;
    }
    return 0;
}
