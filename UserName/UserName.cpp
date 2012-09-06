#include <vector>
#include <string>

using namespace std;

typedef vector<string> vs;

class UserName
{
public:

	string newMember(vs existingNames, string newName)
	{

		bool match = true;
		int newSize = newName.size();

		for(vs::iterator it = existingNames.begin(); it != existingNames.end(); it++)
		{
			int i = 0;
			match = true;
			int sizeOne = it.size();

			if(sizeOne >= newSize)
			{
				while(match && i < newSize)
				{
					if(it[i] == newName[i])
					{
						//Matching
						i++;
					}
					else
					{
						match = false;
					}

					if(i+1 == newName.length())
					{
						//FoundString
						//Number at end
						string number = it.substr(i-1, newName.length()-i+1);


					}
				}
			}
		}

	}
};