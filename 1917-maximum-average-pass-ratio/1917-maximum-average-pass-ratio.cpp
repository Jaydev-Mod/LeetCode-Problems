class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < n; i++){
            double pr = (double)classes[i][0]/classes[i][1];
            double upr = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = upr - pr;
            pq.push({delta, i});
        }

        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();
            
            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double pr = (double)classes[idx][0]/classes[idx][1];
            double upr = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double newdelta = upr - pr;
            pq.push({newdelta, idx});
        }

        double result = 0.0;
        for(int i = 0; i < n; i++){
            result += (double)classes[i][0]/classes[i][1];
        }

        return result / n;
    }
};