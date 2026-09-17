class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n=energy.size();
        int train=0;
        int ene=initialEnergy;
        int exp=initialExperience;
        for(int i=0;i<n;i++){
            if(ene<=energy[i]){
                int need=energy[i]-ene+1;
                train+=need;
                ene+=need;
            }
            if(exp<=experience[i]){
                int need=experience[i]-exp+1;
                train+=need;
                exp+=need;
            }
            exp+=experience[i];
            ene-=energy[i];
        }
        return train;
    }
};