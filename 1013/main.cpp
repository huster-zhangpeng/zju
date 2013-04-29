#include <iostream>
#include <cstring>
#include <stdio.h>
#define LOCAL

using namespace std;

struct {
    int w, s, d;
}helm, armor, boot;
struct {
    int wl, sl;
}caravan[100];
int f[2][500][500];
int c1, c2, c3, d4;
int N;

int cal(int i, int a, int b){
    int remainW = caravan[i-1].wl - a * helm.w - b * armor.w;
    int remainS = caravan[i-1].sl - a * helm.s - b * armor.s;
    return min(remainW / boot.w, remainS / boot.s);
}

int maxBoots(int i, int j, int k){
    int max, helms, armors, remainW, remainS, tmp;
    helms = min(caravan[i-1].wl / helm.w, caravan[i-1].sl / helm.s);
    remainW = caravan[i-1].wl;
    remainS = caravan[i-1].sl;
    max = 0;
    for(int a = 0; a < helms && a <= j; a++){
        armors = min(remainW / armor.w, remainS / armor.s);
        for(int b = 0; b < armors && b <= k; b++){
            tmp = f[i-1][j-a][k-b] + cal(i, a, b);
            if(max < tmp) max = tmp;
        }
        remainW -= helm.w;
        remainS -= helm.s;
    }
    return max;
}

void solve(){
    int i, j, k;
    int maxHelms, maxArmors;
    memset(f, 0, sizeof(f));
    maxHelms = maxArmors = 0;
    for(i = 1; i <= N; i++){
        maxHelms += min(caravan[i-1].wl / helm.w, caravan[i-1].sl / helm.s);
        maxArmors += min(caravan[i-1].wl / armor.w, caravan[i-1].sl / armor.s);
        for(j = 1; j < maxHelms; j++){
            for(k = 1; k < maxArmors; k++){
                f[i][j][k] = maxBoots(i, j, k);
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>N && N){
        cin>>helm.w>>helm.s>>helm.d;
        cin>>armor.w>>armor.s>>armor.d;
        cin>>boot.w>>boot.s>>boot.d;
        for(int i = 0; i < N; i++){
            cin>>caravan[i].wl>>caravan[i].sl;
        }
        solve();
    }
    return 0;
}
