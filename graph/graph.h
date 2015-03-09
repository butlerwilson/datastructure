#ifndef	_GRAPH_H_
#define _GRAPH_H_

#define MAX_VERTEX	100
#define INFDIGIT	-1

#define true 1

struct locate_index {
	int li_row;
	int li_col;
	int li_cov;
};

//adjacency matrix structure
struct vertex_node {
	TYPE vn_info;
};

struct graph_node {
	int gn_weight;
	TYPE gn_info;
};

struct adjacency_matrix {
	struct vertex_node am_vertex[MAX_VERTEX];
	struct graph_node am_matrix[MAX_VERTEX][MAX_VERTEX];
};


//adjacency list structure
struct edge_node {
	int en_index;
	struct edge_node *en_node;
};

struct vertex_node_array {
	TYPE vna_info;
	int vna_flags;
	struct edge_node *vna_en_head;
};

struct adjacency_list {
	int al_count;
	struct vertex_node_array vertex_array[MAX_VERTEX];
};

//orthogonal list structure
struct arch_node {
	int an_atindex;
	int an_ahindex;
	struct arch_node *an_shnext;
	struct arch_node *an_stnext;
};

struct vertex_node_array_ {
	TYPE vna_info;
	struct arch_node *vna_ahnode;
	struct arch_node *vna_atnode;
};

struct orthogonal_list {
	struct vertex_node_array_ ol_vertex[MAX_VERTEX];
};

#endif
