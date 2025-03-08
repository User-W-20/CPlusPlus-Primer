//#include"14.30_StrBlob.h"
//#include<iostream>
//
//int main()
//{
//    StrBlob sb1{ "a", "b", "c" };
//    StrBlob sb2 =sb1;
//
//    sb2[1] = "d";
//
//    if (sb1 > sb2) {
//        for (ConstStrBlobPtr iter = sb1.cbegin(); iter != sb1.cend(); ++iter)
//            std::cout << *iter << " ";
//        std::cout << std::endl;
//    }
//    else
//    {
//        std::cout << "error"<<std::endl;;
//    }
//
//
//    ConstStrBlobPtr iter(sb2);
//    std::cout << iter->size() << std::endl;
//}