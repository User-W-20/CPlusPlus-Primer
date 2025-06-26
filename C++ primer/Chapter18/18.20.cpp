//#include<iostream>
//
//namespace primerLib {
//	void compute();//错误：不运行，匹配调用中的参数过多
//	void compute(const void*) {};
//}
////有效，与参数最接近，所以优先被选择
//void compute(int) { std::cout << "compute(int)" << std::endl; };
////有效，将参数转换为double
//void compute(double, double = 3.4);
////有效，转换成字符指针
//void compute(char* x, char * = 0);
//
//void f() {
//	using  primerLib::compute;
//	compute(0);
//}
//
//int main() {
//	f();
//	return 0;
//}