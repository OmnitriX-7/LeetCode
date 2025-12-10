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
    ListNode* insertion(ListNode* curr, ListNode* sorted){
        if (sorted == NULL || sorted->val >= curr->val){
            curr->next = sorted;
            sorted = curr;
        }
        else {
            ListNode* tmp = sorted;
            while (tmp->next != NULL && tmp->next->val < curr->val){
                tmp = tmp->next;
            }
            curr->next = tmp->next;
            tmp->next = curr;
        }
        return sorted;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* t = curr->next;
            sorted = insertion(curr, sorted);
            curr = t;
        }
        return sorted;
    }
};