#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string solve(string source, string target)
    {
        if (target.empty())
        {
            return "";
        }
        if (source.empty())
        {
            string str;
            int j = 0;
            while (j < target.length())
            {
                str += "+";
                str += target[j];
                j++;
            }
            return str;
        }

        if (source[0] == target[0])
        {
            string str;
            str += source[0];
            return str.append(solve(source.substr(1), target.substr(1)));
        }
        else
        {

            string str1 = solve(source.substr(1), target.substr(0));
            string str2 = solve(source.substr(0), target.substr(1));

            if (str1.length() <= str2.length())
            {
                string str;
                str.append("-").append(source.substr(0, 1)).append(str1);
                return str;
            }
            else
            {
                string str;
                str.append("+").append(target.substr(0, 1)).append(str2);
                return str;
            }
        }
    }
};

int main()
{
    cout << Solution().solve("ABCDEFG", "ABDFFGH") << endl;
    cout << "Correct answer:"
         << "AB-CD-EF+FG+H" << endl;
    return 0;
}
// AB-CD-EF+FG+H
