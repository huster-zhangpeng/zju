/*
* ZOJ-1027
* 动态规划题，第一次AC，分析了很长时间，对动规相当不熟悉啊
*/
#include <iostream>
#include <cstring>
#include <stdio.h>
#define MAX(x, y, z) (x)>(y)?((x)>(z)?(x):(z)):((y)>(z)?(y):(z))
#define LOCAL

using namespace std;

int score[5][5] = {
                {5, -1, -2, -1, -3},
                {-1, 5, -3, -2, -4},
                {-2, -3, 5, -2, -2},
                {-1, -2, -2, 5, -1},
                {-3, -4, -2, -1, -9999}
            };
int f[101][101] = {0};
int p, q;
int seq1[100];
int seq2[100];

void alignment(){
    int i, j;
    memset(f, 0, sizeof(f));
    for(i = 1; i <= p; i++){
        f[0][i] = f[0][i-1] + score[4][ seq1[i] ];
    }
    for(i = 1; i <= q; i++){
        f[i][0] = f[i-1][0] + score[ seq2[i] ][4];
    }
    for(i = 1; i <= q; i++){
        for(j = 1; j <= p; j++){
            f[i][j] = MAX(f[i-1][j-1] + score[ seq2[i] ][ seq1[j] ],
                          f[i-1][j] + score[ seq2[i] ][4],
                          f[i][j-1] + score[4][ seq1[j] ]);
        }
    }
    cout<<f[q][p]<<endl;
}

int main(){
    int i, n;
    char ch;
    int map[85] = {-1};
    map[67] = 1;
    map[71] = 2;
    map[84] = 3;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>n;
    while(n--){
        cin>>p;
        for(i = 1; i <= p; i++){
            cin>>ch;
            seq1[i] = map[ ch ];
        }
        cin>>q;
        for(i = 1; i <= q; i++){
            cin>>ch;
            seq2[i] = map[ ch ];
        }
        alignment();
    }
    return 0;
}
