//#include"textquery.h"
//
//#include"sstream"
//using std::istringstream;
//
//#include<fstream>
//using std::ifstream;
//
//#include<memory>
//using std::make_shared; using std::shared_ptr;
//
//#include<vector>
//using std::vector;
//
//#include<string>
//using std::string;
//
//#include<map>
//using std::map;
//
//#include<set>
//using std::set;
//
//#include"queryResult.h"
//
//TextQuery::TextQuery(ifstream& is) :file(make_shared<vector<string>>())
//{
//	using std::getline;
//
//	string text;
//
//	while (getline(is, text))
//	{
//		file->push_back(text);
//		int n = file->size() - 1;
//		istringstream line(text);
//
//		string word;
//		while (line >> word)
//		{
//			auto p = handlePunct(word);
//			for (auto w : *p)
//			{
//				auto& lines = wm[w];
//				if (!lines)
//					lines.reset(new set<line_no>);
//			}
//		}
//	}
//}
//
//QueryResult TextQuery::query(const string& sought)const
//{
//	static shared_ptr<set<line_no>>nodata(new set<line_no>);
//
//	auto loc = wm.find(sought);
//	if (loc == wm.end())
//		return QueryResult(sought, nodata, file);
//	else
//		return QueryResult(sought, loc->second, file);
//}
//
//shared_ptr<vector<string>>TextQuery::handlePunct(const string& s)
//{
//	shared_ptr<vector<string>>p =
//		make_shared<vector<string>>();
//
//	size_t first = 0, index = 0;
//
//	while (index != p->size())
//	{
//		if (ispunct(s[index]))
//		{
//			string word = s.substr(first, index - first);
//			if (!word.empty())
//				p->push_back(word);
//			p->push_back(s.substr(index, 1));
//			++index;
//			first = index;
//		}
//		else
//			++index;
//	}
//	string trial = s.substr(first);
//	if (!trial.empty())
//		p->push_back(trial);
//
//	return p;
//}