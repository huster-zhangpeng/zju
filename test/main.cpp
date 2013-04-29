#include <iostream>
#include <stdio.h>
#include <cstring>
#include <bitset>

using namespace std;

int main(){
    int a, b;
    bitset<9> may[9][9];
    for(a = 0; a < 9; a++)
        for(b = 0; b < 9; b++)
            may[a][b].set();
    //memset(may, 255, sizeof(may));
    cout<<(-1 % 9)<<endl;
    return 0;
}
