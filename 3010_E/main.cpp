#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>

using namespace std;

int n, m;
int relate[10];
int t[10];
double f[10];
double maxRemain;

int main(){
    int i, j, k;
    //freopen("input.txt", "r", stdin);
    while(cin>>n>>m && n && m){
        memset(relate, 0, sizeof(relate));
        for(i = 0; i < n; i++){
            cin>>t[i];
            relate[i] = relate[i] | (1<<i);
            for(j = 0; j < t[i]; j++){
                cin>>k;
                relate[i] = relate[i] | (1<<(k-1));
            }
            cin>>k;
            f[i] = 1 - k / 100.0;
        }
        maxRemain = -1.0;
        for(i = 1; i < (1<<n); i++){
            k = (1<<n) - 1;
            double r = (double)m;
            int tmp = i;
            for(j = 0; j < n; j++, tmp >>= 1) if(tmp & 1){
                k = k ^ relate[j];
                r = r * f[j];
            }
            if(k == 0 && r > maxRemain)
                maxRemain = r;
        }

        if(maxRemain > 0) printf("%.2lf\n", maxRemain);
        else printf("-1\n");

    }
    return 0;
}
