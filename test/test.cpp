#include<iostream>
#include<fstream>

using namespace std;

int n;
class zsl
{
    public:
        int idx,l, r;
}a[1000];

void kp(int L, int R)
{
    int i=L, j=R;
    int m1=a[L+R>>1].l, m2=a[L+R>>1].r;
    while(i<j)
    {
        while(a[i].l<m1 || a[i].l==m1 && a[i].r<m2)   ++i;
        while(a[j].l>m1 || a[j].l==m1 && a[j].r>m2)   --j;
        if(i<=j)
        {
            swap(a[i], a[j]);
            ++i;    --j;
        }
    }

    if(i<R) kp(i, R);
    if(L<j) kp(L, j);
}

void work()
{
    int f[1000]={0}, pre[1000]={0};
    int len=1, idx=1;
    int out[1000];
    f[1]=1;
    for(int i=2; i<=n; ++i)
    {
        f[i]=1;
        for(int j=1; j<i; ++j)
            if(a[j].r<=a[i].l && f[j]+1 > f[i])
            {
                f[i]=f[j]+1;
                pre[i]=j;
            }

        if(f[i]>len)
        {
            len=f[i];
            idx=i;
        }
    }

    int temp=len;
    while(temp)
    {
        out[temp--]=a[idx].idx;
        idx=pre[idx];
    }

    for(int i=1; i<len; ++i)
        cout<<out[i]<<' ';
    cout<<out[len]<<endl;
}

int main()
{
    cin>>n;
    while(n)
    {
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i].l>>a[i].r;
            a[i].idx=i;
        }

        kp(1, n);
        work();

        cin>>n;
    }
    return 0;
}
