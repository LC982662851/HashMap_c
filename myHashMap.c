//
// Created by liangchen on 2022/1/2.
//

#include "myHashMap.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

HashMap * create_MyHashMap(int (*hash)(char *key),int (*equal)(char *k1,char *k2)){
    HashMap *hashMap=(HashMap*) malloc(sizeof(HashMap));
    hashMap->size=DEFAULT_INITIAL_CAPACITY;
    hashMap->loadFactor=DEFAULT_LOAD_FACTOR;
    hashMap->threshold=(int)(hashMap->size*hashMap->loadFactor);
    hashMap->table=(HashNode*) malloc(sizeof(HashNode)*hashMap->size);
    hashMap->hash= (int (*)(char *, void *)) hashcode;
    hashMap->equal=Equal;

    // 初始化
    int j=0;
    for(j=0;j<hashMap->size;j++){
       //hashMap->table[j].data.val_list_head=0;
        hashMap->table[j].next=NULL;
    }
}


//hashcode
int hashcode(char * k,HashMap hashMap){
    return (intptr_t)k & hashMap.size - 1;
}

//Equal
int Equal(char* k1,char* k2){
    if(*k1==*k2)
        return 1;
    else
        return 0;
}



//将多个v组成一条链表
val_list * create_list(int d){
    val_list* valList= malloc(sizeof (valList)*d);
    return  valList;
}

//对每个节点赋值



//增
void put(HashMap hashMap,char * k
         ,char * v) {
    int remark=0;
    int index = hashcode(k, hashMap);
    if (hashMap.table[index].data.key == NULL) {
        hashMap.table[index].data.key = k;
        hashMap.table[index].data.val_list_head = v;
    } else {
        int result1 = Equal(hashMap.table[index].data.key, k);
        //是同一个值，没必要继续
        if (result1 == 1) {
            hashMap.table[index].data.key = k;
        } else {
//            if (hashMap.table[index].next == NULL) {
//                HashNode *node = (HashNode *) malloc(sizeof(HashNode));
//                node->data.key = k;
//                node->data.val_list_head = v;
//                hashMap.table[index].next = node;
//            } else {
            HashNode *node = (HashNode *) malloc(sizeof(HashNode));
            node = &(hashMap.table[index]);
            while (node->next != NULL) {
                if (Equal(node->data.key, k)) {
                    node->data.key = k;
                    remark = 1;
                    break;
                } else {
                    node = node->next;
                }
            }
                while (!remark) {
                    HashNode *node2 = (HashNode *) malloc(sizeof(HashNode));
                    node2 = node->next;
                    node2->data.key = k;
                    node2->data.val_list_head = v;
                    node2->next = NULL;
                }
        }
    }
}

//删
int  remove_Node(HashMap hashMap,char *k,char* v){
    int index=hashcode(k,hashMap);
    if(index>hashMap.size||index<0)
    {
        return 0;
        printf("查找不到索引\n");
    }
    if(hashMap.table[index].data.key==k){
        //是链表中的首位
        hashMap.table[index].data.key==NULL;
        hashMap.table[index].data.val_list_head=NULL;
    }
    else{
        HashMap*  hm = &hashMap.table[index].next;
        while(hm!=NULL){
            if(hm->table->data.key==k)
            {
                HashMap* hmtmp=hm->table->next;
                hm->table->next=hmtmp->table->next;
                free(hmtmp);
                break;
            }
            else
               hm = hm->table->next;
        }
        if(hm==NULL)
        {
            printf("查不到索引\n");
            return 0;
        }
    }
    return 1;
}


