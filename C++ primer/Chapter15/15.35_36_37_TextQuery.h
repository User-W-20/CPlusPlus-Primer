//#pragma once
//#include"15.35_36_37_StrBlob.h"
//#include<map>
//#include<set>
//#include<string>
//#include<memory>
//#include<fstream>
//
//class QueryResult;
//
//class TextQuery
//{
//public:
//	typedef StrBlob::size_type line_no;
//
//	TextQuery(std::ifstream& fin);
//	QueryResult query(const std::string&)const;
//private:
//	StrBlob file;
//	std::map < std::string, std::shared_ptr<std::set<line_no>>>wordMap;
//};