#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool> & visited, vector<int>& countries, int src)
{
    visited[src] = true;
    int n = countries.size();
    for(int i=0; i<graph[src].size(); i++)
    {
        if(visited[graph[src][i]])
            continue;
        countries[n-1]++;
        dfs(graph, visited, countries, graph[src][i]);
    }
}

int main()
{
    int n, p;
    vector<vector<int>> graph;
    scanf("%d%d", &n, &p);
    graph.resize(n);
    for(int i=0; i<p; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<int> countries;
    int disJointSets = 0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            countries.push_back(1);
            dfs(graph, visited, countries, i);
            disJointSets++;
        }
    }
    long long int res = 0, sum = countries[0];
    for(int i=1; i<countries.size(); i++)
    {
        res+=sum*countries[i];
        sum+=countries[i];
    }
    printf("%lld\n", res);
    return 0;
}
