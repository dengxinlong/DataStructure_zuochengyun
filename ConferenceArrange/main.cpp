/*
 * 题目：一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目的宣讲。
 *      给你每一个项目开始的时间和结束的时间(给你一个数组，里面是一个个具体项目)，你来安排宣讲的日程，要求会议室的宣讲场次最多。
 *      返回这个最多的宣讲场次
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ConferenceArrange
{
public:
    // class ConferenceTime
    // {
    // public:
    //     ConferenceTime() {}
    //     ConferenceTime(int start, int end)
    //     : _start(start)
    //     , _end(end)
    //     {}

    //     int _start;
    //     int _end;
    // };
    // class CompLess
    // {
    // public:
    //     bool
    //     operator()(const ConferenceTime & con1, const ConferenceTime & con2) { return con1._end < con2._end; }
    // };

    int
    conferenceArrange(const vector<int> & start, const vector<int> & end)
    {
        if (start.size() != end.size()) return 0;
        vector<ConferenceTime> conferences;
        int num = start.size();
        for (int i = 0; i < num; i++) {
            conferences.push_back(ConferenceTime(start[i], end[i]));
        }
        // std::sort(conferences.begin(), conferences.end(), CompLess());
        std::sort(conferences.begin(), conferences.end(), [] (const ConferenceTime & con1, const ConferenceTime & con2) -> bool
                                                        { return con1._end < con2._end; });
        int cur = conferences[0]._start;
        int ret = 0;
        for (auto elem : conferences) {
            if (elem._start >= cur) {
                cur += elem._end;
                ret++;
            }
        }
        return ret;
    }

private:
    class ConferenceTime
    {
    public:
        ConferenceTime() {}
        ConferenceTime(int start, int end)
        : _start(start)
        , _end(end)
        {}

        int _start;
        int _end;
    };
};

int
main(void)
{
    vector<int> start{1, 2, 3, 4};
    vector<int> end{3, 5, 5, 5};
    ConferenceArrange con;
    cout << con.conferenceArrange(start, end) << endl;

    return 0;
}