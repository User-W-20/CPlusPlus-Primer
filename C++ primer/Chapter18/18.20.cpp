//#include<iostream>
//
//namespace primerLib {
//	void compute();//���󣺲����У�ƥ������еĲ�������
//	void compute(const void*) {};
//}
////��Ч���������ӽ����������ȱ�ѡ��
//void compute(int) { std::cout << "compute(int)" << std::endl; };
////��Ч��������ת��Ϊdouble
//void compute(double, double = 3.4);
////��Ч��ת�����ַ�ָ��
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