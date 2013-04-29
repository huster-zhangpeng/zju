#include <iostream>
#include <stdio.h>
#include <cstring>
#include <bitset>
#include <algorithm>
#define LOCAL

using namespace std;

typedef struct _state{
    int i, j;
    bitset<9> may;
}State;
State states[81][81];
int top[81];
char sodoku[9][9];

bool cmp(const State& s1, const State& s2){
    if(s1.may.count() == s2.may.count()){
        if(s1.i == s2.i) return s1.j < s2.j;
        return s1.i < s2.i;
    }
    return s1.may.count() < s2.may.count();
}

bool dfs(int x, int m, int n, int k){
    State s;
    int i, j;
    top[x] = 0;
    memset(states[x], 0, sizeof(states[x]));
    for(i = 0; i < top[x-1]; i++){
        s = states[x-1][i];
        if(s.i == m && s.j == n){
            continue;
        }
        if(s.i == m || s.j == n || (s.i / 3 == m / 3 && s.j / 3 == n / 3)){
            s.may.reset(k);
            if(s.may.none()) return false;
            states[x][ top[x]++ ] = s;
            continue;
        }
        states[x][ top[x]++ ] = s;
    }
    if(!top[x]) return true;
    sort(states[x], states[x] + top[x], cmp);
    for(i = 0; i < top[x]; i++){
        for(j = 0; j < 9; j++)if(states[x][i].may.test(j)){
            sodoku[ states[x][i].i ][ states[x][i].j ] = '1' + j;
            if(dfs(x+1, states[x][i].i, states[x][i].j, j))
                return true;
            sodoku[ states[x][i].i ][ states[x][i].j ] = '0';
        }
    }
    return false;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int i, j, T;
    bool ok;
    State s;
    cin>>T;
    while(T--){
        memset(sodoku, 0, sizeof(sodoku));
        for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++)
                cin>>sodoku[i][j];
        top[0] = 0;
        for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++) if(sodoku[i][j] == '0') {
                s.i = i, s.j = j;
                s.may.set();
                for(int p = 0; p < 9; p++){
                    if(sodoku[i][p] != '0') s.may.reset(sodoku[i][p] - '1');
                    if(sodoku[p][j] != '0') s.may.reset(sodoku[p][j] - '1');
                }
                for(int p = i / 3 * 3; p < i / 3 * 3 + 3; p++) for(int q = j / 3 * 3; q < j / 3 * 3 + 3; q++)
                    if(sodoku[p][q] != '0') s.may.reset(sodoku[p][q] - '1');
                states[0][ top[0]++ ] = s;
            }
        sort(states[0], states[0] + top[0], cmp);
        ok = false;
        for(i = 0; i < top[0]; i++){
            for(j = 0; j < 9; j++)if(states[0][i].may.test(j)){
                sodoku[ states[0][i].i ][ states[0][i].j ] = '1' + j;
                if(dfs(1, states[0][i].i, states[0][i].j, j)){
                    ok = true;
                    break;
                }
                sodoku[ states[0][i].i ][ states[0][i].j ] = '0';
            }
            if(ok) break;
        }

        if(ok) for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++)
                cout<<sodoku[i][j];
            cout<<endl;
        } else {
            cout<<"No answers!"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
