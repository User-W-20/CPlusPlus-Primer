//#pragma once
//#include"delete.hpp"
//#include<functional>
//
//namespace cp5
//{
//	template<typename T>
//	class SharedPointer;
//
//	template<typename T>
//	auto swap(SharedPointer<T>& lhs, SharedPointer<T>& rhs)
//	{
//		using std::swap;
//		swap(lhs.ptr, rhs.ptr);
//		swap(lhs.ref_count, rhs.ref_count);
//		swap(lhs.deleter, rhs.deleter);
//	}
//	template<typename T>
//	class SharedPointer
//	{
//	public:
//		SharedPointer() :ptr{ nullptr }, ref_count{ new std::size_t(1) }, deleter{ cp5::Delete{} } {}
//
//		SharedPointer(SharedPointer const& other) :ptr{ other.ptr }, ref_count{ other.ref_count }, deleter{ other.deleter }
//		{
//			++*ref_count;
//		}
//
//		SharedPointer(SharedPointer&& other)noexcept :ptr{ other.ptr }, ref_count{ other.ref_count }, deleter{ std::move(other.deleter) }
//		{
//			other.ptr = nullptr;
//			other.ref_count = nullptr;
//		}
//
//		explicit SharedPointer(T* raw_ptr)
//			: ptr{ raw_ptr }, ref_count{ new std::size_t(1) }, deleter{ cp5::Delete{} }
//		{
//		}
//
//		SharedPointer& operator=(SharedPointer const& rhs)
//		{
//			++*rhs.ref_count;
//			decrement_and_destroy();
//			ptr = rhs.ptr, ref_count = rhs.ref_count, deleter = rhs.deleter;
//			return *this;
//		}
//
//		SharedPointer& operator=(SharedPointer&& rhs)noexcept
//		{
//			cp5::swap(*this, rhs);
//			rhs.decrement_and_destroy();
//			return *this;
//		}
//
//		operator bool()const
//		{
//			return ptr ? true : false;
//		}
//
//		T& operator*()const
//		{
//			return *ptr;
//		}
//
//		T* operator->()const
//		{
//			return &*ptr;
//		}
//
//		auto use_count()const
//		{
//			return *ref_count;
//		}
//
//		auto get()const
//		{
//			return ptr;
//		}
//
//		auto unique()const
//		{
//			return 1 == *ref_count;
//		}
//
//		auto swap(SharedPointer& rhs)
//		{
//			cp5::swap(*this, rhs);
//		}
//
//		auto reset()
//		{
//			decrement_and_destroy();
//		}
//
//		auto reset(T* pointer)
//		{
//			if (ptr != pointer)
//			{
//				decrement_and_destroy();
//				ptr = pointer;
//				ref_count = new std::size_t(1);
//			}
//		}
//
//		auto reset(T* pointer, const std::function<void(T*)>& d)
//		{
//			reset(pointer);
//			deleter = d;
//		}
//
//		~SharedPointer()
//		{
//			decrement_and_destroy();
//		}
//	private:
//		T* ptr;
//		std::size_t* ref_count;
//		std::function<void(T*)>deleter;
//
//		auto decrement_and_destroy()
//		{
//			if (ref_count && 0 == -- * ref_count)
//			{
//				deleter(ptr);
//				delete ref_count;
//			}
//			else if (ref_count&& ptr == nullptr)
//			{
//				delete ref_count;
//			}
//			ptr = nullptr;
//			ref_count = nullptr;
//		}
//	};
//}