#pragma warning(disable: 6385)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "Rubiks_structures.h"
#include "rubiks_prototypes.h"
#include "rubiks_constants.h"



#ifndef RUBIKS_FUNC_ERROR
#define RUBIKS_FUNC_ERROR(x, y) {printf("\n\nERROR: %s %s FAILED TO MEET CONDITIONAL\n\nTRY PYTHON MAYBE?\n\n", x, y);} //"dataType" for x; "variableName" for y
#endif


void CubeOperation(new_cube* Rubiks, bool fOperation) //Generate and assign values to new_cube. Arg1 is cube's mem address. Arg2 is color constants/enums
{

	int color_counter[6] = { 0, 0, 0, 0, 0, 0 }; //address is passed to ThePainter()
	int *p_colorCounter = &(color_counter[0]);		 //to help keep count of the values

	struct surfaces_3x3_structure* p_sides = { NULL }; //Will get side member addresses from Rubiks
	struct rows_321_structure* p_row = { NULL };  //Will get row addresses of each side from p_side
	int* p_int = { NULL }; //Will get column addresses from each row of p_row

	int dataMap[27] = {0};

	int *pDataTable = dataMap;

	int loop_counter[3] = { 0 };


	//SIDES

	for (int k = 0; k <= 5; k++) //Alternates which side's mem address is passed from Rubiks to p_sides
	{
		if (k >= 5)
		{
			p_sides = (&Rubiks->right);
		}
		else if (k == 4)
		{
			p_sides = (&Rubiks->left);
		}
		else if (k == 3)
		{
			p_sides = (&Rubiks->bottom);
		}
		else if (k == 2)
		{
			p_sides = (&Rubiks->top);
		}
		else if (k == 1)
		{
			p_sides = (&Rubiks->back);
		}
		else
		{
			p_sides = (&Rubiks->front);
		}


		//ROWS

		for (int i = 1; i <= 3; i++) //cycles through all three rows for each respective side
		{
			if (i >= 3)
			{
				p_row = (&p_sides->row3);
			}
			else if (i >= 2)
			{
				p_row = (&p_sides->row2);
			}
			else
			{
				p_row = (&p_sides->row1);
			}


			//COLUMNS
			
			for (int j = 1; j <= 3; j++) //cycles through each column for each respective row
			{

				if (j >= 3)
				{
					p_int = (&p_row->col3);
				}
				else if (j >= 2)
				{
					p_int = (&p_row->col2);
				}
				else
				{
					p_int = (&p_row->col1);
				}
				
					switch (fOperation) //case = which operation this function should perform
					{

					case false:
							
							
							*p_int = ThePainter(p_colorCounter); //Pass constants; Then pass the address to the color counter
							    								 //to make sure there is roughly equal distribution
																 //and no value goes above the max	
							break;
					
					case true:

							loop_counter[0] = k; loop_counter[1] = i; loop_counter[2] = j;
							CubePrint((*p_int), loop_counter, pDataTable); // (value to print, side, row, col)
							break;

					} //switch

			}//COL
		}//ROW
	}//SIDES
}//POPULATE



