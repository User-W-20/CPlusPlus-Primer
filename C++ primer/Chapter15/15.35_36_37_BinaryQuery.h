//#pragma once
//#include"15.35_36_37_Query_base.h"
//#include"15.35_36_37_Query.h"
//
//class BinaryQuery :public Query_base
//{
//protected:
//	BinaryQuery(const Query&l,const Query&r,const std::string&s):lhs(l),rhs(r),opSym(s)
//	{
//		std::cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n";
//	}
//
//	std::string rep()const override
//	{
//		std::cout << "BinaryQuery::rep()\n";
//		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
//	}
//
//	Query lhs, rhs;
//	std::string opSym;
//};