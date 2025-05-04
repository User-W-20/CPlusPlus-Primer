//template<typename T, typename U, typename V>void f1(T, U, V);
//
//template<typename T>T f2(T&);
//
//template<typename T>inline T foo(T, unsigned int*);
////inline必须在temple后面
//
//template<typename T>T f4(T, T);
//
////名称遮蔽
//typedef char Ctype;
//template <typename T> T f5(T a); // 将模板参数改为 'T'
//
//int main()
//{
//	return 0;
//}