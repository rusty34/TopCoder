#include <string>
#include <iostream>

using namespace std;

/*

Top Coder Problem - http://community.topcoder.com/stat?c=problem_statement&pm=12125&rd=15172

EasyConversionMachine:

We have a String originalWord. Each character of originalWord is either 'a' or
'b'. Timmy claims that he can convert it to finalWord using exactly k moves.
In each move, he can either change a single 'a' to a 'b', or change a single
'b' to an 'a'.

You are given the Strings originalWord and finalWord, and the int k. Determine
whether Timmy may be telling the truth. If there is a possible sequence of
exactly k moves that will turn originalWord into finalWord, return "POSSIBLE"
(quotes for clarity). Otherwise, return "IMPOSSIBLE".

*/

string isItPossible(string originalWord, string finalWord, int k);

int main(int argc, char** argv)
{

	string oWord[] = {"aababba", "aabb", "aaaaabaa", "aaa", "aababbabaa"};
	string fWord[] = {"bbbbbbb", "aabb", "bbbbbabb", "bab", "abbbbaabab"};
	int steps[] = {2, 1, 8, 4, 9};
	int tests = 5;

	for(int i = 0; i < tests; i++)
	{
		string result = isItPossible(oWord[i], fWord[i], steps[i]);
		cout << result << "\n";
	}

	return 0;
}


string isItPossible(string originalWord, string finalWord, int k)
{
	int size = originalWord.length();
	int sameLetters = 0;

	string possible = "POSSIBLE";
	string impossible = "IMPOSSIBLE";

	for(int i=0; i < size; i++)
	{
		if(originalWord[i] == finalWord[i])
			sameLetters++;
	}

	int differentLetters = size - sameLetters;

	if(differentLetters > k)
		return impossible;
	else if((k - differentLetters) % 2 == 0)
		return possible;
	else
		return impossible;

}