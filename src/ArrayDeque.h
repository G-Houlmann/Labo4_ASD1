#ifndef ArrayDeque_hpp
#define ArrayDeque_hpp

#include <vector>
#include <iostream> // Pour tests

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

	size_type indice_physique(size_type i_deq) const {
		return (i_deq + debut) % capacity();
	}

	size_type indice_deque(size_type i_phys) const {
		if (debut > i_phys)
			i_phys += capacity();
		return (i_phys - debut);
	}

	void resizeIfNecesarry() {
		size_t cap = capacity();
		if (taille == cap) {
			unsigned extendCap = cap == 0 ? 1 : cap;
			std::vector<T> tmp = buffer;
			tmp.resize(cap + extendCap);
			for(size_t i = debut+1; i < buffer.size() ; ++i){
			              tmp.push_back(buffer.at(i));
			          }
			buffer = tmp;
		}
	}

public:
	ArrayDeque(size_type capacity = 0) :
			debut(0), taille(0), buffer(capacity) {
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
		return buffer[indice_physique(0)];
	}

	reference back() {
		return buffer[(taille - 1 + debut) % capacity()];
	}

	const_reference front() const {
		return buffer[indice_physique(0)];
	}

	const_reference back() const {
		return buffer[(taille - 1 + debut) % capacity()];
	}

	void push_back(value_type val) {
		resizeIfNecesarry();
		taille++;
		buffer[indice_physique(taille - 1)] = val;

	}

	void push_front(value_type val) {
		resizeIfNecesarry();
		taille++;
		debut = debut == 0 ? capacity() - 1 : ((debut - 1) % capacity());
		buffer[debut] = val;
	}

	void pop_back() {
		taille--;

	}

	void pop_front() {
		taille--;
		debut = (debut + 1) % capacity();
	}

// Completer cette classe générique pour qu'elle passe le codecheck

	void afficherTest() {
		std::cout << "Debut = " << debut << "; Taille = " << taille
				<< std::endl;
		for (size_t i = 0; i < capacity(); ++i) {
			std::cout << buffer[i] << " ";
		}
		std::cout << "   ->  ";

		for (size_t i = debut; i != (debut + taille) % capacity();
				i = (i + 1) % capacity()) {
			std::cout << buffer[i] << " ";
		}

		std::cout << std::endl;
	}

};

#endif /* ArrayDeque_hpp */
