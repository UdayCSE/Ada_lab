//question: problem 398. Random Pick Index
/* use rand() will cause TLE */
typedef struct {
    int* arr;
    int size;
} Solution;

static unsigned long int seed = 1;
int my_rand(void) 
{ 
      seed = seed * 1103515245 + 12345; 
      return (unsigned int)(seed/65536) % 32768; 
} 

Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)calloc(1, sizeof(Solution));
    obj->arr = nums;
    obj->size = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int idx = -1, cnt = 0;
    
    for(int i = 0; i < obj->size; i++){
        if(obj->arr[i] != target)
            continue;
        
        {
            cnt++;
            if(cnt == 1 || (my_rand() % cnt) == 0)
                idx = i;
        }
    }
    return idx;
}

void solutionFree(Solution* obj) {
    free(obj);
}