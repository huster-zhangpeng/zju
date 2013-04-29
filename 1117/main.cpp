#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stdio.h>

using namespace std;

struct _node{
    bool isLeaf;
    int left, right;
    int weight;
}node[300];
int hash[128];
int count;

struct cmp1
{
    bool operator ()(int &a,int &b)
    {
        return node[a].weight > node[b].weight;//最小值优先
    }
};

void visit(int root, int depth){
    if(node[root].isLeaf)
        count += node[root].weight * depth;
    else{
        visit(node[root].left, depth + 1);
        visit(node[root].right, depth + 1);
    }
}

int main(){
    unsigned int i;
    string str;
    int n1, n2;
    freopen("input.txt", "r", stdin);
    while(cin>>str){
        if(str.compare("END") == 0) break;
        memset(hash, 0, sizeof(hash));
        memset(node, 0, sizeof(node));
        for(i = 0; i < str.length(); i++){
            hash[ str[i] ]++;
        }
        priority_queue<int,vector<int>,cmp1> q;
        for(i = 0; i < 128; i++) if(hash[i] > 0){
            node[i].isLeaf = true;
            node[i].weight = hash[i];
            q.push(i);
        }
        while(true){
            n1 = q.top(); q.pop();
            n2 = q.top(); q.pop();
            node[i].left = n1;
            node[i].right = n2;
            node[i].weight = node[n1].weight + node[n2].weight;
            node[i].isLeaf = false;
            if(q.empty()) break;
            else q.push(i++);
        }
        count = 0;
        visit(i, 0);
        int length = str.length()*8;
        double ratio = (float)length / count;
        cout<<length<<' '<<count;
        printf(" %.1lf\n", ratio);
    }
    return 0;
}
