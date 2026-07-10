class Solution {
public:
        bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto neigh : graph[node]) {

                // if not colored
                if(color[neigh] == 0) {
                    color[neigh] = -color[node];
                    q.push(neigh);
                }

                // if same color
                else if(color[neigh] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int i = 0; i < n; i++) {
            if(color[i] == 0) {
                if(!bfs(i, graph, color))
                    return false;
            }
        }

        return true;
    }
};