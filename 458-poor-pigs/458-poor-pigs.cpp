class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest/minutesToDie;
        
        int x = 0;
        while(pow((rounds+1),x) < buckets){
            x++;
        }
        
        return x;
    }
};