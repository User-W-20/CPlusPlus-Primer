//#include <iostream>
//#include <string>
//
//#include"15.7_quote.h"
//#include"15.7_limit_quote.h"
//#include"15.7_Bulk_quote.h"
//
//double print_total(std::ostream& os, const Quote& item, size_t n)
//{
//	double ret = item.net_price(n);
//
//	os<< "ISBN:" << item.isbn()
//		<< "# sold: " << n << " total due: " << ret << std::endl;
//
//	return ret;
//}
//
//int main()
//{
//    Quote q("textbook", 10.60);
//    Bulk_quote bq("textbook", 10.60, 10, 0.3);
//    Limit_quote lq("Bible", 10.60, 10, 0.3);
//
//    print_total(std::cout, q, 5);
//    print_total(std::cout, bq, 5);
//    print_total(std::cout, lq, 5);
//
//    return 0;
//}