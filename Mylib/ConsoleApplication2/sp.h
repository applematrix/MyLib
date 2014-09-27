#pragma once


template<class T>
class sp
{
public:
	sp()
	{
		m_ptr = NULL;
	}
	sp(T* ptr)
	{
		if (ptr == NULL)return;
		m_ptr = ptr;
		m_ptr->addRef();
	}
	sp(const T* ptr)
	{
		if (ptr == NULL)return;
		m_ptr = ptr;
		m_ptr->addRef();
	}
	sp(sp<T>& other)
	{
		if (other.m_ptr == NULL)return;
		m_ptr = other.m_ptr;
		m_ptr->addRef();
	}
	~sp()
	{
		if (m_ptr == NULL){
			return;
		}
		if (m_ptr->decRef() == 0){
			delete m_ptr;
		}
	}

	sp<T>& operator=(sp<T> other){
		m_ptr = other.m_ptr;
		m_ptr->addRef();
		return *this;
	}

	boolean operator==(sp<T>& other){
		return m_ptr == other.m_ptr;
	}

	T* operator->(){
		return m_ptr;
	}

	T& operator*(){
		return *m_ptr;
	}

private:
	T* m_ptr;
};