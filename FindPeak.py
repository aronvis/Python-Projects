
def findPeak(arr):
    if len(arr) == 0:
        return -1
    elif len(arr) == 1:
        return 0
    left, right = 0, len(arr)-1
    while left + 1 < right:
        mid = left + ((right - left)//2)
        if arr[mid] >= arr[mid+1] and arr[mid] >= arr[mid-1]:
            return mid
        elif arr[mid] < arr[mid+1]:
            left = mid
        else:
            right = mid
    if left == 0 and arr[left] >= arr[right]:
        return left
    elif right == len(arr) - 1 and arr[left] <= arr[right]:
        return right
    else:
        if arr[left] >= arr[right]:
            return left
        else:
            return right

# Above is my first solution to the problem.
# I have simplified my solution below:

def findPeak(arr):
    if len(arr) == 0:
        return -1
    elif len(arr) == 1:
        return 0
    left, right = 0, len(arr)-1
    while left + 1 < right:
        mid = left + ((right - left)//2)
        if arr[mid] >= arr[mid+1] and arr[mid] >= arr[mid-1]:
            return mid
        elif arr[mid] < arr[mid+1]:
            left = mid
        else:
            right = mid
    # I think this can only happen when left = 0
    if arr[left] >= arr[right]:
        return left
    # I think this can only happen when right = len(arr)-1
    else:
        return right

# Test cases:
# 1) [] -> -1
# 2) [1] -> 0
# 3) [1,2] -> 1
# 4) [2,1] -> 0
# 5) [1,1] -> 0
# 6) [1,3,1] -> 1
# 7) [1,3,4,2,1,1,1] -> [1,3,4,2] -> [3,4,2] -> 2
# 8) [4,3,2] -> [4,3] -> 0
# 9) [1,2,3] -> [2,3] -> 2