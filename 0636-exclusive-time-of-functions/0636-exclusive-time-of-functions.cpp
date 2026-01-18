class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string& log : logs) {
            int id, time;
            string type;

            int first = log.find(':');
            int second = log.find(':', first + 1);

            id = stoi(log.substr(0, first));
            type = log.substr(first + 1, second - first - 1);
            time = stoi(log.substr(second + 1));

            if (type == "start") {
                if (!st.empty()) {
                    result[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } else { 
                result[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return result;
    }
};
