#include <stdio.h>
#include <stdlib.h>

#define TYPE int

#include "graph.h"

void init_adjacency_matrix(struct adjacency_matrix *adj_matrix)
{
	int i = 0;
	int j = 0;

	for (i; i < MAX_VERTEX; i++) {
		adj_matrix->am_vertex[i].vn_info = -1;
		for (j; j < MAX_VERTEX; j++) {
			adj_matrix->am_matrix[i][j].gn_weight = INFDIGIT;
			adj_matrix->am_matrix[i][j].gn_info = -1;
		}
	}
}

struct locate_index find_adjacency_vertex(struct vertex_node *vertex, TYPE node0, TYPE node1)
{
	int i = 0;
	int cov = 0;
	int row = 0;
	int col = 0;
	struct locate_index index = { -1, -1 , -1 };

	for (i; i < MAX_VERTEX && vertex[i].vn_info != -1; i++) {
		if (vertex[i].vn_info == node0) {
			row = i;
			cov |= 1;
		}
		if (vertex[i].vn_info == node1) {
			col = i;
			cov |= 2;
		}
	}

	if (cov == 0) {		//both not found
		vertex[i].vn_info = node0; index.li_row = i;
		vertex[++i].vn_info = node1; index.li_col = i;
	} else if (cov == 1) {	//node1 not found;
		vertex[i].vn_info = node1; index.li_col = i;
	} else if (cov == 2) {
		vertex[i].vn_info = node0; index.li_row = i;
	} else
		index.li_cov = 1;
		
	return index;
}

int create_adjacency_matrix(struct adjacency_matrix *adj_matrix)
{
	int weight = 0;
	struct vertex_node node0, node1;
	struct locate_index index = { -1, -1, -1 };

	do {
		//input to initalize the adjacency matrix
		index = find_adjacency_vertex(adj_matrix->am_vertex, node0.vn_info, node1.vn_info);
		if (index.li_cov == 1) {
			//edge info will covered
			adj_matrix->am_matrix[index.li_row][index.li_col].gn_weight = weight;
		}
	} while (true);	//loop to input the vertex and matrix

	return 0;
}

void init_adjacency_list(struct adjacency_list *al_list)
{
	int i = 0;

	al_list->al_count = 0;
	for (i; i < MAX_VERTEX; i++) {
		al_list->vertex_array[i].vna_info = -1;
		al_list->vertex_array[i].vna_flags = -1;
		al_list->vertex_array[i].vna_en_head = NULL;
	}
}

struct locate_index find_adjacency_list_vertex(struct adjacency_list *al_list, TYPE node0, TYPE node1)
{
	int i = 0;
	int cov = 0;
	int row = 0;
	int col = 0;
	struct locate_index index = { -1, -1 , -1 };

	for (i; i < MAX_VERTEX && al_list->vertex_array[i].vna_info != -1; i++) {
		if (al_list->vertex_array[i].vna_info == node0) {
			row = i;
			cov |= 1;
		}
		if (al_list->vertex_array[i].vna_info == node1) {
			col = i;
			cov |= 2;
		}
	}

	if (cov == 0) {		//both not found
		al_list->vertex_array[i].vna_info = node0; index.li_row = i;
		al_list->vertex_array[++i].vna_info = node1; index.li_col = i;
	} else if (cov == 1) {	//node1 not found;
		al_list->vertex_array[i].vna_info = node1; index.li_col = i;
	} else if (cov == 2) {
		al_list->vertex_array[i].vna_info = node0; index.li_row = i;
	} else
		index.li_cov = 1;
		
	return index;
}

int create_adjacency_list(struct adjacency_list *adj_list)
{
	int row = -1;
	int col = -1;
	struct locate_index index;
	struct edge_node *new_edge = NULL;

	do {
		printf("Input:[start--end([-1 -1] end)]:");
		scanf("%d %d", &row, &col);
		if (row == -1 || col == -1)
			break;
		adj_list->al_count += 1;
		new_edge = (struct edge_node *)malloc(sizeof(struct edge_node));
		new_edge->en_index = col;
		index = find_adjacency_list_vertex(adj_list, row, col);
		//list head insert method
		new_edge->en_node = adj_list->vertex_array[index.li_row].vna_en_head;
		adj_list->vertex_array[index.li_row].vna_en_head = new_edge;
	} while (true);

	return 0;
}

