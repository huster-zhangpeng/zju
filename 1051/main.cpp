/*
*ZOJ-1051
*注意，最后一个输出不能输出一个空行，否则会判定失败
*/
#include <iostream>
#include <cstring>
#include <stdio.h>
//#define LOCAL

using namespace std;

int D[16];
int density[22][22];
int temp[22][22];
char map[] = ".!X#";

void init(){
    for(int i = 0; i < 15; i++){
        density[0][i] = density[21][i] = 0;
        density[i][0] = density[i][21] = 0;
        temp[0][i] = temp[21][i] = 0;
        temp[i][0] = temp[i][21] = 0;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    init();
    int n, days, i, j;
    int sum;
    cin>>n;
    while(n--){
        cin>>days;
        for(i = 0; i < 16; i++) cin>>D[i];
        for(i = 1; i < 21; i++)
            for(j = 1; j < 21; j++)
                cin>>density[i][j];
        while(days--){
            for(i = 1; i < 21; i++){
                for(j = 1; j < 21; j++){
                    sum = density[i][j + 1] + density[i][j - 1] +
                            density[i + 1][j] + density[i - 1][j] +
                            density[i][j];
                    temp[i][j] = density[i][j] + D[sum];
                    if(temp[i][j] > 3) temp[i][j] = 3;
                    else if(temp[i][j] < 0) temp[i][j] = 0;
                }
            }
            memcpy(density, temp, sizeof(temp));
        }
        for(i = 1; i < 21; i++){
            for(j = 1; j < 21; j++)
                cout<<map[ density[i][j] ];
            cout<<endl;
        }
        if(n)cout<<endl;
    }
    return 0;
}
