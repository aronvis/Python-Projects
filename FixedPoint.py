def fixedPoint(arr):
    # Checks whether the list is empty
    if arr[len] == 0:
        return -1
    left, right = 0, len(arr) - 1
    # Stops when left and right point at solution or the last element in the search
    while left < right:
        mid = left + ((right - left) // 2)
        # This condition works because we will always have an element on the right of mid when still in the loop
        if arr[mid] < mid:
            left = mid + 1
        else:
            right = mid
    if arr[left] == left:
        return arr[left]
    else:
        return -1

# Test cases:
# 1) [] -> -1
# 2) [1] -> - 1
# 3) [0] -> 0
# 4) [-1] -> -1
# 5) [-1,1,2] -> 1
# 6) [0,1,2] -> 0
# 7) [-1,1] -> 1
# 8) [1,2] -> -1
# 9) Check for infinite loop (left = mid): [0,2] -> Condition not present
