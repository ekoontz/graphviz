/* $Id: tvnodes.h,v 1.4 2008/04/23 18:14:00 arif Exp $ $Revision: 1.4 $ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

#ifndef TVNODES_H
#define TVNODES_H

#include "gui.h"
#define MAX_NODE_PER_PAGE 100
#define LOCATION_X_CHKSELECTED 16
#define LOCATION_X_IDLABEL 45
#define LOCATION_X_CHKVISIBLE 139
#define LOCATION_X_CHKHIGHLIGHTED 202
#define LOCATION_X_NAME  276
#define LOCATION_X_DATA1 356
#define LOCATION_X_DATA2 561

typedef struct token_info {
    int op_index;		// has to 
    int op1_length;
    int op2_length;

} token_info;

typedef struct btree_node {
    int child_count;
    struct btree_node **childs;
    struct btree_node *parent;
    int rank;			//0 root
    char op;			// & | + - whatever
    int node_type;		//0 and 1 or 2 atom
    char *attr_name;
    char *regex;
    float min;
    float max;
    int value;			//filter result true false, 0 , 1
    int active;
} btree_node;

typedef struct _tv_filter {
    btree_node *root;
    char *min_data1;
    char *min_data2;
    char *max_data1;
    char *max_data2;
    char *filter_string;
    int active;
    int visible;		//-1 all 0 not not visible 1 only visibles
    int highlighted;		//same above
    int selected;		//same above
} tv_filter;

typedef struct _tv_node {
    int index;
    GtkCheckButton *chkSelected;
    GtkCheckButton *chkVisible;
    GtkCheckButton *chkHighlighted;
    GtkLabel *IDLabel;
    GtkEntry *Name;
    GtkEntry *Data1;
    GtkEntry *Data2;
    int valid;
} tv_node;


typedef struct _tv_nodes {
    int pagecount;
    int activepage;
    int firstnodeid;
    int *page_history;
    int page_history_count;
    int recordperpage;		//dynamic so that can be changed by plugins etc 
    int filtered;
    int page_data_index;
    int page_data_node_index;
    tv_node TV_Node[MAX_NODE_PER_PAGE];
    tv_filter filter;
    int Y;
    int Y_Gap;
    int initial_Y;
    int chkSelected_X;
    int IDLabel_X;
    int chkVisible_X;
    int chkHighlighted_X;
    int Data1_X;
    int Data2_X;
    int initialized;
    int general_purpose_flag;	//dont forget to to set it back
} tv_nodes;
extern tv_nodes TV_Nodes;



void execute_tv_nodes();
int set_filter(tv_filter * TV_Filter, char *MinData1,
		      char *MaxData1, char *MinData2, char *MaxData2,
		      char *Filter_String, int selected, int visible,
		      int highlighted);
int tv_nodes_goto_page(int page);
int tv_nodes_next_page();
int tv_nodes_prior_page();
int tv_nodes_last_page();
int tv_nodes_first_page();

int reset_page_History();
int prepare_page_history();
int create_save_subgraph_from_filter(char* filename);
int update_TV_data_from_gui();
int apply_filter_from_gui();
int tv_select_all();
int tv_unselect_all();
int tv_highligh_all();
int tv_unhighligh_all();
int tv_show_all();
int tv_hide_all();
int tv_save_as();
#endif
