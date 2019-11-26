#include<vector>
#include<iostream>
using namespace std;
pair<float, float> getLinEqCoeff(string s)
{
    int i1 = s.find('x');
    int i2 = s.find('+');
    int i;
    float a, b;
    int flag = 0;
    vector<int>minus;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '-')
        {
            minus.push_back(i);
        }
    }
    // Set i value to the actual - operator position
    if(minus.size() == 3) i = minus[1];
    else if(minus.size() == 1) i = minus[0];
    else if(minus.size() > 0)
    {
        // 2 equations possible ax - b, b - ax;
        if(minus[0] < i1) i = minus[1];
        else i = minus[0];
    }
    if(i2 != -1)
    {
        i = i2;
    } 
	if(i < i1)
    {
        // equation of the format b +/- ax
        if(i + 1 == i1)
        {
            a = 0;
        }
        else a = stof(s.substr(i + 1, i1));
        b = stof(s.substr(0, i));
        if(i2 == -1)
        {
            a = -a;
            flag = 1;
        }
    }
    else
    {
        // equation of the format ax +/- b
        if(i1 == 0)
        {
            a = 1;
        }
        else a = stof(s.substr(0, i1));
        //cout << i << endl;
        b = stof(s.substr(i + 1, s.size()));
        if(i2 == -1) b = -b;
    }
    if(a == 0)
    {
        if(flag) a = -1;
        else a = 1;
    }
    return make_pair(a, b);
}
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    int i = 9;
    while(i > 0)
    {
        getline(cin, s);
        pair<float, float> p = getLinEqCoeff(s);
        cout << p.first << " " << p.second << endl;
        i--;
    }
}