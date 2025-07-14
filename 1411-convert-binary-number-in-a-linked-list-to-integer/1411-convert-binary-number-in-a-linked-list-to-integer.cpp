/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        int length = 0;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            length++;
            temp = temp->next;
        }
        int i = length;
        while (head != nullptr) {
            if (head->val == 1) {
                ans += pow(2, i);
            }
            i--;
            head = head->next;
        }
        return ans;
    }
};