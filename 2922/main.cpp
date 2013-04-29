#include <iostream>
#include <stdio.h>

using namespace std;

int room[1000][1000];
int N, M, count;

void explode(int r, int c){
    int i;
    for(i = r - 1; i >= 0; i--)
        if(room[i][c])
            explode(i, c);
    int k = c - room[r][c];
    if(k < 0) k = 0;
    for(i = c - 1; i >= k; i--)
        if(room[r][i])
            explode(r, i);

    room[r][c] = 0;
}

int main(){
    int i, j;
    freopen("input.txt", "r", stdin);
    while(cin>>N>>M){
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++)
                cin>>room[i][j];
        count = 0;
        for(i = N - 1; i >= 0; i--)
            for(j = M - 1; j >= 0; j--) if(room[i][j]){
                count++;
                explode(i, j);
            }
        cout<<count<<endl;
    }
    return 0;
}
