<!--(for op, opcode, optype, opcount, typesigs, layouts, broadcast in data)-->
template <typename T>
inline
multi_array<bool>& @!op!@ (multi_array<T>& rhs)
{
    multi_array<bool>* res = &Runtime::instance().create_base<bool, T>(rhs); // Construct result
    @!opcode.lower()!@ (*res, rhs); // Enqueue
    res->setTemp(true); // Mark result as temp

    return *res;
}
<!--(end)-->
