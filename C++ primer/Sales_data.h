#pragma once
#include<iostream>
#include<string>
#include<vector>
struct  Sales_data;
std::istream& read(std::istream& is, Sales_data&);

struct Sales_data
{
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

public:

	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {}
	Sales_data(const std::string& s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n* p)
	{}
	Sales_data(std::istream& is);

	
	


	void CalcRevenue(double price);
	double CalcAveragePrice();
	void SetData(Sales_data data);
	void AddData(Sales_data data);
	void print();

	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);
private:
	inline double avg_price()const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

};

void Sales_data::CalcRevenue(double price)
{
	revenue = units_sold * price;
}

void Sales_data::SetData(Sales_data data)
{
	bookNo = data.bookNo;
	units_sold = data.units_sold;
	revenue = data.revenue;
}

void Sales_data::AddData(Sales_data data)
{
	if (bookNo != data.bookNo) return;
	units_sold += data.units_sold;
	revenue += data.revenue;
}

double Sales_data::CalcAveragePrice()
{
	if (units_sold != 0)
		return revenue / units_sold;
	else
		return 0.0;
}

void Sales_data::print()
{
	std::cout << bookNo << " " << units_sold << " " << revenue << " ";
	double averagePrice = CalcAveragePrice();
	if(averagePrice!=0.0)
		std::cout << averagePrice << std::endl;
	else
		std::cout << "(no sales)" << std::endl;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

class Person;
std::istream& read(std::istream&, Person&);


class Person
{
	friend std::istream& read(std::istream& is, Person& person);
	friend std::ostream& print(std::ostream& os, const Person& person);

public:
	Person() = default;
	Person(const std::string sname,const std::string addr):name(sname),address(addr){}
	Person(std::istream& is) { read(is, *this); }

	auto get_name() const->std::string const& { return name; }
	auto get_addr() const->std::string const& {return address;}

private:
	std::string name;
	std::string address;
};

std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

std::ostream& print(std::ostream& os,const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream& read(std::istream& is, Person& person)
{
	return is >> person.name >> person.address;
}

std::ostream &print(std::ostream& os, const Person& person)
{
	return os << person.name <<" " << person.address;
}

Sales_data::Sales_data(std::istream& is)
{
	read(is, *this);
}

inline
double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

std::istream& read(std::istream& is, Sales_data& item);
std::ostream& print(std::ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& lhs, const Sales_data& rhs);

class Screen;

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	inline void clear(ScreenIndex);

private:
	std::vector<Screen> screens;
};

class Screen
{
	friend void Window_mgr::clear(ScreenIndex);
public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){}

	char get() const { return contents[cursor]; }
	char get(pos r, pos c)const { return contents[r * width + c]; }
	inline Screen& move(pos r, pos c);
	inline Screen& set(char c);
	inline Screen& set(pos r, pos c, char ch);

	const Screen& display(std::ostream& os)const { do_display(os); return *this; }
	Screen& display(std::ostream& os) { do_display(os); return  *this; }
	

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream& os)const { os << contents; }
};

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}

class Y;

class X {
	Y* y = nullptr;
};

class Y {
	X x;
};





inline void Window_mgr::clear(ScreenIndex i)
{
	if (i >= screens.size())return;
	Screen& s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');

}

class Debug {
public:

	constexpr Debug(bool b=true):rt(b),io(b),other(b){}
	constexpr Debug(bool r,bool i,bool o):rt(r), io(i), other(o) {}
	constexpr bool any() { return rt || io || other; }

	void set_rt(bool b) { rt = b; }
	void set_io(bool b) { io = b; }
	void set_other(bool b) { other = b; }
private:
	bool rt;
	bool io;
	bool other;
};

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double newRate) { interestRate = newRate; }

private:
	std::string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 42.42;
	static double initRate() { return todayRate; }
};

std::ostream& operator<<(std::ostream& os, const Sales_data& data) {
	os << data.isbn(); // 假设只输出 ISBN，实际可以根据需求修改
	return os;

	