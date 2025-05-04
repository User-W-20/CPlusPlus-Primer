//#pragma once
//
//#include<iostream>
//#include<fstream>
//#include<vector>
//#include<string>
//#include<map>
//#include<set>
//#include<memory>
//
//class wy_queryResult;
//
//class wy_textQuery
//{
//public:
//	typedef std::shared_ptr<std::vector<std::string>>
//		sp_file_Tp;
//	typedef std::shared_ptr<std::map<std::string, std::set<int>>>sp_Qmap_Tp;
//
//	wy_textQuery() = default;
//	wy_textQuery(std::ifstream& fin);
//
//	wy_queryResult query(const std::string& qWord)const;
//
//
//private:
//	sp_file_Tp sp_fileData = nullptr;
//
//	sp_Qmap_Tp sp_queryMap = nullptr;
//};