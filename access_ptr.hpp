#ifndef JSS_ACCESS_PTR_HPP
#define JSS_ACCESS_PTR_HPP
#include <cstddef>
#include <utility>

namespace jss {
    template <typename T> class access_ptr {
    public:
        constexpr access_ptr() noexcept : ptr(nullptr) {}
        constexpr access_ptr(std::nullptr_t) noexcept : ptr(nullptr) {}
        constexpr access_ptr(T *ptr_) noexcept : ptr(ptr_) {}

        constexpr T *get() const noexcept {
            return ptr;
        }

        constexpr T &operator*() const noexcept {
            return *ptr;
        }

        constexpr T *operator->() const noexcept {
            return ptr;
        }

        constexpr explicit operator bool() const noexcept {
            return ptr != nullptr;
        }

        void swap(access_ptr &other) noexcept {
            std::swap(ptr, other.ptr);
        }

        friend constexpr bool
        operator==(access_ptr const &lhs, access_ptr const &rhs) noexcept {
            return lhs.ptr == rhs.ptr;
        }

        friend constexpr bool
        operator!=(access_ptr const &lhs, access_ptr const &rhs) noexcept {
            return lhs.ptr != rhs.ptr;
        }

    private:
        T *ptr;
    };

    template <typename T> void swap(access_ptr<T> &lhs, access_ptr<T> &rhs) {
        lhs.swap(rhs);
    }

} // namespace jss

#endif
