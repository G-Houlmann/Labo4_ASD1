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

    /**
     * Retourne l'indice physique du buffer
     * @param i_deq l'indice logique du bugger
     * @return
     */
    size_type indice_physique(size_type i_deq) const {
        return (i_deq + debut) % capacity();
    }

    size_type indice_deque(size_type i_phys) const {
        if (debut > i_phys) i_phys += capacity();
        return (i_phys - debut);
    }


    /**
     * Alloce la double de la capacite actuelle si besoin
     */
    void resizeIfNecesarry() {
        size_t cap = capacity();
        if (taille == cap) {
            // Si la capacité est à zéro sinon on ajoute la capacite actuelle en plus
            unsigned extendCap = cap == 0 ? 1 : cap;
            std::vector<T> tmp = buffer;
            tmp.resize(cap + extendCap);
            for (size_t i = debut + 1; i < buffer.size(); ++i) {
                tmp.at(i + extendCap) = buffer.at(i);
            }
            buffer = tmp;
        }
    }


public:
    ArrayDeque(size_type capacity = 0) : debut(0), taille(0), buffer(capacity) {
    }

    /**
     *
     * @return Retourne le nombre d'element dans le buffer
     */
    size_type size() const {
        return taille;
    }


    /**
     *
     * @return Retourne la capacite du bugffer
     */
    size_type capacity() const {
        return buffer.size();
    }


    /**
     *
     * @return Retourne si le buffer contient aucun element
     */
    bool empty() const {
        return taille == 0;
    }

    /**
     *
     * @return retourne la reference du premier element du buffer
     */
    reference front() {
        return buffer[indice_physique(0)];
    }

    /**
     *
     * @return retourne la reference du dernier element du buffer
     */
    reference back() {
        //TODO Pourquoi on utilise pas indice physique par tout
        return buffer[(taille - 1 + debut) % capacity()];
    }

    /**
     *
     * @return retourne la reference constant du premier element du buffer
     */
    const_reference front() const {
        return buffer[indice_physique(0)];
    }

    /**
    *
    * @return retourne la reference constant du dernier element du buffer
    */
    const_reference back() const {
        return buffer[(taille - 1 + debut) % capacity()];
    }

    /**
     * Ajouter val a la fin du buffer
     * @param val
     */
    void push_back(value_type val) {
        resizeIfNecesarry();
        taille++;
        buffer[indice_physique(taille - 1)] = val;
    }

    /**
     * Ajouter val au debut du buffer
     * @param val
     */
    void push_front(value_type val) {
        resizeIfNecesarry();
        taille++;
        // Si le debut se trouve a la position 0, le nouveau debut se trouve à la
        // fin du vecteur
        debut = debut == 0 ? capacity() - 1 : debut - 1;
        buffer[debut] = val;
    }

    /**
     * Diminue la taille effective du buffer
     */
    void pop_back() {
        taille--;
    }

    /**
     * Diminue la taille effective du buffer et deplace le debut a la position
     * suivant
     */
    void pop_front() {
        taille--;
        debut = (debut + 1) % capacity();
    }

// Completer cette classe générique pour qu'elle passe le codecheck

    void afficherTest() {
        std::cout << "Debut = " << debut << "; Taille = " << taille << std::endl;
        for (size_t i = 0; i < capacity(); ++i) {
            std::cout << buffer[i] << " ";
        }
        std::cout << "   ->  ";

        for (size_t i = debut;
             i != (debut + taille) % capacity(); i = (i + 1) % capacity()) {
            std::cout << buffer[i] << " ";
        }

        std::cout << std::endl;
    }

};

#endif /* ArrayDeque_hpp */

