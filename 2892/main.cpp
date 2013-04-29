#include <iostream>
#include <stdio.h>
#define LOCAL

using namespace std;

int signal[256];
int s[128];
int d[128];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int N, i, j;
    while(cin>>N && N){
        for(i = 0; i < N; i++)
            cin>>signal[i];
        for(i = 2; i <= N; i = (i<<1)){
            for(j = 0; j < (i >> 1); j++) s[j] = signal[j];
            for(; j < i; j++)d[j - (i>>1)] = signal[j];
            for(j = 0; j < (i>>1); j++){
                signal[j * 2] = (s[j] + d[j]) >> 1;
                signal[j * 2 + 1] = (s[j] - d[j]) >> 1;
            }
        }
        cout<<signal[0];
        for(int i = 1; i < N; i++)
            cout<<" "<<signal[i];
        cout<<endl;
    }
}
