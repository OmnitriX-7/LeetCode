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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0);
        ListNode* real = dummy;
        ListNode* tmp = head;
        while (tmp){
            if (tmp->val < x) {
                ListNode* z = new ListNode(tmp->val);
                dummy->next = z;
                dummy = dummy->next;
            }
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp){
            if (tmp->val >= x) {
                ListNode* z = new ListNode(tmp->val);
                dummy->next = z;
                dummy = dummy->next;
            }
            tmp = tmp->next;
        }
        return real->next;
    }
};