#include <iostream>
#include <string>
#include <vector>

int binary_search_index(const std::vector<int>& values, int target)
{
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (values[mid] == target)
        {
            return mid;
        }
        else if (values[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void check(int actual, int expected, const std::string& label)
{
    std::cout << label << ": "
              << (actual == expected ? "PASS" : "FAIL")
              << " (expected " << expected << ", got " << actual << ")\n";
}

int main()
{
    const std::vector<int> values{1, 2, 3, 4, 6};

    // Tests.
    check(binary_search_index(values, 5), -1, "missing value");
    check(binary_search_index(values, 3), 2, "middle value");
    check(binary_search_index(values, 1), 0, "first value");
    check(binary_search_index(values, 6), 4, "last value");

    return 0;
}
