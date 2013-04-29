#include <iostream>
#include <cstring>
#include <stdio.h>
#define LAST 2
#define LOSE -1
#define WIN 1
#define UNDEFINED 0
#define INVALID -2
//#define LOCAL

using namespace std;

int date[103][12][31];

void init(){
    int y, d;
    memset(date, 0, sizeof(date));
    for(y = 1900; y <= 2001; y++){
        if(!y%400 || (y%100 && !y%4)){
            date[y-1900][1][29] = date[1900][1][30] = INVALID;
            date[y-1900][1][28] = LAST;
        }else{
            date[y-1900][1][28] = date[y-1900][1][29] = date[y-1900][1][30] = INVALID;
            date[y-1900][1][27] = LAST;
        }
        date[y-1900][3][30] = date[y-1900][5][30] = date[y-1900][8][30] = date[y-1900][10][30] = INVALID;
        date[y-1900][3][29] = date[y-1900][5][29] = date[y-1900][8][29] = date[y-1900][10][29] = LAST;
        date[y-1900][0][30] = date[y-1900][2][30] = date[y-1900][4][30] = LAST;
        date[y-1900][6][30] = date[y-1900][7][30] = date[y-1900][9][30] = date[y-1900][11][30] = LAST;
    }
    for(d = 4; d < 31; d++) date[101][10][d] = INVALID;

}

void dp(){
    int y, m, d;
    int ty, tm;
    date[101][10][3] = LOSE;
    date[101][10][2] = WIN;
    date[101][10][1] = LOSE;
    date[101][10][0] = WIN;
    for(y = 101; y >= 0; y--){
        for(m = 11; m >=0; m--){
            if(y == 101 && m >= 10) continue;
            for(d = 30; d >= 0; d--) if(date[y][m][d] == UNDEFINED || date[y][m][d] == LAST){
                if(m == 11){
                    if(date[y+1][0][d] != INVALID) {date[y][m][d] = -date[y+1][0][d]; continue;}
                } else if(m < 11){
                    if(date[y][m+1][d] != INVALID) {date[y][m][d] = -date[y][m+1][d]; continue;}
                }
                if(date[y][m][d] == LAST){
                    tm = (m + 1) % 12;
                    ty = y + (m + 1) / 12;
                    date[y][m][d] = -date[ty][tm][0];
                }else{
                    date[y][m][d] = -date[y][m][d+1];
                }
            }
        }
    }
}

int main(){
    init();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    dp();
    int T, y, m, d;
    cin>>T;
    while(T--){
        cin>>y>>m>>d;
        if(date[y-1900][m-1][d-1] == WIN){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
