#pragma once

#define MAX_FPS 1000
#define MIN_FPS 10
#define MAX_BOARD_SIZE_X 20
#define MIN_BOARD_SIZE_X 5
#define MAX_BOARD_SIZE_Y 20
#define MIN_BOARD_SIZE_Y 5
#define FALL_DOWN_SPEED_MIN 0.5f
#define FALL_DOWN_SPEED_MAX 10.0f
#define FALL_DOWN_SPEED_FAST 20.0
#define BOARD_BLOCK_SIZE 30
#define SCORE_FROM_PUT_BLOCK 5
#define SCORE_FORM_SET_LINE 100
#define SHAPE_SIZE 5


#define SETTEGINS_FILE "Config/Settegins.ini"
#define SHAPES_FILE "Config/shapes.ini"



template<class T>
const T& clamp(const T& x, const T& upper, const T& lower) {
	return std::min(upper, std::max(x, lower));
}
