//#include"15.35_36_37_TextQuery.h"
//#include"15.35_36_37_QueryResult.h"
//#include<iostream>
//#include<sstream>
//#include<iterator>
//TextQuery::TextQuery(std::ifstream& fin) :file(StrBlob()),wordMap(std::map<std::string,std::shared_ptr<std::set<line_no>>>())
//{
//	std::string line;
//
//	while (std::getline(fin, line))
//	{
//		file.push_back(line);
//		int n = file.size() - 1;
//
//		std::stringstream lineSteam(line);
//		std::string word;
//
//		while (lineSteam >> word)
//		{
//			std::shared_ptr<std::set<line_no>>& sp_lines = wordMap[word];
//
//			if (!sp_lines)
//			{
//				sp_lines.reset(new std::set<line_no>);
//			}
//			sp_lines->insert(n);
//		}
//	}
//}
//
//QueryResult
//TextQuery::query(const std::string& sought)const
//{
//	static std::shared_ptr<std::set<line_no>> noData(new std::set<line_no>);
//
//	auto iter = wordMap.find(sought);
//	if (iter == wordMap.end())
//		return QueryResult(sought, noData, file);
//	else
//		return QueryResult(sought, iter->second, file);
//}