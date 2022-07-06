class Solution {
public:
    int solve(int num){
        int sum = 0;
        while(num>0){
            //cout<<"->"<<num<<" "<<sum<<endl;
            sum+=(num%10)*(num%10);
            num/=10;
        }
        return sum;
    }
    unordered_map<int, int>map;
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }
        map[n]++;
        while(n>1){
            int temp = solve(n);
            if(map.find(temp)!=map.end()){
                return false;
            }
            //cout<<n<<" ";
            map[temp]++;
            n = temp;
        }
        return true;
    }
};