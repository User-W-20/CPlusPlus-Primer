//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//#include <fstream>
//
//#include"15.30_Quote.h"
//#include"15.30_Basket.h"
//#include"15.30_Disc_quote.h"
//#include"15.30_Bulk_quote.h"
//#include"15.30_Limit_quote.h"
//
//int main()
//{
//	Basket basket;
//
//	for (unsigned i = 0; i != 10; ++i)
//		basket.add_item(Bulk_quote("Bible", 20.6, 20, 0.3));
//
//	for (unsigned i = 0; i != 10; ++i)
//		basket.add_item(Bulk_quote("C++Primer", 30.9, 5, 0.4));
//
//	for (unsigned i = 0; i != 10; ++i)
//		basket.add_item(Quote("CLRS", 40.1));
//
//	std::ofstream log("log.txt", std::ios_base::app | std::ios_base::out);
//
//	basket.total_receipt(log);
//	return 0;
//}