/* Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 

key: use a stack, work on the top, merge or push.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class lessInterval{
public:
    bool operator()(const Interval &a, const Interval &b){
        return a.start < b.start;
    }

}mylesser;
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;//use as a stack
        
        if(!intervals.size()){
            return res;
        }
        
        std::sort(intervals.begin(), intervals.end(), mylesser);
        
        int cur = 0;//stack top
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size();){
            if(isOverlap(res[cur], intervals[i])){ //compare with top
                merge(res[cur], intervals[i]);
                i++;
            }else{
                res.push_back(intervals[i]); //push stack
                cur++;//push stack, move top
                i++;
            }
        }
        return res;
    }
    bool isOverlap(const Interval &a, const Interval &b){
        if(a.end >= b.start){
            return true;
        }
        return false;
    }
    void merge(Interval &a, Interval &b){
        a.start = std::min(a.start, b.start);
        a.end = std::max(a.end, b.end);
    }
};