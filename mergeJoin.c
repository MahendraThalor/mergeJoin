/* ---------------------------------------------------------------------------
 * Merge join of 2 sorted array and print the output.
 * ---------------------------------------------------------------------------
 */

/* Header files. */
#include<stdio.h>
#include<stdbool.h>

/* Main function. */
int main()
{
	int	out_len, in_len, out_indx, in_indx, ii;
	int	out_arr[] = {1, 4, 4, 5, 8};
	int	in_arr[] = {4, 8, 12, 12, 16, 19};

	/* Calculate size of both the arrays. */
	out_len = sizeof(out_arr) / sizeof(out_arr[0]);
	in_len = sizeof(in_arr) / sizeof(in_arr[0]);

	out_indx = 0;
	in_indx = 0;

	/* Print the outer array. */
	printf("\nOuter array is :");
	for (ii = 0; ii < out_len; ii++)
		printf(" %d", out_arr[ii]);

	/* Print the inner array. */
	printf("\nInner array is :");
	for (ii = 0; ii < in_len; ii++)
		printf(" %d", in_arr[ii]);

	printf("\nMerge joined array is:");
	for (; out_indx < out_len && in_indx < in_len; )
	{
		/* Store the out_indx element of out array in temp. */
		int		temp = out_arr[out_indx];
		bool	found = false;

		/*
		 * If element of out_arr and in_arr are same, then print all the
		 * same elements of in_arr first.
		 */
		while (in_indx < in_len && temp == in_arr[in_indx])
		{
			/* We found at least one element same so mark flag as true. */
			found = true;

			/* Print the element of inner array. */
			printf(" %d", temp);

			/* Increment the inner array index. */
			in_indx++;
		}

		/*
		 * If found is marked as true, it means we have to print all the temp
		 * elements of out array also.
		 */
		if (found)
		{
			while (out_indx < out_len && temp == out_arr[out_indx])
			{
				/* Print the our_array element.*/
				printf(" %d", temp);

				/* Increment the count of out array index. */
				out_indx++;
			}
		}
		/*
		 * If we didn't find out_arr and in_arr element as same, so we have to
		 * move into next element.  To decide, which index should be incremented
		 * we have to check value of both the array element and lower value index
		 * will be incremented.
		 */
		else if (out_arr[out_indx] < in_arr[in_indx])
		{
			/*
			 * Here, value of out_arr is lower than inner so increment the
			 * out_arr index by 1.
			 */
			out_indx++;
		}
		else
		{
			/* Increment the index of in_arr. */
			in_indx;
		}
	}

	printf("\n");

	return 0;
}
