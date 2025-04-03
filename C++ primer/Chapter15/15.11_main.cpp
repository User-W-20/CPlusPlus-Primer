//#include <iostream>
//#include <string>
//
//#include"15.11_Quote.h"
//#include"15.11_Bulk_quote.h"
//#include"15.11_Limit_quote.h"
//void print_debug(const Quote& q);
//int main()
//{
//    Quote q("aaa", 10.60);
//    Bulk_quote bq("bbb", 111, 10, 0.3);
//    Limit_quote lq("ccc", 222, 10, 0.3);
//
//
//    Quote& r = q;
//    r.debug();
//    std::cout << "\n";
//    r = bq;
//    r.debug();
//    std::cout << "\n";
//    r = lq;
//    r.debug();
//    std::cout << "\n";
//
//    std::cout << "====================\n";
//
//    print_debug(q);
//    std::cout << "\n";
//    print_debug(lq);
//    std::cout << "\n";
//    print_debug(bq);
//    std::cout << "\n";
//
//    return 0;
//}
//
//double print_total(std::ostream& os, const Quote& item, size_t n)
//{
//    double ret = item.net_price(n);
//
//    os << "ISBN: " << item.isbn() << "#sold: " << n << "total due" << ret << std::endl;
//
//    return ret;
//}
//
//void print_debug(const Quote& q)
//{
//    q.debug();
//}