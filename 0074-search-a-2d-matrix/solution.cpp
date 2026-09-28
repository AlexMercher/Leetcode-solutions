class Solution {
public:
    int getrow(const vector<vector<int>>& matrix,int target,int m){
        int up=0;
        int bottom=m-1;
        int row=-1;
        while(up<=bottom){
            int mid=up+(bottom-up)/2;
            if(matrix[mid][0]<=target){
                row=mid;
                up=mid+1;
            }else bottom=mid-1;
        }
        return row;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int row=getrow(matrix,target,m);
        if(row==-1) return false;
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int ele=matrix[row][mid];
            if(ele==target) return true;
            else if(ele>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};