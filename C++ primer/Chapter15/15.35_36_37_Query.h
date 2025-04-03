//#pragma once
//#include<iostream>
//#include<string>
//#include<memory>
//#include"15.35_36_37_Query_base.h"
//#include"15.35_36_37_QueryResult.h"
//#include"15.35_36_37_TextQuery.h"
//#include"15.35_36_37_WordQuery.h"
//
//class Query
//{
//	friend Query operator~(const Query&);
//	friend Query operator|(const Query&, const Query&);
//	friend Query operator&(const Query&, const Query&);
//public:
//	Query(const std::string &s):q(new WordQuery(s))
//	{
//		std::cout << "Query::Query(const std::string& s) where s=" + s + "\n";
//	}
//
//	QueryResult eval(const TextQuery &t)const
//	{
//		return q->eval(t);
//	}
//
//	std::string rep()const
//	{
//		std::cout << "Query::rep() \n";
//		return q->rep();
//	}
//private:
//	std::shared_ptr<Query_base>q;
//
//	Query(std::shared_ptr<Query_base>query):q(query)
//	{
//		std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
//	}
//};
//
//inline std::ostream&
//operator<<(std::ostream& os, const Query& query)
//{
//	return os << query.rep();
//}