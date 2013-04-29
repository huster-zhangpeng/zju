#include <iostream>
#include <cstring>
#include <stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))

using namespace std;

unsigned int map[1002][1002];
int xi, yi, xr, yr, movements;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N, X, Y;

bool check(int k){
    movements = 0;
    int i, temp;
    int queue[1000000][2];
    bool mark[1000][1000];
    int front, tail;
    queue[0][0] = xi, queue[0][1] = yi;
    front = 1, tail = 0;
    memset(mark, 0, sizeof(mark));
    while(front > tail){
        temp = front;
        movements ++;
        for(; tail < temp; tail++)
            for(i = 0; i < 4; i++)
                if(!mark[ queue[tail][0] + dx[i] ][ queue[tail][1] + dy[i] ]
                   && map[ queue[tail][0] + dx[i] ][ queue[tail][1] + dy[i] ] >= k){
                    queue[front][0] = queue[tail][0] + dx[i];
                    queue[front][1] = queue[tail][1] + dy[i];
                    if(queue[front][0] == xr && queue[front][1] == yr) return true;
                    mark[ queue[front][0] ][ queue[front][1] ] = true;
                    front++;
                }
    }
    return false;
}

int main(){
    int T, x, y, k, i, j;
    int left, mid, right;
    freopen("input.txt", "r", stdin);
    cin>>T;
    while(T--){
        bool ok;
        cin>>N>>X>>Y;
        cin>>xi>>yi>>xr>>yr;
        xi++, yi++, xr++, yr++;
        memset(map, -1, sizeof(map));
        for(i = 0; i <= Y+1; i++)
            map[0][i] = map[X+1][i] = 0;
        for(i = 1; i <= X; i++)
            map[i][0] = map[i][Y+1] = 0;
        for(k = 0; k < N; k++){
            cin>>x>>y;
            x++, y++;
            for(i = 1; i <= X; i++)
                for(j = 1; j <= Y; j++)
                    if(map[i][j] > ABS(i - x) + ABS(j - y))
                        map[i][j] = ABS(i - x) + ABS(j - y);
        }
        left = 1, right = map[xi][yi] < map[xr][yr] ? map[xi][yi] : map[xr][yr];
        while(left <= right){
            mid = (left + right) / 2;
            ok = check(mid);
            if(ok) right = mid - 1;
            else left = mid + 1;
        }
        if(ok)cout<<mid<<' '<<movements<<endl;
        else cout<<mid-1<<' '<<movements<<endl;
    }
    return 0;
}
