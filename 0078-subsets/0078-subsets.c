#include <stdlib.h>

void generateSubsets(
    int* nums,
    int numsSize,
    int index,
    int* subset,
    int size,
    int** result,
    int* returnSize,
    int* columnSizes)
{
    // Base case
    if(index == numsSize)
    {
        result[*returnSize] = (int*)malloc(size * sizeof(int));

        for(int i = 0; i < size; i++)
        {
            result[*returnSize][i] = subset[i];  //Each result[i] points to a dynamically allocated array holding one subset.
        }

        columnSizes[*returnSize] = size;
        (*returnSize)++;

        return;
    }

    // Include current element
    subset[size] = nums[index];
    generateSubsets(nums, numsSize, index + 1,
                    subset, size + 1,
                    result, returnSize, columnSizes);

    // Exclude current element
    generateSubsets(nums, numsSize, index + 1,
                    subset, size,
                    result, returnSize, columnSizes);
}

int** subsets(int* nums, int numsSize, //MAIN FUNCTION 
              int* returnSize,
              int** returnColumnSizes)
{
    int totalSubsets = 1 << numsSize;

    int** result = (int**)malloc(totalSubsets * sizeof(int*));

    *returnColumnSizes =
        (int*)malloc(totalSubsets * sizeof(int));

    int* subset = (int*)malloc(numsSize * sizeof(int));

    *returnSize = 0;

    generateSubsets(nums,
                    numsSize,
                    0,
                    subset,
                    0,
                    result,
                    returnSize,
                    *returnColumnSizes);

    free(subset);

    return result;
}