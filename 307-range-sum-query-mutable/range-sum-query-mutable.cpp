class NumArray {
public:
    int n;
    vector<int> SegTree;
    void build(int node, vector<int>& nums, int start, int end){
        if (start == end) {
            SegTree[node] = nums[start];
            return;
        }
        int mid = start + (end - start)/2;
        build(2 * node, nums, start, mid);
        build(2 * node + 1, nums, mid+1, end);
        SegTree[node] = SegTree[2*node] + SegTree[2*node + 1];
    }

    void updateVal(int node, int val, int index, int start, int end){
        if (start == end){
            SegTree[node] = val;
            return;
        }
        int mid = start + (end - start)/2;
        if (index <= mid){
            updateVal(2*node, val, index, start, mid);
        }
        else {
            updateVal(2*node+1, val, index, mid+1, end);
        }
        SegTree[node] = SegTree[2 * node] + SegTree[2 * node + 1];
    }

    int query(int node, int l, int r, int left, int right){
        if (r < left || right < l) return 0;
        if (l >= left && r <= right) return SegTree[node];
        int mid = l + (r - l)/2;
        return query(2 * node, l, mid, left, right) + query(2 * node + 1, mid+1, r, left, right);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        SegTree.resize(4 * n);
        build(1, nums, 0, n-1);
    }
    
    void update(int index, int val) {
        updateVal(1, val, index, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */