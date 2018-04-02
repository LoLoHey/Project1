/*
 * Node.h
 *
 *  Created on: Feb 27, 2018
 *      Author: Laurent
 */

#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_

#include <vector>

class Node
{
public:
	Node(int const& nb = 0, double const& x=0, double const& y=0);

	void get_xy(double &,double &);

	void info_node();

protected:
	int m_node_nb;
	int m_node_x;
	int m_node_y;
};

class Nodes
{
public:
	void resize(int const&);
	void add_node(double const&, double const&);
	void set_nb_nodes(int const&, int const&);
	Node* get_pt_node(int const&);
	void dump_nodes();

protected:
	std::vector<Node> m_nodes;
	int m_nb_nodes_x, m_nb_nodes_y;
};


#endif /* INCLUDE_NODE_H_ */
