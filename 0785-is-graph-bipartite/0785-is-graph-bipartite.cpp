class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph, vector<int>& color)
    {
        queue<int> q;

        q.push(src);

        // Starting node ko pehla color de diya.
        color[src] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto nbr : graph[node])
            {
                // Agar neighbour abhi tak color nahi hua,
                // to current node ka opposite color de do.
                if(color[nbr] == -1)
                {
                    color[nbr] = 1 - color[node];
                    q.push(nbr);
                }

                // Agar neighbour ka color same nikla,
                // to graph bipartite nahi ho sakta.
                else if(color[nbr] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<int> color(n, -1);

        // Graph disconnected ho sakta hai,
        // isliye har component check karna padega.
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(!bfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};
    