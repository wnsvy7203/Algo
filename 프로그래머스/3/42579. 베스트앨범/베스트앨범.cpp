#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

map<string, int> fcnt2;
map<int, string, greater<int>> fcnt;
vector<tuple<int, string, int>> v;

bool comp(tuple<int, string, int> a, tuple<int, string, int> b)
{
    if (get<0>(a) == get<0>(b))
        return get<1>(a) < get<1>(b);
    
    return get<0>(a) > get<0>(b);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    for (int i = 0; i < genres.size(); i++)
    {
        fcnt2[genres[i]] += plays[i];
        v.push_back({plays[i], genres[i], i});
    }
    
    for (auto it = fcnt2.begin(); it != fcnt2.end(); it++)
        fcnt[it->second] = it->first;
    
    sort(v.begin(), v.end(), comp);
    
    vector<int> answer;
    for (auto it = fcnt.begin(); it != fcnt.end(); it++)
    {
        string str = it->second;
        int cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (get<1>(v[i]) == str)
            {
                cnt++;
                answer.push_back(get<2>(v[i]));
            }
            
            if (cnt == 2)
                break;
        }
    }
    return answer;
}