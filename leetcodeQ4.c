//leetcode question 4
//problem 486. Predict the Winner

#define MAX(x,y) (x>y?x:y)

//dp[x][y] = array from x to y, diff of the 1st player and 2nd player.
int helper(int head, int tail, int* nums, int numsSize, int** dp){
    if(head < 0 || tail >= numsSize || head > tail){
        return 0;
    }
    else if(head == tail){
        dp[head][tail] = nums[head];
        return dp[head][tail];
    }
    else if(dp[head][tail] != -1){
        return dp[head][tail];
    }
    int c1 = nums[head] - helper(head+1,tail,nums,numsSize,dp);
    int c2 = nums[tail] - helper(head,tail-1,nums,numsSize,dp);
    dp[head][tail] = MAX(c1,c2);
    return dp[head][tail];
}

bool PredictTheWinner(int* nums, int numsSize){
    int** dp = (int**)malloc(sizeof(int*) * numsSize);
    for(int i = 0;i<numsSize;i++){
        int* temp = (int*)malloc(sizeof(int) * numsSize);
        for(int j = 0;j<numsSize;j++){
            temp[j] = -1;
        }
        dp[i] = temp;
    }
    int p1win = helper(0,numsSize-1,nums,numsSize,dp);
    return p1win >= 0;
}