int ThePainter(int* c_counter) //Returns color/int value for new_cube->->column_#
{

#define c(x) *(c_counter + (x - 1))


#define MAX MAX_OF_EACH_COLOR

	//this randomly applies a color to each cube, checking with an external 'max' for each one


	int iVar = 0;

	do
	{
		iVar = (rand() % 6) + 1; //initially set iVar to random value between 1-6
	} while (c(iVar) == MAX); //loop continues until it finds value that is lower than MAX

	c(iVar) += 1; //increase total number of that color by one

	if (c(iVar) > MAX) //if any color amount goes above MAX
	{
			RUBIKS_FUNC_ERROR("ThePainter: Color_type", "list.color.red"); return 0;
	}

	return iVar; //return the color to be placed on to the surface



	//this is a pattern that cannot be broken by any number of moves

	/*
	if ( ( c(red) >= c(green) ) || (c(red) >= MAX) ) { //IF !RED
	if ((c(green) >= c(blue)) || (c(green) >= MAX)) { //IF !GREEN
	if ( ((c(blue)) >= c(yellow)) || (c(blue) >= MAX)) { //IF !BLUE
	if ((c(yellow) >= c(orange)) || (c(yellow) >= MAX)) { //IF !YELLOW
	if ((c(orange) >= c(white)) || (c(orange) >= MAX)) { //IF !ORANGE
	if ((c(white) >= c(red)) || (c(white) >= MAX)) //!IF WHITE


	{ //If colors are maxed out before ThePainter stops being called...

			c(red) += 1; //this iterates red one time and ends nested conditionals

			if (c(red) > MAX) 
				{ RUBIKS_FUNC_ERROR("ThePainter: Color_type", "list.color.red"); return 0; } //this indicates that something went wrong
																					//and red went over the max

			return red; //this uses base values in the original list as the return, since c_counter is being updated with c()

	} //End Error Conditional




						else //WHITE

	{
	c(white) += 1;

	if (c(white) > MAX) { RUBIKS_FUNC_ERROR("ThePainter: Color_type", "list.color.white"); return 0; }

	return white;

	} //**WHITE




}//**IF !ORANGE 

						else //ORANGE

	{
	c(orange) += 1;

	if(c(orange) > MAX) {RUBIKS_FUNC_ERROR("ThePainter: Color_type", "list.color.orange"); return 0;}

	return orange;

	}//**ORANGE




} //**IF !YELLOW

						else //YELLOW

	{
	c(yellow) += 1;

	if (c(yellow) > MAX) { RUBIKS_FUNC_ERROR("ThePainter: Color_type", "list.color.yellow"); return 0; }

	return yellow;

	}//**YELLOW





} //**IF !BLUE

						else //BLUE

	{
	c(blue) += 1;

	if (c(blue) > MAX) { RUBIKS_FUNC_ERROR("ThePainter: Color_type", "list.color.blue"); return 0; }

	return blue;

	} //**BLUE




}//**IF !GREEN

						else //GREEN

	{
	c(green) += 1;

	return green;

	}//**GREEN
		



}//**IF !RED

						else //RED
	{
	c(red) += 1;

	if (c(red) > MAX) { RUBIKS_FUNC_ERROR("ThePainter: Color_type", "list.color.SECOND_RED"); return 0; }

	return red;

	}//**RED

*/

	/*
		//Prints values to screen for testing 
		//Keep just in case

	 printf("\nRED: %d\nGREEN: %d\nBLUE: %d\nYELLOW: %d\nORANGE: %d\nWHITE: %d\n",
		 c(red), c(green), c(blue), c(yellow), c(orange), c(white)); 

	*/
	

#undef c
#undef MAX

} //End ThePainter




void CubePrint(int print_val, int loop_counter[3], int* pDataTable)
{

#define side_count loop_counter[0]
#define row_count loop_counter[1]
#define col_count loop_counter[2]


	bool second_half = false;
	if (side_count >= BOTTOM) 
	{ second_half = (!second_half); }



	//########## HEADER

	if( (side_count == BOTTOM) && ((col_count + row_count) == 2) ) //If the first three cubes have been printed
	{
		printf("\n\n\n   BOTTOM           LEFT            RIGHT    \n\n\n"); //Print the second header		
	}
	else if ((side_count == FRONT) && ((col_count + row_count) == 2)) //If nothing has yet been printed
	{
		printf("\n   FRNT            BACK            TOP       \n\n\n"); //Print the first header
	}



	//########## STORE VALS


	switch (second_half) //Display is divided into 2 rows of 3 matrices.
						  //Each 'case' in this switch represents one of the rows.
	{

	case false: //Top 3 matrices

		*(pDataTable + (col_count -1) + ((row_count - 1)*9) + ((side_count)*3) ) = print_val;

		break;

	case true: //Bottom 3 matrices

		side_count -= 3;

		*(pDataTable + (col_count - 1) + ((row_count - 1) * 9) + ((side_count) * 3)) = print_val;


		break;
	}

	

	//########## PRINT VAL

	if( ((side_count == TOP) && (row_count == 3) && (col_count == 3)) ||
		((side_count == RIGHT) && (row_count == 3) && (col_count == 3)) )
	{
		for( int matrix = 0; matrix < 3; matrix++)
		for (int matrix_row = 1; matrix_row <= 3; matrix_row++)
		for (int sub_column = 1; sub_column <= 3; sub_column++)
		{	
			 printf("%d   ", *(pDataTable + ((matrix_row - 1)*3) + (matrix * 9) + (sub_column - 1)));

			//static int interations = 1;
			//printf("\nStatic Counter: %d\n", interations);
			//interations++;



			//########## NEXT ROW/MATRIX

			if ((matrix_row == 3) && (sub_column == 3)) //If at end of row
			{

				printf("\n\n"); //Next row

			}
			else if ((matrix_row != 3) && (sub_column == 3)) //If 3 shapes have been made
			{

				printf("     "); //Next matrix

			}

		}
	
	}


#undef side_count
#undef row_count
#undef col_count


}
//Prints cube

