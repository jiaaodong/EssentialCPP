#include"Triangular_iterator.h"
#include"Triangular.h"

// Do not write inline in this cpp file
bool Triangular_iterator::operator==(const Triangular_iterator& rhs) const{
    return _index == rhs._index;
}

bool Triangular_iterator::operator!=(const Triangular_iterator& rhs) const{
    return !(*this == rhs); // Use equality operator overload to implement inequality operator
}

int Triangular_iterator::operator*() const{
    check_integrity();
    return Triangular::_elems[_index]; // Does not need tp specify to which elems vector does this iterator points to, because there is only ONE elem vector;
}


void Triangular_iterator::check_integrity() const{
    if(_index >= Triangular::_max_elems){ // _max_elems is static member data
        return;
    }

    if(_index >= Triangular::_elems.size()){
        Triangular::gen_elements(_index + 1);
    }
}

Triangular_iterator& Triangular_iterator::operator++(){ // Prefix edition
    ++_index;
    check_integrity();
    return *this;
}

Triangular_iterator Triangular_iterator::operator++(int){ // 
    Triangular_iterator tmp = *this; // Postfix edition saves the original value into temporary variable and increase `this'
    ++_index; // save as ++this->_index;
    check_integrity();
    return tmp;
}


Triangular_iterator::~Triangular_iterator()
{
}