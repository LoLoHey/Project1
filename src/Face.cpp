/*
 * Face.cpp
 *
 *  Created on: Mar 8, 2018
 *      Author: Laurent
 */

#include "Face.h"

#include <math.h>
#include <vector>
#include <iostream>


//---------------------class Face------------------------//
Face::Face(Node* const& pt1, Node* const& pt2)
{
	m_pt_node[0] = pt1;
	m_pt_node[1] = pt2;
	m_surface = 0.0;
	this->calc_surface();
}

double Face::get_surface()
{
	return m_surface;
}

void Face::calc_surface()
{
	double x1, x2, y1, y2;
	m_pt_node[0]->get_xy(x1,y1);
	m_pt_node[1]->get_xy(x2,y2);
	m_surface = pow(x1-x2,2) + pow(y1-y2,2);
	m_surface = sqrt(m_surface);
}

void Face::info_face()
{
	std::cout << "Sf = " << m_surface << std::endl;
}

//---------------------class Faces------------------------//

Faces::Faces()
{
	m_nb_faces = 0;
}

void Faces::add_face(Node* const& pt_nd1, Node* const& pt_nd2)
{
	int i = m_faces.size();
	Face temp_face(pt_nd1,pt_nd2);
	m_faces.push_back(temp_face);
	m_nb_faces++;
}

Face* Faces::get_pt_face(int const& i)
{
	return &m_faces[i-1];
}

void Faces::dump_faces()
{
	for(int i = 0; i < m_faces.size(); i++)
	{
		std::cout << "Sf_nb [" << i + 1 << "], " ;
		m_faces[i].info_face();
	}
}
