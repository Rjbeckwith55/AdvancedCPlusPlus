// FILE: nodeTemplateToolkit.h
// IMPLEMENTS: The functions of the nodeTemplate template class and the
// linked list toolkit (see nodeTemplate.h for documentation).
//
// NOTE:
//   Since nodeTemplate is a template class, this file is included in nodeTemplate.h.
//   Therefore, we should not put any using directives in this file.
//
// INVARIANT for the nodeTemplate class:
//   The data of a nodeTemplate is stored in data_field, and the link in link_field.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t

template <class Item>
void list_clear(nodeTemplate<Item>*& head_ptr) {
	while (head_ptr != nullptr)
		list_head_remove(head_ptr);
}

template <class Item>
void list_copy(
	const nodeTemplate<Item>* source_ptr,
	nodeTemplate<Item>*& head_ptr,
	nodeTemplate<Item>*& tail_ptr
)
// Library facilities used: cstdlib
{
	head_ptr = nullptr;
	tail_ptr = nullptr;

	// Handle the case of the empty list
	if (source_ptr == nullptr)
		return;

	// Make the head nodeTemplate for the newly created list, and put data in it
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;

	// Copy rest of the nodeTemplates one at a time, adding at the tail of new list
	source_ptr = source_ptr->link();
	while (source_ptr != nullptr)
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->link();
		source_ptr = source_ptr->link();
	}
}

template <class Item>
void list_head_insert(nodeTemplate<Item>*& head_ptr, const Item& entry) {
	head_ptr = new nodeTemplate<Item>(entry, head_ptr);
}

template <class Item>
void list_head_remove(nodeTemplate<Item>*& head_ptr) {
	nodeTemplate<Item> *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link();
	delete remove_ptr;
}

template <class Item>
void list_insert(nodeTemplate<Item>* previous_ptr, const Item& entry) {
	nodeTemplate<Item> *insert_ptr;

	insert_ptr = new nodeTemplate<Item>(entry, previous_ptr->link());
	previous_ptr->set_link(insert_ptr);
}

template <class Item>
std::size_t list_length(const nodeTemplate<Item>* head_ptr) {
	const nodeTemplate<Item> *cursor;
	std::size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
		++answer;

	return answer;
}

template <class nodeTemplatePtr, class SizeType>
nodeTemplatePtr list_locate(nodeTemplatePtr head_ptr, SizeType position) {
	nodeTemplatePtr cursor;
	SizeType i;
	// ensure valid position
	assert(0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != nullptr); ++i)
		cursor = cursor->link();
	return cursor;
}

template <class Item>
void list_remove(nodeTemplate<Item>* previous_ptr) {
	nodeTemplate<Item> *remove_ptr;

	remove_ptr = previous_ptr->link();
	previous_ptr->set_link(remove_ptr->link());
	delete remove_ptr;
}

template <class nodeTemplatePtr, class Item>
nodeTemplatePtr list_search(nodeTemplatePtr head_ptr, const Item& target) {
	nodeTemplatePtr cursor;

	for (cursor = head_ptr; cursor != nullptr; cursor = cursor->link())
		if (target == cursor->data())
			return cursor;
	return nullptr;
}

