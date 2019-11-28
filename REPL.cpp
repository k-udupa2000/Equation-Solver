#include "REPL.h"

REPL::REPL() : _type(0), _input(""), _coefficients() {}

REPL::REPL(std::string input) : _input(input), _type(-1), _coefficients() {}

REPL::REPL(const REPL &r)
	: _type(r.REPL::_type), _coefficients(r._coefficients), _input(r._input) {}

REPL::~REPL() {}

// This function just finds a rough REPL::_type without really validating the other parameters that much
void REPL::detectType()
{
	// initialize to failure condition
	REPL::_type = -1;

	//  Initialize the necessary vectors and pairs
	pair<string, string> lhs_rhs;
	vector<string> equations;
	vector<pair<string, string>> partsOfEquations;

	//  Declare the necessary iterators
	vector<string>::iterator equationIterator;

	//  Find the number of equations involved
	REPL::split(REPL::_input, ';', equations);

	//  Check whether we have the right number of equations
	if (equations.size() > 2)
		return;

	//  Split the equation into smaller fragments, namely the LHS and the RHS
	for (equationIterator = equations.begin(); equationIterator != equations.end(); equationIterator++)
	{
		vector<string> temp;
		REPL::split(*equationIterator, '=', temp);
		if (temp.size() > 2)
			return;

		partsOfEquations.push_back(make_pair(temp[0], temp[1]));
	}

	//  If there are two equations
	if (equations.size() == 2)
	{
		//	There must be no z component in the equations
		if (partsOfEquations[0].first.find("z") != string::npos || partsOfEquations[0].second.find("z") != string::npos)
			return;

		if (partsOfEquations[1].first.find("z") != string::npos || partsOfEquations[1].second.find("z") != string::npos)
			return;

		REPL::_type = REPL::isValidTwoVariable(partsOfEquations, "x", "y");
	}
	//  If there is only one equation
	else
	{
		//  Linear equations can't have y or z terms at all
		if (partsOfEquations[0].first.find("z") != string::npos || partsOfEquations[0].second.find("z") != string::npos)
			return;

		if (partsOfEquations[0].first.find("y") != string::npos || partsOfEquations[0].second.find("y") != string::npos)
			return;

		//  First check if there are any exponents
		int temp = REPL::isValidOneVariable(partsOfEquations[0], "^");
		REPL::_type = (temp == 0) ? -1 : (temp == 1) ? 7 : 4;
		if (REPL::_type == 4)
		{
			REPL::setCoeff(partsOfEquations);
			int x = equations[0].find('x');
			int expo = equations[0].find('^');
			if (x > expo)
				REPL::_type = 7;
			return;
		}
		else if (REPL::_type == 7)
		{
			REPL::setCoeff(partsOfEquations);
			return;
		}

		// Check if the equation contains a mod sign
		//  Check for |ax+b|=cx+d
		if (equations[0].at(0) == '|')
		{
			if (partsOfEquations[0].first.at(partsOfEquations[0].first.length() - 1) == '|')
			{
				REPL::_type = 9;
				partsOfEquations[0].first = partsOfEquations[0].first.substr(1, partsOfEquations[0].first.length() - 2);
				REPL::setCoeff(partsOfEquations);
				return;
			}
			else
			{
				_type = -1;
				return;
			}
		}

		//  Check for ax+b=|cx+d|
		else if (equations[0].at(equations[0].length() - 1) == '|')
		{
			if (partsOfEquations[0].second.at(0) == '|')
			{
				REPL::_type = 9;
				string temp = partsOfEquations[0].second.substr(1, partsOfEquations[0].second.length() - 2), temp1 = partsOfEquations[0].first;
				partsOfEquations[0] = make_pair(temp, temp1);
				REPL::setCoeff(partsOfEquations);
				return;
			}
			else
			{
				_type = -1;
				return;
			}
		}

		//  Check for purely linear equation format
		temp = REPL::isValidOneVariable(partsOfEquations[0], "x");
		REPL::_type = (temp == 0) ? -1 : (temp == 1) ? 3 : 1;
		if (_type == 1 || _type == 3)
		{
			if (partsOfEquations[0].first.find("x") == string::npos)
			{
				string temp = partsOfEquations[0].second, temp1 = partsOfEquations[0].first;
				partsOfEquations[0] = make_pair(temp, temp1);
			}
		}
	}
	REPL::setCoeff(partsOfEquations);
}

int REPL::getType() const
{
	return REPL::_type;
}

void REPL::setCoeff(vector<pair<string, string>> split)
{
	REPL::_coefficients = split;
}

vector<pair<string, string>> REPL::getCoeff() const
{
	return REPL::_coefficients;
}

