//#include"15.30_Basket.h"
//
//double Basket::total_receipt(std::ostream& os)const
//{
//	double sum = 0.0;
//
//	for (auto iter = items.cbegin(); iter != items.cend(); items.upper_bound(*iter))
//	{
//		sum += print_total(os, **iter, items.count(*iter));
//	}
//
//	os << "Total Sale: " << sum << std::endl;
//	return sum;
//}