/*
Dimension_spec_type DefineTransformation(bool axis, int joint) //Enum constants used to declare blueprint for next move 
{

	Dimension_spec_type y = {7, axis, joint, 0};

	return y;

}
*/


void Transform_Cube(struct rubiks_cube_structure *R, enum movement_spec M_spec)
{
	int* pos1[4] = { NULL };
	int* pos2[4] = { NULL };
	int* pos3[4] = { NULL };

	switch (M_spec) 
	{

	//HORIZONTAL
	case X_JOINT1: //X's always start in row3

		pos1[0] = &(R->front.row3.col1);
		pos1[1] = &(R->top.row3.col1);
		pos1[2] = &(R->back.row3.col1);
		pos1[3] = &(R->bottom.row3.col1);

		pos2[0] = &(R->front.row2.col1);
		pos2[1] = &(R->top.row2.col1);
		pos2[2] = &(R->back.row2.col1);
		pos2[3] = &(R->bottom.row2.col1);

		pos3[0] = &(R->front.row1.col1);
		pos3[1] = &(R->top.row1.col1);
		pos3[2] = &(R->back.row1.col1);
		pos3[3] = &(R->bottom.row1.col1);

		fShift(pos1, pos2, pos3); 

		//SIDE_LEFT

		int row1_left[3];
		int row2_left[3];
		int row3_left[3];

		row1_left[0] = R->left.row1.col1;
		row1_left[1] = R->left.row1.col2;
		row1_left[2] = R->left.row1.col3;

		row2_left[0] = R->left.row2.col1;
		//r2[1] = R->left.row2.col2;
		row2_left[2] = R->left.row2.col3;

		row3_left[0] = R->left.row3.col1;
		row3_left[1] = R->left.row3.col2;
		row3_left[2] = R->left.row3.col3;

		R->left.row1.col1 = row1_left[2];
		R->left.row1.col2 = row2_left[2];
		R->left.row1.col3 = row3_left[2];

		R->left.row2.col1 = row1_left[1];
		//R->left.row2.col2 = r2[2];
		R->left.row2.col3 = row3_left[1];

		R->left.row3.col1 = row1_left[0];
		R->left.row3.col2 = row2_left[0];
		R->left.row3.col3 = row3_left[0];

		break;

	case X_JOINT2:

		pos1[0] = &(R->front.row3.col2);
		pos1[1] = &(R->top.row3.col2);
		pos1[2] = &(R->back.row3.col2);
		pos1[3] = &(R->bottom.row3.col2);

		pos2[0] = &(R->front.row2.col2);
		pos2[1] = &(R->top.row2.col2);
		pos2[2] = &(R->back.row2.col2);
		pos2[3] = &(R->bottom.row2.col2);

		pos3[0] = &(R->front.row1.col2);
		pos3[1] = &(R->top.row1.col2);
		pos3[2] = &(R->back.row1.col2);
		pos3[3] = &(R->bottom.row1.col2);

		fShift(pos1, pos2, pos3);

		break;

	case X_JOINT3:

		pos1[0] = &(R->front.row3.col3);
		pos1[1] = &(R->top.row3.col3);
		pos1[2] = &(R->back.row3.col3);
		pos1[3] = &(R->bottom.row3.col3);

		pos2[0] = &(R->front.row2.col3);
		pos2[1] = &(R->top.row2.col3);
		pos2[2] = &(R->back.row2.col3);
		pos2[3] = &(R->bottom.row2.col3);

		pos3[0] = &(R->front.row1.col3);
		pos3[1] = &(R->top.row1.col3);
		pos3[2] = &(R->back.row1.col3);
		pos3[3] = &(R->bottom.row1.col3);

		fShift(pos1, pos2, pos3);

		//SIDE_RIGHT

		int row1_right[3];
		int row2_right[3];
		int row3_right[3];

		row1_right[0] = R->right.row1.col1;
		row1_right[1] = R->right.row1.col2;
		row1_right[2] = R->right.row1.col3;

		row2_right[0] = R->right.row2.col1;
		//r2[1] = R->right.row2.col2;
		row2_right[2] = R->right.row2.col3;

		row3_right[0] = R->right.row3.col1;
		row3_right[1] = R->right.row3.col2;
		row3_right[2] = R->right.row3.col3;

		R->right.row1.col1 = row1_right[2];
		R->right.row1.col2 = row2_right[2];
		R->right.row1.col3 = row3_right[2];

		R->right.row2.col1 = row1_right[1];
		//R->right.row2.col2 = r2[2];
		R->right.row2.col3 = row3_right[1];

		R->right.row3.col1 = row1_right[0];
		R->right.row3.col2 = row2_right[0];
		R->right.row3.col3 = row3_right[0];

		break;


	//VERTICAL
	case Y_JOINT1: //Y's always start in col1

		pos1[0] = &(R->front.row1.col1);
		pos1[1] = &(R->left.row1.col1);
		pos1[2] = &(R->back.row1.col1);
		pos1[3] = &(R->right.row1.col1);

		pos2[0] = &(R->front.row1.col2);
		pos2[1] = &(R->left.row1.col2);
		pos2[2] = &(R->back.row1.col2);
		pos2[3] = &(R->right.row1.col2);

		pos3[0] = &(R->front.row1.col3);
		pos3[1] = &(R->left.row1.col3);
		pos3[2] = &(R->back.row1.col3);
		pos3[3] = &(R->right.row1.col3);

		fShift(pos1, pos2, pos3);

		//SIDE_TOP

		int row1_top[3];
		int row2_top[3];
		int row3_top[3];

		row1_top[0] = R->top.row1.col1;
		row1_top[1] = R->top.row1.col2;
		row1_top[2] = R->top.row1.col3;

		row2_top[0] = R->top.row2.col1;
		//r2[1] = R->top.row2.col2;
		row2_top[2] = R->top.row2.col3;

		row3_top[0] = R->top.row3.col1;
		row3_top[1] = R->top.row3.col2;
		row3_top[2] = R->top.row3.col3;

		R->top.row1.col1 = row1_top[2];
		R->top.row1.col2 = row2_top[2];
		R->top.row1.col3 = row3_top[2];

		R->top.row2.col1 = row1_top[1];
		//R->top.row2.col2 = r2[2];
		R->top.row2.col3 = row3_top[1];

		R->top.row3.col1 = row1_top[0];
		R->top.row3.col2 = row2_top[0];
		R->top.row3.col3 = row3_top[0];


		break;

	case Y_JOINT2:

		pos1[0] = &(R->front.row2.col1);
		pos1[1] = &(R->left.row2.col1);
		pos1[2] = &(R->back.row2.col1);
		pos1[3] = &(R->right.row2.col1);

		pos2[0] = &(R->front.row2.col2);
		pos2[1] = &(R->left.row2.col2);
		pos2[2] = &(R->back.row2.col2);
		pos2[3] = &(R->right.row2.col2);

		pos3[0] = &(R->front.row2.col3);
		pos3[1] = &(R->left.row2.col3);
		pos3[2] = &(R->back.row2.col3);
		pos3[3] = &(R->right.row2.col3);

		fShift(pos1, pos2, pos3);

		break;

	case Y_JOINT3:

		pos1[0] = &(R->front.row3.col1);
		pos1[1] = &(R->left.row3.col1);
		pos1[2] = &(R->back.row3.col1);
		pos1[3] = &(R->right.row3.col1);

		pos2[0] = &(R->front.row3.col2);
		pos2[1] = &(R->left.row3.col2);
		pos2[2] = &(R->back.row3.col2);
		pos2[3] = &(R->right.row3.col2);

		pos3[0] = &(R->front.row3.col3);
		pos3[1] = &(R->left.row3.col3);
		pos3[2] = &(R->back.row3.col3);
		pos3[3] = &(R->right.row3.col3);

		fShift(pos1, pos2, pos3);


		int row1_bottom[3];
		int row2_bottom[3];
		int row3_bottom[3];

		row1_bottom[0] = R->bottom.row1.col1;
		row1_bottom[1] = R->bottom.row1.col2;
		row1_bottom[2] = R->bottom.row1.col3;

		row2_bottom[0] = R->bottom.row2.col1;
		//r2[1] = R->bottom.row2.col2;
		row2_bottom[2] = R->bottom.row2.col3;

		row3_bottom[0] = R->bottom.row3.col1;
		row3_bottom[1] = R->bottom.row3.col2;
		row3_bottom[2] = R->bottom.row3.col3;

		R->bottom.row1.col1 = row1_bottom[2];
		R->bottom.row1.col2 = row2_bottom[2];
		R->bottom.row1.col3 = row3_bottom[2];

		R->bottom.row2.col1 = row1_bottom[1];
		//R->bottom.row2.col2 = r2[2];
		R->bottom.row2.col3 = row3_bottom[1];

		R->bottom.row3.col1 = row1_bottom[0];
		R->bottom.row3.col2 = row2_bottom[0];
		R->bottom.row3.col3 = row3_bottom[0];


		break;

		//DEPTH JOINTS, TURNS TO THE RIGHT
	/*case Z_JOINT1:

		pos1[0] = &(R->front.row3.col1);
		pos1[1] = &(R->top.row3.col1);
		pos1[2] = &(R->back.row3.col1);
		pos1[3] = &(R->bottom.row3.col1);

		pos2[0] = &(R->front.row2.col1);
		pos2[1] = &(R->top.row2.col1);
		pos2[2] = &(R->back.row2.col1);
		pos2[3] = &(R->bottom.row2.col1);

		pos3[0] = &(R->front.row1.col1);
		pos3[1] = &(R->top.row1.col1);
		pos3[2] = &(R->back.row1.col1);
		pos3[3] = &(R->bottom.row1.col1);

		fShift(pos1, pos2, pos3);

		break;*/
	}

	R->modified += 1;

	//printf("\n\n\nTransformations: %d\n", R->modified);
}

