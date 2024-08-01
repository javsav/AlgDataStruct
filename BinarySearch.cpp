#include <vector>

using namespace std;

vector<int> checkSurrounding(int& index, vector<int>& nums, int& size, int& target) {
        vector<int> ans;
        int indx = index;
        int leftCount = 0;
        int rightCount = 0;

        while (indx > 0 && nums[indx - 1] == target) {
            indx--;
            leftCount++;
        }
        indx = index;




        while (indx < size - 1 && nums[indx + 1] == target) {
            indx++;
            rightCount++;
        }

        ans.push_back(index - leftCount);
        ans.push_back(index + rightCount);

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int end = len - 1;
        int start = 0;
        int mid = (start + end) / 2;

        while (start <= end) {
            if (nums[start] == target) {
                return checkSurrounding(start, nums, len, target);
            } else if (nums[mid] == target) {
                return checkSurrounding(mid, nums, len, target);
            } else if (nums[end] == target) {
                return checkSurrounding(end, nums, len, target);
            }

            if (nums[mid] > target) {
                end = mid - 1;
                mid = (start + end) / 2;
            } else {
                start = mid + 1;
                mid = (start + end) / 2;
            }
        }

        vector<int> notFound;
        notFound.push_back(-1);
        notFound.push_back(-1);
        return notFound;
    }
