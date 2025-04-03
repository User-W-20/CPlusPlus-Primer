//#pragma once
//#include"15.9_Quote.h"
//#include<string>
//
//class Limit_quote :public Quote
//{
//public:
//	Limit_quote() = default;
//	Limit_quote(const std::string&b,double p,std::size_t n,double disc):Quote(b,p),max_qty(n),discount(disc){}
//
//	double net_price(std::size_t n)const override;
//private:
//	std::size_t max_qty = 0;
//	double discount = 0.0;
//};