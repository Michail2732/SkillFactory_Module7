#include "IntegerArray.h"
#include <exception>
#include <stdexcept>

using namespace std;

namespace module_7
{
    IntegerArray::IntegerArray(int length) throw()
    {
        if (length < 0)
            throw length_error("Invalid length. Length must be large or equal 0");
        _length = length;
        _array = new int[length] {};
    }

    IntegerArray::IntegerArray(const IntegerArray& container) noexcept : IntegerArray(container._length)
    {        
        copy_n(container._array, _length, _array);
    }

    IntegerArray::~IntegerArray()
    {
        delete[] _array;
    }

    int IntegerArray::GetLength() const noexcept
    {
        return _length;
    }

    void IntegerArray::Resize(int newLength)
    {
        if (_length == newLength)
            return;        
        if (newLength <= 0)
        {
            Erase();
            return;
        }

        int* newArray = new int[newLength] {};

        if (_length > 0)
        {
            int elementsCount = newLength > _length ? _length : newLength;
            copy_n(_array, elementsCount, newArray);
        }            
        delete[] _array;
        _array = newArray;
        _length = newLength;
    }

    void IntegerArray::InsertBefore(int value, int index) throw()
    {
        if (index < 0 || index > _length)
        {
            throw out_of_range("Index out of range");
        }
        
        int* newArray = new int[_length + 1] {};
        copy_n(_array, index, newArray);
        copy_n(_array + index, _length - index, newArray + index + 1);
        newArray[index] = value;
        delete[] _array;
        _array = newArray;
        _length++;
    }

    void IntegerArray::InsertBegin(int value) noexcept
    {
        InsertBefore(value, 0);
    }

    void IntegerArray::InsertEnd(int value) noexcept
    {
        InsertBefore(value, _length);
    }

    const int IntegerArray::IndexOf(int value) const noexcept
    {
        for (int i = 0; i < _length; i++)
        {
            if (_array[i] == value)
                return i;
        }
        return -1;
    }

    void IntegerArray::Erase()
    {
        delete[] _array;
        _array = nullptr;
        _length = 0;
    }

    void IntegerArray::Remove(int index) throw()
    {
        if (index < 0 || index >= _length)
        {
            throw out_of_range("Index out of range");
        }
        int* newArray = new int[_length - 1] {};
        copy_n(_array, index, newArray);
        if (index > _length - 1)
            copy_n(_array + index + 1, _length - index - 1, newArray + index);
        delete[] _array;
        _length--;
        _array = newArray;
    }

    int& IntegerArray::operator[](int index) const throw()
    {
        if (index >= 0 && index < _length)
        {
            return _array[index];
        }
        throw out_of_range("Index out of range");
    }


}
