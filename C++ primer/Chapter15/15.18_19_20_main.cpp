//#include<iostream>
//#include<string>
//#include"15.15_16_17_Bulk_quote.h"
//#include"15.15_16_17_Disc_quote.h"
//#include"15.15_16_17_Limit_quote.h"
//#include"15.15_16_17_Quote.h"
//
//class Base
//{
//public:
//	void pub_mem();
//protected:
//	int prot_mem;     
//private:
//	char priv_mem;
//};
//
//struct  Pub_Derv:public Base
//{
//	void menfcn(Base& b) { b = *this; }
//};
//
//struct Priv_Derv : private   Base
//{
//	void memfcn(Base& b) { b = *this; }
//};
//struct Prot_Derv : protected Base
//{
//	void memfcn(Base& b) { b = *this; }
//};
//
//struct Derived_from_Public :public Pub_Derv
//{
//	void memfcn(Base& b) { b = *this; }
//};
//
//struct  Derived_from_Private:public Priv_Derv
//{
//	//void memfcn(Base& b) { b = *this; }
//};
//
//struct Derived_from_Protected : public Prot_Derv
//{
//	void memfcn(Base& b) { b = *this; }
//};
//
//
//int main()
//{
//
//    Pub_Derv  d1;
//    Base* p = &d1;
//
//    Priv_Derv d2;
//    //p = &d2;
//
//    Prot_Derv d3;
//    //p = &d3;
//
//    Derived_from_Public dd1;
//   // p = &dd1;
//
//    Derived_from_Private dd2;
//    //p =& dd2;
//
//    Derived_from_Protected dd3;
//    //p = &dd3;
//
//
//    return 0;
//}