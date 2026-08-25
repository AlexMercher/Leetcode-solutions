class Solution {
public:
    double radius,xc,yc;
    Solution(double radius, double x_center, double y_center) {
        this->radius=radius;
        this->xc=x_center;
        this->yc=y_center;
    }
    
    vector<double> randPoint() {
        while(true){
            double x=xc-radius+2.0*radius*rand()/RAND_MAX;
            double y=yc-radius+2.0*radius*rand()/RAND_MAX;

            double dx=x-xc;
            double dy=y-yc;

            if(dx*dx+dy*dy<=radius*radius) return {x,y};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */