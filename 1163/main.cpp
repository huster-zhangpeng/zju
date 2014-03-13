#include <stdio.h>
#include <iostream>

using namespace std;

long long dp[501][501] = {0};

int main() {
    int N;
    for(int i = 0; i < 4; i++) 
        dp[i][2] = 1;
    for(int i = 4; i <= 500; i++)
        dp[i][2] = 0;
    for(int j = 3; j <= 500; j++) {
        for(int i = 0; i <= 500; i++) {
            if(j <= i)
                dp[i][j] = dp[i][j-1] + dp[i-j][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    while(cin>>N && N) {
        cout<<dp[N][N-1]<<endl;
    }
    return 0;
}
