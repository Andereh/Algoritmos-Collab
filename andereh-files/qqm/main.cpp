#include <iostream>
#include <fstream>

#define cls system("clear")

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
	string res;
	int count = 1;

	while (getline(file, line)) {


		if (line.length() == 0) continue;

		switch (line.at(0)) {
		case '&':
			cls;
			cout << " " << count++ << ". " << line.substr(1) << '\n';
			break;
		case '.':
			res = symbol;
		case '#':
			cout << " " << symbol++ << ": " << line.substr(1);
			break;
		}

		if (symbol > 'D')
		{
			cout << "\n\n Elije tu respuesta: ";
			cin >> user_ans;

			while (user_ans.length() > 1)
			{
				cout << " Introduce solo un caracter\n";
				cout << " Elije tu respuesta: ";
				cin >> user_ans;
			}

			if (user_ans[0] - 32 == res[0] || user_ans[0] == res[0])
				cout << " La pegaste mi pana\n";
			else 
			{
				cout << " Perdiste vale\n";
				return 0;
			}

			symbol = 'A';
		}
		cout << "\n";
	}
	return 0;
}


