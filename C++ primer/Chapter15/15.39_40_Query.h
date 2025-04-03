//#pragma once
//
//#include<iostream>
//#include<string> 
//#include<memory>
//#include"15.39_40_TextQuery.h"
//
//class Query_base
//{
//	friend class Query;
//public:
//	using line_no = TextQuery::line_no;
//
//	virtual ~Query_base() = default;
//private:
//	virtual QueryResult eval(const TextQuery&)const = 0;
//
//	virtual std::string rep()const = 0;
//};
//
//class WordQuery :public Query_base
//{
//	friend class Query;
//
//	WordQuery(const std::string &s):query_word(s)
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
//
//
//	std::string query_word;
//};
//
//class Query
//{
//	friend Query operator~(const Query&);
//	friend Query operator|(const Query&, const Query&);
//	friend Query operator&(const Query&, const Query&);
//public:
//	Query(const std::string& s) :q(new WordQuery(s))
//	{
//		std::cout << "Query::Query(const std::string& s) where s=" + s + "\n";
//	}
//
//	QueryResult eval(const TextQuery& t)const
//	{
//		return q->eval(t);
//	}
//
//	std::string rep()const
//	{
//		return q->rep();
//	}
//
//private:
//	Query(std::shared_ptr<Query_base>query):q(query)
//	{
//		std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
//	}
//
//	std::shared_ptr<Query_base>q;
//};
//
//inline std::ostream&
//operator<<(std::ostream& os, const Query& query)
//{
//	return os << query.rep();
//}
//
//class BinaryQuery :public Query_base
//{
//
//protected:
//	BinaryQuery(const Query&l, const Query& r,const std::string s):lhs(l),rhs(r),opSym(s)
//	{
//		std::cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n";
//	}
//
//	std::string rep()const override
//	{
//		std::cout<< "BinaryQuery::rep()\n";
//		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
//	}
//	Query lhs, rhs;
//	std::string opSym;
//};
//
//class OrQuery :public BinaryQuery
//{
//	friend Query operator|(const Query&, const Query&);
//	OrQuery(const Query& left, const Query& right) :BinaryQuery(left, right, "|")
//	{
//		std::cout << "OrQuery::OrQuery\n";
//	}
//
//	QueryResult eval(const TextQuery&)const override;
//};
//
//inline Query operator|(const Query& lhs, const Query& rhs)
//{
//	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
//}
//
//class AndQuery :public BinaryQuery
//{
//	friend Query operator&(const Query&, const Query&);
//	AndQuery(const Query&left,const Query&right):BinaryQuery(left,right,"&")
//	{
//		std::cout << "AndQuery::AndQuery()\n";
//	}
//
//	QueryResult eval(const TextQuery&)const override;
//};
//
//inline Query operator&(const Query& lhs, const Query& rhs)
//{
//	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
//}
//
//class NotQuery :public Query_base
//{
//	friend Query operator~(const Query& operand);
//	NotQuery(const Query&q):query(q)
//	{
//		std::cout << "NotQuery::NotQuery()\n";
//	}
//
//	std::string rep()const override
//	{
//		std::cout << "NotQuery::rep()\n";
//		return "~(" + query.rep() + ")";
//	}
//
//	QueryResult eval(const TextQuery&)const override;
//	Query query;
//};
//
//inline Query operator~(const Query& operand)
//{
//	return std::shared_ptr<Query_base>(new NotQuery(operand));
//}