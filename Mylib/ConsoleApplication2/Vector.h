
namespace hdz{
#define DEFAULT_VECTOR_SIZE 50
	template <class T>
	class Vector{
		class iterator;
	public:
		Vector();
		~Vector();
		void clear();
		size_t size(){ return mSize; }
		void add(T& newItem);
		void removeItemAt(int idx);
		void insertItemAt(int idx, T& newItem);
		iterator begin(){ return iterator(mDataBuffer); };
		iterator end(){ return iterator(mDataBuffer + mSize) };
		
		class iterator{
		public:
			iterator(iterator& other){ m_ptr = other.m_ptr; }
			iterator(const T*& ptr){ m_ptr = ptr; }
			~iterator(){}
			iterator& operator=(iterator& other){
				m_ptr = other.m_ptr;
				return *this;
			}
			bool operator==(iterator& other){
				return m_ptr == other.m_ptr;
			}
			bool operator!=(const iterator& other){
				return !(*this == other);
			}
			T* operator->(){
				return m_ptr;
			}
			iterator operator++(){
				iterator iter(m_ptr++);
				return iter;
			}
			iterator& operator++(int){
				++m_ptr;
				return *this;
			}
			iterator operator--(){
				iterator iter(m_ptr--);
				return iter;
			}
			iterator& operator--(int){
				--m_ptr;
				return this;
			}
			iterator operator+(int i){
				if (m_ptr + i >= mDataBuffer + mSize){
					return end();
				}
				return iter(m_ptr + i);
			}
			iterator operator-(int i){
				if (m_ptr - i < mDataBuffer){
					return begin();//to do
				}
				return iter(m_ptr - i);
			}
			int operator-(iterator& rhs){
				return this->m_ptr - rhs.m_ptr;
			}
		private:
			T* m_ptr;
		};
	private:
		void extendBuffer();
	private:
		T* mDataBuffer;
		size_t mSize;
		size_t mCapacity;
	};

	template<class T>
	Vector<T>::Vector(){
		mDataBuffer = malloc(sizeof(T)*DEFAULT_VECTOR_SIZE);
		mCapacity = DEFAULT_VECTOR_SIZE;
		mSize = 0;
		extendCount = 0;
	}

	template<class T>
	Vector<T>::~Vector(){
		if (mDataBuffer != NULL){
			free(mDataBuffer);
			mDataBuffer = NULL;
		}
		mSize = 0;
		mCapacity = 0;
	}

	template<class T>
	void Vector<T>::insertItemAt(int idx, T& newItem){
		if (idx < 0 || index > mSize){
			return;//out of range
		}
		if (mSize + 1 > mCapacity){
			extendBuffer();
		}
		if (idx < mSize){
			memcpy(mDataBuffer + idx + 1, mDataBuffer + idx, sizeof(T)*(mSize - idx));
		}
		*(mDataBuffer + idx) = newItem;
		++mSize;
	}

	template<class T>
	void Vector<T>::removeItemAt(int idx){
		if (idx < 0 || index >= mSize ){
			return;//out of range
		}
		if (index == mSize - 1){
			--mSize;
			return;
		}
		memcpy(mDataBuffer + idx, mDataBuffer + idx + 1, mSize - idx - 1);
		--mSize;
	}

	template<class T>
	void Vector<T>::add(T& newItem){
		insertItemAt(mSize, newItem);
		return;
	}

	template<class T>
	void Vector<T>::extendBuffer(){
		mDataBuffer = realloc(mDataBuffer, 2*sizeof(T)*mSize);
		if (tmp == NULL){
			//out of memory;
		}

		mCapacity = 2*mSize;
		mEnd = mDataBuffer + mSize;
	}

	template<class T>
	void Vector<T>::clear(){
		mSize = 0;
	}

}// end namespace;