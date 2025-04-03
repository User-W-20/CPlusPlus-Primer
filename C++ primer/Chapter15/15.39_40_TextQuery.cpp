//#include"15.39_40_TextQuery.h"
//#include <iostream>
//#include <sstream>
//#include <iterator>
//
//TextQuery::TextQuery(std::ifstream&fin):file(StrBlob()),wordMap(std::map<std::string,std::shared_ptr<std::set<line_no>>>())
//{
//	std::string line;
//
//	while (std::getline(fin, line))
//	{
//		file.push_back(line);
//		int n = file.size() - 1;
//
//		std::stringstream lineStream(line);
//		std::string word;
//		while (lineStream >> word)
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
//	static std::shared_ptr < std::set<line_no> >noData(new std::set<line_no>);
//
//	auto iter = wordMap.find(sought);
//	if (iter == wordMap.end())
//		return QueryResult(sought, noData, file);
//	else
//		return QueryResult(sought, iter->second, file);
//}
//
//std::ostream&
//operator<<(std::ostream& os, const QueryResult& qr)
//{
//	os<<qr.sought<<" occurs "<<qr.sp_lines->size()<<" "
//		<< "times" << "\n";
//
//	for (auto& index : *qr.sp_lines)
//	{
//		os << "\t(line " << index + 1 << ")";
//		const StrBlobPtr wp(qr.file, index);
//		os << wp.deref() << "\n";
//	}
//	return os;
//}