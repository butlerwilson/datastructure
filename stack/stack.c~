#define ELENUM 100
#define ELEMTYPE int

typedef struct liner_stack {
	ELEMTYPE elem*;
	int top;
} liner_stack;

void init_liner_stack(liner_stack *lstack)
{
	lstack->elem = (ELEMTYPE*)malloc(sizeof(ELEMTYPE) * ELEMNUM);
	lstack->top = -1;
}

void destroy_liner_stack(liner_stack *lstack)
{
	free(lstack->elem);
	lstack_>top = -1;
}

int push_liner_stack(liner_stack *lstack, ELEMTYPE *element)
{
	if (lstack->top + 1 >= ELEMNUM) {
		fprintf("The stack overflow...\n");
		return 1;
	}

	lstack->top += 1;
	lstack->elem[lstack->top] = *element;

	return 0;
}

int pop_liner_stack(liner_stack *lstack, ELEMTYPE *element)
{
	if (lstack->top < 0) {
		fprintf(stderr, "The stack is empty, no element to pop...\n");
		return 1;
	}

	*element = lstack->elem[lstack->top];
	lstack->top -= 1;

	return 0;
}

int get_top_element_liner_stack(liner_stack *lstack, ELEMTYPE *element)
{
	if (lstack->top < 0) {
		fprintf(stderr, "Empty stack, can't get the top element...\n");
		return 1;
	}

	*element = lstack->elem[lstack->top];

	return 0;
}

int is_liner_stack_full(liner_stack *lstack)
{
	if (lstack->top >= ELEMTYPE)
		return 0;

	return 1;
}

int is_liner_stack_empty(liner_stack *lstack)
{
	if (lstack->top < 0)
		return 0;

	return 1;
}
