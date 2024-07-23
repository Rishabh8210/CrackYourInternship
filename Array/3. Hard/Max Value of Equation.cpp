class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int maxEquVal = INT_MIN;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < points.size(); i++){
            int xi = points[i][0];
            int yi = points[i][1];

            while(!pq.empty() && points[i][0] - pq.top().second > k)
                pq.pop();
            
            if(!pq.empty()){
                maxEquVal = max(maxEquVal, (pq.top().first + points[i][0] + points[i][1]));
            }
            pq.push({yi-xi, xi});
        }
        return maxEquVal;
    }
};