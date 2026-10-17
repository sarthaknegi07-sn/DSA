class Solution {
public:
    bool checkPerfectNumber(int num) {
        int n=num;
        if(n == 6 || n == 28 || n == 496 || n == 8128 || n == 33550336)
            return true;
        return false;
    }
};