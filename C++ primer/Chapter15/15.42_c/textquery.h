//#pragma once
//
//#include<fstream>
//#include<memory>
//#include<vector>
//#include<string>
//#include<map>
//#include<set>
//
//class QueryResult;
//
//class TextQuery
//{
//public:
//	typedef std::vector<std::string>::size_type line_no;
//
//	TextQuery(std::ifstream&);
//	QueryResult query(const std::string&)const;
//private:
//	std::shared_ptr<std::vector<std::string>>file;
//
//	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
//
//	std::shared_ptr<std::vector<std::string>>handlePunct(const std::string&);
//};