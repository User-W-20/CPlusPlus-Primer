//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//#include <fstream>
//
//#include"15.39_40_Query.h"
//#include"15.39_40_TextQuery.h"
//
//int main()
//{
//	std::ifstream file(R"(C:\Users\X\source\repos\C++ primer\C++ primer\Chapter15\test.txt)");
//
//	TextQuery tQuery(file);
//
//	Query q= Query("fieryzzz") | Query("wind");
//	Query q2= Query("fieryzzz") & Query("wind");
//	Query q3 = ~Query("fieryzzz")  ;
//	std::cout << q.eval(tQuery);
//	std::cout << q2.eval(tQuery);
//	std::cout << q3.eval(tQuery);
//
//	return 0;
//}