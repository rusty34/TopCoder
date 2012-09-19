#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<string> vs;

#define ARRAY_SIZE( array ) (sizeof(array) / sizeof(array[0]))

/*

Top Coder Problem - http://community.topcoder.com/stat?c=problem_statement&pm=11494&rd=15172

Ralph was once playing with a set of cards and a grid of cells. Each card was
a rectangle of a unique color. Different cards may have had different
dimensions. Ralph took his cards one at a time, and placed each of them onto
the grid. When placing a card, Ralph aligned its sides with grid lines, so
each card covered some rectangular block of cells. Some cards may have
overlapped other, previously placed cards partially or even completely. Once
all the cards were placed, on each cell only the topmost card was visible. You
are given a String[] grid that describes what Ralph could see after placing
the cards. The j-th character of element i of grid is '.' if the cell at
position (i,j) is empty (does not contain any card) or is an alphanumeric
character that represents the only color Ralph could see when looking at the
cell.

Ralph does not remember the order he used to place the cards. Write a program
that finds the order in which the cards of each visible color were placed. The
return value should be a String, containing exactly once each of the
alphanumeric characters that occur in grid. The i-th character of the return
value should be the color of the i-th card (0-based index) that Ralph placed.
In case there are multiple valid orders, return the lexicographically smallest
one. In case there is no valid order of colors, return "ERROR!" (quotes for
clarity).

*/

string findOrder(vs grid);

int main(int argc, char** argv)
{
	string gridArray[] = {"..AA..", ".CAAC.", ".CAAC."};

	vs testGrid(gridArray, gridArray + ARRAY_SIZE(gridArray));

	string order = findOrder(testGrid);

	cout << order << "\n";

	return 0;
}

string findOrder(vs grid)
{

	int width = grid[0].length();
	int height = grid.size();

	char* gridArray = new char[width * height];

	int j = 0;

	for(vs::iterator it = grid.begin(); it != grid.end(); it++)
	{
		for(int i = 0; i < it->length(); i++)
		{
			gridArray[j * width + i] = it->at(i);
		}
		j++;
	}


	return grid[0];
}