class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int s : students)
            q.push(s);

        int idx = 0;
        int rotations = 0;
        int n = students.size();

        while (!q.empty() && rotations < q.size()) {
            if (q.front() == sandwiches[idx]) {
                q.pop();
                idx++;
                rotations = 0;
            } else {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }
        return q.size();
    }
};