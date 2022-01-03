#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

typedef struct list{
   char * data;
   struct list* next;
}List;
//
//typedef struct entry{
//    char * key;
//    void * list_head;
//    struct entry* next;
//}Entry;

typedef struct{
     char * key;  //键
     void * val_list_head;//值
}DataType; //对基本数据类型进行封装，类似泛型
typedef struct{
    DataType data;
    struct HashNode *next;  //key冲突时，通过next指针进行连接
}HashNode;
typedef struct{
    int size;
    HashNode *table;
}HashMap,*hashmap;

HashMap* CreatrHashMap(int *nums,int size){
    HashMap *hashmap=(HashMap*)malloc(sizeof (HashMap));
    //hash表的装填因子  table的长度为给定数组长度的两倍
    hashmap->size=2*size;

    hashmap->table=(HashNode*)malloc(sizeof(HashNode) * hashmap->size);
    //初始化
    int j=0;
    for(j=0;j<hashmap->size;j++){
        hashmap->table[j].data.val_list_head=INT_MIN;
        hashmap->table[j].next=NULL;
    }

    int i=0;
    while(i<size){
        int pos=abs(nums[i])%hashmap->size;
        if(hashmap->table[pos].data.val_list_head==INT_MIN){
            hashmap->table[pos]
        }
    }

}
