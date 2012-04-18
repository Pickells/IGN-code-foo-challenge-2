// This is a program that will generate the best plate patteren needed for a population that will produce the minnimum number of excess plate 
// This program is made by : Abdullah Alhasan 
// for IGN Code Foo 
//#include "stdio"
#include "iomanip"
#include "cmath"
#include "iostream"

using namespace std;

int combonator ( double ca , double cb ,double temp );

int main()
{
	double inp , b=10 , a=26 , countera=1 , counterb=1;
	double bestn , bestb , besta , bestex;
	double ca , cb , temp=0 , total , com=0;
	char flag = 'y';

	cout <<"\nThis Program generates the best plate pattern needed to be used for a population\nand the";
	cout << " program will choose the pattern that will produce the minnimum number of\nexcess plates\n";
	cout << "\nexample : if the population was 519\nthe program will print :\n\nPopulation: 519\nPattern : 1 letter and 1 number";
	cout << "\nTotal plates : 520\nExcess plates : 1\n\nhow did i get 520 ?\n1 letter is 26 so there is 26 letters for each number";
	cout << ", so 26x10=260 for the\nnumber of plates for a letter and a number but\nthe letter can be first or last so we multiply 260x2=520 to get the total result\n";

	while ( flag == 'y' )
	{
		b=10;
		a=26;
		countera=1;
		counterb=1;
		temp=0;
		com=0;
	
		cout << "enter population :";
	
		cin >> inp;
	
		while ( b < inp )
		{
			b = b*10;
			counterb++;
		}
	
		bestn = b;
		bestb = counterb;
		besta = 0;
		bestex = b-inp;
	
		while ( a < inp )
		{
			a = a*26;
			countera++;
		}
		
		if ( bestex > ( a-inp ) )
		{
			bestn = a;
			besta = countera;
			bestb = 0;
			bestex = a-inp;
		}
	
		for ( ca = 1 ; ca < countera && bestex != 0 ; ca++ )
		{
			temp = pow(26.0,ca);
			for ( cb = 1 ; cb < counterb && temp <= bestn && bestex != 0 ; cb++ )	
			{
				total = ca + cb;
	
				temp = pow(26.0,ca) * pow(10.0,cb);
				if ( temp < bestn )
				{
					if ( ca == 1 || cb == 1 )
						temp = temp*total;
					else if ( ca == 2 || cb == 2 )	
					{
						com = 0;
						for ( int t = total-1 ; t != 0 ; t-- )
							com = com + t;
						temp = temp * com;
					}
		
					else
						if ( temp < bestn )
							temp =temp * combonator ( ca , cb , temp );
	
					if ( (temp - inp) == 0 )
					{
						bestn = temp;
						besta = ca;
						bestb = cb;
						bestex = 0;
					}
					else if ( temp > inp && temp < bestn )
					{
						bestn = temp;
						besta = ca;
						bestb = cb;
						bestex = temp - inp;
					}
				}
			}
		}
		cout << "\n\nPopulation :        " << fixed << setprecision(0) <<  inp << "\nPattern :           ";
		if ( bestb == 0 )
			cout << besta << " letter/s " ;
		else if ( besta == 0 )
			cout << bestb << " number/s" ;
		else 
			cout << besta << " letters and " << bestb << " numbers " ;
		
		cout << "\nTotal Plates :      " << bestn << "\nExcess Plates :     " << bestex << "\n";
		cout << "\n\nDo you want to enter another population ? (y/n)\n";
		cin >> flag;
		while ( flag != 'y' && flag != 'n' )
		{
			cout << "please Enter 'y' for yes or 'n' for no\n";
			cin >> flag;
		}
	}
	

	
	return 0;
}

int combonator ( double ca , double cb ,double temp )
{
	double com=0 , tot , r=0 , r1=0 , r2=0 ;
	double na = ca-1;
	double nb = cb-1;

	if ( na == 2 )
	{
		tot = na + cb;
		com = 0;
		for ( int t = tot-1 ; t !=0 ; t-- )
			com = com + t;
		r1 = com;
	}

	else 
		r = r + combonator ( na , cb , temp);
	if ( nb == 2 )
	{
		tot = nb + ca;
		com = 0;
		for ( int t = tot-1 ; t != 0 ; t--)
			com = com + t ;
		r2 = com;
	}
	else r = r + combonator ( ca , nb , temp );
	r = r +r1 + r2;
	return r;
}
