#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
typedef double(*func)(double x, double y);
double pr(double x, double y)
{
	return (x);
}
double f1(double x, double y)
{
	return (x + y);
}
double f2(double x, double y)
{
	return(2 * (x - 2) + x*pow((x - 2), 2) - x*y);
}
double f3(double x, double y)
{
	return(sin(x)-cos(y));
}
double f4(double x, double y)
{
	return((2 * pow(x, 3) + pow(x, 2) - pow(y, 2)) / (2 * pow(x, 2)));
}
double f5(double x, double y)
{
	return((y-x*pow(y,2))/x);
}
double f6(double x, double y)
{
	return((2*pow(y,2)+3*x*y-2*x)/(2*pow(x,2)));
}

//Краскевич В.Є. Численные методы стр.85
//Чисельні методи в інформатиці (Фельдман Л.П., Петренко А.І., Дмитрієва О.А.) стр.263
void Runge(double x, double y,double h,double limit,func f)
{
	double  k1, k2, k3, k4, d;
	cout<<"x0="<<x<<" y0="<<y<<" h="<<h<<endl;
	cout << "x      |      y" << endl;
	for (0; x <= limit; x += h)
	{
		printf("%.1f    |   %.4f     \n", x, y);
		k1 = h*f(x, y);
		k2 = h*f(x + h / 2, y + k1 / 2);
		k3 = h*f(x + h / 2, y + k2 / 2);
		k4 = h*f(x + h, y + k3);
		d = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		y = y + d;
	}
}

void info()
{
	cout << endl;
	cout << "This program was made by Stepovyi T. student of the group IS-51." << endl;
	cout << endl;
	cout << "All the instructions and guide to the program can be found on the disk." << endl;
	cout << endl;
	cout << "For the further information, please contact: tarasstep1998@gmail.com" << endl;
	cout << endl;
	cout << "Press any button to return to the menu screen..." << endl;
}
void priklad()
{
	cout << "find solutions for the equation: y'=x" << endl;
	Runge(0, 1, 1, 3, &pr);
	cout << "Press any button to return to the menu screen..." << endl;
}
void task1()
{
	cout << "find solutions for the equation: y'=y+x"<<endl;
	Runge(0, 1, 0.1, 0.3, &f1);
	cout << "Press any button to return to the menu screen..." << endl;
}
void task2()
{
	cout << "find solutions for the equation: y'=2*(x-2) + x*(x-2)^2 - x*y" << endl;
	Runge(2, 0, 0.5, 4, &f2);
	cout << "Press any button to return to the menu screen..." << endl;
}
void task3()
{
	cout << "find solutions for the equation : y'=sin(x)-cos(y)" << endl;
	Runge(0, 1, 0.2, 1, &f3);
	cout << "Press any button to return to the menu screen..." << endl;
}
void task4()
{
	cout << "find solutions for the equation : y'=(2*x^3+x^2-y^2)/(2*x^2)" << endl;
	Runge(1, 1, 0.1, 2, &f4);
	cout << "Press any button to return to the menu screen..." << endl;
}
void task5()
{
	cout << "find solutions for the equation : y'=(y-x*y^2)/x" << endl;
	Runge(1, 2, 0.1, 2, &f5);
	cout << "Press any button to return to the menu screen..." << endl;
}
void task6()
{
	cout << "find solutions for the equation : y'=(2*y^2+3*x*y-2*x)/(2*x^2)" << endl;
	Runge(1, 0.5, 0.1, 2, &f6);
	cout << "Press any button to return to the menu screen..." << endl;
}
int main()
{
	int key;
	do{
		cout << "\n\tMENU" << endl;
		cout << "1. Information about author" << endl;
		cout << "2. Priklad" << endl;
		cout << "3. Task #1" << endl;
		cout << "4. Task #2" << endl;
		cout << "5. Task #3" << endl;
		cout << "6. Task #4" << endl;
		cout << "7. Task #5" << endl;
		cout << "8. Task #6" << endl;
		cout << "x. Exit" << endl;
		key = _getch();
		system("cls");
		switch (key)
		{
		case'1':info(); break;
		case'2':priklad(); break;
		case'3':task1(); break;
		case'4':task2(); break;
		case'5':task3(); break;
		case'6':task4(); break;
		case'7':task5(); break;
		case'8':task6(); break;
		case'x':return 0;
		}
		_getch();
		system("cls");
	} while (key != 'x');
}