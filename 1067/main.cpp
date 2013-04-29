#include <iostream>
#include <stdio.h>
#include <math.h>
//#define LOCAL

using namespace std;

int R[16];
int G[16];
int B[16];

int main(){
    int r, g, b, t, minD, closest;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    for(int i = 0; i < 16; i++){
        cin>>R[i]>>G[i]>>B[i];
    }
    while(cin>>r>>g>>b){
        if(r < 0 && g < 0 && b < 0) break;
        minD = sqrt((r - R[0]) * (r - R[0]) + (g - G[0]) * (g - G[0]) + (b - B[0]) * (b - B[0]));
        closest = 0;
        for(int i = 1; i < 16; i++){
            t = sqrt((r - R[i]) * (r - R[i]) + (g - G[i]) * (g - G[i]) + (b - B[i]) * (b - B[i]));
            if(minD > t){
                minD = t;
                closest = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, R[closest], G[closest], B[closest]);
    }
    return 0;
}
