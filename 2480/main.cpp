#include <iostream>
#include <stdio.h>
//#define LOCAL

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int top[10], bottom[10], left[10], right[10];
    int n, k, i, x, y;
    while(cin>>n && n){
        for(i = 0; i < n; i++)
            cin>>left[i]>>bottom[i]>>right[i]>>top[i];
        cin>>k;
        while(k--){
            cin>>x>>y;
            for(i = n - 1; i >= 0; i--){
                if(x >= left[i] && x <= right[i] && y >= bottom[i] && y <= top[i])
                    break;
            }
            if(i < 0) cout<<-1<<endl;
            else cout<<i<<endl;
        }
    }
    return 0;
}
