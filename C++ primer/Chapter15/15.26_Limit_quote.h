//#include"15.26_Disc_quote.h"
//
//class Limit_quote :public Disc_quote
//{
//public:
//	Limit_quote() = default;
//	Limit_quote(const std::string &b,double p,std::size_t q,double disc):Disc_quote(b,p,q,disc){}
//
//	double net_price(std::size_t n)const override
//	{
//		return n * price * (n < quantity ? 1 - discount : 1);
//	}
//
//	void debug() const override;
//};