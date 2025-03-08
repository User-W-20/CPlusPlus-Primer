//#include <iostream>
//#include <vector>
//#include <string>
//#include <memory>
////为什么 shared_ptr 没有 release 成员？
//// 因为指向同一个对象的其他 shared_ptr 仍然可以删除这个对象。
//// 因此，提供这个成员毫无意义。
//int main()
//{
//	int ix = 1024, * pi = &ix, * pi2 = new int(2048);
//	typedef std::unique_ptr<int> IntP;
//
//	//IntP p0(ix);@brief错误：从 “int ”到 “std::unique_ptr<int>::指针 { 又名 int* }”的转换无效 [-fpermissive]
//
//
//	/*IntP p1(pi); @brief 下面的代码可以编译，但运行时会出错。
//		* 原因是当 unique_ptr p1 离开作用域时，将调用 delete
//		* 以释放对象。但该对象没有使用 new 分配。
//		* 操作系统会抛出一个错误。
//		* 错误代码*/
//
//	/*IntP p2(pi2); @brief 这段代码可以编译，但在运行时会导致指针悬空。
//		* 原因是 unique_ptr 会释放原始指针所指向的对象。
//		* 指向的对象。
//		* @坏代码*/
//
//	/*IntP p3(&ix); @brief 当 unique_ptr 离开作用域时，它会调用 delete 来释放未使用 new 分配的* 对象。
//		* 未使用 new 分配的对象。
//		* @坏代码*/
//
//
//	//IntP p4(new int(2048));// @brief 推荐
//
//	/*IntP p2(new int(555));
//	IntP p5(p2.get());
//	@brief error : double free or corruption at run time
//		* 两个 unique_ptr 指向同一个对象。因此，当两个对象都退出
//		* 范围时，操作系统将抛出双重释放或损坏。
//		* @badcode*/
//	return 0;
//}