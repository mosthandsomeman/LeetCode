#include<vector>
using namespace std;
class MyCalendar {
public:
    struct Node
    {
        int beg, end;
        Node(int _b,int _e):beg(_b), end(_e){}
    };
    vector<Node> vec;
    MyCalendar() {
        vec.clear();
    }
    
    bool book(int start, int end) {
        if(start >= end) return false;
        for(int i=0;i<vec.size();++i){
            if((start >= vec[i].beg && start < vec[i].end)||(end > vec[i].beg && end <= vec[i].end)
            ||(start <= vec[i].beg && end >= vec[i].end)){
              return false;
            }
        }
        Node tmp(start, end);
        vec.push_back(tmp);
        return true;
    }
};