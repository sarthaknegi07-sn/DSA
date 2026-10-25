class Solution {
public:
    int binRep(int no){
        int cnt=0;
        while(no!=0){
            if(no%2!=0)
                cnt++;
            no=no/2;
        }
        return cnt;
    }
    int calculateScore(int a, int b) {
        int s1=0;
        int s2=0;
        s1=binRep(a);
        s2=binRep(b);

        if(s1>=s2)
            return s1*s2;
        return s2/s1;
    }
};