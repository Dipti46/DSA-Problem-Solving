class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjLs, vector<int>& vis){
        vis[node] =1;
        //for(int i=0; i<adjLs[node].size(); i++)
        for(auto it : adjLs[node])
        {
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
    }



    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjLs(v);

        // to change adjansay matrix to list

        for (int i=0; i<v; i++){
            for( int j=0; j<v; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    //adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(v,0);

        int count = 0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjLs,vis);
            }
        }
        return count;
    }
};