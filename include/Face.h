/*
 * Face.h
 *
 *  Created on: Mar 8, 2018
 *      Author: Laurent
 */

#ifndef INCLUDE_FACE_H_
#define INCLUDE_FACE_H_

#include <vector>

#include "Node.h"

//---------------------class Face-------------------------//
class Face
{
public:
	Face(Node* const&, Node* const&);

	double get_surface();
	void calc_surface();

	void info_face();

protected:
	double m_surface;
	Node* m_pt_node[2];
};

//---------------------class Faces------------------------//
class Faces
{
public:
	Faces();

	void add_face(Node* const&, Node* const&);
	Face* get_pt_face(int const&);

	void dump_faces();

protected:
	int m_nb_faces;
	std::vector<Face> m_faces;
};

#endif /* INCLUDE_FACE_H_ */
