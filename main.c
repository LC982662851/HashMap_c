#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <stdlib.h>
#include "myHashMap.h"


//int hashcode(char * k,HashMap hashMap);
//
////Equal
//int Equal(char* k1,char* k2);
//
int main() {

    //创建
    HashMap*  hm= create_MyHashMap(hashcode,Equal);
    val_list* v1= create_list(2);
    v1->value= (char *) 1;
    val_list* v2= (val_list*) malloc(sizeof (val_list));
    v1->next=v2;v2->value= (char *) 100;

    char*  k1= (char *) 111;
    char* v= (char *) v1;

    put(hm,k1,v);
    search(hm,k1);
    int res= remove_Node(hm,k1,v);


    printf("%d",res);
    return 0;
}
//
//typedef struct list{
//   char * data;
//   struct list* next;
//}List;
////
////typedef struct entry{
////    char * key;
////    void * list_head;
////    struct entry* next;
////}Entry;
//
//typedef struct{
//     char * key;  //键
//     void * val_list_head;//值
//}DataType; //对基本数据类型进行封装，类似泛型
//typedef struct{
//    DataType data;
//    struct HashNode *next;  //key冲突时，通过next指针进行连接
//}HashNode;
//typedef struct{
//    int size;
//    HashNode *table;
//}HashMap,*hashmap;
//
//HashMap* CreatrHashMap(int *nums,int size){
//    HashMap *hashmap=(HashMap*)malloc(sizeof (HashMap));
//    //hash表的装填因子  table的长度为给定数组长度的两倍
//    hashmap->size=2*size;
//
//    hashmap->table=(HashNode*)malloc(sizeof(HashNode) * hashmap->size);
//    //初始化
//    int j=0;
//    for(j=0;j<hashmap->size;j++){
//        hashmap->table[j].data.val_list_head=INT_MIN;
//        hashmap->table[j].next=NULL;
//    }
//
//    int i=0;
//    while(i<size){
//        int pos=abs(nums[i])%hashmap->size;
//        if(hashmap->table[pos].data.val_list_head==INT_MIN){
//            hashmap->table[pos]
//        }
//    }
//
//}
