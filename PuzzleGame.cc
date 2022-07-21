// Puzzle game
//Generates a random maze of increasing dificulty. The objective is getting from start to finish (obv)

#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matrix;

const int width = 40;
const int height = 12; 		// Dimensions of maze 

Matrix Maze(height, vector<char>(width, ' '));

bool ExitGame;

bool EndReached;



int blocks = 7;						// # of obstacles on each maze

int PlayerX, PlayerY;				// Position of player

int GoalX, GoalY;					// Position of goal

enum Moves {STOP = 0, LEFT, RIGHT, UP, DOWN}; // Controls

Moves dir;

void Setup() {

	ExitGame = false;

	dir = STOP;

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i == 0 or i == height - 1 or j == 0 or j == width - 1) Maze[i][j] = '#';
		}
	}
}

bool BFS_Maze_Check(int i, int j) {
	if (Maze[i][j] == 'O') return true;

	else if ((Maze[i+1][j] == '#' or Maze[i+1][j] == 'x') and (Maze[i-1][j] == '#' or Maze[i-1][j] == 'x') and
		(Maze[i][j+1] == '#' or Maze[i][j+1] == 'x') and (Maze[i][j-1] == '#' or Maze[i][j-1] == 'x')) {
		Maze[i][j] = 'x';
		return false;
		}

	else {
		Maze[i][j] = 'x';
		if ((i + 1 <= 11) and Maze[i+1][j] != 'x' and Maze[i+1][j] != '#' and BFS_Maze_Check(i+1, j)) return true;
		else if ((i - 1 >= 1) and Maze[i-1][j] != 'x' and Maze[i-1][j] != '#' and BFS_Maze_Check(i-1, j)) return true;
		else if ((j + 1 <= 39) and Maze[i][j+1] != 'x' and Maze[i][j+1] != '#' and BFS_Maze_Check(i, j+1)) return true;
		else if ((i - 1 >= 1) and Maze[i][j-1] != 'x' and Maze[i][j-1] != '#' and BFS_Maze_Check(i, j-1)) return true;
		else return false;
	}
}

void CleanMazeX() {
	for (int i = 1; i < height - 1; ++i) {
		for (int j = 1; j < width - 1; ++j) {
			if (Maze[i][j] == 'x' or Maze[i][j] == '*') Maze[i][j] = ' ';
		}
	}
}

void CleanMazeP() {
	for (int i = 1; i < height - 1; ++i) {
		for (int j = 1; j < width - 1; ++j) {
			if (Maze[i][j] == '#') Maze[i][j] = ' ';
		}
	}
}

void GenerateMaze() {			// Creación del laberinto

	srand((unsigned) time(0));

	PlayerX = rand() % 10 + 1;
	PlayerY = rand() % 38 + 1;


	GoalX = rand() % 10 + 1;
	GoalY = rand() % 38 + 1;

	while ((PlayerX == GoalX and PlayerY == GoalY)) {
		GoalX = rand() % 10 + 1;
		GoalY = rand() % 38 + 1;
	}

	Maze[PlayerX][PlayerY] = '*';
	Maze[GoalX][GoalY] = 'O';

	EndReached = false;
	bool possible = false;

	while (not possible) {
		for (int i = 0; i < blocks; ++i) {		
			int x = rand() % 10 + 1;
			int y = rand() % 38 + 1;
			while ((x == GoalX and y == GoalY) or (x == PlayerX and y == PlayerY)) {
				x = rand() % 10 + 1;
				y = rand() % 38 + 1;
			}
			Maze[x][y] = '#';
		}
		possible = BFS_Maze_Check(PlayerX, PlayerY);
		CleanMazeX();
		if (not possible) CleanMazeP();
		Maze[PlayerX][PlayerY] = '*';
	}
}

void PrintMaze() {

	system("clear");

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			cout << Maze[i][j];
		}
		cout << endl;
	}
}

void Inputs() {

	char move;
	move = getchar();

	switch (move) {
		case 'a':
		 dir = LEFT;
		 break;
		case 'd':
		 dir = RIGHT;
		 break;
		case 'w':
		 dir = UP;
		 break;
		case 's':
		 dir = DOWN;
		 break;
		case 'x':
		 ExitGame = true;
		 break;
	}

}

void Checks() {
	switch (dir) {
		case UP:
			if (Maze[PlayerX - 1][PlayerY] != '#') {
				Maze[PlayerX - 1][PlayerY] = '*';
				Maze[PlayerX][PlayerY] = ' ';
				--PlayerX;
			}
			break;
		case DOWN:
			if (Maze[PlayerX + 1][PlayerY] != '#') {
				Maze[PlayerX + 1][PlayerY] = '*';
				Maze[PlayerX][PlayerY] = ' ';
				++PlayerX;
			}
			break;
		case LEFT:
			if (Maze[PlayerX][PlayerY - 1] != '#') {
				Maze[PlayerX][PlayerY - 1] = '*';
				Maze[PlayerX][PlayerY] = ' ';
				--PlayerY;
			}
			break;
		case RIGHT:
			if (Maze[PlayerX][PlayerY + 1] != '#') {
				Maze[PlayerX][PlayerY + 1] = '*';
				Maze[PlayerX][PlayerY] = ' ';
				++PlayerY;
			}
			break;
	}

	if (PlayerX == GoalX and PlayerY == GoalY) EndReached = true;
}


int main() {
	Setup();

	while (not ExitGame) {		// General loop used to check if a new maze should be created							
		GenerateMaze();
		while (not EndReached and not ExitGame) {	// Internal loop that draws the map everytime new move is done and the player hasn't reached the goal

			PrintMaze();

			Inputs();

			Checks();
		}
	}
}