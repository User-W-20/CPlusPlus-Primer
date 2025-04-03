//#pragma once
//
//#include<string>
//using std::string;
//
//#include"query.h"
//#include"query_base.h"
//
//class BinaryQuery :public Query_base
//{
//protected:
//	BinaryQuery(const Query&l,const Query&r,const string &s):lhs(l),rhs(r),opSym(s){}
//
//	string rep()const override
//	{
//		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
//	}
//
//	Query lhs, rhs;
//	string opSym;
//
//};