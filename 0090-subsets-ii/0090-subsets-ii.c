#include <stdlib.h>

void sort(int *a, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void dfs(int *a, int n, int st,
         int *cur, int sz,
         int **ans,
         int *rs,
         int *cs)
{
    ans[*rs] = (int*)malloc(sz * sizeof(int));

    for(int i = 0; i < sz; i++)
        ans[*rs][i] = cur[i];

    cs[*rs] = sz;
    (*rs)++;

    for(int i = st; i < n; i++)
    {
        if(i > st && a[i] == a[i - 1])
            continue;

        cur[sz] = a[i];

        dfs(a, n, i + 1,
            cur, sz + 1,
            ans, rs, cs);
    }
}

int** subsetsWithDup(int* nums,
                     int numsSize,
                     int* returnSize,
                     int** returnColumnSizes)
{
    sort(nums, numsSize);

    int mx = 1 << numsSize;

    int **ans = (int**)malloc(mx * sizeof(int*));

    *returnColumnSizes =
        (int*)malloc(mx * sizeof(int));

    int *cur =
        (int*)malloc(numsSize * sizeof(int));

    *returnSize = 0;

    dfs(nums,
        numsSize,
        0,
        cur,
        0,
        ans,
        returnSize,
        *returnColumnSizes);

    free(cur);

    return ans;
}