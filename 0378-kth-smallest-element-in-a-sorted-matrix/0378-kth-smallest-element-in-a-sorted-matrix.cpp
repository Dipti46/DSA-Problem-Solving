class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        for(int i=0;i<n;i++){
            pq.push({matrix[i][0], i, 0});
        }

        while(--k){
            auto cur = pq.top();
            pq.pop();

            int val = cur[0];
            int r = cur[1];
            int c = cur[2];

            if(c+1 < n){
                pq.push({matrix[r][c+1], r, c+1});
            }
        }

        return pq.top()[0];
    }
};