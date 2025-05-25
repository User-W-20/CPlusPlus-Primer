//#include"textquery.h"
//#include<iterator>
//#include<algorithm>
//#include<sstream>
//
//TextQuery::TextQuery(std::ifstream& is) :file(new std::vector<std::string>)
//{
//	std::string line;
//	while (std::getline(is, line))
//	{
//		file->push_back(line);
//
//		int index = file->size() - 1;
//
//		std::stringstream lineStream(line);
//		std::string word;
//		while(lineStream >> word)
//		{
//			std::shared_ptr<std::set<line_no>>& sp_lineIndex = wm[word];
//
//			if (!sp_lineIndex)
//				sp_lineIndex->insert(index);
//		}
//	}
//}
//
//TextQuery::result_tuple 
//TextQuery::query_return_tuple(const std::string&sought)
//{
//	static auto noData = std::make_shared<std::set<TextQuery::line_no>>();
//
//	auto iter = wm.find(sought);
//	if (iter == wm.end())
//		return result_tuple(sought, noData, file);
//	else
//		return result_tuple(sought, iter->second, file);
//}