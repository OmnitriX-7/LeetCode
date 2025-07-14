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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<>> pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        for (int i=0; i<lists.size(); i++){
            ListNode* curr = lists[i];
            while (curr) {
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        while (!pq.empty()) {
            dummy->next = new ListNode(pq.top());
            pq.pop();
            dummy = dummy->next;
        }
        return head->next;
    }
};