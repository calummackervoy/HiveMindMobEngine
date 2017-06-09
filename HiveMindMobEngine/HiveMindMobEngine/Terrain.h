
enum Terrain : uint8_t {
	OPEN,
	PART_COV,
	FULL_COV
};

typedef struct Map {
	uint8_t numColumns = 0;
	uint8_t numRows = 0;
	Terrain grid[MAX_COLUMNS][MAX_ROWS];
};

const uint8_t MAX_COLUMNS = 32;
const uint8_t MAX_ROWS = 32;