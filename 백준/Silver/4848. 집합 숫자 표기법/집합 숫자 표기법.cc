//

#include <iostream>

using namespace std;

int n;
string gwal[16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    gwal[0] = "{}";
    gwal[1] = "{{}}";

    for (int i = 2; i <= 15; i++)
    {
        string tmp = gwal[i-1];
        tmp = tmp.substr(0, tmp.size()-1);
        tmp += ',';
        tmp += gwal[i-1];
        tmp += '}';

        gwal[i] = tmp;
    }

    cin >> n;
    string a, b;
    int ans1, ans2;
    while (n--)
    {
        cin >> a >> b;
        for (int i = 0; i <= 15; i++)
        {
            if (gwal[i] == a)
                ans1 = i;
            if (gwal[i] == b)
                ans2 = i;
        }

        cout << gwal[ans1+ans2] << '\n';
    }
}