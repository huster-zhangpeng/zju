#include <iostream>
#include <algorithm>
#include <stdio.h>
#define LOCAL

using namespace std;

int bsearch(long *arr, int size, long v) {
    int left = 0, right = size, middle = (left + right) / 2;
    while(left < right) {
        if(arr[middle] == v) return middle;
        else if(arr[middle] < v) {
            left = middle + 1;
            middle = (left + right) / 2;
        } else {
            right = middle;
            middle = (left + right) / 2;
        }
    }
    return -1;
}

int main() {
    int N;
    long wagers[1000];
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>N && N) {
        for(int i = 0; i < N; i++)
            cin>>wagers[i];
        sort(wagers, wagers+N);
        for(int i = N-1; i >= 0; i--) {
            for(int j = 0; j < N; j++) if(j != i) {
                for(int k = 0; k < N; k++) if(k != j && k != i) {
                    long s = wagers[i] - wagers[j] - wagers[k];
                    if(s == wagers[j] || s == wagers[k] || s == wagers[i])
                        continue;
                    if(bsearch(wagers, N, s) >= 0) {
                        cout<<wagers[i]<<endl;
                        goto end;
                    }
                }
            }
        
        }
        cout<<"no solution"<<endl;
end:    continue;
    }
    return 0;
}
