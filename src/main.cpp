//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include "Geometry.h"
#include "Mesh.h"
#include "Cell.h"

int main(void) {

	std::cout << "Welcome to LoLo v:alpha" << std::endl
		<< "version alpha 0.0"<< std::endl
		<< "|--------------------|"<< std::endl;

	int i = 1;
	int k = 3;

	Mesh mesh;
	mesh.get_geom();
	mesh.display();
	mesh.get_mesh();
	mesh.build_mesh();

	Cells cells;
	mesh.mesh_to_cells(cells);
	cells.build_cells_dependency();

	return 0;
}
