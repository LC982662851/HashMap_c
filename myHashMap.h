//
// Created by liangchen on 2022/1/2.
//

#ifndef HASHMAP_C_MYHASHMAP_H
#define HASHMAP_C_MYHASHMAP_H
#define DEFAULT_INITIAL_CAPACITY 16
#define  DEFAULT_LOAD_FACTOR 0.75f




typedef struct{
    char * key;  //键
    void * val_list_head;//值
}DataType;
typedef struct{
    DataType data;
    struct HashNode *next;  //key冲突时，通过next指针进行连接
}HashNode;
//一个key对应多个v，用链表来存储多个v
typedef struct val{
    char * value;
    struct val * next;
}val_list;
typedef struct HashMap
{
    int size;
    int initialCapacity;// 初始容量
    float loadFactor; // 加载因子
    int threshold; ////扩容临界点
    int  (*hash)(char * key,void *);
    int  (*equal)(char *k1,char *k2);
    HashNode *table;
}HashMap;

//int  (*hash)(char * key,HashMap hashMap);
//int  (*equal)(char *k1,char *k2);

int hashcode(char * key,HashMap* hashMap);
int Equal(char *k1,char *k2);

//创建hashmap
HashMap*  create_MyHashMap(int (*hash)(char *key),int (*equal)(char *k1,char *k2));
//int  (*equal)(char *k1,char *k2));

//增
void put(HashMap* hashMap,char* const key,void * const val);

//创建value链表
val_list * create_list(int d);

//删
int  remove_Node(HashMap* hashMap,char *k,void * v);

//查
void * search(HashMap* hashMap,char* const k);

//调节hashmap大小size
HashMap *rebuildMyHashMap(HashMap *hashMap);

#endif // HASHMAP_C_MYHASHMAP_H