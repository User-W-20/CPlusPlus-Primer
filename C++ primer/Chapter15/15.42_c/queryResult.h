//#pragma once
//#include<string>
//#include<iostream>
//#include<memory>
//#include<set>
//#include<vector>
//
//#include"textquery.h"
//
//class QueryResult
//{
//	friend std::ostream& print(std::ostream&, const QueryResult&);
//	friend std::ostream& print(std::ostream&, const QueryResult&, size_t, size_t);
//public:
//	QueryResult(std::string s,
//		std::shared_ptr<std::set<TextQuery::line_no>>l,
//		std::shared_ptr<const std::vector<std::string>>f):
//		sought(s),lines(l),file(f){}
//
//	std::set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
//	std::set<TextQuery::line_no>::iterator end()
//	  {return lines->end();}
//	std::shared_ptr<const std::vector<std::string>>get_file() const{ return file; }
//private:
//	std::string sought;
//
//	std::shared_ptr<std::set<TextQuery::line_no>>lines;
//	std::shared_ptr<const std::vector<std::string>>file;
//
//	size_t line_no()const { return lines->size(); }
//};
//
//std::ostream&
//print(std::ostream&, const QueryResult&);
//
//std::ostream&
//print(std::ostream&, const QueryResult&,size_t ,size_t);