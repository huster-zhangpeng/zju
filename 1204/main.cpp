#include <iostream>
#include <algorithm>
#include <stdio.h>
#define LOCAL

using namespace std;

int M, P[30];
int path[30];

int bsearch(int v) {
    int left = 0, right = M, mid;
    while(left < right) {
        mid = (left + right) / 2;
        if(v == P[mid]) return mid;
        else if(v < P[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

/*
bool dfs(int sum, int cur, int depth) {
    if(depth == M - 1) return false;
    if(cur == M) return false;

    bool flag = false;
    for(int i = cur; i < M; i++) {
        if(bsearch(sum + P[i]) >= 0) {
            flag = true;
            for(int j = 0; j <= depth; j++) {
                cout<<P[path[j]]<<"+";
            }
            cout<<P[i]<<"="<<sum+P[i]<<endl;
        }
    }
    for(int i = cur; i < M; i++) {
        path[depth + 1] = i;
        if(dfs(sum + P[i], i + 1, depth + 1))
            flag = true;
    }
    return flag;
}
*/

bool dfs(int sum, int cur, int depth, int length) {
    if(cur + (length - depth) >= M) return false;
    if(depth == length){
        if(bsearch(sum) >= 0) {
            for(int j = 0; j < depth-1; j++) {
                cout<<P[path[j]]<<"+";
            }
            cout<<P[path[depth-1]]<<"="<<sum<<endl;
            return true;
        }
        return false;
    }

    bool flag = false;
    for(int i = cur; i < M; i++) {
        path[depth] = i;
        if(dfs(sum + P[i], i + 1, depth + 1, length))
            flag = true;
    }
    return flag;
}

int main() {
    int N;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>N;
    while(N--) {
        cin>>M;
        for(int i = 0; i < M; i++)
            cin>>P[i];
        sort(P, P+M);
        bool flag = false;
        for(int l = 2; l < M; l++) {
            if(dfs(0, 0, 0, l))
                flag = true;
        }
        if(!flag) {
            cout<<"Can't find any equations."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
