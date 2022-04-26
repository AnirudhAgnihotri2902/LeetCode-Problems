class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int r=m.size();
        int c=m[0].size();
        vector<int>a(r,0);
        vector<int>b(c,0);
        // for(int i=0;i<r;i++){
        //     a[i]=0;
        // }
        // for(int i=0;i<c;i++){
        //     b[i]=0;
        // }
        // for(int i=0;i<r;i++){
        //     cout<<a[i]<<"\n";
        // }
        // for(int i=0;i<c;i++){
        //     cout<<b[i]<<"\n";
        // }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                   a[i]=1;
                    b[j]=1;
                }
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(a[i]==1 || b[j]==1){
                    m[i][j]=0;
                }
            }
        }
    }
};