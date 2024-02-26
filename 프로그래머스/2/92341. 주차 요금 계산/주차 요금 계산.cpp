#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, tuple<bool, int, int>> input;
    for (string record : records)
    {
        string code = record.substr(11);
        int time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
        string car = record.substr(6, 4);
        
        if (code == "IN")
        {
            get<0>(input[car]) = true;
            get<1>(input[car]) = time;
        }
        else
        {
            int parking = time - get<1>(input[car]);
            get<0>(input[car]) = false;
            get<1>(input[car]) = 0;
            get<2>(input[car]) += parking;
        }
    }
    
    map<string, int> costs;
    for (auto it : input)
    {
        if (get<0>(it.second) == true)
        {
            int parking = 1439 - get<1>(it.second);
            get<0>(it.second) = false;
            get<1>(it.second) = 0;
            get<2>(it.second) += parking;
        }
        
        costs[it.first] = get<2>(it.second);
    }

    for (auto it : costs)
    {
        int parking = it.second;
        int cost = 0;
            
        if (parking <= fees[0])
            cost = fees[1];
        else
        {
            parking -= fees[0];
            cost += fees[1];

            if (!(parking % fees[2]))
            {
                parking /= fees[2];
            }
            else
            {
                parking /= fees[2];
                parking++;
            }
            
            cost += (parking * fees[3]);
        }
        
        answer.push_back(cost);
    }
    
    return answer;
}