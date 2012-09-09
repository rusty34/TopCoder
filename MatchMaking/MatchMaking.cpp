#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<string, string> ps;
typedef vector<string> vs;
typedef vector<ps> vp;

#define ARRAY_SIZE( array ) (sizeof(array) / sizeof(array[0]))

/*

Top Coder Problem - http://community.topcoder.com/stat?c=problem_statement&pm=2911&rd=5849

MatchMaking:

You are developing the matchmaking component of an online dating site.
Prospective members must fill out a questionnaire consisting of binary
questions such as Do you prefer to vacation (a) in the mountains or (b) at the
seaside? and Would you rather travel (a) by plane or (b) by train?

You are to match up men with women by maximizing the number of answers each
couple has in common. A man and a woman have an answer in common whenever they
give the same answer to the same question. Conflicts can easily arise due to
numerical ties, but you will be able to resolve all such conflicts using the
following procedure. Note that there will be equal numbers of men and women,
with names being unique in each sex.

Take the woman whose name comes earliest in lexicographic order, and consider
the men with whom she has the greatest number of answers in common. Among
these men, pick the one whose name comes earliest in lexicographic order. You
have found the woman's best match. Remove this couple from the dating pool,
and repeat the matching procedure until there are no more singles left.

You are given a String[], namesWomen, containing the names of single women,
and another String[], answersWomen, containing their answers. The kth element
of answersWomen lists the answers of the woman whose name is the kth element
of namesWomen. If there are n questions in the questionnaire, then every
element of answersWomen consists of n characters, each of which is either 'a'
or 'b'. The answers are always given in the fixed questionnaire order. You are
similarly given the String[]s namesMen and answersMen for the single men.
Lastly, you are given a String, queryWoman, containing the name of a woman.
Return the name of the man to whom she is matched after you have formed all
couples according to the above rules.

*/

string makeMatch(vs namesWomen, vs answersWomen, vs namesMen, vs answersMen, string queryWoman);

int main(int argc, char** argv)
{
	string womenArray[] = {"Constance", "Bertha", "Alice"};
	string wAnswersArray[] = {"aaba", "baab", "aaaa"};
	string menArray[] = {"Chip", "Biff", "Abe"};
	string mAnswersArray[] = {"bbaa", "baaa", "aaab"};
	string testName = "Bertha";

	//Random tests from TopCoder
	string wArray[] = {"q", "M", "w", "y", "p", "N", "s", "r", "a", "H", "o", "n",
 					   "F", "m", "l", "b", "D", "j", "C", "u", "f", "I", "g", "L",
					   "i", "x", "A", "G", "O", "k", "h", "d", "c", "E", "B", "v",
					   "J", "z", "K", "e", "t"};
	string wAnswers[] = {"aabbaaabb", "baabababb", "bbaababba", "bbbaaaaaa", "abaaaabaa",
						 "bababbbab", "abbaabbaa", "aabababbb", "bababaaaa", "abbababaa",
						 "aabbbbbba", "bbabbabab", "babaabbba", "babbabbbb", "baaabbbbb",
						 "baaabaaaa", "aaabbaaab", "abbaabbbb", "abbabbbab", "bbaaaabba",
						 "babbaaabb", "aabbabbab", "baaababba", "ababaabab", "bbbaabbab",
						 "aaaabbabb", "babaaaaaa", "abbbbaaab", "aabaaabba", "bbbaaaaba",
						 "bbbbbbaab", "aabbaaabb", "aabaabbab", "aababaaba", "bbabbbbab",
						 "abbabaaab", "babaaabbb", "bababbaaa", "aabbaabaa", "baaabbabb",
						 "bbbbbbbbb"};
	string mArray[] = {"m", "k", "n", "q", "L", "E", "M", "l", "w", "x", "g", "e",
					   "i", "z", "F", "r", "a", "h", "f", "D", "J", "K", "j", "v",
					   "A", "t", "N", "y", "s", "c", "o", "p", "d", "b", "B", "G",
					   "O", "I", "u", "C", "H"};
	string mAnswers[] = {"bbaaabbba", "bbaaaaaab", "abaaababb", "baaaabbbb", "abbbababa",
					     "baaaaaaaa", "aabbbbbab", "aaaaabbba", "baabababb", "babaaabab",
						 "baaababaa", "bbbbaabba", "bbaabbabb", "bbaaababb", "abbabbaba",
						 "aababaaab", "abbbbbbaa", "aabbaabaa", "bbbaabbba", "abbabbaba",
						 "aaabbbaaa", "bbaabaaaa", "aabababbb", "abbbbabab", "baaabbbba",
						 "bababbbba", "aababbaab", "bbaabbaab", "bbbaaabbb", "babbbbabb",
						 "ababababb", "babaaabab", "bbaaaaaba", "aaaaabaaa", "abbaaabbb",
						 "bbbbababb", "baabababb", "bbaabaaaa", "aaababbbb", "abbbbbbba",
						 "bbaabbaaa"};
	string testNameTwo = "o";

	/*vs namesWomen(womenArray, womenArray + ARRAY_SIZE(womenArray));
	vs answersWomen(wAnswersArray, wAnswersArray + ARRAY_SIZE(wAnswersArray));
	vs namesMen(menArray, menArray + ARRAY_SIZE(menArray));
	vs answersMen(mAnswersArray, mAnswersArray + ARRAY_SIZE(mAnswersArray));*/

	vs namesWomen(wArray, wArray + ARRAY_SIZE(wArray));
	vs answersWomen(wAnswers, wAnswers + ARRAY_SIZE(wAnswers));
	vs namesMen(mArray, mArray + ARRAY_SIZE(mArray));
	vs answersMen(mAnswers, mAnswers + ARRAY_SIZE(mAnswers));

	cout << "Query Woman: " << testName << "\n";
	string answer = makeMatch(namesWomen, answersWomen, namesMen, answersMen, testNameTwo);
	cout << "Answer: " << answer << "\n";

	return 0;

}


string makeMatch(vs namesWomen, vs answersWomen, vs namesMen, vs answersMen, string queryWoman)
{
	vp women;
	vp men;

	int size = namesWomen.size();

	for(int i = 0; i<size; i++)
	{
		women.push_back(ps(namesWomen[i], answersWomen[i]));
		men.push_back(ps(namesMen[i], answersMen[i]));
	}

	sort(women.begin(), women.end());
	sort(men.begin(), men.end());

	int compatible = 0;
	vp dates;

	for(vp::iterator it = women.begin(); it != women.end(); it++)
	{
		vp::iterator idealMale;
		string wAnswer = it->second;
		compatible = -1;

		for(vp::iterator mit = men.begin(); mit != men.end(); mit++)
		{
			string mAnswer = mit->second;
			int score = 0;
			for(int x = 0; x < wAnswer.length(); x++)
			{
				if(wAnswer[x] == mAnswer[x])
					score++;
			}

			if(score > compatible)
			{
				compatible = score;
				idealMale = mit;
			}
		}

		if(it->first == queryWoman)
			return idealMale->first;

		men.erase(idealMale);
	}

	string noMatch = "NO_MATCH";
	return noMatch;
}
