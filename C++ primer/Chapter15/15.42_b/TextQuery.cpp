//#include"TextQuery.h"
//#include"QueryResult.h"
//#include<fstream>
//#include<sstream>
//#include<memory>
//#include<vector>
//#include<string>
//#include<map>
//#include<set>
//
//TextQuery::TextQuery(std::ifstream&is):file(new std::vector<std::string>)
//{
//	using std::getline;
//	std::string text;
//
//	while (getline(is, text))
//	{
//		file->push_back(text);
//		int n = file->size() - 1;
//		std::istringstream line(text);
//
//
//		std::string word;
//		while (line >> word)
//		{
//			auto p = handlePunct(word);
//			for (auto w : *p)
//			{
//				auto& lines = wm[w];
//				if (!lines)
//					lines.reset(new std::set<line_no>);
//				lines->insert(n);
//			}
//		}
//	}
//}
//
//QueryResult TextQuery::query(const std::string& sought)const
//{
//	static	std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
//
//	auto loc = wm.find(sought);
//	if (loc == wm.end())
//		return QueryResult(sought, nodata, file);
//	else
//		return QueryResult(sought, loc->second, file);
//}
//
//std::shared_ptr<std::vector<std::string>>TextQuery::handlePunct(const std::string& s)
//{
//	std::shared_ptr<std::vector<std::string>>p =
//		std::make_shared<std::vector<std::string>>();
//
//	size_t first = 0, index = 0;
//	while (index != s.size())
//	{
//		if (ispunct(s[index]))
//		{
//			std::string word = s.substr(first, index - first);
//			if (!word.empty())
//				p->push_back(word);
//			p->push_back(s.substr(index, 1));
//			++index;
//			first = index;
//		}
//		else
//			++index;
//	}
//	std::string trial = s.substr(first);
//	if (!trial.empty())
//		p->push_back(trial);
//
//	return p;
//}