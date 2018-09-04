#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main() {
	bool check1, check2, check4, check8;
	ifstream fin;
	ofstream fout;
	fin.open("numbers.txt");
	fout.open("answer.txt");
	string number;
	fin >> number;
	number.erase(0, 3);
	do
	{
		check1 = false;
		check2 = false;
		check4 = false;
		check8 = false;

		//Check1
		for (int i = 0; i < number.length(); i++)
		{
			if (i % 2 == 0)
			{
				if (number[i] == '1') { 
					check1 = !check1; 
				}
			}
		}

		//Check2
		for (int i = 0; i < number.length(); i++)
		{
			if ((i > 0 && i < 3) || (i > 4 && i < 7) || (i > 8 && i < 11))
			{
				if (number[i] == '1') { 
					check2 = !check2; 
				}
			}
		}

		//Check4
		for (int i = 0; i < number.length(); i++)
		{
			if ((i > 2 && i < 7) || i == 11)
			{
				if (number[i] == '1') { 
					check4 = !check4;
				}
			}
		}

		//Check8
		for (int i = 0; i < number.length(); i++)
		{
			if (i > 6) { 
				if (number[i] == '1') {
					check8 = !check8;
				}
			}
		}

		int whichToChange = 0;
		if (check1) { whichToChange += 1; }
		if (check2) { whichToChange += 2; }
		if (check4) { whichToChange += 4; }
		if (check8) { whichToChange += 8; }
		//whichToChange--;
		if (whichToChange != 0) {
			number[whichToChange - 1] == '1' ? number[whichToChange - 1] = '0' : number[whichToChange - 1] = '1';
		}
		string part1 = number.substr(2, 1);
		string part2 = number.substr(4, 3);
		string part3 = number.substr(8, 4);
		string answer = part1 + part2 + part3;
		cout << answer << endl;
		long numberAnswer = stoi(answer, 0, 2);
		cout << numberAnswer << endl; 
		cout << (char)numberAnswer << endl;
		fout << (char)numberAnswer;
	} while (fin >> number);
	system("pause");
}