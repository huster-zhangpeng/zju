#include <iostream>
#include <string>
#include <stdio.h>
//#define LOCAL

using namespace std;

char map[27][6] = {"00001", "00010", "00011", "00100", "00101", "00110", "00111",
                    "01000", "01001", "01010", "01011", "01100", "01101", "01110",
                    "01111", "10000", "10001", "10010", "10011", "10100",
                    "10101", "10110", "10111", "11000", "11001", "11010", "00000"};
char matrix[23][23];
int N, R, C;
int direct[4][2] = {{0, 1}, {1, 0}, {0, -1},{-1, 0}};
string str;

int main(){
    int i, j, k, c, d, p, q;
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin>>N;
    for(i = 0; i < N; i++){
        cin>>R>>C;
        getline(cin, str);
        for(q = 0; q < C+2; q++)
            matrix[0][q] = matrix[R+1][q] = '2';
        for(p = 1; p < R+1; p++)
            matrix[p][0] = matrix[p][C+1] = '2';
        for(p = 1; p < R+1; p++)
            for(q = 1; q < C+1; q++)
                matrix[p][q] = -1;
        p = q = 1;
        d = 0;
        for(j = 1; j < str.length(); j++){
            if(str[j] == ' ') c = 26;
            else c = str[j] - 'A';
            for(k = 0; k < 5; k++){
                matrix[p][q] = map[c][k];
                if(matrix[ p + direct[d][0] ][ q + direct[d][1] ] < 0){
                    p = p + direct[d][0];
                    q = q + direct[d][1];
                } else {
                    d = (d + 1) % 4;
                    p = p + direct[d][0];
                    q = q + direct[d][1];
                }
            }
        }
        j = (j-1) * 5;
        while(j < R * C){
            matrix[p][q] = '0';
            if(matrix[ p + direct[d][0] ][ q + direct[d][1] ] < 0){
                p = p + direct[d][0];
                q = q + direct[d][1];
            } else {
                d = (d + 1) % 4;
                p = p + direct[d][0];
                q = q + direct[d][1];
            }
            j++;
        }
        cout<<i+1<<' ';
        for(p = 1; p < R+1; p++)
            for(q = 1; q < C+1; q++)
                cout<<matrix[p][q];
        cout<<endl;
    }
    return 0;
}
