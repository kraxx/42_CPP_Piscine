#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <list>

template<typename T>
class MutantStack : public std::stack<T> {

private:

	std::vector<T> 		 _vec;

public:

	MutantStack() {};

	MutantStack(MutantStack const& rhs) {
		*this = rhs;
	};

	MutantStack& operator=(MutantStack const& rhs) {
		_vec = rhs._vec;
		return *this;
	};
	
	~MutantStack() {};

	typedef typename std::vector<T>::iterator iterator;
	
	iterator begin() {
		return _vec.begin();
	}
	
	iterator end(){
		return _vec.end();
	}
		void	 push(T x) {
		_vec.push_back(x);
	}

	void	 pop() {
		_vec.pop_back();
	}

	T		top() {
		return *(_vec.end() - 1);
	}

};

#endif