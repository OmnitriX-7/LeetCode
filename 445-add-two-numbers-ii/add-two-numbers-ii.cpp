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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        ListNode* x = l1;
        ListNode* y = l2;
        while (x){
            st1.push(x->val);
            x = x->next;
        }
        while (y){
            st2.push(y->val);
            y = y->next;
        }
        int c = 0;
        vector<int> v;

        while (!st1.empty() || !st2.empty() || c){
            int sum = c;
            if (!st1.empty()){
                sum += st1.top();
                st1.pop();
            }
            if (!st2.empty()){
                sum += st2.top();
                st2.pop();
            }
            v.push_back(sum%10);
            c = sum/10;
        }

        reverse(v.begin(), v.end());
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        for (auto i : v){
            ListNode* t = new ListNode(i);
            temp->next = t;
            temp = temp->next;
        }
        return ans->next;
    }
};