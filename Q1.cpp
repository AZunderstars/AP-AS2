#include <iostream>
#include <string>
using namespace std;

const string STARTING_STRING = "0";
const string EMPTY_STRING = "";
const string ZER0_REPLACEMENT = "01";
const string ONE_REPLACEMENT = "10";

string placement(int index, int level, int &levels_done, string &input_string, string &output_string)
{
    if (index >= input_string.size())
    {
        levels_done++;
        if (levels_done == level)
            return output_string;
        input_string = output_string;
        output_string = EMPTY_STRING;
        return placement(0, level, levels_done, input_string, output_string);
    }
    if (input_string[index] == '0')
        output_string.append(ZER0_REPLACEMENT);
    else
        output_string.append(ONE_REPLACEMENT);
    index++;
    return placement(index, level, levels_done, input_string, output_string);
}

int main()
{
    int level, find;
    cin >> level >> find;
    int levels_done = 1;
    string input_string = STARTING_STRING;
    string output_string = EMPTY_STRING;
    placement(0, level, levels_done, input_string, output_string);
    cout << output_string[find - 1];
    return 0;
}