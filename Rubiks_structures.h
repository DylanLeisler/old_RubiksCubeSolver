
#ifndef _RUBIKS_STRUCTURES_H_
#define _RUBIKS_STRUCTURES_H_

/*
typedef struct A_Structure_Of_Grace {

	new_cube* Rubics_Cube_Pointer;


	Move_Matrix* Matrix_Pointer;
	int worth_of_Matrices[3];

	//intent of this structure is to find novel way to allow computer to work through various processes and gain knowledge
	//and then to subsequently use that knowledge to develop more effective strategies against the Cube

	



} Godhead;

// Godhead Avagantamos;

*/

typedef struct surfaces_3x3_structure {

	struct rows_321_structure {

		int col1;
		int col2;
		int col3;

	} row1, row2, row3;

	int relations;

} surface;


typedef struct Matrix_of_Moves_structure {

	enum movement_type value[3];


} Move_Matrix;



typedef struct rubiks_cube_structure {

	surface front, back, top, bottom, left, right;

	int modified;

	int highestRelational;
	int sumOfRelationals;

	int increment_value;


	bool complete;

} new_cube;


/*
typedef struct dimensions_3x3_structure {

	int side; //Temporarily not in use

	bool axis;

	int joint;

	bool direction; //Temp not in use


} Dimension_spec_type;
*/ //Not needed for simple calculations

#endif