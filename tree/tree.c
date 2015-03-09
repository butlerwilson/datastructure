/*
		A		|   |		|   |
	       / \		|   |		|   |
	      B   C		| D |	pop(D)	|   |
	     / \   \		| B |	pop(B)	|   |
	    D   E   F		|_A_|		|_A_|

In order none recusion visit the tree using ths stack structure.

If the pointor goto the node whose right child is NULL(that is D node),
then we should pop it's parent node(here is B node), or it will be a dead
loop. Note this is a must!

*/
int nonR_in_order_visit(struct TNode *root)
{
	struct TNode node;
	struct TNode *p = root;

	while (p || !is_stack_empty()) {
		if (!is_stack_full() && p) {
			push(&S, p);
			p = p->left;
		} else if (!is_stack_empty()) {
			pop(&S, &node);
			visit(node);
			p = node.right;
		} else
			return 1;
	}

	return 0;
}


/*
		A		|   |		|   |		|   |
	       / \		|   |		|   |		|   |
	      B   C		| D |	pop(D)	| E |	pop(E)	|   |
	     / \   \		| B |	push(E)	| B |	pop(B)	|   |
	    D   E   F		|_A_|		|_A_|		|_A_|

Vist root after visited left child and right child. <None recusion visit
the tree using stack>

Analysis: Basic thought is visit left child first, then visit right child,
visit root finnally. But here is a serious problem. If now visit the E
node, and then we will visit B node. Now problem ocurred, when we pop B
node? Now the B node is not NULL, it should push it's left child and right
child. But we already visited B node's left child and right child. So how
to solve it? The easy and directly method is marking it's right child is
alread visited. That's the key to solve those problem.
*/
int nonR_end_order_visit(struct TNode *root)
{
	struct TNode node;
	struct TNode *p = root;
	struct TNode *q = NULL;

	while (p || !is_stack_empty()) {
		if (p && !is_stack_full()) {
			push(&S, p);
			p = p->left;
		} else if (!is_stack_empty()) {
			gettop(&S, p);
			p = p->right;
			if (p == NULL || q == p) {
				pop(&S, &node);
				visit(node);
				q = &node;
				p = NULL;
			}
		} else
			return 1;
	}

	return 0;
}

/*

Liner a tree means we can visit the identified node's previous node and
behind node, also we can visit the tree like a liner structure.

		A
	       / \
	      B   C
	     / \   \
    prev--->D   E   F--->

Here we can visit the D node's previous node and behind node. Using this
structure, if we know D, we can directly visit D node. This is why use it.

Also we want to visit the tree using a liner structure, the visit order like
this:
	D  B  E  A  C  F. Here we don't use recusion thoughts.
We found that every child node has two empty area, we use them to store
thire previous node and the behind node. After this step, we will got a
liner structure. This time if we visit it, we don't use recusion and stack
any more. We only use a loop to visit this liner structire.

We must distinguish the left node is parent node or previous node, here we
use a flag to record who they are.

	struct TNode {
		TYPE data;
		struct TNode *left;
		struct TNode *right;
		char lTag;
		char rTag;
	};
We define the flag as char type to save memory space. And try to make the
memory align. Moreover, we define lTag = 0 means that left child is parent.
And we define lTag = 1 means that left child is previous node. As same as
lTag, the rTag has the similiar meaning.
*/
/* liner the binary tree
   root: the tree's root pointor
   prev: we define the prev is NULL as beginning
*/
int liner_in_order_create(struct TNode *root, struct TNode *prev)
{
	struct TNode *p = root;

	if (p) {
		p->lTag = '0'; p->rTag = '0';
		liner_in_order_create(p->left, prev);
		if (p->left == NULL) {
			p->left = prev;
			p->lTag = 1;
		}
		if (prev != NULL && prev->right == NULL) {
			prev->right = p;
			prev->rTag = 1;
		}
		prev = p;
		liner_in_order_create(p->right, prev);
	}

	return 0;
}

/*After liner the binary tree, then we visit it. But we found if the tree
structure like this:    A
		      /   \
		     B     E
			  /
			 F 
How we visit it? We see that the A node's rTag is '0', and the next visit
node is F. If the binary tree's right child only have a left child node,
finding the next node is a great cost.

It's great convience is that visiting the previous or behind is quick;
*/
int nonR_in_order_visit(struct TNode *head)
{
	struct TNode *prev = NULL;
	struct TNode *point = head;

	while (point) {
		if (point->lTag == '0' && point != prev)
			point = point->left;
		else {
			visit(point);
			prev = point;
			point = point->right;
		}
	}
}
