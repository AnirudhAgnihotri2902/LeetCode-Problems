class Solution {
public:
    vector<long long int>tree;
    int mod = 1e9+7;
    vector<long long int>arr;
    long long int constructST(int ss, int se, int si){
        if(ss == se){
            tree[si] = arr[ss];
            return tree[si];
        }
        int mid = (ss+ se)/2;
        tree[si] = ((constructST(ss, mid, 2*si+1)%mod) * (constructST(mid+1, se, 2*si+2)%mod))%mod;
        return tree[si]%mod;
    }
    long long int getmult(int qs, int qe, int ss, int se, int si){
        if(se<qs || ss >qe){
            return 1;
        }
        if(qs<=ss && qe>=se){
            return tree[si];
        }
        int mid = (ss+ se)/2;
        return (getmult(qs, qe, ss, mid, 2*si+1)%mod * getmult(qs, qe, mid+1, se, 2*si+2)%mod)%mod;
    }
    vector<int> productQueries(int N, vector<vector<int>>& queries) {
        for(int i = 0; i<4*32 +10; i++)tree.push_back(1);
        for(int i = 0; i < 32; i++) {
            long long int mask = 1 << i;
            if(N & mask)
                arr.push_back(mask);
        }
        int n = arr.size();
        constructST(0, n-1, 0 );
        vector<int>ans;
        for(auto it : queries) {
            long long int f = getmult(it[0], it[1],0,n-1, 0);
            ans.push_back(f % mod);
        }
        return ans;
    }
};