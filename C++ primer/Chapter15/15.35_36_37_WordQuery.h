//#pragma once
//#include"15.35_36_37_Query_base.h"
//
//class WordQuery :public Query_base
//{
//	friend class Query;
//	WordQuery(const std::string&s):query_word(s)
//	{
//		std::cout << "WordQuery::WordQuery(" + s + ")\n";
//	}
//	
//	QueryResult eval(const TextQuery&t)const override
//	{
//		return t.query(query_word);
//	}
//
//	std::string rep()const override
//	{
//		std::cout << "WodQuery::rep()\n";
//		return query_word;
//	}
//
//	std::string query_word;
//};