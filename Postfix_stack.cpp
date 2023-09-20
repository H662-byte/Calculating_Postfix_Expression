#include<iostream>
#include<string>
#include<cstring>
using namespace std;


int const c = 50;
string stack[c];
int top = -1;
int siz = 0;



void push(string element) {
	if (top >= c - 1) {
		cout << "stack overflow" << endl;
	}
	else {
		top++;
		stack[top]= element ;

	}
}

void pop() {
	if (top == -1) {
		cout << "stack underflow" << endl;
	}
	else {
		cout << "YOu Poped :" << stack[top] << endl;
		top--;
	}


}


void Display() {
	for (int i = top; i >= 0; i--)
	{
		cout << stack[i] << endl;
	}
	cout << "*******************" << endl;

}


int first(string d) {

	
	if (d == "*" || d == "/") {
		return 3;
	}
	if (d == "+" || d == "-") {
		return 2;
	}

	
}

string postfix(string e) {
	string y, mid = "", Sta;
	char g[1];
	
	int sign;
	for (int i = 0; i < e.size(); i++)
	{
		if (int(e[i]) > 47) {
			y += e[i];
		}


		if (int(e[i]) <= 47 && int(e[i]) > 41) {
			mid = e[i];



			if (top == -1) {
				push(mid);
			}
			else {
				Sta = stack[top];
				//cout << "stack" << Sta;
				if (first(Sta) < first(mid) && Sta != "(") {
					push(mid);
				}
				if (Sta == "(") {
					push(mid);
				}
				if (first(Sta) >= first(mid) && Sta != "(") {
					while (top != -1) {

						//cout << "vorod";
						y += stack[top];
						pop();
						if (first(stack[top]) < first(mid)) {
							break;
						}
					}
					mid = e[i];
					push(mid);
				}
				sign = i;
			}






		}



		if (e[i] == '(') {
			push("(");
		}
		else if (e[i] == ')') {
			for (int k = i - 1; k >= 0; k--) {
				if (top == -1)  {
					break;
				}
				if (e[k] == '(') {
					break;
				}
				if (stack[top] != "(") {
					y += stack[top];
					pop();
				}
				if (stack[top] == "(") {
					pop();
					break;
				}
			}
	    }


		
	}

	for (int i = top; i >=0; i--)
	{
		if (stack[i] != "(") {
			y += stack[i];
			pop();
		}
		if (stack[top] == "(") {
			pop();
		}
	}
	return y;

}



string SubDev(string Polynomial) {


	string mid1, mid2, Result;


	int  bracket = 0, bracket2 = 0, NUm;
	siz = Polynomial.size();
	for (int i = 0; i < Polynomial.size(); i++) {
		if (Polynomial[i] == '*' || Polynomial[i] == '/') {
			siz += 2;
		}
	
	}
	
	int signl = -1, signm = -1;
	for (int i = 0; i < siz; i++)
	{
		if (i > siz) {
			break;
		}
		if (Polynomial[i] == '*' || Polynomial[i] == '/') {

			NUm = 0;
			//cout << "i" << i << endl;
			Result = "", mid1 = "", mid2 = "";

			for (int j = i - 1; j >= 0; j--)
			{
	
				if (int(Polynomial[j]) <= 47 && int(Polynomial[j]) > 41) {
					signl = j;
					break;
				}
				if (int(Polynomial[j]) == 41) {
					NUm = 1;
					//bracket++;

			
					for (int k = j; k >= 0; k--) {
						if (int(Polynomial[k]) == 41)
						{
							bracket++;
						}
						
						if (int(Polynomial[k]) == 40) {
							break;
						}

						Result = Polynomial[k] + Result;
					}
					break;
				}
				Result = Polynomial[j] + Result;
			}



			Result += Polynomial[i];



			for (int j = i + 1; j < Polynomial.size(); j++)
			{

				if (int(Polynomial[j]) <= 47) {
					signm = j;
					break;
				}
				else {
					signm = siz + 44;
				}


				Result += Polynomial[j];


			}


			for (int i = 0; i <= signl; i++)
			{
				mid1 += Polynomial[i];
			}


			for (int i = signm; i < Polynomial.size(); i++)
			{

				mid2 += Polynomial[i];

			}


			Result += ")";
	
			if (NUm == 1) {
				for (int i = 0; i < bracket; i++)
				{
					Result = "(" + Result;
				}
			}
			bracket = 0;

			Result = "(" + Result;

			Polynomial = mid1 + Result + mid2;
	
			i += 2;
	

		}

	}


	return Polynomial;


}

string Add(string Polynomial) {





	string mid1, mid2, Result;
	int signl = -1, signm = -1, bracket = 0, bracket2=0;
	int Bigsign = 0;
	for (int i = 0; i < Polynomial.size(); i++) {
		if (Polynomial[i] == '+' || Polynomial[i] == '-') {
			siz += 2;
		}

	}


	for (int i = 0; i < siz; i++)
	{
		if (Polynomial[i] == '+' || Polynomial[i] == '-') {


	
			Result = "", mid1 = "", mid2 = "";


			for (int j = i - 1; j >= 0; j--)
			{
		

				if (int(Polynomial[j]) <= 47 && int(Polynomial[j]) > 41) {
					signl = j;
					break;
				}
				if (int(Polynomial[j]) == 41) {


					//bracket++;
					for (int k = j; k >= 0; k--) {

						if (int(Polynomial[k]) == 41)
						{
							bracket2++;
						}


						Result = Polynomial[k] + Result;
						if (int(Polynomial[k]) == 40) {
							Bigsign++;
						}
						if (Bigsign == bracket2) {
							break;
						}
						//Result = Polynomial[k] + Result;
					}
					break;
				}
				Result = Polynomial[j] + Result;
			}


			Result += Polynomial[i];

			Bigsign = 0, bracket2 = 0;

			for (int j = i + 1; j < Polynomial.size(); j++)
			{

				if (int(Polynomial[j]) <= 47 && int(Polynomial[j]) > 41) {
					signm = j;
					break;
				}
				if (int(Polynomial[j]) == 40) {

					for (int k = j; k < siz; k++)
					{

						if (int(Polynomial[k]) == 40)
						{
							bracket2++;

						}

						if (int(Polynomial[k]) == 41) {
							Bigsign++;
							signm = k;
						}

						if (Bigsign == bracket2) {
							break;
						}
						Result = Result + Polynomial[k];
					}
					break;
				}
				else {
					if (int(Polynomial[j]) <= 47) {
						signm = j;
						break;
					}
					else {
						signm = siz + 44;
					}


					Result += Polynomial[j];


				}
			}



			for (int i = 0; i <= signl; i++)
			{
				mid1 += Polynomial[i];
			}



			for (int i = signm; i < Polynomial.size(); i++)
			{

				mid2 += Polynomial[i];

			}

			Result = Result + ")";
			bracket = 0;
			Result = "(" + Result;
			Polynomial = mid1 + Result + mid2;
	
			i += 2;
	

		}


	}


	return Polynomial;



}





int main()
{



	string Polynomial, polFinal,Result;
	cin >> Polynomial;
	//polFinal = Polynomial;
	cout << "Answer:" << endl;
	cout<<Add(SubDev(Polynomial))<<endl;
	polFinal = Add(SubDev(Polynomial));
	cout << "*********** para" << endl;
	cout << postfix(Polynomial)<<endl;
	cout << "*************" << endl<< postfix(polFinal) <<endl;

	
	if (postfix(polFinal) == postfix(Polynomial)) {
		Result = "True";
	}
	else {
		Result = "False";
	}
	cout << Result;

	return 0;
}
