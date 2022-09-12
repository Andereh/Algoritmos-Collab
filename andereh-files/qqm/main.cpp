#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	string filename = "preg/test1.txt";
	string line;
	fstream file(filename.c_str());
	int prevIndex = 0;
	int index;

	char symbol = 'A';
	string user_ans;

	while (getline(file, line)) {

		string res;

		if (line.length() == 0) continue;

		switch (line.at(0)) {
		case '&':
			cout << line.substr(1);
			break;
		case '#':
			cout << " " << symbol++ << ") " << line.substr(1);
			break;
		case '!':
			res = line.at(1);
			cout << "\n Elije tu respuesta: ";
			cin >> user_ans;

			if (user_ans == res)
				cout << " La pegaste mi pana\n";
			break;
		}
		cout << "\n";
	}
	return 0;
}


