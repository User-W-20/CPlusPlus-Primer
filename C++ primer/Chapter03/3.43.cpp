//#include<iostream>
//
//using std::cout;
//using std::endl;
//
//int main()
//{
//	int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
//
//	//范围for
//	for (const int(&p)[4] : ia)
//	{
//		for (int q : p)
//		{
//			cout << q << " ";
//		}
//	}
//
//	//普通for
//	for (size_t i = 0; i != 3; ++i)
//	{
//		for (size_t j = 0; j != 4; ++j)
//		{
//			cout << ia[i][j] << " ";
//		}
//	}
//	
//	//使用指针
//	for (int(*p)[4] = ia; p != ia + 3; ++p)
//	{
//		for (int* q = *p; q != *p + 4; ++q)
//		{
//			cout << *q << " ";
//		}
//	}
//	cout << endl;
//
//	return 0;
//
//}