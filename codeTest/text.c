#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// returns the found number index or -1 of the number is not found
int binarySearch(int what, int nums[], int len)
{
	// search area is 1
	if (len == 1)
		if (what == nums[0])
			return 0;
		else
			return -1;

	// search area is at least 2, low < high
	int low = 0;
	int high = len - 1;
	int middle;

	while (1)
	{
		middle = (low + high) / 2;
		if (low == middle) // serach area is 2, we are done
		{
			if (what == nums[low])
				return low;
			if (what == nums[high])
				return high;
			return -1;
		}
		// Not done yet
		if (what == nums[middle]) // Found!
			return middle;
		if (what < nums[middle]) // reduce the search area, redefine low or high,
			high = middle;		 // still, low < high
		else
			low = middle;
	}
}

int main(void)
{
	int i;
	int case1[] = { 0 };
	int result = binarySearch(0, case1, 1);
	(result == 0) ? printf("Case #1 by Tianwen Wang PASSED\n") : printf("Case #1 by Tianwen Wang FAILED\n");
	// And so on... 9 more test cases
	// 2
	int case2[] = { 1, 2 };
	result = binarySearch(2, case2, 2);
	(result == 1) ? printf("Case #2 by Tianwen Wang PASSED\n") : printf("Case #2 by Tianwen Wang FAILED\n");

	// 3
	int case3[] = { 0, 1, 2 };
	result = binarySearch(2, case3, 3);
	(result == 2) ? printf("Case #3 by Tianwen Wang PASSED\n") : printf("Case #3 by Tianwen Wang FAILED\n");

	// 4
	int case4[] = { 1, 10, 100, 1000 };
	result = binarySearch(12, case4, 4);
	(result == -1) ? printf("Case #4 by Tianwen Wang PASSED\n") : printf("Case #4 by Tianwen Wang FAILED\n");

	// 5
	int case5[] = { 1, 20, 30, 1000, 10000 };
	result = binarySearch(0, case5, 5);
	(result == -1) ? printf("Case #5 by Tianwen Wang PASSED\n") : printf("Case #5 by Tianwen Wang FAILED\n");

	// 6
	int case6[] = { 9, 99, 999, 9999, 9999 };
	result = binarySearch(11, case6, 5);
	(result == -1) ? printf("Case #6 by Tianwen Wang PASSED\n") : printf("Case #6 by Tianwen Wang FAILED\n");

	// 7
	int case7[] = { 3, 4, 5, 7 };
	result = binarySearch(3, case7, 4);
	(result == 0) ? printf("Case #7 by Tianwen Wang PASSED\n") : printf("Case #7 by Tianwen Wang FAILED\n");

	// 8
	int case8[] = { 1, 2, 3, 10, 78 };
	result = binarySearch(10, case8, 5);
	(result == 3) ? printf("Case #8 by Tianwen Wang PASSED\n") : printf("Case #8 by Tianwen Wang FAILED\n");

	// 9
	int case9[] = { 909, 888, 782, 2183, 3798 };
	result = binarySearch(3798, case9, 5);
	(result == 4) ? printf("Case #9 by Tianwen Wang PASSED\n") : printf("Case #9 by Tianwen Wang FAILED\n");

	// 10
	int case10[] = { 23, 445, 1, 4087 };
	result = binarySearch(4087, case10, 4);
	(result == 3) ? printf("Case #10 by Tianwen Wang PASSED\n") : printf("Case #10 by Tianwen Wang FAILED\n");

	return 0;
}