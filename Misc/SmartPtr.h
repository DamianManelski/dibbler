/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * Released under GNU GPL v2 licence
 *
 */

#ifndef SPtr_H
#define SPtr_H

#include <iostream>

<<<<<<< HEAD
//Don't use this class alone, it's used only in casting 
//one smartpointer to another smartpointer 
=======
//Don't use this class alone, it's used only in casting
//one smartpointer to another smartpointer
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
//e.g.
//SPtr<a> a(new a()); SPtr<b> b(new(b)); a=b;

class Ptr {
public:
    //constructor used in case of NULL SPtr
    Ptr() {
<<<<<<< HEAD
	      ptr=NULL;
	      refcount=1;
    }
    //Constructor used in case of non NULL SPtr
    Ptr(void* object) {
	      ptr=object;
	      refcount=1;
    }
    
    ~Ptr() {
      	//if(ptr) delete ptr;
    }
    int refcount; //refrence counter
    void * ptr;	  //pointer to the real object
=======
              ptr=NULL;
              refcount=1;
    }
    //Constructor used in case of non NULL SPtr
    Ptr(void* object) {
              ptr=object;
              refcount=1;
    }

    ~Ptr() {
        //if(ptr) delete ptr;
    }
    int refcount; //refrence counter
    void * ptr;   //pointer to the real object
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
};

template <class T>
class SPtr
{

public:
    SPtr();
    SPtr(T* something);
<<<<<<< HEAD
	SPtr(Ptr *voidptr) { 
        if(voidptr) 
        {
            this->ptr=voidptr; 
=======
        SPtr(Ptr *voidptr) {
        if(voidptr)
        {
            this->ptr=voidptr;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
            this->ptr->refcount++;
        }
        else
            this->ptr=new Ptr();
    }
    SPtr(const SPtr & ref);
<<<<<<< HEAD
	SPtr(int onlyNull);
	SPtr& operator=(const SPtr& old);

	operator Ptr*() {
	    if (this->ptr->ptr) 
		return this->ptr;
	    else
		return (Ptr*)NULL;
	}
=======
    SPtr(int onlyNull);
    SPtr& operator=(const SPtr& old);

    operator Ptr*() {
      if (this->ptr->ptr)
        return this->ptr;
      else
        return (Ptr*)NULL;
    }
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

    int refCount();
    ~SPtr();
    T& operator*() const;
    T* operator->() const;

 private:
    Ptr * ptr;
};

template <class T> SPtr<T>::SPtr() {
    ptr = new Ptr();
}

template <class T> int SPtr<T>::refCount() {
    if (this->ptr)
<<<<<<< HEAD
	return this->ptr->refcount;
=======
        return this->ptr->refcount;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    return 0;
}

template <class T>
SPtr<T>::SPtr(T* something) {
    ptr = new Ptr(something);
}

<<<<<<< HEAD
template <class T>
SPtr<T>::SPtr(const SPtr& old) {
	old.ptr->refcount++;
	this->ptr = old.ptr;
    this->ptr->refcount=old.ptr->refcount;
=======
#include <typeinfo>

template <class T>
SPtr<T>::SPtr(const SPtr& old) {
    // std::cout << "### Copy constr " << typeid(T).name() << std::endl;
    old.ptr->refcount++;
    this->ptr = old.ptr;

    // this doesn't make sense. It just copies value to itself
    this->ptr->refcount = old.ptr->refcount;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}

template <class T>
SPtr<T>::~SPtr() {
    if (!(--(ptr->refcount))) {
<<<<<<< HEAD
	delete (T*)(ptr->ptr);
	delete ptr;
=======
        delete (T*)(ptr->ptr);
        delete ptr;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
}

template <class T>
T& SPtr<T>::operator*() const {
    return *((T*)(ptr->ptr)); //it can return NULL
}

template <class T>
T* SPtr<T>::operator->() const {
    if (!ptr) {
<<<<<<< HEAD
	return 0;
=======
        return 0;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
    return (T*)(ptr->ptr); //it can return NULL
}

//It's is called in eg. instrusction: return NULL;
//and SPtr is returned in function
template <class T>
SPtr<T>::SPtr(int )
{
<<<<<<< HEAD
	ptr=new Ptr(); //this->ptr->ptr is NULL
=======
        ptr=new Ptr(); //this->ptr->ptr is NULL
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}

template <class T>
SPtr<T>& SPtr<T>::operator=(const SPtr& old) {
<<<<<<< HEAD
	if (this==&old)
		return *this;
	if (this->ptr) 
		if(!(--this->ptr->refcount))
		{
		    delete (T*)(this->ptr->ptr);
		    delete this->ptr;
		    this->ptr=NULL;
		}
		this->ptr=old.ptr;
		old.ptr->refcount++;
		//    cout << "operator=" << endl;
		return *this;
=======
        if (this==&old)
                return *this;
        if (this->ptr)
                if(!(--this->ptr->refcount))
                {
                    delete (T*)(this->ptr->ptr);
                    delete this->ptr;
                    this->ptr=NULL;
                }
                this->ptr=old.ptr;
                old.ptr->refcount++;
                //    cout << "operator=" << endl;
                return *this;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}
#endif
