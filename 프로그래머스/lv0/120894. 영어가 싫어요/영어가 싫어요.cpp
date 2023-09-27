#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string numbers) {
    string answer = "";
    for (int i = 0; i < numbers.size(); i++)
        switch (numbers[i])
        {
            case 'o':
                if (numbers.substr(i, 3) == "one")
                    answer += '1';
                break;
            case 't':
                if (numbers.substr(i, 3) == "two")
                    answer += '2';
                else if (numbers.substr(i, 5) == "three")
                    answer += '3';
                break;
            case 'f':
                if (numbers.substr(i, 4) == "four")
                    answer += '4';
                else if (numbers.substr(i, 4) == "five")
                    answer += '5';
                break;
            case 's':
                if (numbers.substr(i, 3) == "six")
                    answer += '6';
                else if (numbers.substr(i, 5) == "seven")
                    answer += '7';
                break;
            case 'e':
                if (numbers.substr(i, 5) == "eight")
                    answer += '8';
                break;
            case 'n':
                if (numbers.substr(i, 4) == "nine")
                    answer += '9';
                break;
            case 'z':
                if (numbers.substr(i, 4) == "zero")
                    answer += '0';
                break;
        }
    
    return stol(answer);
}