#include <cassert>
#include <iostream>
#include <vector>

void merge(std::vector<double>& values, int left, int mid, int right) {
    std::vector<double> temp;
    temp.reserve(right - left + 1);

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (values[i] <= values[j]) {
            temp.push_back(values[i++]);
        } else {
            temp.push_back(values[j++]);
        }
    }
    while (i <= mid) temp.push_back(values[i++]);
    while (j <= right) temp.push_back(values[j++]);

    for (int k = 0; k < static_cast<int>(temp.size()); ++k) {
        values[left + k] = temp[k];
    }
}

void merge_sort(std::vector<double>& values, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort(values, left, mid);
    merge_sort(values, mid + 1, right);

    if (values[mid] <= values[mid + 1]) return;
    merge(values, left, mid, right);
}

void print_check(const std::vector<double>& actual,
                 const std::vector<double>& expected,
                 const std::string& label)
{
    std::cout << label << ": " << (actual == expected ? "PASS" : "FAIL") << '\n';
}

void run_test(std::vector<double> values,
              const std::vector<double>& expected,
              const std::string& label)
{
    if (!values.empty()) {
        merge_sort(values, 0, static_cast<int>(values.size()) - 1);
    }
    print_check(values, expected, label);
}

int main()
{
    // Tests.
    run_test({}, {}, "empty vector");
    run_test({4.0}, {4.0}, "one value");
    run_test({3.0, -1.0, 2.0, 2.0, 0.0},
             {-1.0, 0.0, 2.0, 2.0, 3.0},
             "mixed values");
    run_test({1.0, 2.0, 3.0, 4.0},
             {1.0, 2.0, 3.0, 4.0},
             "already sorted");
    run_test({4.0, 3.0, 2.0, 1.0},
             {1.0, 2.0, 3.0, 4.0},
             "reverse order");

    return 0;
}
