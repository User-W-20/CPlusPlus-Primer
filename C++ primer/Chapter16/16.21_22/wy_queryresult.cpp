//#include"wy_queryresult.h"
//
//inline
//wy_queryResult::wy_queryResult(const wy_queryResult& qr):
//	counter(qr.getCounter()),queryWord(qr.getQueryWord()),
//	sp_file(qr.getSp_file()),sp_Qamp(qr.getSp_Qmap()){}
//
//wy_queryResult::wy_queryResult(std::size_t c,const std::string &str,const wy_textQuery::sp_file_Tp &sp_f,const wy_textQuery::sp_Qmap_Tp &sp_m):
//	counter(c),queryWord(str),sp_file(sp_f),sp_Qamp(sp_m)
//{ }
//
//void print(std::ostream& os, const wy_queryResult& qr)
//{
//	const std::string queryWord = qr.getQueryWord();
//
//	os<<"The word ["<<queryWord<<"] occurs "
//		<< qr.getCounter() << " times :\n";;
//
//	auto sp_m = qr.getSp_Qmap();
//	auto sp_f = qr.getSp_file();
//
//	for (const auto& index : (*sp_m)[queryWord])
//	std::cout<<"\n(Line "<<index<<") "
//		<<(*sp_f)[index]<< "\n\n";
//}