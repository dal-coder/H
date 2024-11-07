#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Target not found
}

void analyzeSearchPerformance() {
    vector<int> arr(10000);
    for (int i = 0; i < 10000; ++i) {
        arr[i] = i;
    }

    // Best case: target in the middle
    int target_best = arr[arr.size() / 2];
    auto start = chrono::high_resolution_clock::now();
    int result = binary_search(arr, target_best);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Best Case: Target found at index " << result << " in " << duration.count() / 1e9 << " seconds\n";

    // Worst case: target not in the array
    int target_worst = -1;
    start = chrono::high_resolution_clock::now();
    result = binary_search(arr, target_worst);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Worst Case: Target not found in " << duration.count() / 1e9 << " seconds\n";

    // Average case: random target
    int target_avg = rand() % 10000;
    start = chrono::high_resolution_clock::now();
    result = binary_search(arr, target_avg);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Average Case: Target found at index " << result << " in " << duration.count() / 1e9 << " seconds\n";
}
