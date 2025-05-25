//#include<iostream>
//#include"SalesData.h"
//using std::istream; using std::ostream;
//
//Sales_data::Sales_data(std::istream& is)
//{
//	read(is, *this);
//}
//
//double
//Sales_data::avg_price()const
//{
//	if (units_sold)
//		return revenue / units_sold;
//	else
//		return 0;
//}
//
//Sales_data&
//Sales_data::combine(const Sales_data& rhs)
//{
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}
//
//Sales_data& Sales_data::operator=(const Sales_data& rhs)
//{
//	this->bookNo = rhs.bookNo;
//	this->revenue = rhs.revenue;
//	this->units_sold = rhs.units_sold;
//
//	return *this;
//}
//
////string=
//Sales_data& Sales_data::operator=(const std::string &rhs)
//{
//	*this = Sales_data(rhs);
//	return *this;
//}
//
//Sales_data& Sales_data::operator+=(const Sales_data& rhs)
//{
//	this->revenue += rhs.revenue;
//	this->units_sold += rhs.units_sold;
//
//	return *this;
//}
//
//Sales_data
//add(const Sales_data& lhs, const Sales_data& rhs)
//{
//	Sales_data sum = lhs;
//	sum.combine(rhs);
//	return sum;
//}
//
//istream&
//read(istream& is, Sales_data& item)
//{
//	double price = 0.0;
//	is >> item.bookNo >> item.units_sold >> price;
//	item.revenue = item.units_sold * price;
//	return is;
//}
//
//ostream&
//print(ostream& os, const Sales_data& item)
//{
//	os << item.isbn() << " " << item.units_sold << " "
//		<< item.revenue << " " << item.avg_price();
//	return os;
//}
//
//std::ostream&
//operator<<(std::ostream& os, const Sales_data& item)
//{
//	os << item.isbn() << " " << item.units_sold << " "
//		<< item.revenue << " " << item.avg_price();
//
//	return os;
//}
//
//std::istream&
//operator>>(std::istream& is, Sales_data& item)
//{
//	double price;
//	is >> item.bookNo >> item.units_sold >> price;
//
//	if (is)
//		item.revenue = item.units_sold * price;
//	else
//		item = Sales_data();
//	return is;
//}