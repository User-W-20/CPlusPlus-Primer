//#include<iostream>
//#include<stdexcept>
//#include<memory>
//#include<fstream>
//#include<vector>
//
//struct intArry
//{
//	intArry():p(nullptr){}
//
//	explicit intArry(std::size_t s):p(new int[s]){}
//
//	~intArry() {
//		delete[] p;
//	}
//
//	int* p;
//};
//
//void exercise(int* b, int* e) {
//	std::vector<int>v(b, e);//v将被析构函数销毁
//
//	//旧代码
//	//int* p = new int[v.size()];动态分配的int数组将无法被释放
//
//	//法1
//	intArry p(v.size());
//
//	//法2
//	std::shared_ptr<int>p(new int[v.size()], [](int* p) {delete p; });//使用lambda删除数组
//
//	std::ifstream("ints");
//}
//
//int main() {
//	std::range_error r("error");
//	throw r;
//
//	std::exception* p = &r;
//	throw p;
//}


