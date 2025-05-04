//#include"wy_queryresult.h"
//#include"wy_textquery.h"
//#include"DebugDelete.h"
//#include<sstream>
//#include<algorithm>
//
//wy_textQuery::wy_textQuery(std::ifstream& fin) :
//	sp_fileData(new std::vector<std::string>(), DebugDelete()),
//	sp_queryMap(new std::map<std::string, std::set<int>>(), DebugDelete())
//{
//	std::string line;
//	while (std::getline(fin, line))
//		sp_fileData->push_back(line);
//}
//
//wy_queryResult
//wy_textQuery::query(const std::string& qWord)const
//{
//	std::size_t counter = 0;
//
//	for (std::size_t i = 0; i != sp_fileData->size(); ++i)
//	{
//		std::stringstream lineStream((*sp_fileData)[i]);
//		std::string word;
//		while (lineStream >> word)
//		{
//			if(!word.compare(qWord))
//			{
//				++counter;
//				(*sp_queryMap)[qWord].insert(i);
//			}
//		}
//	}
//
//
//	wy_queryResult qResult(counter, qWord, sp_fileData, sp_queryMap);
//
//	return qResult;
//}