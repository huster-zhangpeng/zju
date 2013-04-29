/*
*ZOJ-1005
*宽度优先搜索，写的还蛮复杂的
*/
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <stdio.h>

using namespace std;

typedef struct _status{
    struct _status* parent;
    int step;
    int p;
    int q;
}status;

list<status> statusList;
list<status>::iterator front;
map<int, bool> ret;

int a, b, c;
bool isFinalB;

const char* const strs[] = {
            "fill A",
            "fill B",
            "pour A B",
            "pour B A",
            "empty A",
            "empty B"
        };

bool wfs(){
    int tp, tq;
    map<int, bool>::iterator keyPos;
    status s;
    s.parent = NULL;
    s.step = -1;
    s.p = 0;
    s.q = 0;
    statusList.clear();
    statusList.push_back(s);
    ret.clear();
    //ret.insert(map<int, bool>::value_type(0, true));
    ret[0] = true;
    front = statusList.begin();
    int i = 0;
    while(true){
        tp = front->p;
        tq = front->q;
        if(tp == c){
            isFinalB = false;
            return true;
        }
        if(tq == c){
            isFinalB = true;
            return true;
        }
        if(++i == 9){
            i = 9;
        }
        keyPos = ret.find(a*(b+1) + tq);
        if(tp < a && keyPos == ret.end()){
            s.p = a;
            s.q = tq;
            s.step = 0;
            s.parent = &(*front);
            statusList.push_back(s);
            ret.insert(map<int, bool>::value_type(a*(b+1) + tq, true));
        }
        keyPos = ret.find(tp*(b+1) + b);
        if(tq < b && keyPos == ret.end()){
            s.p = tp;
            s.q = b;
            s.step = 1;
            s.parent = &(*front);
            statusList.push_back(s);
            ret.insert(map<int, bool>::value_type(tp*(b+1) + b, true));
        }
        keyPos = ret.find(tq);
        if(tp > 0 && keyPos == ret.end()){
            s.p = 0;
            s.q = tq;
            s.step = 4;
            s.parent = &(*front);
            statusList.push_back(s);
            ret.insert(map<int, bool>::value_type(tq, true));
        }
        keyPos = ret.find(tp*(b+1));
        if(tq > 0 && keyPos == ret.end()){
            s.p = tp;
            s.q = 0;
            s.step = 5;
            s.parent = &(*front);
            statusList.push_back(s);
            ret.insert(map<int, bool>::value_type(tp*(b+1), true));
        }

        if(tq < b && tp > 0){
            s.p = tp < (b - tq) ? 0 : (tp - b + tq);
            s.q = tq + tp - s.p;
            keyPos = ret.find(s.p*(b+1) + s.q);
            if(keyPos == ret.end()){
                s.step = 2;
                s.parent = &(*front);
                statusList.push_back(s);
                ret.insert(map<int, bool>::value_type(s.p*(b+1) + s.q, true));
            }
        }
        if(tp < a && tq > 0){
            s.q = tq < (a - tp) ? 0 : (tq - a + tp);
            s.p = tp + tq - s.q;
            keyPos = ret.find(s.p*(b+1) + s.q);
            if(keyPos == ret.end()){
                s.step = 3;
                s.parent = &(*front);
                statusList.push_back(s);
                ret.insert(map<int, bool>::value_type(s.p*(b+1) + s.q, true));
            }
        }
        front ++;
    }
    return false;
}

void print_r(){
    stack<int> s;
    status* p = &(*front);
    while(p){
        if(p->step >= 0)
            s.push(p->step);
        p = p->parent;
    }
    while(!s.empty()){
        printf("%s\n", strs[ s.top() ]);
        s.pop();
    }
    if(!isFinalB){
        printf("%s\n%s\n", strs[5], strs[2]);
    }
}

int main(){
    while(cin>>a>>b>>c){
        if(wfs()){
            print_r();
            cout<<"success"<<endl;
        } else {
            cout<<"failed"<<endl;
        }
    }
    return 0;
}
