#include<cmath>
#include <cstdlib>
#include"Task4.h" 
Task4::Task4(){}
Task4::Task4(string s1):str(s1){};
double Task4::geta(){return a;}
double Task4::getb(){return b;}
double Task4::getc(){return c;}
void Task4::parse(string str)
{
    int strSize = str.size();
	int k = 1;
	for(int i = 1; i < strSize; ++i)
		if(str[i] == '+' || str[i] == '-')
			k++;
 	int n_terms = k ;
 	
    if(isdigit(str[0])) str.insert(0, "+");
	if(str[0] == 'x') str.insert(0, "+");
	str.append("+");
	strSize = str.size();
	
	//dividing each term
	
	k = 0;
	int j = 0;
	std::string terms[3];
	for(int i = 1; i < strSize; ++i)
    {
		if(str[i] == '+' || str[i] == '-')
		{
			terms[k++] = str.substr(j, i -j);
			j = i;
		}
    }

	//storing in ax^2+bx^1+cx^0 format

	for(int i = 0; i < n_terms; ++i)
	{
		if(terms[i][1] == 'x')	 
			terms[i].insert(1, "1");	
        bool flag = false;	
		int len = terms[i].size();
		for(int j = 1; j < len; ++j)
			if(terms[i][j] == 'x')	
			{
				flag = true;	
				if(j == len - 1)	 
					terms[i].append("^1");	
				break;	
			}
		if(!flag)	
			terms[i].append("x^0");	
	}

	//coefficients extraction
	
	for(int i = 0; i < n_terms; ++i)
	{
		int termsize = terms[i].size();
		for(int j = 0; j < termsize; ++j)
		{
			if(terms[i][j] == '^')
			{
                if(terms[i][j+1] == '0')
                {
                    c=stod(terms[i].substr(0, j));
                }
                else if(terms[i][j+1] == '1')
                {
                    b=stod(terms[i].substr(0, j));
                }
                else if(terms[i][j+1] == '2')
                {
                    a=stod(terms[i].substr(0, j));
                }
				break;
			}
		}	
	}
   
}

//plus and minus returns solution

/*double Task4::plus()
{
    return ((-b/(2*a))+((sqrt((b*b)-(4*a*c)))/(2*a)));
}

double Task4::minus () 
{
    return ((-b/(2*a))-((sqrt((b*b)-(4*a*c)))/(2*a)));
}*/

vector<double> Task4::solve()
{
	vector<double> roots;
	roots.push_back((-b/(2*a))+((sqrt((b*b)-(4*a*c)))/(2*a)));
	roots.push_back((-b/(2*a))-((sqrt((b*b)-(4*a*c)))/(2*a)));
	return roots;
}
    

//checking whether solution exists or not

int Task4::find_d(double a,double b,double c)
{
    double qwe=(b*b)-(4*a*c);   
    if(qwe<0)
    {
        return 0;
    }
    return 1;
}
