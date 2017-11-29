// FILE: hashNode.h
// PROVIDES: A toolkit of ten template functions for manipulating linked lists.
// Each hashNode of the list contains a piece of data and a pointer to the next
// hashNode, as shown in this template struct:
// 
//     template <class Item>        Item may be any of the C++ built-in types
//     struct hashNode                  (int, char, etc.), or a class with a default
//     {                            constructor, an assignment operator,
//         Item data;               and a test for equality (x == y).
//         hashNode *link;
//     };
//
// FUNCTIONS in the linked list toolkit:
//   template <class Item>
//   size_t list_length(hashNode<Item>* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list. The list itself is unaltered.
//
//   template <class Item>
//   void list_head_insert(hashNode<Item>*& head_ptr, const Item& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   template <class Item>
//   void list_insert(hashNode<Item>* previous_ptr, const Item& entry) 
//     Precondition: previous_ptr points to a hashNode in a linked list.
//     Postcondition: A new hashNode containing the given entry has been added
//     after the hashNode that previous_ptr points to.
//
//   template <class Item>
//   hashNode<Item>* list_search(hashNode<Item>* head_ptr, const Item& target)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first hashNode containing
//     the specified target in its data member. If there is no such hashNode, the
//     null pointer is returned. The list itself is unaltered.
//
//   template <class Item, class SizeType>
//   hashNode<Item>* list_locate(hashNode<Item>* head_ptr, SizeType position)
//     Precondition: head_ptr is the head pointer of a list, and position > 0.
//     Postcondition: The pointer returned points to the hashNode at the specified
//     position in the list. (The head hashNode is position 1, the next hashNode is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned. The list itself is unaltered.
//
//   template <class Item>
//   void list_head_remove(hashNode<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one hashNode.
//     Postcondition: The head hashNode has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   template <class Item>
//   void list_remove(hashNode<Item>* previous_ptr)
//     Precondition: previous_ptr points to a hashNode in a linked list, and this
//     is not the tail hashNode of the list.
//     Postcondition: The hashNode after previous_ptr has been removed.
//
//   template <class Item>
//   void list_clear(hashNode<Item>*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All hashNodes of the list have been returned to the heap,
//     and the head_ptr is now nullptr.
//
//   template <class Item>
//   void list_copy
//     (hashNode<Item>* source_ptr, hashNode<Item>*& head_ptr, hashNode<Item>*& tail_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that that contains the same items as the list pointed to by
//     source_ptr.
//
//   template <class Item>
//   void list_piece
//     (hashNode<Item>* source_ptr, hashNode<Item>* end_ptr,
//     hashNode<Item>*& head_ptr, hashNode<Item>*& tail_ptr)
//     Precondition: source_ptr and end_ptr are pointers to hashNodes on the same
//     linked list, with the source_ptr hashNode at or before the end_ptr hashNode.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new linked list that contains the items from source_ptr to end_ptr.
//     The original list is unaltered.

#ifndef HASH_NODE_H
#define HASH_NODE_H
#include <cstdlib> // Provides size_t

template <class Item>
struct hashNode
{
	Item data;
	hashNode *link;
};

// FUNCTIONS for the linked list toolkit
template <class Item>
size_t list_length(hashNode<Item>* head_ptr);

template <class Item>
void list_head_insert(hashNode<Item>*& head_ptr, const Item& entry);

template <class Item>
void list_insert(hashNode<Item>* previous_ptr, const Item& entry);

template <class Item>
hashNode<Item>* list_search(hashNode<Item>* head_ptr, const Item& target);

template <class Item, class SizeType>
hashNode<Item>* list_locate(hashNode<Item>* head_ptr, SizeType position);

template <class Item>
void list_head_remove(hashNode<Item>*& head_ptr);

template <class Item>
void list_remove(hashNode<Item>* previous_ptr);

template <class Item>
void list_clear(hashNode<Item>*& head_ptr);

template <class Item>
void list_copy
(hashNode<Item>* source_ptr, hashNode<Item>*& head_ptr, hashNode<Item>*& tail_ptr);

template <class Item>
void list_piece
(hashNode<Item>*  source_ptr, hashNode<Item>*  end_ptr,
	hashNode<Item>*& head_ptr, hashNode<Item>*& tail_ptr);

#include "hashNode_template.h"  // Include the implementation
#endif
