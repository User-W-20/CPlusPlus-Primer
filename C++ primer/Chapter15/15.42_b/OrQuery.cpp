//#include"OrQuery.h"
//#include<set>
//using std::set;
//#include<memory>
//using std::make_shared;
//
//#include"TextQuery.h"
//#include"QueryResult.h"
//#include"Query.h"
//
//QueryResult
//OrQuery::eval(const TextQuery& text)const
//{
//	auto left = lhs.eval(text);
//	auto right = rhs.eval(text);
//
//	auto ret_lines = make_shared<set<line_no>>();
//
//	ret_lines->insert(left.begin(), left.end());
//	ret_lines->insert(right.begin(), right.end());
//	return QueryResult(rep(), ret_lines, left.get_file());
//}