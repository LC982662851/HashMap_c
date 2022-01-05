//
// Created by liangchen on 2022/1/2.
//

int estimate_num=0;
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
void put(HashMap hashMap,char * const k
         ,char * const v) {
    int remark=0;

    //对factor和capacity进行评估
    if(estimate_num==hashMap.threshold){

    }


    int index = hashcode(k, hashMap);
    if (hashMap.table[index].data.key == NULL) {
        hashMap.table[index].data.key = k;
        hashMap.table[index].data.val_list_head = v;
        //对索引使用率的记录
        estimate_num++;
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
int  remove_Node(HashMap hashMap,char * const k,char* const v){
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

//查
void* search(HashMap hashMap,char* const k){
    int index= hashcode(k,hashMap);
    if(hashMap.table[index].data.key==k)
        return hashMap.table[index].data.val_list_head;

    HashNode *hashNode =&hashMap.table[index].next;
    while(hashNode!=NULL){
        if(hashNode->data.key==k){
            return hashNode->data.val_list_head;
        }
        else
        {
         hashNode=hashNode->next;
        }
    }
    printf("未查到相应的key\n");
    return 0;
}

//改
int modify(HashMap hashMap,char * const k){
    void * result=search(hashMap,k);
    if(result==0){
        printf("未查到改索引，无法修改\n");
    }

    val_list * list = (val_list *)result;
}


//调节hashmap大小size
void rebuildMyHashMap(HashMap hashMap){
    HashMap* hm =(HashMap*) malloc(sizeof(HashMap));
    hm->size=hashMap.size*2;
    hm->loadFactor=DEFAULT_LOAD_FACTOR;
    hm->threshold=(int)(hm->size*hm->loadFactor);
    hm->table=(HashNode*) malloc(sizeof(HashNode)*hm->size);
    hm->hash= (int (*)(char *, void *)) hashcode;
    hm->equal=Equal;
    for(int i=0;i<hashMap.size;i++){
       hm->table[i]=hashMap.table[i];
    }


}
