//#include "queryResult.h"
//
//#include <iostream>
//using std::ostream;
//
//ostream& print(ostream& os, const QueryResult& qr)
//{
//    os << "The result of your query \"" << qr.sought << "\" is:\n";
//
//    for (const auto& index : *qr.lines)
//        os << "\t(line " << index + 1 << ") "
//        << *(qr.file->begin() + index) << "\n";
//
//    return os;
//}
//
//ostream& print(ostream& os, const QueryResult& qr, size_t head, size_t tail)
//{
//    if (head > tail)
//    {
//        os << "Error: Invalid range! (head=" << head << ", tail=" << tail
//            << "). Head must be <= tail.\n";
//        return os;
//    }
//
//    os << "The result of your query \"" << qr.sought << "\" in range ("
//        << head << "-" << tail << ") is:\n";
//
//    for (const auto& index : *qr.lines)
//    {
//        if (index + 1 >= head && index + 1 <= tail)  // 只打印符合范围的行
//        {
//            os << "\t(line " << index + 1 << ") "
//                << *(qr.file->begin() + index) << "\n";
//        }
//    }
//    return os;
//}
