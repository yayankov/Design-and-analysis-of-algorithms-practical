#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

struct DisjointSets
{
    int *parent, *rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

struct Graph
{
    int V, E;
    vector< pair<int, pair<int, int>> > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST()
    {
        int mst_wt = 0;
        sort(edges.begin(), edges.end());

        DisjointSets ds(V);

        vector< pair<int, pair<int, int>> >::iterator it;
        for (it=edges.begin(); it!=edges.end(); it++)
        {
            int u = it->second.first;
            int v = it->second.second;

            int set_u = ds.find(u);
            int set_v = ds.find(v);

            if(mst_wt < it->first) {
                    mst_wt = it->first;
            }

            if (set_u != set_v)
            {
                //mst_wt += it->first;

                ds.merge(set_u, set_v);
            } else {

                return mst_wt;
            }
        }

        return mst_wt;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    int f;
    cin >> f;
     Graph g(k, f);
    int a,b,c;

    for(int i=0;i<f;i++)
    {
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
    }
    int mst_wt = g.kruskalMST();

    cout << mst_wt;

    return 0;
}



