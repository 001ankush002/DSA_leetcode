class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int count1 = 0;
        for(int i = n-2; i >= 0 && bits[i]; i--){
            count1++;
        }
        return count1%2 == 0 ? true : false;
    }
};