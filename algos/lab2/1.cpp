#include <iostream>
#include <vector>

int findDuplicate(std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    
    // Находим точку встречи в цикле
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Сбрасываем медленный указатель и находим вход в цикл
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}

int main() {
    std::vector<int> nums;
    int num;
    
    while (std::cin >> num) {
        nums.push_back(num);
    }
    
    std::cout << findDuplicate(nums) << std::endl;
    
    return 0;
}