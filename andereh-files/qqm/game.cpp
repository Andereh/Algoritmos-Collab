#include <fstream>

#include "game.h"


using namespace std;

Game::Game()
{
	string line;
}

string seleccFile()
{
	string filename = "preg/test1.txt";
	fstream file(filename.c_str());
}

