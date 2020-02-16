#include"Triangular.h"

Triangular::Triangular(int len, int bp)
{
    _begin_pos = bp > 0 ? bp:1;
    _length = len > 0 ? len:1;
    _next = _begin_pos - 1; // TODO: Why minus 1

    int elem_cnt = _begin_pos + _length - 1;
    if(_elems.size() < elem_cnt){
        gen_elements(elem_cnt);
    }
    
}

Triangular::Triangular(const Triangular& rhs)
: _length(rhs._length), _begin_pos(rhs._begin_pos), _next(rhs._next) // According to the format of this initialization, we could tell that this is not needed (will be defined automatically)
{// Since the elems vector is static member data, there is no need to `copy' this vector when new Triangular sequence is created
}


Triangular::~Triangular()
{
}

Triangular& Triangular::copy(const Triangular & rhs){

    if(this != &rhs){
        _length = rhs._length;
        _begin_pos = rhs._begin_pos;
        _next = rhs._begin_pos - 1;
    }

    return *this; // The returned value is not a pointer but a value
}

bool Triangular::is_elem(int value){
    if(!_elems.size()||_elems[_elems.size() - 1] < value){
        gen_elems_to_value(value); // If this static function calls another member function, that function should also be static function.
    }
    std::vector<int>::iterator found_it;
    std::vector<int>::iterator end_it = _elems.end();
    
    found_it = std::find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elems_to_value(int value){
    int ix = _elems.size();
    if(!ix){
        _elems.push_back(1);
        ix = 1;
    }
    while(_elems[ix - 1] < value && ix < _max_elems){
        ++ix;
        _elems.push_back(ix*(ix+1)/2);
    
    }
    if(ix == _max_elems){
        std::cerr<<"Triangular Sequence: oops: value too large "
        << value <<" -- exceeds max size of "
        << _max_elems <<std::endl;
        }
}

void Triangular::gen_elements(int length){
    if(length<0 || length > _max_elems){
        std::cerr<< " Triangular Sequence: oops: length too large "
        <<length<<" -- exceeds max size of "
        <<_max_elems <<std::endl;
    }

    if(_elems.size() < length){
        int ix = _elems.size()? _elems.size() + 1: 1;
        for(; ix<=length; ++ix){
            _elems.push_back(ix * (ix + 1)/2);
        }
    }
}

bool Triangular::next(int &val) const{
    if(_next < _begin_pos + _length - 1){
        val = _elems[_next ++];
        return true;
    }
    return false;
}

const int Triangular::_max_elems = 1024; // Visual c++ does not support initilization this value inside class decalaration, thus I initialized it here
std::vector<int> Triangular::_elems; // These two lines are required, since no definition is provided inside the class decalaration for this static member data.
