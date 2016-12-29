#define MAX_FPS 1000
#define MIN_FPS 10
#define MAX_BOARD_SIZE_X 20
#define MIN_BOARD_SIZE_X 5
#define MAX_BOARD_SIZE_Y 20
#define MIN_BOARD_SIZE_Y 5
#define FALL_DOWN_SPEED 1.0
#define FALL_DOWN_SPEED_FAST 15.0





template<class T>
const T& clamp(const T& x, const T& upper, const T& lower) {
	return std::min(upper, std::max(x, lower));
}
