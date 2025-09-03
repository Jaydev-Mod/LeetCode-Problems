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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        ListNode* temp = head;
        int length = 0;
        while (temp) {
            temp = temp->next;
            length++;
        }

        int rotate = k % length;
        if (rotate == 0){
            return head;
        }

        ListNode* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = head;

        ListNode* tail = head;
        int tailNode = length - rotate;
        for(int i = 0; i < tailNode-1; i++){
            tail = tail->next;
        }

        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};