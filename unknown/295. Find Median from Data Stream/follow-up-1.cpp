#include <iostream>
#include <vector>
using namespace std;

double getMedian(vector<int> &stream)
{
    int n = stream.size();
    vector<int> counter(101, 0);
    for (auto i : stream)
    {
        counter[i]++;
    }
    if (n % 2 == 0)
    {
        int first = ((n - 1) / 2) + 1;
        int second = (n / 2) + 1;
        int currIdx = 0;
        for (int i = 0; i < 101; i++)
        {
            if (first > currIdx && first <= currIdx + counter[i])
            {
                first = i;
            }
            if (second > currIdx && second <= currIdx + counter[i])
            {
                second = i;
                break;
            }
            currIdx += counter[i];
        }
        return (first + second) / 2.0;
    }
    int idx = (n / 2) + 1;
    int currIdx = 0;
    int median = -1;
    for (int i = 0; i < 101; i++)
    {
        if (idx > currIdx && idx <= currIdx + counter[i])
        {
            median = i;
            break;
        }
        currIdx += counter[i];
    }
    return median;
}

int main()
{
    vector<int> input = {1, 1, 1, 3};
    cout << getMedian(input) << endl;
}