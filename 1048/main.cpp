#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main(){
    float tmp, sum, avg;
    sum = 0.00f;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    for(int i = 0; i < 12; i++){
        cin>>tmp;
        sum += tmp;
    }
    avg = sum / 12;
    cout<<'$'<<setiosflags(ios::fixed)<<setprecision(2)<<avg<<endl;
    return 0;
}
