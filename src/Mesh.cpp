/*
 * mesh.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: Laurent
 */

#include <fstream>
#include <iostream>

#include "Mesh.h"
#include "Cell.h"

void Mesh::get_mesh()
{
	std::ifstream ifile;
	ifile.open("Files/mesh.dat");
	if(ifile.is_open())
	{
		std::cout << "Reading the mesh information" << std::endl;
		ifile >> m_div_x;
		ifile >> m_div_y;
		std::cout << "Information successfully extract" << std::endl
				<< "nb of node x : " << m_div_x + 1 << " , nb of node y : " << m_div_y +1 << std::endl
				<< "|--------------------|"<< std::endl;
	}
	else
	{
		std::cout << "Cannot open file mesh.dat" << std::endl;
	}
}

void Mesh::build_mesh()
{
	std::cout << "Nodes generation" << std::endl;
	double interval_x,interval_y;

	m_nodes.set_nb_nodes(m_div_x+1, m_div_y+1);

	interval_x = m_max_x/m_div_x;
	interval_y = m_max_y/m_div_y;

	for(int j = 0; j < m_div_y + 1 ; j++)
	{
		for(int i = 0 ; i < m_div_x + 1 ; i++)
		{
			m_nodes.add_node(interval_x * i, interval_y * j);
		}
	}

	//m_nodes.dump_nodes();

	int j(0);

	std::cout << "Horizontal surfaces generation" << std::endl;
	for(int i = 1; i <= (m_div_y + 1)*m_div_x ; i++)
		{
			j++;
			int k = i + (i - 1)/(m_div_x);
			m_faces.add_face(m_nodes.get_pt_node(k), m_nodes.get_pt_node(k+1));
			/*std::cout << "Surface nb:" << j  <<
					", Node nb:" << k << std::endl;*/
		}

	std::cout << "Vertical surfaces generation" << std::endl;
	for(int i = 1; i <= (m_div_x + 1)*m_div_y ; i++)
		{
			j++;
			int k = i;
			m_faces.add_face(m_nodes.get_pt_node(k), m_nodes.get_pt_node(k+m_div_x+1));
			/*std::cout << "Surface nb:" << j  <<
					", Node nb:" << k << std::endl;*/
		}

	//m_faces.dump_faces();

}

void Mesh::mesh_to_cells(Cells & all_cells)
{
	all_cells.define_cells(m_div_x, m_div_y);

	for(int i = 1; i <= m_div_x * m_div_y; i++)
	{
		/*std::cout << "Cell nb: " << i;
				  << ", N_nw: " << i + (i-1)/m_div_x
				  << ", N_ne: " << i + (i-1)/m_div_x + m_div_x + 1
				  << ", N_sw: " << i + (i-1)/m_div_x + 1
				  << ", N_se: " << i + (i-1)/m_div_x + m_div_x + 1 + 1
				  << ", Sf e: " << (m_div_x)* (m_div_y + 1) + i + (i-1)/m_div_x
				  << ", Sf w: " << (m_div_x)* (m_div_y + 1) + i + (i-1)/m_div_x  + 1
				  << ", Sf n: " << i
				  << ", Sf s: " << i + m_div_x << std::endl;*/

		Node *n_nw = m_nodes.get_pt_node( i + (i-1)/m_div_x);
		Node *n_ne = m_nodes.get_pt_node( i + (i-1)/m_div_x + m_div_x + 1);
		Node *n_sw = m_nodes.get_pt_node( i + (i-1)/m_div_x + 1);
		Node *n_se = m_nodes.get_pt_node( i + (i-1)/m_div_x + m_div_x + 1 + 1);

		Face *sf_e = m_faces.get_pt_face(m_div_x*(m_div_y + 1) + i + (i-1)/m_div_x);
		Face *sf_w = m_faces.get_pt_face(m_div_x*(m_div_y + 1) + i + (i-1)/m_div_x  + 1);
		Face *sf_n = m_faces.get_pt_face(i);
		Face *sf_s = m_faces.get_pt_face(i + 1);

		all_cells.add_cell(n_sw, n_nw, n_ne, n_se, sf_w, sf_e, sf_n, sf_s);

	}

	all_cells.dump_cells();

}
