//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SOKULIB_STACK_HPP
#define SOKULIB_STACK_HPP


#include "UnionCast.hpp"

namespace SokuLib
{
	template<typename T>
	struct Dequeue {
		int unknown1;
		T** data;
		int chunkSize;
		int counter;
		int size;

		//Assumes ChunkSize == 8
		//PeekCard
		T &at(int id) {
			int pos = this->counter + id;

			return data[(pos >> 3) % this->chunkSize][pos & 0b111];
		}

		T &operator[](int id) {
			return at(id);
		}

		//GetCard
		T pop_front() {
			//Err, not sure if this works, at/[] might have to be changed to pointers instead
			T &value = at(0);

			this->counter++;
			this->size--;
			return value;
		}

		T &peekValue()
		{
			return (this->*union_cast<T *(__thiscall Dequeue<T>::*)()>(ADDR_STACK_PEEK_VALUE))();
		}
	};

	template<typename T>
	//Is deprecated
	using mVC9Dequeue = Dequeue<T>;
}


#endif //SOKULIB_STACK_HPP
