# DSA-II Assignment 1: Two-Pointer Technique
def remove_duplicates_reference(arr):
    unique = []
    for value in arr:
        if value not in unique:
            unique.append(value)
    return unique


def remove_duplicates_two_pointer(arr):
    if not arr:
        return 0

    slow = 0
    for fast in range(1, len(arr)):
        if arr[fast] != arr[slow]:
            slow += 1
            arr[slow] = arr[fast]
    return slow + 1


def pair_sum_brute_force(arr, target):
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if arr[i] + arr[j] == target:
                return (i, j)
    return (-1, -1)


def pair_sum_two_pointer(arr, target):
    left, right = 0, len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return (left, right)
        if current_sum < target:
            left += 1
        else:
            right -= 1
    return (-1, -1)


def main():
    duplicate_tests = [
        [1, 1, 2, 2, 2, 3, 4, 4],
        [5],
        [],
        [-3, -3, -1, 0, 0],
    ]
    print("DSA-II Assignment 1: Two-Pointer Technique\n")
    print("PART A: Remove Duplicates")
    for original in duplicate_tests:
        reference = remove_duplicates_reference(original)
        optimized = original.copy()
        k = remove_duplicates_two_pointer(optimized)
        print(f"Input: {original}")
        print(f"Reference unique list: {reference}")
        print(f"Optimized unique prefix: {optimized[:k]} (k={k})\n")

    pair_tests = [
        ([1, 2, 4, 7, 11, 15], 15),
        ([1, 3, 5, 8], 7),
        ([2, 4, 6], 20),
        ([1, 2, 2, 3], 4),
    ]
    print("PART B: Pair Sum")
    for arr, target in pair_tests:
        brute = pair_sum_brute_force(arr, target)
        fast = pair_sum_two_pointer(arr, target)
        print(f"Array: {arr}, target={target} | Brute force={brute} | Two pointers={fast}")


if __name__ == "__main__":
    main()