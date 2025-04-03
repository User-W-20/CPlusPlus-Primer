//#include"15.35_36_37_QueryResult.h"
//
//std::ostream 
//& print(std::ostream& os, const QueryResult& qr)
//{
//	os<<qr.sought<<" occurs "<<qr.sp_lines->size()<< " "
//		<< "times" << "\n";
//
//	for (auto& index : *qr.sp_lines)
//	{
//		os<< "\t(line " <<index+1<< ") ";
//		const StrBlobPtr wp(qr.file, index);
//		os << wp.deref() << "\n";
//	}
//	return os;
//}