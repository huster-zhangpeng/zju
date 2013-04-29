/*
*ZOJ 1002 Fire net
*二部图最大匹配算法
*     --匈牙利算法
*/
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char map[4][4];
int v1[4][4];
int v2[4][4];
bool status[8];
int result[8];
bool graph[8][8];

int n;
int p, q;

bool find(int i){
    for(int j = 0; j < q; j ++){
        if(graph[i][j] && !status[j]){
            status[j] = true;
            if(result[j] == -1 || find(result[j])){
                result[j] = i;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int i, j, max;
    while(cin>>n && n){
        for(i = 0; i < n; i++)
            cin>>map[i];
        p = q = 0;
        bool lastIsWallR, lastIsWallC;
        for(i = 0; i < n; i++){
            lastIsWallR = lastIsWallC = true;
            for(j = 0; j < n; j++){
                if(map[i][j] == '.'){
                    if(lastIsWallR) p++;
                    v1[i][j] = p;
                    lastIsWallR = false;
                } else{
                    lastIsWallR = true;
                }
                if(map[j][i] == '.'){
                    if(lastIsWallC) q++;
                    v2[j][i] = q;
                    lastIsWallC = false;
                } else {
                    lastIsWallC = true;
                }
            }
        }
        // 创建二部图
        memset(graph, 0, sizeof(graph));
        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j++){
                if(map[i][j] == '.')
                    graph[ v1[i][j] - 1 ][ v2[i][j] - 1 ] = true;
            }
        }
        // 求最大匹配
        max = 0;

        for(i = 0; i < 8; i++){
            result[i] = -1;
        }
        for(i = 0; i < p; i++){
            memset(status, 0, sizeof(status));
            if(find(i))
                max ++;
        }
        printf("%d\n", max);
    }
    return 0;
}
