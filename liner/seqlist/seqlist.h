#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdlib.h>

//init the sequence list
void init_seqence_list(seqence_list *seqlist, int size);

//destroy sequence list
void destroy_seqence_list(seqence_list *seqlist);

//get the length of sequence list
int get_seqence_list_length(seqence_list *seqlist);

//get the value of the sequence list
ELEMTYPE *get_seqence_list_value(seqence_list *seqlist, int index);

//insert an element into the list
int insert_elem_into_seqence_list(seqence_list *seqlist, int index, ELEMTYPE *element);

//delete an element from the sequence list in the index
int delete_ielem_from_seqence_list(seqence_list *seqlist, int index);

//delete an element from the sequence list base the value
int delete_velem_from_seqence_list(seqence_list *seqlist, ELEMTYPE element);

//clear the sequence list, do not delete the space
void clear_seqence_list(seqence_list *seqlist);

#endif
