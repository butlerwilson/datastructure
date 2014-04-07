/*
 * =========================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  Implement the list functions.
 *
 *        Version:  1.0
 *        Created:  04/07/2014 06:45:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Youngcy (), youngcy.youngcy@gmail.com
 *   Organization:  
 *
 * =========================================================================
 */

#include "types.h"


#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)
/* The first time I add the data into the structure, badly I was wrong. Here
 * we'd better use abstract data type. So it has good externtional
 *  performance. This is really programming.
 */

static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

/* Add the new entry 'new' between next and prev. */
static inline void _list_add(struct list_head *new,
			     struct list_head *next,
			     struct list_head *prev)
{
	new->next = next;
	next->prev = new;
	prev->next = new;
	new->prev = prev;
}

/* Insert the entry front in head， we call it head interpolation*/
static inline void list_add(struct list_head *new, struct list_head *head)
{
	_list_add(new, head, head->prev);
}

/* Insert the entry behind the head, we call it tail interpolation*/
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	_list_add(new, head->prev, head);
}

/* Delete a entry between next and prev.*/
static inline void _list_del(struct list_head *prev, struct list_head *next)
{
	prev->next = next;
	next->prev = prev;
}

/* Delete a entry from list.*/
static inline void _list_del_entry(struct list_head *head)
{
	_list_del(head->prev, head->next);
}

/* Delete the entry from list */
static inline void list_del(struct list_head *entry)
{
	_list_del(entry->prev, entry->next);
	entry->prev = NULL;
	entry->next = NULL;
}

/* Test the list is empty.*/
static inline int list_empty(struct list_head *head)
{
	return head->next == head;
}

static inline void list_replace(struct list_head *old, struct list_head *new)
{
	new->next = old->next;
	new->next->prev = new;
	old->prev->next = new;
	new->prev = old->prev;
}

/* Move the list into the head's tail.*/
static inline void list_move_tail(struct list_head *list, struct list_head *head)
{
	_list_del_entry(list);
	list_add_tail(list, head);
}

static inline int list_is_last(struct list_head *list, struct list_head *head)
{
	return list->next == head;
}

/* Iterate over a list */
#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)
