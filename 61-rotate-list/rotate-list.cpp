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
        if (!head) return head;
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        ListNode* curr = head;
        k %= n;
        if (k == 0) return head;

        for (int i = 1; i < n-k; i++){
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;
        tail->next = head;
        return newHead;
    }
};