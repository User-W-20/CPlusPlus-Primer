//#include"15.1_2_3_Quote.h"
//#include<iostream>
//#include<string>
//#include<map>
//#include<functional>
//
// 虚成员：在基类中使用virtual关键字修饰的成员函数，允许派生类覆盖（override），并且支持动态绑定
// 
// private：只能被 本类 访问，派生类无法直接访问。
// protected：除了本类，派生类也能访问。
// 
//double print_total(std::ostream& os, const Quote& item, size_t n)
//{
//	double ret = item.net_price(n);
//
//	os << "ISBN:" << item.isbn() << "  #sold:" << n << "total due:" << ret << std::endl;
//	return ret;
//}
//int main()
//{
//	Quote q("978-7-121-15535-2", 50.0); // 创建一个 Quote 对象
//	print_total(std::cout, q, 3);
//
//	return 0;
//}