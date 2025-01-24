//#include <iostream>
//#include <string>
//#include <memory>
//
//using std::string; using std::unique_ptr;
//
//int main()
//{
//	unique_ptr<string> p1(new string("pezy"));
//	//unique_ptr<string> p2(p1);//copy
//	//错误： 调用 “unique_ptr<string>”的隐式删除副本构造函数
//
//	//unique_ptr<string> p3 = p1; // assign
//	//错误： 调用 “unique_ptr<string>”的隐式删除副本构造函数
//
//	std::cout << *p1 << std::endl;
//	p1.reset(nullptr);
//	return 0;
//}