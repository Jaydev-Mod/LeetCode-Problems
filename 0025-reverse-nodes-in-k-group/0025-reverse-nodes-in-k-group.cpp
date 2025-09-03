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
    ListNode* KthNode(ListNode* node, int k) {
        k -= 1;
        while (node != nullptr && k > 0) {
            node = node->next;
            k--;
        }

        return node;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
    
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;   
            prev = curr;        
            curr = next;        
        }
        return prev; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while (temp) {
            ListNode* kthNode = KthNode(temp, k);
            if (!kthNode) {
                if (prevNode) {
                    prevNode->next = temp;
                    break;
                }
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            reverseLinkedList(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};