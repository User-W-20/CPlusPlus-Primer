//#include<iostream>
//#include<vector>
//
//struct Base1
//{
//	void print(int)const {
//		std::cout << "Base1 Print Used" << std::endl;
//	}
//protected:
//	int ival;
//	double dval;
//	char cval;
//private:
//	int* id;
//};
//
//struct Base2
//{
//	void print(double)const;
//protected:
//	double fval;
//private:
//	double dval;
//};
//
//struct  Derived:public Base1
//{
//	void print(std::string)const;
//protected:
//	std::string sval = std::string(1, Base1::cval);
//	double dval;
//};
//
//struct MI:public Derived,public Base2
//{
//	void print(std::vector<double>){}
//	void print(int x) {
//		Base1::print(x);
//	}
//
//
//int ival;
//double dval;
//
//void foo(double cval) {
//	int dval;
//	dval = Base1::dval + Derived::dval;
//	Base2::fval = dvec.back() - 1;
//	std::cout << dval;
//}
//protected:
//	std::vector<double>dvec = { 9,8,7 };
//};
//
//int main() {
//	MI mi;
//	return 0;
//}