//#include <iostream>
//#include <string>
//#include"15.12_13_14_Bulk_quote.h"
//#include"15.12_13_14_quote.h"
//#include"15.12_13_14_Limit_quote.h"
//
////有必要将一个成员函数同时声明成override和final吗，为什么。
////有必要。
////override 确保该函数覆盖了基类的虚函数，防止因拼写错误或参数不匹配导致的隐藏问题。
////final 禁止派生类进一步重写该函数，确保该实现不会被修改。
////如果不希望子类再重写某个虚函数，建议同时使用 override 和 final。
//
//class base
//{
//public:
//	std::string name() { return basename; }
//	virtual void print(std::ostream& os) { os << basename; }
//
//private:
//	std::string basename = "base\n";
//};
//
//class derived :public base
//{
//public:
//	void print(std::ostream& os) override { base::print(os); os << " derived\n " << i; }
//private:
//	int i;
//};
//
//void print_debug(const Quote& q);
//double print_total(std::ostream& os, const Quote& item, size_t n);
//
//int main()
//{
//	base bobj;
//	base* bp1 = &bobj;
//	base& br1 = bobj;
//	derived dobj;
//	base* bp2 = &dobj;
//	base& br2 = dobj;
//
//
//	bobj.print(std::cout);
//
//	dobj.print(std::cout);
//
//	std::cout << bp1->name();
//
//	std::cout << bp2->name();
//
//	br1.print(std::cout);
//
//	br2.print(std::cout);
//	return 0;
//}
//
//double print_total(std::ostream& os, const Quote& item, size_t n)
//{
//	double ret = item.net_price(n);
//
//	os << "ISBN:" << item.isbn()
//		<< "# sold: " << n << " total due: " << ret << std::endl;
//
//	return ret;
//}
//
//
//void print_debug(const Quote& q)
//{
//	q.debug();
//}