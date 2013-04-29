#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#define hash(num) (num[3]+num[2]*9+num[1]*81+num[0]*729)
#define isSame(a, b) (a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3])
//#define LOCAL

using namespace std;

short queue[10000][4];
bool map[10000];
int front, tail;

void tryAddQueue(){
    int pos = hash(queue[front]);
    if(!map[pos]){
        front++;
        map[pos] = true;
    }
}

int main(){
    int T, i, j, k, step;
    char ch;
    short M[4];
    bool ok;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>T;
    while(T--){
        front = tail = 0;
        step = 0;
        ok = false;
        for(i = 0; i < 4; i++){
            cin>>ch;
            queue[0][i] = ch - '1';
        }
        for(i = 0; i < 4; i++){
            cin>>ch;
            M[i] = ch - '1';
        }
        memset(map, 0, sizeof(map));
        map[hash(queue[0])] = true;
        front++;
        while(front != tail){
            k = front;
            for(; tail < k; tail++){
                if(isSame(queue[tail],M)) {
                    ok = true;
                    break;
                }
                for(j = 0; j < 4; j++){
                    memcpy(queue[front], queue[tail], 4*sizeof(short));
                    queue[front][j] = (queue[front][j] + 1) % 9;
                    tryAddQueue();

                    memcpy(queue[front], queue[tail], 4*sizeof(short));
                    queue[front][j] = (queue[front][j] + 8) % 9;
                    tryAddQueue();
                }
                for(j = 0; j < 3; j++){
                    memcpy(queue[front], queue[tail], 4*sizeof(short));
                    ch = queue[front][j];
                    queue[front][j] = queue[front][j+1];
                    queue[front][j+1] = ch;
                    tryAddQueue();
                }
            }
            if(ok){
                cout<<step<<endl;
                break;
            }
            step ++;
        }
    }
    return 0;
}
