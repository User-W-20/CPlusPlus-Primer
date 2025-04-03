//#pragma once
//#include<string>
//using std::string;
//
//#include"textquery.h"
//#include"query_base.h"
//#include"queryResult.h"
//
//class WordQuery :public Query_base
//{
//	friend class Query;
//	WordQuery(const string&s):word_query(s){}
//	QueryResult eval(const TextQuery& t)const { return t.query(word_query); }
//	string rep()const { return word_query; }
//
//	string word_query;
//};