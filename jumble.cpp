/*
	Created by: Jhon Nunez
	ID: jnunez34
	UIC, CS251

*/

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


string ssort(std::string &s) { //test
	sort(s.begin(),s.end() );
	return s;
}

/*
*   usage:   ./freq <filename>
*
*   example:  ./freq words.txt
*
*/
int main(int argc, char *argv[]) {
	/*
	   the variable word2freq is an unordered_map
		  from strings to integers.
	*/
	unordered_map<string, vector<string> > word2jumble;

	ifstream file;
	string word;
	string wordCopy;
	string key;
    string maxKey;
	int counter = 0;
	int newMax = 0;
	int maxClass = 0;

	if (argc != 2) {
		cout << "usage:  ./freq <filename>\n";
		cout << "goodbye\n";
		return 1;
	}

	/*
	*  argv[1] is a C-string which is the filname specified
	*    by the user.  Let's try to open it.
	*/

	file.open(argv[1], std::ios::in);

	if (!file.is_open()) {
		cout << "Error: could not open file '" <<
			argv[1] << "'\n";
		cout << "goodbye\n";
		return 1;
	}

	cout << "reading input file...\n";

	while (!file.eof()) {

		file >> word;
		wordCopy = word;
		key = ssort(wordCopy); //sort word copy

		if (file.eof()) {//break eof once empty 
			break;
		}

		//add words to list in table 			
		word2jumble[key].push_back(word);
		counter++; //increase counter after every read
		
		newMax = word2jumble[key].size(); //calculate size of Class

		if (newMax > maxClass) {
			maxClass = newMax;
			maxKey = key;
		}
		
	}

	cout << "start entering jumbled words (ctrl-d to terminate) \n" << endl;
	cout << "> ";

	while (cin >> word) {
		
		string searchWord = word;
		string reply = ssort(searchWord); //sort word copy

		auto iter = word2jumble.find(reply);

		if (iter == word2jumble.end() ) {

			cout << "no anagrams found...try again" << endl;

		}
		else {
			cout << "English Anagrams Found: " << endl;
			for (auto x : word2jumble[reply])
				std::cout << "   " << x << endl;

		}
		cout << "> ";

	}
	// user has quit.  Let's dump the map contents

	cout << "REPORT:\n\n";

	cout << "  num_words \t\t:  " << counter << endl;
	cout << "  num_classes \t\t:  " << word2jumble.size() << endl;
	cout << "  size-of-largest-class :  " << maxClass << endl;
	cout << "  largest-class key \t: '" << maxKey << "'" << endl;
	cout << "  members of largest class: \n" << endl;
	for (auto x : word2jumble[maxKey])
		std::cout << "   '" << x << "'" << endl;


	return 0;
}


