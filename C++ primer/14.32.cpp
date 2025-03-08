//#include"14.30_StrBlob.h"
//#include"14.32.h"
//#include<iostream>
//
//StrBlobPtr& StrBlobPtr_pointer::operator*()const
//{
//	return *pointer;
//}
//
//StrBlobPtr* StrBlobPtr_pointer::operator->()const
//{
//	return pointer;
//}
//
//int main()
//{
//	StrBlob sb{ "hello", "world" };
//	StrBlobPtr iter = sb.begin();
//	StrBlobPtr_pointer p(&iter);
//	std::cout << p->deref() << std::endl;
//}