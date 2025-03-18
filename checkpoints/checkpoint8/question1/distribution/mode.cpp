#include <iostream>

int search(int *arr, int size, int target);
int mode(int *arr, int size);

int main(void)
{
    int n;
    std::cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "The mode of the set is " << mode(arr, n) << std::endl;
    delete[] arr;
    return 0;

}

int search(int *arr, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int mode(int *arr, int size)
{
    int *nums = new int[size];
    int *counts = new int[size];
    int num_count = 0;

    for (int i = 0; i < size; i++)
    {
        int index = search(nums, num_count, arr[i]);
        if (index == -1)
        {
            nums[num_count] = arr[i];
            counts[num_count] = 1;
            num_count++;
        }
        else
        {
            counts[index]++;
        }
    }

    int mode_index = 0;
    for (int i = 1; i < num_count; i++)
    {
        if (counts[i] > counts[mode_index])
        {
            mode_index = i;
        }
    }
    
    int ret = nums[mode_index];
    delete[] nums;
    delete[] counts;
    return ret;
}