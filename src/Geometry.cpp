/*
 * Geometry.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Laurent
 */

#include "Geometry.h"
#include <fstream>
#include <iostream>

void Geometry::get_geom()
{
	std::ifstream ifile;
	ifile.open("Files/geom.dat");
	if(ifile.is_open())
	{
		std::cout << "Reading the geometry" << std::endl;
		ifile >> m_nb_dim;
		ifile >> m_max_x;
		ifile >> m_max_y;
	}
	else
	{
		std::cout << "Cannot open file geom.dat" << std::endl;
	}

}

void Geometry::display()
{
	std::cout << "Geometry is : " << m_nb_dim << "D" << std::endl
			<< "m_max_x: " << m_max_x << std::endl
			<< "m_max_y: " << m_max_y << std::endl
			<< "|--------------------|"<< std::endl;
}
