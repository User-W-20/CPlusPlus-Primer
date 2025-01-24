//#include<iostream>
//#include"13.34_36_37.h"
//
//
//void swap(Message& lhs, Message& rhs)
//{
//	using std::swap;
//	lhs.remove_from_Folders();
//	rhs.remove_from_Folders();
//
//	swap(lhs.folders, rhs.folders);
//	swap(lhs.contents, rhs.contents);
//
//	lhs.add_to_Folders(lhs);
//	rhs.add_to_Folders(rhs);
//}
//
//void Message::save(Folder& f)
//{
//	folders.insert(&f);
//	f.addMsg(this);
//}
//
//void Message::remove(Folder& f)
//{
//	folders.erase(&f);
//	f.remMsg(this);
//}
//
//void Message::add_to_Folders(const Message& m)
//{
//	for (auto f : m.folders)
//		f->addMsg(this);
//}
//
//Message::Message(const Message &m) 
//    : contents(m.contents), folders(m.folders) 
//{
//    add_to_Folders(m);
//}
//
//void Message::remove_from_Folders()
//{
//	for (auto f : folders)
//		f->remMsg(this);
//}
//
//Message::~Message()
//{
//	remove_from_Folders();
//}
//
//Folder& Folder::operator=(const Folder& rhs)
//{
//	remove_from_Message();
//	msgs = rhs.msgs;
//	add_to_Message(rhs);
//	return *this;
//
//}
//
//void Folder::print_debug()
//{
//	for (auto m : msgs)
//		std::cout << m->contents << std::endl;
//	std::cout << std::endl;
//}
//
//int main()
//{
//	return 0;
//}