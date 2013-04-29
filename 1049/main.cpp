#include <vector>
#include <stdio.h>
#include <iostream>
#define PI 3.1415926


using namespace std;

int main(){
    int n;
    float x, y;
    float s;
    vector<int> ret;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        s = (x * x + y * y) / 100 *PI;
        ret.push_back((int)s + 1);
    }
    for(int i = 0; i < n; i++){
        cout<<"Property "<<i+1<<": This property will begin eroding in year "<<ret[i]<<"."<<endl;
    }
    cout<<"END OF OUTPUT.";
    return 0;
}
