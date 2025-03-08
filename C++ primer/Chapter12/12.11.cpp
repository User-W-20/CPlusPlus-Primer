//#include<iostream>
//#include<vector>
//#include<string>
//#include<memory>
//
//void process(std::shared_ptr<int>ptr)
//{
//	std::cout << "inside the process function:" << ptr.use_count() << "\n";
//}
//
//int main()
//{
//	std::shared_ptr<int>p(new int(42));
//
//	process(std::shared_ptr<int>(p.get()));// Ë«ÖØÊÍ·Å (double free) 
//	return 0;
//}
