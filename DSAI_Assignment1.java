import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DSAI_Assignment1 {
    static List<Integer> removeDuplicatesReference(int[] arr) {
        List<Integer> unique = new ArrayList<>();
        for (int value : arr) {
            if (!unique.contains(value)) unique.add(value);
        }
        return unique;
    }

    static int removeDuplicatesTwoPointer(int[] arr) {
        if (arr.length == 0) return 0;
        int slow = 0;
        for (int fast = 1; fast < arr.length; fast++) {
            if (arr[fast] != arr[slow]) {
                slow++;
                arr[slow] = arr[fast];
            }
        }
        return slow + 1;
    }

    static int[] pairSumBruteForce(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] + arr[j] == target) return new int[]{i, j};
            }
        }
        return new int[]{-1, -1};
    }

    static int[] pairSumTwoPointer(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) return new int[]{left, right};
            if (sum < target) left++;
            else right--;
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        int[][] duplicateTests = {
            {1, 1, 2, 2, 2, 3, 4, 4},
            {5},
            {},
            {-3, -3, -1, 0, 0}
        };
        System.out.println("PART A: Remove Duplicates");
        for (int[] input : duplicateTests) {
            List<Integer> reference = removeDuplicatesReference(input);
            int[] optimized = Arrays.copyOf(input, input.length);
            int k = removeDuplicatesTwoPointer(optimized);
            System.out.println("Input: " + Arrays.toString(input));
            System.out.println("Reference: " + reference);
            System.out.println("Optimized unique prefix: " +
                Arrays.toString(Arrays.copyOf(optimized, k)) + " (k=" + k + ")\n");
        }

        int[][] arrays = {
            {1, 2, 4, 7, 11, 15},
            {1, 3, 5, 8},
            {2, 4, 6},
            {1, 2, 2, 3}
        };
        int[] targets = {15, 7, 20, 4};
        System.out.println("PART B: Pair Sum");
        for (int i = 0; i < arrays.length; i++) {
            int[] brute = pairSumBruteForce(arrays[i], targets[i]);
            int[] fast = pairSumTwoPointer(arrays[i], targets[i]);
            System.out.println("Array: " + Arrays.toString(arrays[i]) +
                ", target=" + targets[i] +
                " | Brute force=" + Arrays.toString(brute) +
                " | Two pointers=" + Arrays.toString(fast));
        }
    }
}