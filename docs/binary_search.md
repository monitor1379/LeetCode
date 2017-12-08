# 二分查找及其变形

以下的所有输入nums均假设已排序。

### 二分查找nums中target的下标，如果不存在，则返回-1

```c++
int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        if(nums[mid] < target) low = mid + 1;
        else if(nums[mid] > target) high = mid;
        else return mid;
    }
    return low;
}
```

### 二分查找nums中第一个大于target的数的下标，如果不存在，则返回-1

```c++
int binarySearchFirstLargerNum(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;
        cout << low << ", " << mid << ", " << high << endl;
        if(nums[mid] <= target) low = mid + 1;
        else if(nums[mid] > target) high = mid;
    };
    cout << low << ", " << high << endl;
    return nums[low] > target ? low : -1;
}
```

### 二分查找nums中最后一个小于target的数的下标，如果不存在，则返回-1

```c++
int binarySearchLastSmallerNum(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low < high) {
        int mid = (low + high + 1) / 2;
        if(nums[mid] < target)
            low = mid;
        else if(nums[mid] >= target)
            high = mid - 1;
    };
    return nums[high] < target ? high : -1;
}
```