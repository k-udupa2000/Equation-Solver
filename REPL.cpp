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
	REPL::setCoeff(partsOfEquations);



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
		if (REPL::_type != -1)
			return;

		// Check if the equation contains a mod sign
		//  Check for |ax+b|=cx+d
		if (equations[0].at(0) == '|')
		{
			if (partsOfEquations[0].first.at(partsOfEquations[0].first.length() - 1) == '|')
			{
				REPL::_type = 9;
				return;
			}
		}
		//  Check for ax+b=|cx+d|
		else if (equations[0].at(equations[0].length() - 1) == '|')
		{
			if (partsOfEquations[0].second.at(partsOfEquations[0].second.length() - 1) == '|')
			{
				REPL::_type = 9;
				return;
			}
		}

		//  Check for purely linear equation format
		temp = REPL::isValidOneVariable(partsOfEquations[0], "x");
		REPL::_type = (temp == 0) ? -1 : (temp == 1) ? 3 : 1;
	}
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
void run()
{
	cout << "Welcome to the equation solver" << endl;
	cout << "Type in an equation and press enter to get the answer" << endl;
	string inp = "a";
	while (1)
	{
		cout << ">>> ";
		cin >> inp;
		if (inp == "exit")
			break;
		REPL a(inp);
		a.detectType();
		cout << ">>> Type: " << a.getType() << endl;
	}
}

int main()
{
	run();
}
