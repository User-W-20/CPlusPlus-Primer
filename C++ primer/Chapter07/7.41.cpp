//#include"Sales_data.h"
//using std::cout; using std::endl;
//
//Sales_data::Sales_data(std::istream& is) :Sales_data()
//{
//	std::cout<< "Sales_data(istream &is)" << std::endl;
//	read(is,*this);
//}
//
//Sales_data& Sales_data::combine(const Sales_data& rhs)
//{
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}
//
//std::istream& read(std::istream& is, Sales_data& item)
//{
//	double price = 0;
//	is >> item.bookNo >> item.units_sold >> price;
//	item.revenue = price * item.units_sold;
//	return is;
//}
//
//std::ostream& print(std::ostream& os,const Sales_data& item)
//{
//	return os << item.isbn() << " " << item.units_sold << " " << item.revenue;
//}
//
//Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
//{
//	Sales_data sum = lhs;
//	sum.combine(rhs);
//	return sum;
//}
//
//int main()
//{
//    cout << "1. default way: " << endl;
//    cout << "----------------" << endl;
//    Sales_data s1;
//
//    cout << "\n2. use std::string as parameter: " << endl;
//    cout << "----------------" << endl;
//    Sales_data s2("CPP-Primer-5th");
//
//    cout << "\n3. complete parameters: " << endl;
//    cout << "----------------" << endl;
//    Sales_data s3("CPP-Primer-5th", 3, 25.8);
//
//    cout << "\n4. use istream as parameter: " << endl;
//    cout << "----------------" << endl;
//    Sales_data s4(std::cin);
//
//    return 0;
//}