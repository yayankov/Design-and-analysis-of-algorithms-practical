#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <list>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool used[2000000];
vector<int> gr[2000000];
void dfs(int start)
{
  used[start] = true;
  for(int i : gr[start])
  {
        if(!used[i])
        {
            dfs(i);
        }
  }
}

int maxColours(int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            counter++;
            dfs(i);
        }
    }
    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m,from,to,counter = 0;
    cin >> n >> m;

    unordered_map<int,int> nodes;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        if (nodes.find(from) == nodes.end())
        {
            nodes[from] = counter;

            counter++;
        }
        if (nodes.find(to) == nodes.end())
        {
            nodes[to] = counter;

            counter++;
        }
        gr[nodes[from]].push_back(nodes[to]);
        gr[nodes[to]].push_back(nodes[from]);
    }
    cout << maxColours(counter)+(n-counter);
}
