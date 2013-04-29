#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>

using namespace std;

int n, m;
int relate[10];
int t[10], f[10];
float remain[1024];

void wfs(){
    int queue[102400];
    int tail, front, state;
    float r;
    memset(remain, 0, sizeof(remain));
    queue[0] = 0, remain[0] = m;
    tail = 0, front = 1;
    while(tail < front){
        state = queue[tail++];
        r = remain[state];
        for(int i = 0; i < n; i++)
            if(remain[ state ^ relate[i] ] < remain[state] * (1 - f[i] / 100.0)){
                queue[front++] = state ^ relate[i];
                remain[ state ^ relate[i] ] = remain[state] * (1 - f[i] / 100.0);
            }
    }
}

int main(){
    int i, j, k;
    //freopen("input.txt", "r", stdin);
    cout.setf(ios::fixed);
    while(cin>>n>>m && n && m){
        memset(relate, 0, sizeof(relate));
        for(i = 0; i < n; i++){
            cin>>t[i];
            relate[i] = relate[i] | (1<<i);
            for(j = 0; j < t[i]; j++){
                cin>>k;
                relate[i] = relate[i] | (1<<(k-1));
            }
            cin>>f[i];
        }
        wfs();
        if(remain[(1<<n) - 1] == 0) cout<<-1<<endl;
        else cout<<setprecision(2)<<remain[(1<<n) - 1]<<endl;
    }
    return 0;
}
