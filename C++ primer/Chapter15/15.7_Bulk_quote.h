//#pragma once
//#include"15.7_quote.h"
//#include<string>
//
//class Bulk_quote :public Quote
//{
//public:
//	Bulk_quote() = default;
//	Bulk_quote(const std::string &b,double p,size_t q,double disc):Quote(b,p),min_qty(q),discount(disc){}
//
//	double net_price(std::size_t n)const override;
//private:
//	std::size_t min_qty = 0;
//	double discount = 0.0;
//};