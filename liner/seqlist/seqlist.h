#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdlib.h>

void init_seqence_list(seqence_list *seqlist, int size);
void destroy_seqence_list(seqence_list *seqlist);
int get_seqence_list_length(seqence_list *seqlist);
ELEMTYPE *get_seqence_list_value(seqence_list *seqlist, int index);
int insert_elem_into_seqence_list(seqence_list *seqlist, int index, ELEMTYPE *element);
int delete_ielem_from_seqence_list(seqence_list *seqlist, int index);
int delete_velem_from_seqence_list(seqence_list *seqlist, ELEMTYPE element);
void clear_seqence_list(seqence_list *seqlist);

#endif
