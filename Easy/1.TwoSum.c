/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stddef.h>
#include "uthash.h"

typedef struct{
    int key;
    int value;

    UT_hash_handle hh; // Makes this structure hashable
}hash_table;

hash_table *hash=NULL, *elem, *tmp;
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = calloc((*returnSize = 2), sizeof(int)); //(size_t nitems, size_t size)
    
    for(int i=0; i<numsSize; i++){
        int temp = target - nums[i];
        HASH_FIND_INT(hash, &temp, elem); //(從哪找, &key值, 找到的hash內容)
        if(elem != NULL){
            res[0] = elem->value;
            res[1] = i;
            break;
        }else{
            elem = malloc(sizeof(hash_table));
            elem->key = nums[i];
            elem->value = i;
            HASH_ADD_INT(hash, key, elem); //(放進哪, key欄位名稱, 要放的內容)
        }
    }
    
        //Free up the hash table 
        HASH_ITER(hh, hash, elem, tmp) {
            HASH_DEL(hash, elem); 
            free(elem); 
        }


        return res;
}