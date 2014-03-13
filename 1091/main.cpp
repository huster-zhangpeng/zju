#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#define LOCAL

using namespace std;

queue<int> x[2];
queue<int> y[2];
int sp[8][8];
int MX[] = {1, 2, 2, 1, -1, -2, -2, -1};
int MY[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    string pos1, pos2;
    int cx, cy, dx, dy, k = 0;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>pos1>>pos2) {
        cx = pos1[0] - 'a';
        cy = pos1[1] - '1';
        dx = pos2[0] - 'a';
        dy = pos2[1] - '1';
        memset(sp, -1, sizeof(sp));
        while(!x[k].empty()) x[k].pop();
        while(!y[k].empty()) y[k].pop();
        sp[cx][cy] = 0;
        x[k].push(cx);
        y[k].push(cy);
        while(sp[dx][dy] == -1 && !x[k].empty()) {
            while(!x[k].empty()) {
                cx = x[k].front(); x[k].pop();
                cy = y[k].front(); y[k].pop();
                for(int i = 0; i < 8; i++) {
                    if(cx + MX[i] >=0 && cx + MX[i] < 8 && cy + MY[i] >=0 && cy + MY[i] < 8) {
                        if(sp[cx + MX[i]][cy + MY[i]] == -1) {
                            sp[cx + MX[i]][cy + MY[i]] = sp[cx][cy] + 1;
                            x[1-k].push(cx + MX[i]);
                            y[1-k].push(cy + MY[i]);
                        }
                    }
                }
            }
            k = 1 -k;
        }
        printf("To get from %s to %s takes %d knight moves.\n", pos1.c_str(), pos2.c_str(), sp[dx][dy]);
    }
    return 0;
}
