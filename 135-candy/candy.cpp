class Solution {
public:
    int candy(vector<int>& ratings) {
        int n =ratings.size();

        //first check left neighbors
        int left[n];
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
            else
                left[i]=1;
        }

        //first check right neighbors
        int right[n];
        right[n-1]=left[n-1];
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                right[i]=max(left[i],right[i+1]+1);
            else
                right[i]=left[i];
        }

        //now sum all the candies of right array
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=right[i];
        }

        return sum;
    }
};