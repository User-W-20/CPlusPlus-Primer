//#pragma once
//#include<string>
//#include<iostream>
//
//template<unsigned H,unsigned W>
//class Screen
//{
//public:
//	typedef std::string::size_type pos;
//
//	Screen() = default;
//
//	Screen(char c):contents(H*W,c){}
//
//	char get()const
//	{
//		return contents[cursor];
//	}
//
//	Screen& move(pos r, pos c);
//
//	Screen& display(std::ostream& os)
//	{
//		for (pos i = 0; i < H; ++i)
//			os << contents.substr(i * W, W) << "\n";
//		return *this;
//	}
//
//	friend std::ostream& operator<<(std::ostream& os, const Screen<H, W>& c)
//	{
//		for (pos i = 0; i < H; ++i)
//			os << c.contents.substr(i * W, W) << "\n";
//		return os;
//	}
//
//	friend std::istream& operator>>(std::istream& is, Screen& c)
//	{
//		std::string temp;
//		is >> temp;
//		temp.resize(H * W, ' ');
//		c.contents = temp;
//		return is;
//	}
//
//	
//private:
//	pos cursor = 0;
//	pos height = H, width = W;
//	std::string contents;
//};
//
//template<unsigned H, unsigned W>
//Screen<H,W>& Screen<H, W>::move(pos r, pos c)
//{
//	cursor = r * W + c;
//	return *this;
//}