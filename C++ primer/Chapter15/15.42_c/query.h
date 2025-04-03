//#pragma once
//#include<string>
//using std::string;
//
//#include<ostream>
//using std::ostream;
//
//#include<memory>
//using std::shared_ptr;
//
//#include"query_base.h"
//#include"wordquery.h"
//#include"queryResult.h"
//
//class TextQuery;
//class  Query
//{
//	friend Query operator~(const Query&);
//	friend Query operator|(const Query&, const Query&);
//	friend Query operator&(const Query&, const Query&);
//public:
//	Query(const string&);
//
//	QueryResult eval(const TextQuery& t)const { return q->eval(t); }
//
//	string rep()const { return q->rep(); }
//
//private:
//	Query(shared_ptr<Query_base>query):q(query){}
//	shared_ptr<Query_base>q;
//};
//
//ostream& operator<<(ostream& os, const Query& query);
//
//inline Query::Query(const string&s):q(new WordQuery(s)){}