//#include"14.18_StrVec.h"
//#include<iostream>
//
//int main()
//{
//    StrVec vec;
//    vec.push_back("hello");
//    vec.push_back("world");
//    vec.push_back("StrVec");
//
//
//    std::cout << "StrVec contents:" << std::endl;
//    for(auto &s:vec)
//        std::cout << s << std::endl;
//
//    std::cout << "Size: " << vec.size() << std::endl;
//    std::cout << "Capacity: " << vec.capacity() << std::endl;
//
//    vec.resize(5, "default");
//    std::cout << "After resize(5):" << std::endl;
//    for (auto& s : vec) {
//        std::cout << s << std::endl;
//    }
//
//    vec.reserve(10);
//    std::cout << "After reserve(10):" << std::endl;
//    std::cout << "Capacity: " << vec.capacity() << std::endl;
//
//    StrVec vec2{ "apple", "banana", "cherry" };
//    std::cout << "vec2 contents:" << std::endl;
//    for (auto& s : vec2) {
//        std::cout << s << std::endl;
//    }
//
//
//    if (vec == vec2) {
//        std::cout << "vec and vec2 are equal." << std::endl;
//    }
//    else {
//        std::cout << "vec and vec2 are not equal." << std::endl;
//    }
//
//
//    if (vec > vec2) {
//        std::cout << "vec is greater than vec2." << std::endl;
//    }
//
//
//    StrVec vec3 = std::move(vec);
//    std::cout << "After move, vec3 contents:" << std::endl;
//    for (auto& s : vec3) {
//        std::cout << s << std::endl;
//    }
//
//    return 0;
//}