//	Just run this function
//	Currently only gives the type number of the function
void REPL::run()
{
	cout << "Welcome to the equation solver" << endl;
	cout << "Type in an equation and press enter to get the answer" << endl;
	cout << "Type \"exit\" to exit the REPL" << endl;
	string inp = "a";
	while (1)
	{
		cout << ">>> ";
		getline(cin, inp);
		inp.erase(remove(inp.begin(), inp.end(), ' '), inp.end());
		if (inp == "exit")
		{
			cout << "Exit" << endl;
			break;
		}
		else if(inp == "")
			continue;
		REPL a(inp);
		a.detectType();
		// cout << ">>> Type: " << a.getType() << endl;
		if (a.getType() != -1)
			cout << ">>> ";
		a.displayAnswer();
	}
}
// Expects string of format ax +/- b or b +/- ax. : Returns <a, b> with correct sign. Includes all cases
// - -  and - + is taken care off.
pair<float, float> getLinEqCoeff(string s)
{
	try
	{
		if (s.find('x') == string ::npos)
		{
			return make_pair(0, stof(s));
		}
		int i1 = s.find('x');
		int i2 = s.find('+');
		if (i1 == 0)
		{
			s = "1" + s;
		}
		if (s[i1 - 1] > 57 || s[i1 - 1] < 48)
		{
			string temp = s.substr(0, i1) + "1";
			temp += s.substr(i1, s.size());
			s = temp;
			i1++;
			i2 = s.find('+');
		}

		int i;
		float a, b;
		vector<int> minus;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '-')
			{
				minus.push_back(i);
			}
		}
		// Only x (b = 0). Returns value when b is not present.
		if (s.find('+') == string ::npos)
		{
			if (s.find('-') == string ::npos)
			{
				if (i1 == 0)
				{
					return make_pair(1, 0);
				}
				return make_pair(stof(s.substr(0, i1)), 0);
			}
			else if (minus.size() == 1)
			{
				if (minus[0] == 0)
				{
					return make_pair(stof(s.substr(0, i1)), 0);
				}
			}
		}

		// Set i value to the actual - operator position
		if (minus.size() == 3)
			i = minus[1];
		else if (minus.size() == 1)
			i = minus[0];
		else if (minus.size() > 0)
		{
			// 2 equations possible ax - b, b - ax;
			if (minus[0] < i1)
				i = minus[1];
			else
				i = minus[0];
		}
		if (i2 != -1)
		{
			i = i2;
		}
		if (i < i1)
		{
			// b +/- ax
			a = stof(s.substr(i + 1, i1));
			b = stof(s.substr(0, i));
			if (i2 == -1)
			{
				a = -a;
			}
		}
		else
		{
			// equation of the format ax +/- b
			a = stof(s.substr(0, i1));
			b = stof(s.substr(i + 1, s.size()));
			if (i2 == -1)
				b = -b;
		}
		return make_pair(a, b);
	}
	catch (const out_of_range &oor)
	{
		cout << "The entered number exceeded the inner limits. Error: " << oor.what() << endl;
	}
	catch (const std::invalid_argument &ia)
	{
		cout << "Invalid inputs! Please check your input format! Error: " << ia.what() << endl;
	}
}

void REPL ::displayAnswer()
{
	Solver *t;
	if (_type == 1)
	{
		pair<float, float> p = getLinEqCoeff(_coefficients[0].first);
		float c;
		try
		{
			c = stof(_coefficients[0].second);
		}
		catch (const out_of_range &oor)
		{
			cout << "The entered number exceeded the inner limits. Error: " << oor.what() << endl;
		}
		catch (const std::invalid_argument &ia)
		{
			cout << "Invalid inputs! Please check your input format! Error: " << ia.what() << endl;
		}

		t = new Task1(p.first, p.second, c);
	}
	else if (_type == 2)
	{
		vector<string> equations;
		REPL::split(REPL::_input, ';', equations);
		t = new Task2(equations[0], equations[1]);
	}
	else if (_type == 3)
	{
		pair<float, float> p1 = getLinEqCoeff(_coefficients[0].first);
		pair<float, float> p2 = getLinEqCoeff(_coefficients[0].second);
		t = new Task3(p1.first, p1.second, p2.first, p2.second);
	}
	else if (_type == 4)
	{
		t = new Task4(_coefficients[0].first);
	}
	else if (_type == 7)
	{
		t = new Task7(_input);
	}
	else if (_type == 9)
	{
		pair<float, float> p1 = getLinEqCoeff(_coefficients[0].first);
		pair<float, float> p2 = getLinEqCoeff(_coefficients[0].second);
		t = new Task9(p1.first, p1.second, p2.first, p2.second);
	}

	if (_type == -1)
	{
		cout << "Equation type not found" << endl;
	}
	else
	{
		t->print();
	}
}