void fShift(int* var_add1[], int* var_add2[], int* var_add3[])
{	

	enum { FIRST, SECOND, THIRD, FOURTH }; //used to make array elements more readable

	//1

	int L1 = *var_add1[FIRST];
	int L2 = *var_add1[SECOND];
	int L3 = *var_add1[THIRD];
	int L4 = *var_add1[FOURTH];

	*var_add1[SECOND] = L1;
	*var_add1[THIRD] = L2;
	*var_add1[FOURTH] = L3;
	*var_add1[FIRST] = L4;

	//2

	L1 = *var_add2[FIRST];
	L2 = *var_add2[SECOND];
	L3 = *var_add2[THIRD];
	L4 = *var_add2[FOURTH];

	*var_add2[SECOND] = L1;
	*var_add2[THIRD] = L2;
	*var_add2[FOURTH] = L3;
	*var_add2[FIRST] = L4;

	//3

	L1 = *var_add3[FIRST];
	L2 = *var_add3[SECOND];
	L3 = *var_add3[THIRD];
	L4 = *var_add3[FOURTH];

	*var_add3[SECOND] = L1;
	*var_add3[THIRD] = L2;
	*var_add3[FOURTH] = L3;
	*var_add3[FIRST] = L4;

} 

void calcSideRelations(surface *side)
{
	int relations[6] = { 0 };

	relations[(side->row1.col1) - 1] += 1;
	relations[(side->row1.col2) - 1] += 1;
	relations[(side->row1.col3) - 1] += 1;

	relations[(side->row2.col1) - 1] += 1;
	relations[(side->row2.col2) - 1] += 1;
	relations[(side->row2.col3) - 1] += 1;

	relations[(side->row3.col1) - 1] += 1;
	relations[(side->row3.col2) - 1] += 1;
	relations[(side->row3.col3) - 1] += 1;

	int highestRelation = 0;

	for (int i = 0; i < 6; i++) 
	{
		if (highestRelation < relations[i])
		{
			highestRelation = relations[i];
		}
	}


	side->relations = highestRelation;


}

