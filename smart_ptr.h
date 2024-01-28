#ifndef SMART_PTR_H
#define SMART_PTR_H

template <typename T>
class SmartUniquePtr {
private:
    T* ptr;

public:
    SmartUniquePtr(T* p) : ptr(p) {}

    ~SmartUniquePtr() {
        delete ptr;
    }

    T* get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
};

template <typename T>
class SmartSharedPtr {
private:
    T* ptr;
    size_t* refCount;

public:
    SmartSharedPtr(T* p) : ptr(p), refCount(new size_t(1)) {}

    SmartSharedPtr(const SmartSharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        (*refCount)++;
    }

    ~SmartSharedPtr() {
        (*refCount)--;
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
        }
    }

    SmartSharedPtr& operator=(const SmartSharedPtr& other) {
        if (this != &other) {
            (*refCount)--;
            if (*refCount == 0) {
                delete ptr;
                delete refCount;
            }

            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    T* get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    size_t useCount() const {
        return *refCount;
    }
};

#endif // SMART_PTR_H
