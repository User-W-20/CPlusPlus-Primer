//#include <iostream>
//using std::cout; using std::cin; using std::endl;
//
//#include <fstream>
//using std::ifstream;
//
//#include <string>
//using std::string;
//
//#include <vector>
//using std::vector;
//
//#include "queryresult.h"
//#include "textquery.h"
//#include "query.h"
//#include "andquery.h"
//#include "orquery.h"
//#include "notquery.h"
//
//int main()
//{
//	ifstream fin(R"(C:\Users\X\source\repos\C++ primer\C++ primer\Chapter15\15.42_c\test.txt)");
//
//	TextQuery text(fin);
//
//	auto q = ~Query("Alice");
//
//	auto result = q.eval(text);
//	print(cout, result);
//	cout << endl;
//	print(cout, result, -3, 5);
//	cout << endl;
//	print(cout, result, 3, 5);
//	cout << endl;
//	print(cout, result, 3, 20);
//	cout << endl;
//
//	return 0;
//
//}