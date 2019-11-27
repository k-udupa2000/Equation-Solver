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
		if (REPL::_type != -1)
			return;

		// Check if the equation contains a mod sign
		//  Check for |ax+b|=cx+d
		if (equations[0].at(0) == '|')
		{
			if (partsOfEquations[0].first.at(partsOfEquations[0].first.length() - 1) == '|')
			{
				REPL::_type = 9;
                partsOfEquations[0].first = partsOfEquations[0].first.substr(1, partsOfEquations[0].first.length()-1);
				return;
			}
		}
		//  Check for ax+b=|cx+d|
		else if (equations[0].at(equations[0].length() - 1) == '|')
		{
			if (partsOfEquations[0].second.at(partsOfEquations[0].second.length() - 1) == '|')
			{
				REPL::_type = 9;
                string temp = partsOfEquations[0].second, temp1 = partsOfEquations[0].first;
                        partsOfEquations[0] = make_pair(temp, temp1);
				return;
			}
		}

		//  Check for purely linear equation format
		temp = REPL::isValidOneVariable(partsOfEquations[0], "x");
		REPL::_type = (temp == 0) ? -1 : (temp == 1) ? 3 : 1;
        if(_type == 1 || _type == 3)
        {
                if(partsOfEquations[0].first.find("x") == string::npos)
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
void run()
{
	cout << "Welcome to the equation solver" << endl;
	cout << "Type in an equation and press enter to get the answer" << endl;
	string inp = "a";
	while (1)
	{
		cout << ">>> ";
		getline(cin, inp);
		if (inp == "exit")
			break;
		REPL a(inp);
		a.detectType();
		cout << ">>> Type: " << a.getType() << endl;
		a.displayAnswer();
	}
}
// Expects string of format ax +/- b or b +/- ax. : Returns <a, b> with correct sign. Includes all cases
// - -  and - + is taken care off.
pair<float, float> getLinEqCoeff(string s)
{
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
    int i1 = s.find('x');
    int i2 = s.find('+');
    int i;
    float a, b;
    int flag = 0;
    vector<int>minus;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '-')
        {
            minus.push_back(i);
        }
    }
    // Set i value to the actual - operator position
    if(minus.size() == 3) i = minus[1];
    else if(minus.size() == 1) i = minus[0];
    else if(minus.size() > 0)
    {
        // 2 equations possible ax - b, b - ax;
        if(minus[0] < i1) i = minus[1];
        else i = minus[0];
    }
    if(i2 != -1)
    {
        i = i2;
    } 
	if(i < i1)
    {
        // equation of the format b +/- ax
        if(i + 1 == i1)
        {
            a = 0;
        }
        else a = stof(s.substr(i + 1, i1));
        b = stof(s.substr(0, i));
        if(i2 == -1)
        {
            a = -a;
            flag = 1;
        }
    }
    else
    {
        // equation of the format ax +/- b
        if(i1 == 0)
        {
            a = 1;
        }
        else a = stof(s.substr(0, i1));
        //cout << i << endl;
        b = stof(s.substr(i + 1, s.size()));
        if(i2 == -1) b = -b;
    }
    if(a == 0)
    {
        if(flag) a = -1;
        else a = 1;
    }
    return make_pair(a, b);
}
void REPL :: displayAnswer()
{
	if(_type == 1)
	{
		pair<float, float> p = getLinEqCoeff(_coefficients[0].first);
		float c = stof(_coefficients[0].second);
		Task1 t(p.first, p.second, c);
		cout << t << endl;
	}
	else if (_type == 2)
	{
		vector<string> equations;
		REPL::split(REPL::_input, ';', equations);
	}
	else if (_type == 3)
	{
		pair<float, float> p1 = getLinEqCoeff(_coefficients[0].first);
		pair<float, float> p2 = getLinEqCoeff(_coefficients[0].second);
		Task3 t(p1.first, p1.second, p2.first, p2.second);
		cout << t << endl;
	}
	else if (_type == 4)
	{
		/* code */
		Task7 t(_input);
		cout << t;
	}
	else if (_type == 7)
	{
		//cout << _coefficients[0].first + _coefficients[0].second << endl;
		Task7 t(_input);
		cout << t;
	}
	else if (_type == 9)
	{
		/* code */
	}
	
	
	
	
}
int main()
{
	run();
}
