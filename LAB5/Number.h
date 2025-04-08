#pragma once

class Number
{
private:
	int baza, lungime;
	char numar[100] = {};
public:
	Number(const char* value, int base); 
	~Number(); 

	int GetBase10Value() const;

	bool operator < (Number& num); 
	bool operator > (Number& num);
	bool operator <= (Number& num);
	bool operator >= (Number& num); 
	bool operator == (Number& num);
	
	friend Number operator+ (const Number& num1, const Number& num2);
	friend Number operator- (const Number& num1, const Number& num2);

	Number& operator--();
	Number operator--(int);

	void SwitchBase(int newBase);
	void Print();
	void Print1();
	int  GetDigitsCount() const;
	int  GetBase() const; 
};
