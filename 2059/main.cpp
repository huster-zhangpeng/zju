#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int height[100];
int N;
int dp[2][2001];

int main(){
    int cur, next;
    freopen("input.txt", "r", stdin);
    while(cin>>N && N >= 0){
        for(int i = 0; i < N; i++)
            cin>>height[i];
        memset(dp, -1, sizeof(dp));
        cur = 0, next = 1;
        dp[cur][0] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < 2001; j++){
                dp[next][j] = max(dp[next][j], dp[cur][j]);
                if(dp[cur][j] < 0) continue;
                if(j + height[i] < 2001)
                    dp[next][j + height[i]] = max(dp[cur][j], dp[next][j + height[i]]);
                if(j >= height[i])
                    dp[next][j - height[i]] = max(dp[cur][j] + height[i], dp[next][j-height[i]]);
                else
                    dp[next][height[i] - j] = max(dp[cur][j] + j, dp[next][height[i]-j]);
            }
            cur = cur ^ 1, next = next ^ 1;
        }
        if(dp[cur][0] != 0)
            cout<<dp[cur][0]<<endl;
        else cout<<"Sorry"<<endl;
    }
    return 0;
}
