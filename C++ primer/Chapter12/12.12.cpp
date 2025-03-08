//#include <iostream>
//#include <vector>
//#include <string>
//#include <memory>
//
//void process(std::shared_ptr<int>ptr)
//{
//	std::cout << "inside the process function:" << ptr.use_count() << "\n";
//}
//
//int main()
//{
//	auto p = new int();
//	auto sp = std::make_shared<int>();
//	//process(sp);//合法，只需将 sp 作为 shared_ptr 复制到 process()。
//
//	//process(new int());//不合法， 普通指针不能隐式转换为智能指针。
//
//	//process(p);//不合法,普通指针不能隐式转换为智能指针。
//
//	//process(std::shared_ptr<int>(p));//合法,但这样做是不好的。
//	//因为将智能指针与原始指针一起使用可能会导致问题。双重释放
//	return 0;
//}