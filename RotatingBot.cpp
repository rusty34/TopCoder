#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define ARRAY_SIZE( array ) (sizeof(array) / sizeof(array[0]))

/*

Top Coder Problem - http://community.topcoder.com/stat?c=problem_statement&pm=12033&rd=15172

We had a rectangular grid that consisted of W x H square cells. We placed a
robot on one of the cells. The robot then followed the rules given below.
- Initially, the robot is facing east.
- The robot moves in steps. 
- In each step it moves to the adjacent cell in the direction it currently faces.
- The robot may not leave the grid.
- The robot may not visit the same cell twice. (This also means that it may not reenter the starting cell.)
- If a step forward does not cause the robot to break the above rules, the robot takes the step.
- Otherwise, the robot rotates 90 degrees to the left (counter-clockwise) and checks whether a step forward still breaks the above rules.
- If not, the robot takes the step and continues executing this program (still rotated in the new direction).
- If the rotation left did not help, the robot terminates the execution of this program.
- We can also terminate the execution of the program manually, at any moment.

We forgot the dimensions of the grid and the original (x,y) coordinates of the
cell on which the robot was originally placed, but we do remember its
movement. You are given a int[] moves. This sequence of positive integers
shall be interpreted as follows: The robot performed moves[0] steps eastwards,
turned left, performed moves[1] steps northwards, turned left, and so on.
After performing the last sequence of steps, the robot stopped. (Either it
detected that it should terminate, or we stopped it manually.) We are not sure
if the sequence of moves is valid. If the sequence of moves is impossible,
return -1. Else, return the minimum area of a grid in which the sequence of
moves is possible. (I.e., the return value is the smallest possible value of
the product of W and H.).

*/

int minArea(vi moves);
bool isValid(vi moves, int height, int width);
int findArea(vi moves, int &height, int &width);

int main(int argc, char** argv)
{

	int testZero[] = {15};
	int testOne[] = {3,10};
	int testTwo[] = {1,1,1,1};
	int testThree[] = {9,5,11,10,11,4,10};
	int testFour[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
	int testFive[] = {8,6,6,1};
	int testSix[] = {8,6,6};
	int testSeven[] = {5,4,5,3,3};

	int testCount = 8;

	vi test;
	int area = 0;

	for(int i = 0; i < testCount; i++)
	{
		switch(i)
		{
			case 0:
				test.assign(testZero, testZero + ARRAY_SIZE(testZero));
				break;
			case 1:
				test.assign(testOne, testOne + ARRAY_SIZE(testOne));
				break;
			case 2:
				test.assign(testTwo, testTwo + ARRAY_SIZE(testTwo));
				break;
			case 3:
				test.assign(testThree, testThree + ARRAY_SIZE(testThree));
				break;
			case 4:
				test.assign(testFour, testFour + ARRAY_SIZE(testFour));
				break;
			case 5:
				test.assign(testFive, testFive + ARRAY_SIZE(testFive));
				break;
			case 6:
				test.assign(testSix, testSix + ARRAY_SIZE(testSix));
				break;
			case 7:
				test.assign(testSeven, testSeven + ARRAY_SIZE(testSeven));
				break;
			default:
				break;
		}

		area = minArea(test);
		cout << "Test " << i << " - Area = " << area << "\n";

		test.clear();
	}

	/*test.assign(testTwo, testTwo + ARRAY_SIZE(testTwo));
	area = minArea(test);
	cout << "Area: " << area << "\n";*/

	return 0;
}

int minArea(vi moves)
{

	int height = 1;
	int width = 1;

	int area = findArea(moves, height, width);

	//cout << "Width: " << width << " Height: " << height << "\n";

	if(isValid(moves, height, width))
		return area;
	else
		return -1;
}

bool isValid(vi moves, int height, int width)
{

	bool* grid = new bool[width * height];

	//fill(grid, grid + ARRAY_SIZE(grid), false);

	for(int x = 0; x < width * height; x++)
	{
		grid[x] = false;
	}

	/*for(int x = 0; x < width * height; x++)
	{
		if(grid[x])
			cout << "grid[" << x << "] is true\n";
	}
	cout << "finished printing\n";*/

	bool valid = true;

	int size = moves.size();

	int x = 0;
	int y = 0;

	/*for(vi::iterator it = moves.begin(); it != moves.end(); it++)
	{
		cout << *it << "\n";
	}*/

	if(size > 1)
	{
		x = width - (moves[0] + 1);
		y = moves[1];
		//cout << "Start x: " << x << " Start y: " << y << "\n";
		//grid[y * width + x] = true;
	}
	else
	{
		delete[] grid;
		return valid;
	}

	int sign = 1;
	int i = 0;

	int xLength = moves[0] + 1;
	int yLength = height - (moves[1] + 1);

	while(i < size && valid)
	{
		int side = i % 4;

		switch(side)
		{
			case 0:
				sign = 1;
				if(i >= 3 && moves[i-1] < yLength)
					valid = false;
				break;
			case 1:
				sign = -1;
				if(i >= 3 && moves[i-1] < xLength)
					valid = false;
				break;
			case 2:
				sign = -1;
				if(i >= 3 && moves[i-1] < yLength)
					valid = false;
				break;
			case 3:
				sign = 1;
				if(i >= 3 && moves[i-1] < xLength)
					valid = false;
				break;
			default:
				break;
		}

		int j = 0;
		int currX = 0;
		int currY = 0;

		while(j < moves[i] && valid)
		{
			if(x < 0 || x >= width || y < 0 || y >= height)
			{
				valid = false;
				break;
			}

			switch(side)
			{
				case 1:
				case 3:
					currY = y + j * sign;
					if(currY < 0 || currY >= height || grid[(currY + sign) * width + x])
					{
						//cout << "Fail at - x: " << x << " y: " << currY << " i: " << i << "\n";
						valid = false;
						break;
					}
					else
					{
						//cout << "x: " << x << " y: " << currY << "\n";
						grid[currY * width + x] = true;
					}

					break;
				case 0:
				case 2:
					currX = x + j * sign;
					if(currX < 0 || currX >= width || grid[y * width + currX + sign])
					{
						//cout << "Fail at - x: " << currX << " y: " << y << " i: " << i << "\n";
						valid = false;
						break;
					}
					else
					{
						//cout << "x: " << currX << " y: " << y << "\n";
						grid[y * width + currX] = true;
					}

					break;
				default:
					break;
			}

			j++;
		}

		switch(side)
		{
			case 0:
			case 2:
				x += moves[i] * sign;
				if(i >= 2)
					xLength--;
				break;
			case 1:
			case 3:
				y += moves[i] * sign;
				if(i >= 3)
					yLength--;

				if(i == 3)
					xLength = moves[i];
				break;
			default:
				break;
		}

		//cout << "Turn left\n";

		/*if(!valid)
			cout << "Fail on " << i << "\n";*/

		i++;
	}

	delete[] grid;
	return valid;

}

int findArea(vi moves, int &height, int &width)
{
	int startTest = moves.size();

	if(startTest >= 4)
		startTest = 4;

	for(int i = 0; i < startTest; i++)
	{
		int side = i % 4;

		switch(side)
		{
			case 0:
			case 2:
				if(moves[i] + 1 > width)
					width = moves[i] + 1;

				break;
			case 1:
			case 3:
				if(moves[i] + 1 > height)
					height = moves[i] + 1;

				break;
			default:
				break;
		} 
	}

	return height * width;

}