int breadth_travel_adjacency_list(struct adjacency_list *al_list)
{
	int i = 0;
	int flags = 0;
	struct edge_node *tmp = NULL;

	for (i; i < MAX_VERTEX; i++) {
		tmp = al_list->vertex_array[i].vna_en_head;
		flags = al_list->vertex_array[i].vna_flags;
		if (flags == -1 && al_list->vertex_array[i].vna_info != -1)
			printf("Visit: [%d]\n",al_list->vertex_array[i].vna_info);
		while (tmp) {
			flags = al_list->vertex_array[tmp->en_index].vna_flags;
			if (flags == -1 && al_list->vertex_array[tmp->en_index].vna_info != -1) {
				printf("Visit: [%d]\n",
					al_list->vertex_array[i].vna_info);
				al_list->vertex_array[tmp->en_index].vna_flags = 1;
			}
			tmp = tmp->en_node;
		}
	}

	return 0;
}

int deepth_travel_adjacency_list(struct adjacency_list *al_list)	
{

}

void init_orthogonal_list(struct orthogonal_list *orth_list)
{
	int i = 0;

	for (i; i < MAX_VERTEX; i++) {
		orth_list->ol_vertex[i].vna_info = -1;
		orth_list->ol_vertex[i].vna_ahnode = NULL;
		orth_list->ol_vertex[i].vna_atnode = NULL;
	}
}

struct locate_index find_orthogonal_list_vertex(struct orthogonal_list *ol_list, TYPE node0, TYPE node1)
{
	int i = 0;
	int cov = 0;
	int row = 0;
	int col = 0;
	struct locate_index index = { -1, -1 , -1 };

	for (i; i < MAX_VERTEX && ol_list->ol_vertex[i].vna_info != -1; i++) {
		if (ol_list->ol_vertex[i].vna_info == node0) {
			row = i;
			cov |= 1;
		}
		if (ol_list->ol_vertex[i].vna_info == node1) {
			col = i;
			cov |= 2;
		}
	}

	if (cov == 0) {		//both not found
		ol_list->ol_vertex[i].vna_info = node0; index.li_row = i;
		ol_list->ol_vertex[++i].vna_info = node1; index.li_col = i;
	} else if (cov == 1) {	//node1 not found;
		ol_list->ol_vertex[i].vna_info = node1; index.li_col = i;
	} else if (cov == 2) {
		ol_list->ol_vertex[i].vna_info = node0; index.li_row = i;
	} else
		index.li_cov = 1;
		
	return index;
}

int create_orthogonal_list(struct orthogonal_list *orth_list)
{
	int row = -1;
	int col = -1;
	struct vertex_node node0, node1;
	struct locate_index index = { -1, -1, -1};
	struct arch_node *new_arch = NULL;

	do {
		//input the vertex and weight. eg: A  b  23
		index = find_orthogonal_list_vertex(orth_list, node0.vn_info, node1.vn_info);
		if (index.li_cov == 1) {
			//cover the original data
		}
		row = index.li_row; col = index.li_col;
		new_arch = malloc(sizeof(struct arch_node));
		new_arch->an_atindex = col;
		new_arch->an_ahindex = row;
		new_arch->an_shnext = orth_list->ol_vertex[row].vna_ahnode;
		orth_list->ol_vertex[row].vna_ahnode = new_arch;
		new_arch->an_stnext = orth_list->ol_vertex[col].vna_atnode;
		orth_list->ol_vertex[col].vna_atnode = new_arch;
	} while (true);

	return 0;
}

/*
breadth first search: this is similar with tree's lever search, we search
the node untill the node alread visited. Then we should go next to find
other paths to search. We known that there will no loop back, because the
visited nodes won't visit any more. But we should store the next nodes.
So we should use a data structure to store those nodes. As breadth first
search algorithm, we will find the current node's next nodes, then visit
them. When we visit them, mark them and we should make their next nodes
store. And loop those steps, when loop visit nodes if the node is not visit,
or not visit. But what data structure we use?

== Here we use queue to store nodes.
	       A--------G
	      / \       |
	     /   \      |
	    E     F     |
	     \   /      |
	       B        |
	     /	 \      |
	    /	   \    |
	   /	     \  |
	  H		N
Breadth first search algorithm: If we use this algorithm, thw Visted order
are: A  E  F  G  B  N  H
The queue element changes are:
	  visit A  "find A's next nodes"  inqueue->queue: E F  G
outqueue  visit E  --------------------   inqueue->queue: F G B
outqueue  visit F  "not find"
outqueue  visit G  --------------------   inqueue->queue: B N
outqueue  visit B  "N already in queue, but not visit" inqueue->queue: N H N
outqueue  visit N  "B already visited, not in queue"    queue: H N
outqueue  visit H  "no more to visite"                  queue: N
outqueue  N visited, not visit again. All nodes visited queue:

int breadth_first_search(struct graph_node *head)
{
	struct graph_node next_node;
	struct graph_node *node = NULL;

	init_queue(&queue);
	in_queue(&queue, head);

	while (!is_queue_empty()) {
		out_queue(&queue, &node);
		visit(node);	//mark the flag as visited
		while (next_node = find_graph_next_node(node)) {
			if (not_visited(next_node))
				in_queue(&queue, next_node);
		}
	}

	return 0;
}
*/

