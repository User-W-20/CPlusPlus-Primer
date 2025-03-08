//#include <iostream>
//#include <forward_list>
//
//using std::forward_list;
//using std::cout;
//
//auto remove_odds(forward_list<int>& flist)
//{
//	auto is_odds = [](int i) {return i & 0x1; };
//	flist.remove_if(is_odds);
//}
//
//int main()
//{
//	forward_list<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	remove_odds(data);
//	for (auto i : data)
//		cout << i << " " ;
//
//}