//#pragma once
//#include"query.h"
//#include"binaryquery.h"
//
//#include<memory>
//using std::shared_ptr;
//
//class QueryResult;
//class TextQuery;
//
//class OrQuery :public BinaryQuery
//{
//	friend Query operator|(const Query&, const Query&);
//	OrQuery(const Query&left,const Query&right):BinaryQuery(left,right,"|") {}
//
//	QueryResult eval(const TextQuery& t)const;
//};
//
//inline Query operator|(const Query& lhs, const Query& rhs)
//{
//	return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
//}