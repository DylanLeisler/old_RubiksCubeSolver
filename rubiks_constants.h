#ifndef _RUBIKS_CONSTANTS_H_
#define _RUBIKS_CONSTANTS_H_


enum {

	empty_DONOTUSE,
	red,
	blue,
	green,
	yellow,
	orange,
	white,

};

enum movement_spec {X_JOINT1 = 1, X_JOINT2, X_JOINT3,
				   Y_JOINT1, Y_JOINT2, Y_JOINT3/*, 
					Z_JOINT1, Z_JOINT2, Z_JOINT3*/};



//enum {UP_LEFT, DOWN_RIGHT};

enum {

	FRONT,
	BACK,
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
	NUM_SIDES //FRONT = 0, so NUM_SIDES will equal total num of options

};

enum {MAX_OF_EACH_COLOR = 9, NUM_COLORS = 6};

enum {MAX_MOVES_PER_TURN = 21, NUM_TRANSFORM_OPTIONS = 6, MATRIX_SIZE = 3};


#endif _RUBIKS_CONSTANTS_H_