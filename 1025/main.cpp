/*
* ZOJ-1025
* 把数字给看错了，后来才发现数字是5000
* 此题是求最长递增序列的最少数目，等价于
* 求最长不降子序列的长度
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _stick{
    int length;
    int weight;
}Stick;

Stick sticks[5000];
int n;
int least[5000] = {0};

bool cmp(const Stick& s1, const Stick& s2){
    if(s1.length == s2.length){
        return s1.weight < s2.weight;
    }
    return s1.length < s2.length;
}

void solve(){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(sticks[j].weight > sticks[i].weight &&
               least[j] >= least[i]){
                least[i] = least[j] + 1;
            }
        }
    }
    int max = least[0];
    for(int i = 1; i < n; i++){
        if(max < least[i]) max = least[i];
    }
    cout<<max<<endl;
}

int main(){
    int m;
    cin>>m;
    while(m--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>sticks[i].length>>sticks[i].weight;
            least[i] = 1;
        }
        sort(sticks, sticks+n, cmp);
        solve();
    }
    return 0;
}
