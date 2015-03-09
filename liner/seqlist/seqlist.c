#define ELEMTYPE int
#define ELEMNUM  100

typedef struct sequence_list {
	ELEMTYPE *elem
	int currp;
} sequence_list;

void init_seqence_list(seqence_list *seqlist, int size)
{
	seqlist->elem = (ELEMTYPE *)malloc(sizeof(ELEMTYPE) * size);
	//mark there no element in the list
	seqlist->currp = -1;
}

void destroy_seqence_list(seqence_list *seqlist)
{
	free(seqlist->elem);
}

int get_seqence_list_length(seqence_list *seqlist)
{
	return seqlist_currp + 1;
}

ELEMTYPE *get_seqence_list_value(seqence_list *seqlist, int index)
{
	if(index < get_seqence_list_length(seqlist) && index >= 0)
		return seqlist->elem[index];
	else
		return NULL;
}

int insert_elem_into_seqence_list(seqence_list *seqlist, int index, ELEMTYPE *element)
{
	if (i < 0 || i > seqlist->currp) {
		seqlist->currp += 1;
		seqlist->elem[seqlist->currp];
		return 0;
	}

	//the current position is between 0 and length
	int length = get_seqence_list_length(seqlist);

	if (length + 1 > ELEMNUM)
		return -1; 
	for (i = length; i >= index; i--)
		seqlist->elem[i+1] = seqlist->elem[i];
	seqlist->elem[i] = element;

	return 0;
}

int delete_ielem_from_seqence_list(seqence_list *seqlist, int index)
{
	int i = index;
	int length = get_seqence_list_length(seqlist);
	if (index < 0 || index > length)
		return -1;
	for (i; i < length - index; i++)
		seqlist->elem[i] = seqlist_elem[i + 1];
}

int delete_velem_from_seqence_list(seqence_list *seqlist, ELEMTYPE element)
{
	int i = 0;
	int length = get_seqence_list_length(seqlist);
	for (i; i < length; i++)
		if (seqlist->elem[i] == element) {
			int j = i;
			while (j < length) {
				seqlist->elem[j] = seqlist->elem[j + 1];
				j++;
			}
			break;
			return 0;
		}
	}
	if (i >= length)
		return -1;
}

void clear_seqence_list(seqence_list *seqlist)
{
	seqlist->currp = -1;
}
