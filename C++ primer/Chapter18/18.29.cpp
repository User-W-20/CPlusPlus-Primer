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
//	//pb = new Class;//不能将 "Class *" 类型的值分配到 "Base *" 类型的实体
//	//pc = new Final;//error C2594: “=”: 从“Final *”到“Class *”的转换不明确
//	//pmi = pb; //不能将 "Base *" 类型的值分配到 "MI *" 类型的实体
//	pd2 = pmi;
//	return 0;
//}