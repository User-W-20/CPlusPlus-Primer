//#include<iostream>
//using namespace std;
//
//class Class {
//public:
//	Class() { cout << "Class() called" << endl; }
//	~Class(){ cout << "~Class() called" << endl; }
//};
//
//class Base :public Class {
//public:
//	Base() { cout << "Base() called" << endl; }
//	~Base() { cout << "~Base() called" << endl; }
//};
//
//class D1 : virtual public Base {
//public:
//	D1() { cout << "D1() called" << endl; }
//	~D1() { cout << "~D1() called" << endl; }
//};
//
//class D2 : virtual public Base {
//public:
//	D2() { cout << "D2() called" << endl; }
//	~D2() { cout << "~D2() called" << endl; }
//};
//
//class MI :public D1, public D2 {
//public:
//	MI() { cout << "MI() called" << endl; }
//	~MI() { cout << "~MI() called" << endl; }
//};
//
//class Final :public MI, public Class {
//public:
//	Final() { cout << "Final() called" << endl; }
//	~Final() { cout << "~Final() called" << endl; }
//};
//
//int main() {
//	Final final;
//	Base* pb = nullptr;
//	Class* pc = nullptr;
//	MI* pmi = nullptr;
//	D2* pd2 = nullptr;
//	//pb = new Class;//���ܽ� "Class *" ���͵�ֵ���䵽 "Base *" ���͵�ʵ��
//	//pc = new Final;//error C2594: ��=��: �ӡ�Final *������Class *����ת������ȷ
//	//pmi = pb; //���ܽ� "Base *" ���͵�ֵ���䵽 "MI *" ���͵�ʵ��
//	pd2 = pmi;
//	return 0;
//}