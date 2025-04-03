//#include"notquery.h"
//
//#include<memory>
//using std::make_shared;
//
//#include<set>
//using std::set;
//
//#include"textquery.h"
//#include"query.h"
//#include"binaryquery.h"
//
//QueryResult
//NotQuery::eval(const TextQuery& t)const
//{
//	auto result = query.eval(t);
//
//	auto ret_lines = make_shared<set<line_no>>();
//
//	auto beg = result.begin();
//	auto end = result.end();
//
//	auto sz = result.get_file()->size();
//
//	for (size_t n = 0; n != sz; ++n)
//	{
//		if (beg == end || *beg != n)
//			ret_lines->insert(n);
//		else if (beg != end)
//			++beg;
//	}
//	return QueryResult(rep(),ret_lines,result.get_file());
//}