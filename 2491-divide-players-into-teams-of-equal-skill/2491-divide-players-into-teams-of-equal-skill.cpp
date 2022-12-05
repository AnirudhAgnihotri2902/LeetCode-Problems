class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        sort(skill.begin(), skill.end());
        int i = 0, j = skill.size()-1;
        int prev = skill[0] + skill[j];
        ans+= skill[0] * skill[j];
        i++; j--;
        while(i<j){
            if(skill[i]+ skill[j]!=prev)return -1;
            ans+= skill[i]*skill[j];
            i++;
            j--;
        }
        return ans;
    }
};