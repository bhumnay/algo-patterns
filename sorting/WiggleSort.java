package sorting;

//nums[0] <= nums[1] >= nums[2] <= nums[3]....
public class WiggleSort {

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int[] getWiggleSort(int[] nums) { // TC: O(n) SC:O(1)
        for (int i = 0; i < nums.length - 1; i++) {
            if (i % 2 == 0) {
                if (nums[i] > nums[i + 1]) {
                    swap(nums, i, i + 1);
                }
            } else {
                if (nums[i] < nums[i + 1]) {
                    swap(nums, i, i + 1);
                }
            }
        }
        return nums;
    }

    public static void main(String[] args) {
        WiggleSort wiggleSort = new WiggleSort();
        int[] nums = { 3, 5, 2, 1, 6, 4 };
        int[] result = wiggleSort.getWiggleSort(nums);
        for (int i : result) {
            System.out.print(i + " ");
        }
    }
}
