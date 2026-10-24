class Solution {
public:
    int dayofYear(string date){
        vector<int> days={31,28,31,30,31,30,31,31,30,31,30,31};
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));

        for(int i=0;i<month-1;i++){
            day+=days[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start=max(dayofYear(arriveAlice),dayofYear(arriveBob));
        int end=min(dayofYear(leaveAlice),dayofYear(leaveBob));
        if(start>end) return 0;
        return end-start+1;
        
    }
};