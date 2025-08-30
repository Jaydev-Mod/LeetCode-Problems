class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for (int num : nums) {
            if (minh.size() < k) {
                minh.push(num);
            } else if (num > minh.top()) {
                minh.pop();
                minh.push(num);
            }
        }
        return minh.top();
    }
};