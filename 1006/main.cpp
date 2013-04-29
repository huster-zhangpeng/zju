/*
*ZOJ-1006
*º”√‹”ÎΩ‚√‹
*/
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string ciphertext;
string plaintext;
int k;

void decrypt(){
    char ch;
    int cyphercode;
    int plaincode;
    int n = ciphertext.length();
    for(int i =0; i < n; i++){
        ch = ciphertext.at(i);
        switch(ch){
            case '_': cyphercode = 0; break;
            case '.': cyphercode = 27; break;
            default: cyphercode = ch - 'a' + 1; break;
        }
        plaincode = (i + cyphercode) % 28;
        switch(plaincode){
            case 0: ch = '_'; break;
            case 27: ch = '.'; break;
            default: ch = 'a' + plaincode - 1; break;
        }
        plaintext[ k*i % n ] = ch;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    while(cin>>k && k){
        cin>>ciphertext;
        plaintext.clear();
        plaintext.append(ciphertext.length(), ' ');
        decrypt();
        cout<<plaintext<<endl;
    }
    return 0;
}
