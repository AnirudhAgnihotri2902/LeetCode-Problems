class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while(maxDoubles > 0 & target>1){
            cout<<target<<" ";
            if(target%2 == 0){
                target /=2;
                count++;
                maxDoubles--;
            }
            else if(target%2 == 1){
                target-=1;
                count++;
            }
        }
        count+= target-1;
        return count;
        
    }
};