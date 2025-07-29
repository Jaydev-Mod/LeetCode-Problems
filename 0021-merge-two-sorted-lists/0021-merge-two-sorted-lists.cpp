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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* sorted = head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                sorted->next = list1;
                list1 = list1->next;
            } else if (list2->val < list1->val) {
                sorted->next = list2;
                list2 = list2->next;
            }
            sorted = sorted->next;
        }
        if (list1 != nullptr) {
            sorted->next = list1;
        }else{
            sorted->next = list2;
        }
        return head->next;
    }
};