//#pragma once
//#include"15.35_36_37_BinaryQuery.h"
//
//
//class AndQuery :public BinaryQuery
//{
//	friend Query operator&(const Query&, const Query&);
//
//	AndQuery(const Query&left,const Query&right):BinaryQuery(left,right,"&") 
//	{
//		std::cout << "AndQuery::AndQuery()\n";
//	}
//
//	QueryResult eval(const TextQuery&)const override
//	{
//
//	}
//};
//
//inline Query operator&(const Query& lhs, const Query& rhs)
//{
//	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
//}