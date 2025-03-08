//#include<iostream>
//#include<vector>
//
//using std::begin;
//using std::end;
//using std::vector;
//using std::endl;
//using std::cout;
//
////pb是array指向begin的指针，pe是array指向end的指针
//bool compare(int* const pb1, int* const pe1, int* const pb2, int* const pe2)
//{
//	if ((pe1 - pb1) != (pe2 - pb2))//有不同的值
//	{
//		return false;
//	}
//	else
//	{
//		for (int* i = pb1, *j = pb2; (i != pb1) && (j != pb2); ++i, ++j)
//		{
//			if (*i != *j)
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int arr1[3] = { 0,1,2 };
//	int arr2[3] = { 0,2,4 };
//
//	if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
//	{
//		cout<<"两个数组相等"<<endl;
//	}
//	else
//	{
//		cout << "两个数组不相等" << endl;
//	}
//
//	cout<< "============" << endl;
//
//	vector<int>vec1 = { 0,1,2 };
//	vector<int>vec2 = { 0,1,2 };
//
//	if (vec1 == vec2)
//	{
//		cout<< "两个数组相等" << endl;
//	}
//	else
//	{
//		cout << "两个数组不相等" << endl;
//	}
//
//	return 0;
//}