bool calcRelations(new_cube* Rubiks, new_cube* Real_Rubics)
{
	calcSideRelations(&Rubiks->front); calcSideRelations(&Rubiks->back);
	calcSideRelations(&Rubiks->top); calcSideRelations(&Rubiks->bottom);
	calcSideRelations(&Rubiks->left); calcSideRelations(&Rubiks->right);

	if ( (Rubiks->front.relations == 9) && (Rubiks->back.relations == 9) && (Rubiks->top.relations == 9) &&
		(Rubiks->bottom.relations == 9) && (Rubiks->left.relations == 9) && (Rubiks->right.relations == 9))
	{
		return true;
	}

	int sum_of_relations = ( (Rubiks->front.relations) + (Rubiks->back.relations) + (Rubiks->top.relations) +
		(Rubiks->bottom.relations) + (Rubiks->left.relations) + (Rubiks->right.relations) );

	if (sum_of_relations > Real_Rubics->highestRelational)
	{
		Real_Rubics->highestRelational = sum_of_relations;

		if (Real_Rubics->highestRelational > 21)
		{
			Real_Rubics->increment_value++;
		}
	}
	else
	{
		Real_Rubics->sumOfRelationals = sum_of_relations;
	}

	return false;

}

void showRelations(new_cube *Rubiks)
{
	printf("\n\t\t\t\t\t\t\tRELATIONS:");
	printf(" %d ", Rubiks->front.relations); printf(" %d ", Rubiks->back.relations);
	printf(" %d ", Rubiks->top.relations); printf(" %d ", Rubiks->bottom.relations);
	printf(" %d ", Rubiks->left.relations); printf(" %d \n", Rubiks->right.relations);


}


