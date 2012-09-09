#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef vector<string> vs;

/*
TopCoder Problem - http://community.topcoder.com/stat?c=problem_statement&pm=2913&rd=5849

UserName:

You are implementing the member registration system of an online dating site.
When a new member signs up, it is possible that she initially chooses the same
username as an existing member. The system must then inform the new member of
the conflict and suggest a variant of the chosen name with a number attached
to the end.

If an existing member is named "FunkyMonkey", for example, and a new member
wants the same username, the simplest suggestion the system can make is
"FunkyMonkey1". If there is already a member by that name, the system must
suggest "FunkyMonkey2", unless that variant is also taken. If all names from
"FunkyMonkey1" through "FunkyMonkey9" are taken as well as the original
"FunkyMonkey", the system moves on to consider "FunkyMonkey10", and so on. The
goal is to use the smallest possible number in the variant. Note that each
username consists of letters (the characters from 'a' to 'z' and from 'A' to
'Z') and numerals ('0' to '9').

You are given a String[], existingNames, containing all usernames that have
already been registered in the system. You are also given a single String,
newName, containing the username that a new member wants to use. In the event
of a conflict, this member will accept the suggestion offered by your system
in accordance with the principles above. Return a String containing the
username finally assigned to the new member.

*/

string newMember(vs existingNames, string newName);
string newMemberTwo(vs existingNames, string newName);

int main(int argc, char** argv)
{
	string testOne[] = {"MasterOfDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"};
	string testTwo[] = {"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus", "TygerTyger", "WolfMan", "MrKnowItAll"};
	string testThree[] = {"TygerTyger2000", "TygerTyger1", "MasterDisaster", "DingBat", "Orpheus", "WolfMan", "MrKnowItAll"};
	string testFour[] = {"grokster2", "BrownEyedBoy", "Yoop", "BlueEyedGirl", "grokster", "Elemental", "NightShade", "Grokster1"};
	string testFive[] = {"Bart4", "Bart5", "Bart6", "Bart7", "Bart8", "Bart9", "Bart10",
 						 "Lisa", "Marge", "Homer", "Bart", "Bart1", "Bart2", "Bart3",
 						 "Bart11", "Bart12"};

 	string nameOne = "TygerTyger";
 	string nameTwo = "TygerTyger";
 	string nameThree = "TygerTyger";
 	string nameFour = "grokster";
 	string nameFive = "Bart";

 	string userName = nameFive;
	int size = sizeof(testFive) / sizeof(string);
	vs memberNames(testFive, testFive + size);

	cout << "Member Names:\n";
	for(vs::iterator it = memberNames.begin(); it != memberNames.end(); it++)
	{
		cout << *it << "\n";
	}

	cout << "New User Query: " << userName << "\n";

	string newUserName = newMemberTwo(memberNames, userName);

	cout << "New Username: " << newUserName << "\n";

	return 0;
}

string newMemberTwo(vs existingNames, string newName)
{
	set<string> names(existingNames.begin(), existingNames.end());

	if(names.count(newName) == 0 )
		return newName;

	char testName[1024];
	int currentInt = 1;

	while(1)
	{

		sprintf(testName, "%s%d", newName.c_str(), currentInt);

		if(names.count(testName) == 0)
			return testName;
		else
			currentInt++;
	}
}

string newMember(vs existingNames, string newName)
{

	bool match = true;
	int newSize = newName.size();
	vector<int> numberList;

	for(vs::iterator it = existingNames.begin(); it != existingNames.end(); it++)
	{
		match = true;
		int stringSize = it->size();

		if(stringSize >= newSize)
		{
			for(int i = 0; i < newSize; i++)
			{
				if(it->at(i) != newName[i])
				{
					match = false;
					//cout << "Match not found\n";
					break;
				}
			}

			if(match)
			{
				//FoundString
				//Number at end
				int numberInt;
				if(stringSize == newSize)
				{
					numberInt = 0;
				}
				else
				{
					string number = it->substr(newSize, stringSize-1);
					numberInt = atoi(number.c_str());
				}

				numberList.push_back(numberInt);

				//cout << "Match found - int = " << numberInt << "\n";
			}
		}
		else
		{
			//cout << "Match not found\n";
		}

	}

	if(!numberList.empty())
	{
		sort(numberList.begin(), numberList.end());

		int lowestNumber = 0;
		for(vector<int>::iterator it = numberList.begin(); it != numberList.end(); it++)
		{
			if(*it == lowestNumber)
			{
				lowestNumber++;
			}
			else
			{
				break;
			}
		}

		if(lowestNumber > 0)
		{
			stringstream ss;
			ss << newName << lowestNumber;
			return ss.str();
		}
		else
		{
			return newName;
		}
	}
	else
	{
		return newName;
	}
}
