/*
 * Cell.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Laurent
 */
#include <stdio.h>
#include <iostream>
#include <cmath>

#include "cell.h"

//---------------------------Cell------------------------------//

Cell::Cell(): m_vol(0.0), m_x(0.0),m_y(0.0),
			m_fw(NULL),m_fe(NULL),m_fn(NULL),m_fs(NULL),
			m_nsw(NULL),m_nnw(NULL),m_nne(NULL),m_nse(NULL),
			m_ngh_n(NULL),m_ngh_s(NULL),m_ngh_e(NULL),m_ngh_w(NULL)
{}

Cell::Cell(Node *n_sw, Node *n_nw, Node *n_ne, Node *n_se,
		   Face *f_w, Face *f_e, Face *f_n, Face *f_s):
		   m_vol(0.0), m_x(0.0),m_y(0.0),
		   m_fw(f_w),m_fe(f_e),m_fn(f_n),m_fs(f_s),
		   m_nsw(n_sw),m_nnw(n_nw),m_nne(n_ne),m_nse(n_se),
			m_ngh_n(NULL),m_ngh_s(NULL),m_ngh_e(NULL),m_ngh_w(NULL)
{
// xy calculation
	double x1, x2, x3, x4, y1, y2, y3, y4;
	n_sw->get_xy(x1,y1);
	n_nw->get_xy(x2,y2);
	n_se->get_xy(x3,y3);
	n_ne->get_xy(x4,y4);

	m_x =(x1+x2+x3+x4)/4.0;
	m_y =(y1+y2+y3+y4)/4.0;

// volume calculation
	m_vol = f_w->get_surface() * f_s->get_surface();
}

Cell::~Cell()
{}

void Cell::set_neighbors(Cell *ngh_n, Cell *ngh_s, Cell *ngh_w, Cell *ngh_e)
{
	m_ngh_n = ngh_n;
	m_ngh_s = ngh_s;
	m_ngh_w = ngh_w;
	m_ngh_e = ngh_e;
}

void Cell::info_cell()
{
	std::cout << "[" << m_x << "," << m_y << "], Vol =  " << m_vol << std::endl;
}

//---------------------------Cells container------------------------------//

Cells::Cells(): m_cells_x(0), m_cells_y(0), m_num_cell(0)
{}

void Cells::define_cells(int const &nb_x, int const &nb_y)
{
	m_cells_x = nb_x;
	m_cells_y = nb_y;
}

void Cells::add_cell(Node *n_sw, Node *n_nw, Node *n_ne, Node *n_se,
		Face *f_w, Face *f_e, Face *f_n, Face *f_s)
{
	m_num_cell++;
	Cell tempo_cell(n_sw, n_nw, n_ne, n_se, f_w, f_e, f_n, f_s);
	m_cells.push_back(tempo_cell);
}

void Cells::build_cells_dependency()
{
	std::cout << "Cells dependency" << std::endl;
	this->ghost_cells();

	int num_cell(0);
	Cell *ngh_n, *ngh_s, *ngh_e, *ngh_w;

	for(int j=1 ; j <= m_cells_y; j++)
	{
		for(int i=1 ; i <= m_cells_x; i++)
			{
				num_cell = (j-1)*m_cells_x + i;
				std::cout << "cell [" << i << ", " << j << "], nb =" << num_cell;

				//------get north--------//
				if(j == m_cells_y)
				{
					ngh_n = &m_ghost_cells[0];
					std::cout << ", ngh_n:ghost 0";
				}
				else
				{
					ngh_n = &m_cells[num_cell + m_cells_x - 1];
					std::cout << ", ngh_n:" << num_cell + m_cells_x;
				}
				//------get south--------//
				if(j == 1)
				{
					ngh_s = &m_ghost_cells[1];
					std::cout << ", ngh_s:ghost 1";
				}
				else
				{
					ngh_s = &m_cells[num_cell - m_cells_x - 1];
					std::cout << ", ngh_s:" << num_cell - m_cells_x;
				}
				//------get west---------//
				if(i == 1)
				{
					ngh_w = &m_ghost_cells[2];
					std::cout << ", ngh_w:ghost 2";
				}
				else
				{
					ngh_w = &m_cells[num_cell - 1 - 1];
					std::cout << ", ngh_w:" << num_cell - 1;
				}
				//------get east---------//
				if(i == m_cells_x)
				{
					ngh_e = &m_ghost_cells[3];
					std::cout << ", ngh_e:ghost 3" << std::endl;
				}
				else
				{
					ngh_e = &m_cells[num_cell + 1 - 1];
					std::cout << ", ngh_e:" << num_cell + 1 << std::endl;
				}
				m_cells[num_cell].set_neighbors(ngh_n, ngh_s, ngh_w, ngh_e);
			}
	}
}

void Cells::dump_cells()
{
	for(int i = 0; i < m_cells.size(); i++)
	{
		std::cout << "Cell(" << i+1 << "), ";
		m_cells[i].info_cell();
	}
}

void Cells::ghost_cells()
{
	m_ghost_cells.resize(4);
}

Cell * Cells::get_cell(int const &i)
{
	return &m_cells[i-1];
}