/*
deepth first search: this algorithm also similar with tree's deep serch.
The basic thoughts are:
  1.visit current node, if the node has next not visited nodes,
store current node.
  2.loop 1 step untill the current node has no next not visited nodes.
  3.if 2 step end, loop back to last visited node. Loop 1 step unitill
visited all nodes.

This time we must store the nodes which we already visited. The stack is
a good structure to store information because of it's memory function.

==So based on many charactors, here we use stack to store nodes.
	       A--------G
	      / \       |
	     /   \      |
	    E     F     |
	     \   /      |
	       B        |
	     /	 \      |
	    /	   \    |
	   /	     \  |
	  H		N
We use this algorithm to see what the stack sotred?
	pushstack(A)
	visit A "find A's first unvisited node"	push:A E
gettop	visit E "-----------------------------" push:A E B
------	visit B "-----------------------------" push:A E B H
------	visit H "no next node to visit"		pop H:A E B	loop back
------	visited "-----B's---------------------" push:A E B N
------	visit N "-----------------------------" push:A E B N G
------	visit G "no next node to visit"		pop G:A E B N	loop back
------	visited "no next node to visit"		pop N:A E B	loop back
------	visited "-----B's---------------------" push:A E B F
------	visit F "next node A visited, no more"	pop F:A E B	loop back
------	visited "no next node to visit"		pop B:A E	loop back
------	visited "no next node to visit"		pop E:A		loop back
------	visited "no next nodes to visit"	pop A:		loop back
------	visited "no more nodes to visit, end"
The visit order are: A E B H N G F.
This is different from breadth first search.

int deepth_first_search(struct graph_node *head)
{
	struct graph_node node;

	init_stack(&stack);

	while (!is_stack_empty(&stack)) {
		get_stack_top(stack, &node);
		do {
			if (not_visited(node)) {
				visited(node);
				//mark the flag as visited
				push(&stack, &node);
			}
		} while (node = find_graph_next_node(node));
		pop(&stack, &node);
	}

	return 0;
}
*/

/*
Dijkstra search mininum path algorithm: select a mininum edge join to the
visited set, make the current edge's node as a middle node. And then search
the next node, here we must promise that this path's weight is the mininum.
If the node we visited, we don't visit afain. Loop this step, untill the all
nodes we visited.
		   1
		A-----H
	     2/  \   /4
	     /   3\ /
	    B      C
	   3|     / \3
	    |    /7  \
	    G----     K
we use set[] to store visited node, use length[vi] to store A->vi's length,
and we use path[] to store the visit path.

We begin in A node:
add A to visited set
visited(set[]):	not visited:
A 		B C G K H	chose B, join visited set
A B		  C G K H
A->B->C=-  >  A->C=3		length[C]=3; path[C]=1; visit C
A B C		    G K H	chose G, join visited set
A B C G		      K H	

*/

int dijkstra(struct graph_node *begin, int length[], char visited[])
{
	int i = 0;
	int j = 0;
	int min = 0;
	int set[MAX_VERTEX];

	for (i; i < MAX_VERTEX; i++) {
		lenght[i] = begin[i].weight;
		set[i] = 0;
		if (begin[i].weight < INFDIGIT)
			length[i] = x;
		else
			length[i] = -1;
	}

	//select the mininum path from the set
	for (i = 0; i < MAX_VERTEX; i++) {
		min = INFDIGIT;
		for (j = 0; j < MAX_VERTEX; j++) {
			if (set[j] == 0 && length[j] < min) {
				u = j;
				min = length[j];
			}
		}
		set[u] = 1;	//join into visited set
		
		for (j = 0; j < MAX_VERTEX; j++) {
			if (set[j] == 0 &&
				length[u] + begin[u][j] < length[j]) {
				length[j] = length[u] + begin[u][j] < length[j];
				path[j] = u;
			}
		}
	}

	return 0;
}

int main(int argc, char** argv)
{
	struct adjacency_list al_list;

	init_adjacency_list(&al_list);

	create_adjacency_list(&al_list);
	travel_adjacency_list(&al_list);

	return 0;
}
