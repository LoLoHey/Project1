/*
 * Geometry.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Laurent
 */

#ifndef INCLUDE_GEOMETRY_H_
#define INCLUDE_GEOMETRY_H_

class Geometry
{
public:
	void get_geom();
	void display();

protected:
	int m_nb_dim;
	double m_max_x, m_max_y;
};



#endif /* INCLUDE_GEOMETRY_H_ */
