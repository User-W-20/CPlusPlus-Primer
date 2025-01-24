//#include <iostream>
//#include <vector>
//#include <list>
//#include <algorithm>
//
//using std::vector; using std::cout; using std::endl; using std::list; using std::cin; using std::fill_n;
//
//template<typename Sequence>
//void print(Sequence const& seq)
//{
//	for (const auto& i : seq)
//		cout << i << " ";
//	cout << endl;
//}
//
//int main()
//{
//	//a
//	vector<int >vec;
//	list<int >lst;
//	int i;
//	while (cin >> i)
//		lst.push_back(i);
//	//copy(lst.cbegin(), lst.cend(), vec.begin());
//	//fixed use back_inserter
//	copy(lst.cbegin(), lst.cend(), back_inserter(vec));
//	//b
//	vector<int> v;
//	v.reserve(10);
//	//1.use resize(10)
//	//2.use back_inserter 
//	fill_n(std::back_inserter(v), 10, 0);
//
//	print(vec);
//	print(v);
//	
//}