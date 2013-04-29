#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>

using namespace std;

int N1, N2;
int a[102], b[102];
int pos1[102][102], pos2[102][102], s[102];
int f[102][102];

int main(){
    int T, i, j;
    freopen("input.txt", "r", stdin);
    cin>>T;
    while(T--){
        cin>>N1>>N2;
        for(i = 1; i <= N1; i++) cin>>a[i];
        for(i = 1; i <= N2; i++) cin>>b[i];
        memset(s, 0, sizeof(s));
        for(i = 1; i <= 100; i++){
            for(j = 1; j<= 100; j++)
                pos1[i][j] = s[j];
            s[ a[i] ] = i;
        }
        memset(s, 0, sizeof(s));
        for(i = 1; i <= 100; i++){
            for(j = 1; j <= 100; j++)
                pos2[i][j] = s[j];
            s[ b[i] ] = j;
        }
        memset(f, 0, sizeof(f));
        for(i = 1; i <= N1; i++){
            for(j = 1; j <= N2; j++){
                f[i][j] = max(f[i-1][j], f[i][j-1]);
                int bina = pos1[i][ b[j] ];
                int ainb = pos2[j][ a[i] ];
                if(a[i] != b[j] && bina > 0 && ainb > 0)
                    f[i][j] = max(f[i][j], f[bina-1][ainb-1] + 2);
            }
        }
        cout<<f[N1][N2]<<endl;
    }
    return 0;
}
