class MyCalendar {
public:
     map<int,int>map;
    MyCalendar() {   
    }
    bool book(int start, int end) {
        auto next = map.upper_bound(start);
        if(next != map.end() &&   (*next).second < end)return false;
        map.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */