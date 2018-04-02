/*
 * Cell.h
 *
 *  Created on: Feb 22, 2018
 *      Author: Laurent
 */

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <vector>
#include "Node.h"
#include "Face.h"

class Cell
{
public:

	Cell();
	Cell(Node *, Node *, Node *, Node *, Face *, Face *, Face *, Face *);
	~Cell();

	void info_cell();

	void set_neighbors(Cell *ngh_n, Cell *ngh_s, Cell *ngh_w, Cell *ngh_e);

protected:
	double m_x, m_y;
	double m_vol;
	Face *m_fw, *m_fe, *m_fn, *m_fs;
	Node *m_nsw, *m_nse, *m_nnw, *m_nne;
	Cell *m_ngh_e, *m_ngh_w, *m_ngh_n, *m_ngh_s;
};

class Cells
{
public:

	Cells();

	void define_cells(int const&, int const&);
	void add_cell(Node *,Node *,Node *, Node *, Face*, Face*, Face*, Face*);
	void build_cells_dependency();
	void dump_cells();
	void ghost_cells();

	Cell *get_cell(int const&);

protected:
	std::vector<Cell> m_cells;
	std::vector<Cell> m_ghost_cells;

	int m_cells_x, m_cells_y;
	int m_num_cell;
};

#endif /* INCLUDE_CELL_H_ */
