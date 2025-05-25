//#include<iostream>
//#include<random>
//#include<string>
//
//unsigned random_gen();
//
//unsigned random_gen(unsigned seed);
//
//unsigned random_gen(unsigned seed, unsigned min, unsigned max);
//
//int main()
//{
//	std::string temp;
//	while (std::cin >> temp)
//		//std::cout << std::hex << random_gen(19, 1, 10) << std::endl;
//		//std::cout << std::hex << random_gen(19) << std::endl;
//		//std::cout << std::hex << random_gen() << std::endl;
//
//	return 0;
//}
//
//unsigned random_gen()
//{
//	static std::default_random_engine e;
//	static std::uniform_int_distribution<unsigned>ud;
//	return ud(e);
//}
//
//unsigned random_gen(unsigned seed)
//{
//	 std::default_random_engine e(seed);
//	 std::uniform_int_distribution<unsigned>ud;
//	return ud(e);
//}
//
//unsigned random_gen(unsigned seed,unsigned min,unsigned max)
//{
//	 std::default_random_engine e(seed);
//	 std::uniform_int_distribution<unsigned>ud(min,max);
//	return ud(e);
//}