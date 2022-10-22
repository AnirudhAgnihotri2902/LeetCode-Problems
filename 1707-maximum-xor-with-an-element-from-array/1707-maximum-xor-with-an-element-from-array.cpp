struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i = 0; i<queries.size(); i++){
            queries[i].push_back(i);
            swap(queries[i][0], queries[i][1]);
        }
        Trie trie;
        sort(queries.begin(), queries.end());
        sort(nums.begin(), nums.end());
        vector<int>ans(queries.size() , -1);
        int ind = 0;
        for(int i = 0; i<queries.size(); i++){
            int ai = queries[i][0];
            int xi = queries[i][1];
            int itr = queries[i][2];
            while(ind<nums.size() && nums[ind]<=ai){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind!=0) ans[itr] = trie.findMax(xi);
        }
        return ans;
        
    }
};