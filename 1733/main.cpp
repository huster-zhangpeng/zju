#include <cstring>
#include <iostream>

#define MAX(a,b,c)  ((a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c)))

using namespace std;

int dp[1001][1001];

int main() {
    string s1, s2;
    int l1, l2;
    while(cin>>s1>>s2) {
        l1 = s1.size();
        l2 = s2.size();
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < l1; i++) {
            for(int j = 0; j < l2; j++) {
                dp[i+1][j+1] = MAX(dp[i][j+1], dp[i+1][j], s1[i]==s2[j]?dp[i][j]+1:dp[i][j]);
            }
        }
        cout<<dp[l1][l2]<<endl;
    }
    return 0;
}
