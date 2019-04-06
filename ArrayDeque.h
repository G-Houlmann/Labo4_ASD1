#ifndef ArrayDeque_hpp
#define ArrayDeque_hpp

#include <vector>

template<class T>
class ArrayDeque {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

private:
    std::vector<value_type> buffer;
    size_type debut;
    size_type taille;

    size_type indice_physique(size_type i_deq) {
        return (i_deq + debut) % capacity();
    }

//  size_type indice_deque(size_type i_phys){
//
//  }


public:
    ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {
    }

    size_type size() const {
        return taille;
    }


    size_type capacity() const {
        return buffer.size();
    }


    bool empty() const {
        return taille == 0;
    }

    reference front() {
        return buffer[debut];
    }

    reference back() {
        return buffer[(taille - 1 + debut) % capacity()];
    }

    const_reference front() const {
        return buffer[debut];
    }

    const_reference back() const {
        return buffer[(taille - 1 + debut) % capacity()];
    }

    void push_back(value_type val) {
        taille++;
        buffer[(taille + debut) % capacity()] = val;
    }

    void push_front(value_type val) {

    }

    void pop_back() {
        taille--;
        debut = (debut - 1) % capacity();
    }


    void pop_front() {
       
    }

// Completer cette classe générique pour qu'elle passe le codecheck


};

#endif /* ArrayDeque_hpp */