void NextTurn(enum movement_spec *nextMoveList, new_cube* Main_Rubiks_Pointer)
{

	//These two seemingly pointless cubes here are to keep the original rubix cube from getting updated
	//via pass by pointer. Fixing the code to de-necessitate this is something I need to return to later.
	//Alternative is to add a new_cube* Original_Pos to Rubix. Worth nothing, with this method this scope
	//Can still access Rubik-members through the pointer.

	new_cube Rubiks_Local = *Main_Rubiks_Pointer;
	new_cube* Rubiks = &Rubiks_Local;

	enum movement_spec currentMove[20] = {7}; //if value doesn't get overwritten, it will trigger error and report
	enum movement_spec lastMove[20] = { X_JOINT1 }; //Initialized to X_JOINT1 (val 1) for first move

	static int oscillator = 0;
	static int control_switch = 0;


	//UPDATE
	for (int i = 0; i < 20; i++) {

		currentMove[i] = nextMoveList[i]; //nextMoveList, as its name implies, will be soon updated

		if (i > 0) {

			lastMove[i] = nextMoveList[i - 1]; //used to quickly end needless repetitions in process
		}

	}

	int consecutive_moves = 0; //defitnetly doesn't keep track of what the name suggests
	new_cube temp_values;

	//MOVE

	for (int move_loop = 0; move_loop < MAX_MOVES_PER_TURN; move_loop++)
	{

		if (currentMove[move_loop] > NUM_TRANSFORM_OPTIONS)
		{
			currentMove[move_loop] = (NUM_TRANSFORM_OPTIONS/2);
		}


		//TRANSFORM

		Transform_Cube(Rubiks, currentMove[move_loop]); //Moves the values on the cube
		Main_Rubiks_Pointer->modified++;
			
		temp_values.highestRelational = Main_Rubiks_Pointer->highestRelational;

		//CHECK FOR COMPLETION AND THEN FOR INCREASE IN RELATIONAL
	
		if (calcRelations(Rubiks, Main_Rubiks_Pointer)) //if all sides match
		{
			*Main_Rubiks_Pointer = *Rubiks; //Set the original Rubiks to the completed state
			Main_Rubiks_Pointer->complete = true; //Complete external loop 
			//do not set complete to true before setting them equal otherwise the one will wipe out the other
			 
			break; //Break current loop
		}
		



		//CONSECUTIVES
		//THIS NEEDS TO BE CHECKED AND FIX AT START OF THIS FUNCTION

		if  //checks if last move was identical to this one
		( (move_loop > 0)   && 	(lastMove[move_loop] == currentMove[move_loop]) )  
		{
			consecutive_moves += 1;
		}
		else
		{
			consecutive_moves = 0; //this resets the counter for CONSECUTIVE moves
		}



		if (consecutive_moves > 2) //three moves in a row will end current turn and increment the move list
		{
			consecutive_moves = 0;
			break; //end turn and move to increment
		}

	} //For Loop




	//INCREMENT

	printf("\n%lld\n", LLONG_MAX);
		nextMoveList[Main_Rubiks_Pointer->increment_value] += 1;

	//nextMoveList[MEASURE_WORTH(Main_Rubiks_Pointer, nextMoveList)];


	//REDISTRIBUTE
	BalanceMoveSet(nextMoveList);

	//PRINT RELATIONS
	//showRelations(Rubiks);
	printf("\n     SUM OF RELATIONALS: %d              Highest Relational: %d\n", Main_Rubiks_Pointer->sumOfRelationals, Main_Rubiks_Pointer->highestRelational);

	//CubeOperation(Rubiks, 1);
	MovesToScreen(currentMove, Main_Rubiks_Pointer->modified); //knowledge is power
}


