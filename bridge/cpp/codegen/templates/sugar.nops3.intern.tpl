//
//  multi_array - Internally defined operator overloads
//
<!--(for op, opcode, optype, opcount, typesigs, layouts, broadcast in data)-->
template <typename T>
inline
multi_array<T>& multi_array<T>::@!op!@ (const T& rhs)
{
    @!opcode.lower()!@ (*this, *this, rhs);
    return *this;
}

template <typename T>
inline
multi_array<T>& multi_array<T>::@!op!@ (multi_array<T>& rhs)
{
    @!opcode.lower()!@ (*this, *this, rhs);
    return *this;
}
<!--(end)-->
