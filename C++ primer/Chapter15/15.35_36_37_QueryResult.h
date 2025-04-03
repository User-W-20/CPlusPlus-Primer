//#pragma once
//
//#include<iostream>
//#include <memory>
//#include <set>
//#include <vector>
//#include <string>
//#include"15.35_36_37_TextQuery.h"
//
//class QueryResult
//{
//	friend std::ostream& print(std::ostream&, const QueryResult&);
//
//public:
//	QueryResult(const std::string&s,std::shared_ptr<std::set<TextQuery::line_no>>sp_l,const StrBlob& f):sought(s),sp_lines(sp_l),file(f){}
//
//	const StrBlob& get_file()const { return file; }
//
//	std::set<TextQuery::line_no>::iterator begin() { return sp_lines->begin(); }
//
//	std::set<TextQuery::line_no>::iterator end() { return sp_lines->end(); }
//
//private:
//	std::string sought;
//	std::shared_ptr<std::set<TextQuery::line_no>>sp_lines;
//	StrBlob file;
//};
//
//std::ostream&
//print(std::ostream&, const QueryResult&);