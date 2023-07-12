/// https://lightoj.com/problem/back-to-underworld
/*
The algorithm used in this code is a variation of Breadth-First Search (BFS) for graph traversal and coloring. It is used to determine the maximum number of nodes that can be colored in two different colors (black and red) such that no two adjacent nodes have the same color.
*/

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 20005;

list<int> adj[SIZE];
int color[SIZE];

enum Color
{
    NOT_VISITED,
    BLACK,
    RED
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numTestCases;
    cin >> numTestCases;

    for(int testCase = 1; testCase <= numTestCases; testCase++)
    {
        int numNodes;
        cin >> numNodes;

        memset(color, 0, sizeof color);
        for(int i=0; i<SIZE; i++)
            adj[i].clear();

        for(int i=0; i<numNodes; i++)
        {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int maxRace = 0;
        for (int i=0; i<SIZE; i++)
        {
            if (!adj[i].empty() && color[i] == NOT_VISITED)
            {
                int black = 0, red = 0;
                queue<int>q;
                q.push(i);
                color[i] = BLACK;
                black++;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(auto it = adj[node].begin(); it != adj[node].end(); it++)
                    {
                        if(color[*it] == NOT_VISITED)
                        {
                            q.push(*it);
                            if(color[node] == BLACK)
                            {
                                color[*it] = RED;
                                red++;
                            }
                            else
                            {
                                color[*it] = BLACK;
                                black++;
                            }
                        }
                    }
                }
                maxRace += max(red, black);
            }
        }
        cout << "Case " << testCase << ": " << maxRace << "\n";
    }

    return 0;
}
