#include <iostream>
#include <stdio.h>
#define LOCAL

using namespace std;

int width[3], height[3], num[3];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int i, j, k, w, h, temp, count;
    bool ok, step[3];
    while(1){
        ok = true;
        count = 0;
        num[0] = num[1] = num[2] = 0;
        i = 0;
        while(i < 6 && cin>>w>>h){
            for(j = 0; j < count; j++){
                if((width[j] == w && height[j] == h) ||
                   (width[j] == h && height[j] == w)){
                    num[j]++; break;
                }
            }
            if(j == 3){
                ok = false;
                for(k = i + 1; k < 6 && cin>>w>>h; k++);
                i = 6;
                break;
            }
            if(j == count){
                num[j] = 1;
                width[j] = w;
                height[j] = h;
                count++;
            }
            ++i;
        }
        if(i == 0)break;
        if(!ok) cout<<"IMPOSSIBLE"<<endl;
        else if(num[0] == 2 && num[1] == 2 &&num[2] == 2){
            if(height[0] == height[1]){
                step[0] = true;
            }else if(height[0] == width[1]){
                temp = width[1], width[1] = height[1], height[1] = temp;
                step[0] = true;
            }else if(width[0] == height[1]){
                temp = width[0], width[0] = height[0], height[0] = temp;
                step[0] = true;
            }else if(width[0] == width[1]){
                temp = width[0], width[0] = height[0], height[0] = temp;
                temp = width[1], width[1] = height[1], height[1] = temp;
            }else step[0] = false;
            if(step[0]){
                if(width[1] == height[2]) step[1] = true;
                else if(width[1] == width[2]){
                    temp = width[2], width[2] = height[2], height[2] = temp;
                    step[1] = true;
                }else step[1] = false;
            }else step[1] = false;
            if(step[1]){
                if(width[2] == width[0]) step[2] = true;
                else step[2] = false;
            }else step[2] = false;
            if(step[2]) cout<<"POSSIBLE"<<endl;
            else cout<<"IMPOSSIBLE"<<endl;
        }else if(num[0] == 2 && num[1] == 4) {
            if(width[0] == height[0] && (width[0] == width[1] || width[0] == height[1]))
                cout<<"POSSIBLE"<<endl;
            else cout<<"IMPOSSIBLE"<<endl;
        }else if(num[0] == 4 && num[1] == 2){
            if(width[1] == height[1] && (width[1] == width[0] || width[1] == height[0]))
                cout<<"POSSIBLE"<<endl;
            else cout<<"IMPOSSIBLE"<<endl;
        }else if(num[0] == 6){
            if(width[0] == height[0])cout<<"POSSIBLE"<<endl;
            else cout<<"IMPOSSIBLE"<<endl;
        }else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
