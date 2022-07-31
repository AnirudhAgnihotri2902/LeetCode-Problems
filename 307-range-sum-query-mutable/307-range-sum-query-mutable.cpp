class NumArray {
public:
    vector<int>tree;
    vector<int>arr;
    int constructST(int ss, int se, int si){
        if(ss == se){
            tree[si] = arr[ss];
            return tree[si];
        }
        int mid = (ss+ se)/2;
        tree[si] = constructST(ss, mid, 2*si+1)+ constructST(mid+1, se, 2*si+2);
        return tree[si];
    }
    int getsum(int qs, int qe, int ss, int se, int si){
        if(se<qs || ss >qe){
            return 0;
        }
        if(qs<=ss && qe>=se){
            return tree[si];
        }
        int mid = (ss+ se)/2;
        return getsum(qs, qe, ss, mid, 2*si+1)+ getsum(qs, qe, mid+1, se, 2*si+2);
    }
    void updatee(int ss, int se, int i, int si, int diff){
        if(i<ss || i>se){
            return;
        }
        tree[si] = tree[si]+diff;
        // cout<<tree[si]<<" "<<si<<" "<<diff<<endl;
        if(se>ss){
            int mid = (ss+ se)/2;
            updatee(ss, mid, i, 2*si+1, diff);
            updatee(mid+1, se, i, 2*si+2, diff);
        }
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr = nums;
        for(int i = 0; i<4*n; i++)tree.push_back(0);
        constructST(0, n-1, 0);
        // for(int i : tree)
        //     cout<<i<<" ";
        // cout<<"\n";
    }
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        updatee(0, arr.size()-1, index, 0,diff);
        // for(int i : tree)
        //     cout<<i<<" ";
        // cout<<"\n";
    }
    
    int sumRange(int left, int right) {
        return getsum(left, right, 0,arr.size()-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */