/*
 * mesh.h
 *
 *  Created on: Feb 19, 2018
 *      Author: Laurent
 */

#ifndef INCLUDE_MESH_H_
#define INCLUDE_MESH_H_

#include <vector>
#include "Geometry.h"
#include "Cell.h"
#include "Node.h"
#include "Face.h"

class Mesh: public Geometry
{
public:
	void get_mesh();
	void build_mesh();
	void mesh_to_cells(Cells &);

protected:
	Nodes m_nodes;
	Faces m_faces;
	int m_div_x;
	int m_div_y;
};



#endif /* INCLUDE_MESH_H_ */
