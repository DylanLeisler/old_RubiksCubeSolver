
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "Rubiks_structures.h"
#include "rubiks_prototypes.h"
#include "rubiks_constants.h"
#include <time.h>




int main() {

//########Constants/Enums########//

enum { POPULATE, PRINT }; //enum Operations

//########**Constants/Enums**########//



	//new_cube Completed_Rubiks = { 0 };
	//CustomPopulateSide(&Completed_Rubiks.front, red); CustomPopulateSide(&Completed_Rubiks.back, blue);
	//CustomPopulateSide(&Completed_Rubiks.top, green); CustomPopulateSide(&Completed_Rubiks.bottom, yellow);
	//CustomPopulateSide(&Completed_Rubiks.left, orange); CustomPopulateSide(&Completed_Rubiks.right, white);

	//CubeOperation(&Completed_Rubiks, POPULATE);
	//CubeOperation(&Completed_Rubiks, PRINT);

	////Transform_Cube(&Completed_Rubiks, Y_JOINT1); Transform_Cube(&Completed_Rubiks, Y_JOINT1); Transform_Cube(&Completed_Rubiks, Y_JOINT1);

	////CubeOperation(&Completed_Rubiks, PRINT);
	//
	//calcRelations(&Completed_Rubiks);
	//showRelations(&Completed_Rubiks);

	////return 0;

	////Transform_Cube(&Completed_Rubiks, X_JOINT1); Transform_Cube(&Completed_Rubiks, X_JOINT1); Transform_Cube(&Completed_Rubiks, X_JOINT1);

	
	




	new_cube Rubiks_Cube = { 0 }; //ignore this, serves no purpose

	CubeOperation(&Rubiks_Cube, POPULATE);
	//CubeOperation(&Rubiks_Cube, PRINT);

	Rubiks_Cube.modified = 0;
	Rubiks_Cube.highestRelational = 0;
	Rubiks_Cube.increment_value = 0;
	


	enum movement_spec nextMoveList[MAX_MOVES_PER_TURN] = { 1,1,1,1,1,
														    1,1,1,1,1,
														    1,1,1,1,1,
														    1,1,1,1,1 } ; //4 rows of 5, single dimensional */

	Move_Matrix Primary_Matrix = { X_JOINT1, X_JOINT1, X_JOINT1 };



	int counter = 0;
	Rubiks_Cube.complete = false;
	while ((counter > -1) && (Rubiks_Cube.complete == false))
	{


		//Rubiks_Cube.complete = ApplyMatrix(&Rubiks_Cube, &Primary_Matrix);
		//Primary_Matrix.value[(counter%3)] = (counter%6);
		//showRelations(&Rubiks_Cube);
		//printf("\n\n\ %dn\n", Rubiks_Cube.highestRelational);
		////CubeOperation(&Rubiks_Cube, PRINT);
		NextTurn(nextMoveList, &Rubiks_Cube);
		MovesToScreen(nextMoveList, counter);
		counter++;
		//Rubiks_Cube.front.relations = 3;
		//printf(" %d ", Rubiks_Cube.front.relations); printf(" %d ", Rubiks_Cube.back.relations);
		//printf(" %d ", Rubiks_Cube.top.relations); printf(" %d ", Rubiks_Cube.bottom.relations);
		//printf(" %d ", Rubiks_Cube.left.relations); printf(" %d \n", Rubiks_Cube.right.relations);

		//CubeOperation(&Rubiks_Cube, PRINT);
	}


	if (Rubiks_Cube.complete == true)
	{
		CubeOperation(&Rubiks_Cube, PRINT);
		MovesToScreen((nextMoveList), Rubiks_Cube.modified);
		printf("\nCompleted.\n");
		return 0;
	}



	return 1;
}


//PRINTF TAKING A LOT PROCESSING POWER

//TRANSFORMING CUBE IS NOT NEEDED. ADD ENCODING AND DECODING.