void MovesToScreen(enum movement_spec* move_set, int Num_of_Transformations)
{
	printf("\n\n\nMOVE CODE: ");

	for (int i = 0; i < 20; i++)
	{
		printf("%d  ", move_set[i]);
	}

	printf("\nTransformation Num: %d\n", Num_of_Transformations);
}


/*
void AdjustMoveSet(enum movement_spec *nextMovieList)
{
	for (int i = 19; i > 0; i--)
	{

		if (nextMovieList[i] > nextMovieList[(i - 1)])
		{

		}

	}
}
*/

void BalanceMoveSet(enum movement_spec* nextMoveList)
{
	for (int i = 0; i < MAX_MOVES_PER_TURN; i++)
	{
		if (nextMoveList[i] > 6)
		{
			nextMoveList[i] -= 6;
			nextMoveList[i + 1] += 1;
		}

		/*if (nextMoveList[MAX_MOVES_PER_TURN - i] > 6)
		{

			nextMoveList[MAX_MOVES_PER_TURN - i] -= 6;
			nextMoveList[i]++;

			/*printf("\n\n\nERROR: No solution was found.\n\n\n\n\n");
			exit(3);*/
		//}
	}

}

void CustomPopulateSide(surface* surface_of_cube, int color)
{

	for(int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if ((i == 1) && (j == 1))
			{
				surface_of_cube->row1.col1 = color;
			}
			else if ((i == 2) && (j == 1))
			{
				surface_of_cube->row2.col1 = color;
			}
			else if ((i == 3) && (j == 1))
			{
				surface_of_cube->row3.col1 = color;
			}


			else if ((i == 1) && (j == 2))
			{
				surface_of_cube->row1.col2 = color;
			}
			else if ((i == 2) && (j == 2))
			{
				surface_of_cube->row2.col2 = color;
			}
			else if ((i == 3) && (j == 2))
			{
				surface_of_cube->row3.col2 = color;
			}


			else if ((i == 1) && (j == 3))
			{
				surface_of_cube->row1.col3 = color;
			}
			else if ((i == 2) && (j == 3))
			{
				surface_of_cube->row2.col3 = color;
			}
			else if ((i == 3) && (j == 3))
			{
				surface_of_cube->row3.col3 = color;
			}


		}

}

