#include <iostream>
#include <stdio.h>

using namespace std;

struct {
    int x, y;
}stack[2000];
int top;

char room[22][22];
int directX[4] = {0, 1, 0, -1};
int directY[4] = {1, 0, -1, 0};

int main(){
    int W, H, x, y, sum;
//    freopen("input.txt", "r", stdin);
    while(cin>>W>>H && W && H){
        for(int i = 0; i < W+2; i++){
            room[0][i] = room[H+1][i] = '#';
        }
        for(int i = 0; i < H+2; i++){
            room[i][0] = room[i][H+1] = '#';
        }
        for(int i = 1; i < H+1; i++)
            for(int j = 1; j < W+1; j++){
                cin>>room[i][j];
                if(room[i][j] == '@'){
                    stack[0].x = i;
                    stack[0].y = j;
                    room[i][j] = '.';
                }
            }

        top = 1;
        sum = 0;
        while(top > 0){
            top --;
            x = stack[top].x;
            y = stack[top].y;
            if(room[x][y] == '.'){
                sum++;
                room[x][y] = '*';
            } else continue;
            for(int i = 0; i < 4; i++){
                if(room[ x+directX[i] ][ y+directY[i] ] == '.'){
                    stack[top].x = x + directX[i];
                    stack[top].y = y + directY[i];
                    top ++;
                }
            }
        }
        cout<<sum<<endl;
    }
}
