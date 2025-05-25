//#pragma once
//#include<string>
//#include<tuple>
//#include<memory>
//#include<vector>
//#include<set>
//#include<map>
//#include<fstream>
//
//
//class TextQuery
//{
//public:
//typedef std::vector<std::string>::size_type line_no;
//typedef std::tuple<std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>>result_tuple;
//
//
//	TextQuery(std::ifstream&);
//
//	result_tuple query_return_tuple(const std::string& sought);
//
//private:
//	std::shared_ptr<std::vector<std::string>>file;
//	std::map<std::string, std::shared_ptr<std::set<line_no>>>wm;
//
//};