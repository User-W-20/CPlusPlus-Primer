//#pragma once
//
//#include"wy_textquery.h"
//
//class wy_queryResult
//{
//public:
//	wy_queryResult() = default;
//
//	wy_queryResult(const wy_queryResult& qr);
//
//	wy_queryResult(std::size_t c, const std::string& str,
//		const wy_textQuery::sp_file_Tp& sp_f,
//		const wy_textQuery::sp_Qmap_Tp& sp_m);
//
//	std::size_t
//		getCounter()const { return counter; }
//
//	std::string
//		getQueryWord()const { return queryWord; }
//
//	wy_textQuery::sp_file_Tp
//		getSp_file()const { return sp_file; }
//
//	wy_textQuery::sp_Qmap_Tp
//		getSp_Qmap()const { return sp_Qamp; }
//private:
//	std::size_t counter=0;
//
//	std::string queryWord = "";
//
//	wy_textQuery::sp_file_Tp sp_file = nullptr;
//
//	wy_textQuery::sp_Qmap_Tp sp_Qamp = nullptr;
//};
//
//void print(std::ostream& os, const wy_queryResult& qr);