#include "LinkedList.h"
#include "util.h"

void LinkedListUt();
void LinkedListUt_Append_Get();
void LinkedListUt_InsertBefore();
void LinkedListUt_InsertAfter();
void LinkedListUt_Delete();

void InitLinkedList(LinkedList*);
void LinkedListAppend(LinkedList* this, void* value);
void LinkedListDelete(LinkedList*, LinkedListNode*);
void* LinkedListGet(LinkedList* this, int index);

LinkedListNode* NewLinkedListNode(LinkedList* list, void* value);
void NodeInsertAfter(LinkedListNode* this, void* value);    
void NodeInsertBefore(LinkedListNode* this, void* value);

void LinkedListUt() {
    LinkedListUt_Append_Get();
    LinkedListUt_InsertBefore();
    LinkedListUt_InsertAfter();
    LinkedListUt_Delete();
}

void LinkedListUt_Append_Get() {
    LinkedList list;
    InitLinkedList(&list);
    list.Append(&list, 1);
    list.Append(&list, 2);
    list.Append(&list, 3);

    check(list.Get(&list, 0) == 1);
    check(list.Get(&list, 1) == 2);
    check(list.Get(&list, 2) == 3);
    check(list.size == 3);
}

void LinkedListUt_Delete() {
    LinkedList list;
    InitLinkedList(&list);
    list.Append(&list, 1);
    list.Append(&list, 2);
    list.Append(&list, 3);

    list.Delete(&list, list.head->next);
    check(list.head->next->value == 3);
    check(list.head->next->prev->value == 1);
    check(list.size == 2);

    list.Delete(&list, list.head->next);
    check(list.tail == list.head);
    check(list.head->next == NULL);

    list.Delete(&list, list.head);
    check(list.tail == list.head);
    check(list.head == NULL);
    check(list.size == 0);    
}

void LinkedListUt_InsertBefore() {
    LinkedList listS;
    LinkedList* list = &listS;
    InitLinkedList(list);

    list->Append(list, 1);

    list->head->InsertBefore(list->head, 0);
    check(list->size == 2);
    check(list->head->value == 0);
    check(list->head->next->value == 1);

    LinkedListNode* second = list->head->next;
    second->InsertBefore(second, -1);
    check(list->head->next->value == -1);
}

void LinkedListUt_InsertAfter() {
    LinkedList listS;
    LinkedList* list = &listS;
    InitLinkedList(list);
    list->Append(list, 1);

    list->head->InsertAfter(list->head, 2);
    check(list->size == 2);
    check(list->tail->value == 2);
    check(list->head->next->value == 2);

    LinkedListNode* second = list->head->next;
    second->InsertAfter(second, 3);
    check(second->next->value == 3);
}

LinkedListNode* NewLinkedListNode(LinkedList* list, void* value) {
    LinkedListNode* n = (LinkedListNode*)calloc(1, sizeof(LinkedListNode));
    n->InsertAfter = NodeInsertAfter;
    n->InsertBefore = NodeInsertBefore;
    n->value = value;
    n->_list = list;

    return n;
}

void NodeInsertAfter(LinkedListNode* this, void* value) {
    LinkedListNode* n = NewLinkedListNode(this->_list, value);

    if (this == this->_list->tail) {
        this->next = n;
        n->prev = this;
        this->_list->tail = n;
    } else {
        n->next = this->next;
        n->prev = this;
        this->next->prev = n;
        this->next = n;
    }

    this->_list->size++;
}
    
void NodeInsertBefore(LinkedListNode* this, void* value) {
    LinkedListNode* n = NewLinkedListNode(this->_list, value);

    if (this == this->_list->head) {
        this->prev = n;
        n->next = this;
        this->_list->head = n;
    } else {
        n->prev = this->next;
        n->next = this;
        this->prev->next = n;
        this->prev = n;
    }

    this->_list->size++;
}

void LinkedListDelete(LinkedList* list, LinkedListNode* n) {
    if (n == list->head && list->size == 1) {
        list->head = list->tail = NULL;      
    } else if (n == list->head) {
        n->next->prev = NULL;
        list->head = n->next;          
    } else if (n == list->tail) {
        n->prev->next = NULL;
        list->tail = n->prev;          
    } else {
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }

    list->size--;
    
    memset(n, 0, sizeof(LinkedListNode));
    free(n);
}

void LinkedListAppend(LinkedList* this, void* value) {
    LinkedListNode* n = NewLinkedListNode(this, value);

    if (this->head == NULL) {
        this->head = this->tail = n;
    } else {
        this->tail->next = n;
        n->prev = this->tail;
        this->tail = n;
    }

    n->InsertAfter = NodeInsertAfter;
    n->InsertBefore = NodeInsertBefore;

    this->size++;
}

void* LinkedListGet(LinkedList* this, int index) {
    if (this->size <= index) {
        return NULL;
    }

    LinkedListNode* n = this->head;
    for (int i = 0; i < index; i++) {
        n = n->next;
    }

    return n->value;
}


void InitLinkedList(LinkedList* l) {
    memset(l, 0, sizeof(LinkedList));
    l->Append = LinkedListAppend;
    l->Get = LinkedListGet;
    l->Delete = LinkedListDelete;
}