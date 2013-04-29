#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, ways;
int val[10], num[10];

void dfs(int k, int cur){
    if(cur == n){
        ways ++;
        return;
    }
    if(k == m) return;

    for(int i = 0; i <= num[k]; i++){
        if(cur + val[k] * i <= n){
            dfs(k + 1, cur + val[k] * i);
        } else break;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    bool isFirst = true;
    while(cin>>n>>m){
        if(isFirst) isFirst = false;
        else cout<<endl;
        for(int i = 0; i < m; i++)
            cin>>val[i]>>num[i];

        ways = 0;
        dfs(0, 0);
        cout<<ways<<endl;
    }
    return 0;
}
