/*
 * Node.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: Laurent
 */

#include <iostream>
#include <stdio.h>
#include <vector>

#include "Node.h"

//---------------------Class Node-------------------------//
Node::Node(int const &i, double const &x, double const &y)
{
	m_node_nb = i;
	m_node_x = x;
	m_node_y = y;
}

void Node::get_xy(double &x, double &y)
{
	x = m_node_x;
	y = m_node_y;
}

void Node::info_node()
{
	std::cout << "node[" << m_node_nb << "], (x="
			<< m_node_x << "), (y=" << m_node_y << ")" << std::endl;
}

//---------------------Class Nodes-------------------------//
void Nodes::resize(int const &size)
{
	m_nodes.resize(size);
}

void Nodes::add_node(double const &x, double const &y)
{
	int i = m_nodes.size();
	Node temp_node(i+1,x,y);
	m_nodes.push_back(temp_node);
}

void Nodes::set_nb_nodes(int const& nb_x, int const& nb_y)
{
	m_nb_nodes_x = nb_x;
	m_nb_nodes_y = nb_y;
}

void Nodes::dump_nodes()
{
	for(int i = 0; i < m_nodes.size(); i++)
	{
		m_nodes[i].info_node();
	}
}

Node* Nodes::get_pt_node(int const &i)
{
	return &m_nodes[i-1];
}

