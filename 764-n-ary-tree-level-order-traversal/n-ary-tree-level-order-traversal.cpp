/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> lvl_order;
        if (!root) return lvl_order;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()){
            int sz = q.size();
            vector<int> v;
            for (int i = 0; i < sz; i++){
                Node* node = q.front();
                q.pop();
                v.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++){
                    q.push(node->children[i]);
                }
            }
            lvl_order.push_back(v);
        }

        return lvl_order;
    }
};