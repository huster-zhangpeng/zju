#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

bool mayBe[12];
bool mustNot[12];

int main(){
    int T, i, j;
    char data[8]
    string str;
    freopen("input.txt", "r", stdin);
    cin>>T;
    while(T--){
        memset(mustNot, 0, sizeof(mustNot));
        memset(mayBe, 0, sizeof(mayBe));
        for(i = 0; i < 3; i++){
            for(j = 0; j < 8; j++)
                cin>>data[j];
            cin>>str;
            if(str.compare("even") == 0)
                for(j = 0; j < 8; j++)
                    mustNot[data[j]-'A'] = true;
            else
                for(j = 0; j < 8; j++)
                    mayBe[data[j]-'A'] = true;
        }
    }
    return 0;
}
