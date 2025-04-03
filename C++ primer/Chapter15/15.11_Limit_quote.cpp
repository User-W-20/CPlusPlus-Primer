//#include"15.11_Limit_quote.h"
//
//double Limit_quote::net_price(std::size_t n)const
//{
//	return n * price * (n < max_qty ? 1 - discount : 1);
//}
//
//void Limit_quote::debug()const
//{
//	Quote::debug();
//	std::cout << "max_qty= " <<this->max_qty<< " "
//		<< "discount= " << this->discount << " ";
//}