//#include"orquery.h"
//#include"query.h"
//#include"query_base.h"
//#include"textquery.h"
//
//#include<memory>
//using std::make_shared;
//
//#include<set>
//using std::set;
//
//QueryResult
//OrQuery::eval(const TextQuery& text)const
//{
//	auto left = lhs.eval(text);
//	auto right = rhs.eval(text);
//
//	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
//	ret_lines->insert(right.begin(), right.end());
//
//	return QueryResult(rep(), ret_lines, left.get_file());
//}