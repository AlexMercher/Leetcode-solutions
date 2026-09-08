class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<m;i++){
            int left=0;
            int right=n-1;
            while(left<=right){
                int temp=image[i][left];
                image[i][left]=1-image[i][right];
                image[i][right]=1-temp;

                left++;
                right--;
            }
        }
        return image;
    }
};