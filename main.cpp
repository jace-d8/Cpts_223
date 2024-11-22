#include <iostream>
#include <vector>
#include <chrono>
#include <random>

class SortingComparison {
public:
    // insrtion sort
    void insertionSort(std::vector<int>& arr, int begin, int end)
    {
        // Compare the second element with the first element and check if the second element is smaller than swap them
        // Move to the third element and compare it with the first two elements and put at its correct position
        // Repeat until the entire array is sorted

        // Better way:
        // If we find a value that is smaller than its lhs,
        // keep de-incrementing until we find a lhs value that is smaller and insert + shuffle the rest down
        for(int i = begin; i <= end; i++) // find unordered index via looking back using j
        {

            int tmp = arr[i];
            int j = i - 1;
            for(; j >= begin && arr[j] > tmp; --j)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = tmp;
        }
        // while(!isSorted(arr))
        // {
        //     for(int i = 0, j = i + 1; j < arr.size(); i++, j++)
        //     {
        //        if(arr[j] < arr[i])
        //        {
        //            std::swap(arr[i], arr[j]);
        //        }
        //     }
        // }
    }

    // quick sort
    void quickSort(std::vector<int>& arr, int left, int right)
    {
        // Use insertionSort for vector size less than 10
        // Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary
        // (e.g., first element, last element, random element, or median).
        // Rearrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on
        // its left, and all elements greater than the pivot will be on its right. The pivot is then in its correct
        // position, and we get the index of the pivot
        // Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).
        // The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.
        if(left + 10 <= right)
        {
           int pivot = median3(arr, left, right);
            int i = left, j = right - 1;
            while(true)
            {
                while (arr[++i] < pivot) { }
                while (pivot < arr[--j]) { }
                if (i < j)
                {
                    std::swap(arr[i], arr[j]);
                }
                else
                {
                    break;
                }
            }
            std::swap(arr[i], arr[right - 1]); // Restore pivot
            quickSort(arr, left, i - 1); // Sort small elements
            quickSort(arr, i + 1, right); // Sort large elements
        }else
        {
            insertionSort(arr, left, right);
        }
    }

    // merge sort
    void mergeSort(std::vector<int>& arr, int left, int right)
    {

    }

    int median3(std::vector<int>& arr, int left, int right)
    {
        int center = (left + right) / 2;

        if (arr[center] < arr[left])
            std::swap(arr[left], arr[center]);
        if (arr[right] < arr[left])
            std::swap(arr[left], arr[right]);
        if (arr[right] < arr[center])
            std::swap(arr[center], arr[right]);

        // Place pivot at position right - 1
        std::swap(arr[center], arr[right - 1]);
        return arr[right - 1];

    }
    // generate random integers
    std::vector<int> generateRandomArray(int size)
    {
        std::vector<int> arr(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 100000);
        for (int& x : arr) {
            x = dist(gen);
        }
        return arr;
    }

    // test sorted
    bool isSorted(const std::vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // comparison run time for three sorting algorithms
    void compareSortingAlgorithms() {
        std::vector<int> sizes = {1000, 10000, 100000}; // data scales
        for (int size : sizes) {
            std::vector<int> arr = generateRandomArray(size);
            
            std::cout << "Data size: " << size << "\n";

            // test insertion sort
            std::vector<int> arr_copy = arr;
            auto start = std::chrono::high_resolution_clock::now();
            insertionSort(arr_copy, 0, arr.size() - 1);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Insertion Sort: " << elapsed.count() << " seconds\n";
            std::cout << "Sorted: " << (isSorted(arr_copy) ? "Yes" : "No") << "\n";

            // test quick sort
            arr_copy = arr;
            start = std::chrono::high_resolution_clock::now();
            quickSort(arr_copy, 0, arr_copy.size() - 1);
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std::cout << "Quick Sort: " << elapsed.count() << " seconds\n";
            std::cout << "Sorted: " << (isSorted(arr_copy) ? "Yes" : "No") << "\n";

            // test merge sort
            arr_copy = arr;
            start = std::chrono::high_resolution_clock::now();
            mergeSort(arr_copy, 0, arr_copy.size() - 1);
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std::cout << "Merge Sort: " << elapsed.count() << " seconds\n";
            std::cout << "Sorted: " << (isSorted(arr_copy) ? "Yes" : "No") << "\n\n";
        }
    }

private:
    // Some internal helper functions
};

int main() {
    SortingComparison sorter;
    sorter.compareSortingAlgorithms();
    return 0;
}
