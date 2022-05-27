#ifndef _RUBIKS_PROTOTYPES_
#define _RUBIKS_PROTOTYPES_



void CubeOperation(new_cube* Rubix, bool populate_or_print);

int ThePainter(int pointer_to_color_counter[]); //CodePopulate uses it to fill each square with the proper amount of each 'color.' 

void CubePrint(int cube_value_to_print, int loop_counter[3], int* pointer_to_num_table); //print values of arg 'new_cube' type to screen

//Dimension_spec_type DefineTransformation(bool axis, int joint);

void Transform_Cube(struct rubiks_cube_structure* Rubiks_memAdd, enum movement_spec axis_joint);

void fShift(int* row_or_col_1[4], int* row_or_col_2[4], int* row_or_col_3[4]);

void calcSideRelations(surface* side);

bool calcRelations(new_cube* Rubiks, new_cube* real_rubix);

void showRelations(new_cube* Rubix);

void NextTurn(enum movement_spec *nextMove, new_cube* Rubiks);

void MovesToScreen(enum movement_spec* move_set, int moveNum);

//void AdjustMoveSet(enum movement_spec* move_set);

void BalanceMoveSet(enum movement_spec* move_set);

void CustomPopulateSide(surface* surface_of_cube, int color);

//int MEASURE_WORTH(new_cube* Rubix_Cube, enum movement_spec* the_movement_list);

int ApplyMatrix(new_cube* Cube, Move_Matrix* spec_content);

void BalanceMatrixSpec(enum movement_spec* specs);


#endif