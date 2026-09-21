class Solution {
public:
    bool canAliceWin(int n) {
       bool IsAliceTurn = true;
       int s = 10;
       while(s>0){
        n -= s;
        if(n<0){
            return !IsAliceTurn;
        }
        IsAliceTurn = !IsAliceTurn;
        s--;
       }
       return true;
    }
};