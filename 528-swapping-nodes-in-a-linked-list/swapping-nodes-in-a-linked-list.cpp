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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* first = nullptr;
        int size = 1;
        while (tmp){
            if (size == k){
                first = tmp;
            }
            size++;
            tmp = tmp->next;
        }
        int c = size-k-1;
        tmp = head;
        while (c--){
            tmp = tmp->next;
        }
        int z = first->val;
        first->val = tmp->val;
        tmp->val = z;
        return head;
    }
};