/*int MEASURE_WORTH(new_cube* Rubix_Cube, enum movement_spec* the_movement_list)
{
	const int MODIFIED_DIVISOR = 30000; //Divide the transformation count of the cube by this value for the Incremental_Element

	if ( Rubix_Cube->modified / (MODIFIED_DIVISOR * (Rubix_Cube->transformation_interator + 1)) < 1 )
	{
		//nothing
		//printf("\n\nTEST TEST TEST %d\n\n", (Rubix_Cube->modified / (MODIFIED_DIVISOR * (Rubix_Cube->transformation_interator + 1))));

	}
	else
	{
		int the_worthiest = 0; int highestTotal = Rubix_Cube->worth[0];
		for (int i = 1; i < 6; i++)
		{
			if (Rubix_Cube->worth[i] > highestTotal)
			{
				the_worthiest = i;
				highestTotal = Rubix_Cube->worth[i];
				//printf("\n\n %d\n\n", the_worthiest);
			}

			Rubix_Cube->worth[0] = 0;
			Rubix_Cube->worth[i] = 0;

		}

		//printf("\n\nELSEEEEEEE %d\n\n", the_worthiest);

		the_movement_list[(Rubix_Cube->Incremental_Element)] = the_worthiest;
		Rubix_Cube->transformation_interator++;
		Rubix_Cube->Incremental_Element++;
		
	}

		

		return Rubix_Cube->Incremental_Element;
}*/

int ApplyMatrix(new_cube* Cube, Move_Matrix* spec_content)
{
	//new_cube changeCube = *Cube;
	//new_cube* p2changeCube = &changeCube;
	//changeCube has all the content Cube does, but it is stored locally.
	//Anything you want to save should be stored with Cube, not changeCube.


	enum movement_spec specs[3] = {spec_content->value[0],
								   spec_content->value[1],
								   spec_content->value[2]
									};


	Move_Matrix shell_matrix = {0}; //will be used to transform cube



	for (int i = 0; i < 3; i++) //moves content from spec to shell
								//run BMatrixSpecs() to organize specs/array
	{
		
		shell_matrix.value[i] = specs[i]; //hell in a shell
	}

	specs[0]++; //BMatrix can allocate the proper location for increments
	BalanceMatrixSpec(specs); //will call itself until critical allocations are complete



	for (int move_loop = 0; move_loop < MAX_MOVES_PER_TURN; move_loop++) //move loop, MAX_MOVES_PER_TURN long runs
																		 //which is 21 at the time of writing this
	{
		for (int j = 0; j < 3; j++) //Apply all three transformations to Cube type
		{
			Transform_Cube(Cube, shell_matrix.value[j]); 
			CubeOperation(Cube, 1);
		}

		//CubeOperation(p2changeCube, 1);
		calcRelations(Cube, Cube);
		showRelations(Cube);
	}


	return calcRelations(Cube, Cube);
}




void BalanceMatrixSpec(enum movement_spec* specs) //Keeps matrix arrays organized and below MAX TRANSFORMS
{
	for (int i = 0; i < 3; i++) //array loop
	{

		if (specs[i] > NUM_TRANSFORM_OPTIONS) //if specs' content is bigger than max)
		{

			specs[i] -= NUM_TRANSFORM_OPTIONS; //if so, reduce it by 1 factor of the max

			if (i < 2) //then check if can safely access the next element up
			{
				specs[i + 1]++; 
			}
			else
			{
				specs[i - 1]++; //We can't? Then that must mean we can safely access one below
								//Note: this is wrapping around. Not arbitrary number repositioning.

			}//this conditional replaces 6 ints for one int in the right-next spot


		}//if

	}//loop

	if ( (specs[0] > 2) || (specs[1] > 2) || (specs[2] > 2) ) //if any one of the values did not get properly
															  //allocated, re-call the function
	{
		BalanceMatrixSpec(specs);
	}

}//void


#undef RUBIKS_FUNC_ERROR

