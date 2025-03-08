//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//#include<functional>
//
//int main()
//{
//	using std::placeholders::_1;
//
//	std::vector<int>ivec{ 1, 111, 1111, 11111 };
//	int count = std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(),_1, 1024));
//	std::cout << count << std::endl;
//
//	std::vector<std::string> svec{ "pooh", "pooh", "pezy", "pooh" };
//	auto found = std::find_if(svec.cbegin(), svec.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
//	std::cout << *found << std::endl;
//
//	//std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<>(), _1, 2));
//	std::transform(ivec.begin(), ivec.end(), ivec.begin(), [](int x) {return x * 2; });
//	for (int i : ivec)std::cout << i << " ";
//	std::cout << std::endl;
//}