#include<cmath>
#include<iostream>
using namespace std;

bool ispossible(long long mid, long long b[],long long c[],long long n,long long m)
{
    long long temp = 0;
    for(int i=0; i<n; i++)
    {
        long long candies = b[i] * c[i];

        if(candies > mid)
        {
            long long x = candies-mid;
            temp += ceil(((long double)x)/c[i]);
        }
    }
    if(temp<=m)
        return true;
    else return false;
}

long long bs(long long b[], long long c[], long long n, long long m)
{

    long long r;
    long long l = 0;
    for(int i=1; i<n; i++)
        r = max(r, b[i] * c[i]);
    long long ans = r;
    while(l <= r)
    {
        long long mid = (l+r)/2;
        if(ispossible(mid, b, c, n, m))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m;
    cin >> n >> m;
    long long b[n];
    long long c[n];

    for(int i=0;i<n;i++)
        cin >> b[i];

    for(int i=0;i<n;i++)
        cin >> c[i];

    cout << bs(b,c,n,m);

    return 0;

}
