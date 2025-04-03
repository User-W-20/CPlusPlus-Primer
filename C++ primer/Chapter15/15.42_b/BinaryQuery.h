//#pragma once
//#include<string>
//
//#include"Query.h"
//#include"Query_base.h"
//
//class BinaryQuery :public Query_base
//{
//protected:
//	BinaryQuery(const Query&l,const Query&r,const std::string&s):lhs(l),rhs(r),opSym(s){}
//
//	std::string rep()const
//	{
//		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
//	}
//
//	Query lhs, rhs;
//	std::string opSym;
//};