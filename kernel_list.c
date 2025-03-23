#include"kernel_list.h"

static LIST_HEAD(list);

node_t *list_create(datatype x)
{
    // 
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL)
    {
        printf("%s:%dmalloc fail\n", __FILE__, __LINE__);
        return NULL;
    }

    // 初始化数据
    node->data = x;

    return node;
}

void list_push_front(datatype x)
{
    node_t *node = list_create(x);

    // 添加到链表里
    list_add(&node->list, &list);
}

void list_push_back(datatype x)
{
    node_t *node = list_create(x);

    // 添加到链表里
    list_add_tail(&node->list, &list);
}

void list_pop_front(void)
{
    list_del(list.next);
}

void list_pop_back(void)
{
    list_del(list.prev);
}

bool list_is_empty(void)
{
    return list_empty(&list);
}

void list_erase(void)
{
    node_t *node = NULL;
    struct list_head *pos;
    struct list_head *n;

    list_for_each_safe(pos, n, &list)
    {
        node = list_entry(pos, node_t, list);
        list_del(pos);
        free(node);
    }
    
}

node_t *search_node(datatype x)
{
    node_t *node = NULL;
    struct list_head *pos = NULL;
    // 遍历链表
    list_for_each(pos, &list)
    {
        // 通过小结构体找到大结构体
        node = list_entry(pos, node_t, list);
        // 返回对应的节点
        if (node->data == x)
        {
            return node;
        }
    }
    
    return NULL;
}

void list_print(void)
{
    node_t *node = NULL;
    struct list_head *pos = NULL;

    list_for_each(pos, &list)
    {
        node = list_entry(pos, node_t, list);
        printf("%d\t", node->data);
    }
    printf("\n");
}
