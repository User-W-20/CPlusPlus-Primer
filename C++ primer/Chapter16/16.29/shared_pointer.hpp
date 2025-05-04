//#pragma once
//#include "DebugDelete.hpp"
//#include <functional>
//#include <memory>
//#include <stdexcept>
//
//namespace my_sharedPtr {
//    template<typename> class shared_pointer;
//    template<typename T> void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs);
//
//    template<typename T>
//    class shared_pointer {
//        friend void swap<T>(shared_pointer<T>& lhs, shared_pointer<T>& rhs);
//
//    public:
//        shared_pointer() = default;
//
//        explicit shared_pointer(T* up, std::function<void(T*)> d = DebugDelete())
//            : ptr{ up }, ref_count{ new std::size_t(1) }, deleter{ d } {
//        }
//
//        shared_pointer(const shared_pointer& sp)
//            : ptr{ sp.ptr }, ref_count{ sp.ref_count }, deleter{ sp.deleter } {
//            ++*ref_count;
//        }
//
//        
//
//        shared_pointer(shared_pointer&& sp) noexcept;
//
//        shared_pointer& operator=(const shared_pointer& rhs);
//        shared_pointer& operator=(shared_pointer&& rhs) noexcept;
//
//        operator bool() const { return ptr != nullptr; }
//        T& operator*() const { return *ptr; }
//        T* operator->() const { return ptr; }
//
//        std::size_t use_count() const { return ref_count ? *ref_count : 0; }
//        T* get() const noexcept { return ptr; }
//        bool unique() const noexcept { return use_count() == 1; }
//
//        void swap(shared_pointer& rhs) { ::my_sharedPtr::swap(*this, rhs); }
//        void reset() noexcept { decrement_n_destroy(); }
//        void reset(T* p);
//        void reset(T* p, const std::function<void(T*)>& d);
//
//        ~shared_pointer() {
//            decrement_n_destroy();
//        }
//
//    private:
//        T* ptr = nullptr;
//        std::size_t* ref_count = nullptr;
//        std::function<void(T*)> deleter{ DebugDelete() };
//
//        void decrement_n_destroy();
//    };
//
//    template<typename T>
//    void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs) {
//        using std::swap;
//        swap(lhs.ptr, rhs.ptr);
//        swap(lhs.ref_count, rhs.ref_count);
//        swap(lhs.deleter, rhs.deleter);
//    }
//
//    template<typename T>
//    shared_pointer<T>::shared_pointer(shared_pointer&& sp) noexcept
//        : ptr{ sp.ptr }, ref_count{ sp.ref_count }, deleter{ std::move(sp.deleter) } {
//        sp.ptr = nullptr;
//        sp.ref_count = nullptr;
//    }
//
//    template<typename T>
//    shared_pointer<T>& shared_pointer<T>::operator=(const shared_pointer& rhs) {
//        if (this != &rhs) {
//            ++*rhs.ref_count;
//            decrement_n_destroy();
//            ptr = rhs.ptr;
//            ref_count = rhs.ref_count;
//            deleter = rhs.deleter;
//        }
//        return *this;
//    }
//
//    template<typename T>
//    shared_pointer<T>& shared_pointer<T>::operator=(shared_pointer&& rhs) noexcept {
//        if (this != &rhs) {
//            decrement_n_destroy();
//            ptr = rhs.ptr;
//            ref_count = rhs.ref_count;
//            deleter = std::move(rhs.deleter);
//            rhs.ptr = nullptr;
//            rhs.ref_count = nullptr;
//        }
//        return *this;
//    }
//
//    template<typename T>
//    void shared_pointer<T>::reset(T* p) {
//        if (ptr != p) {
//            decrement_n_destroy();
//            ptr = p;
//            ref_count = new std::size_t(1);
//        }
//    }
//
//    template<typename T>
//    void shared_pointer<T>::reset(T* p, const std::function<void(T*)>& d) {
//        if (ptr != p) {
//            decrement_n_destroy();
//            ptr = p;
//            ref_count = new std::size_t(1);
//            deleter = d;
//        }
//    }
//
//    template<typename T>
//    void shared_pointer<T>::decrement_n_destroy() {
//        if (ref_count && -- * ref_count == 0) {
//            deleter(ptr);
//            delete ref_count;
//        }
//        ptr = nullptr;
//        ref_count = nullptr;
//    }
//
//    template<typename T>
//    std::ostream& operator<<(std::ostream& os, const shared_pointer<T>& p) {
//        os << p.get();
//        return os;
//    }
//}