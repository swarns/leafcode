/*
* Copyright 2021 @LeafCode
*
* This code is for fixed size lru cache implementation using C++ template
*
*/

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template <typename T> 
class _lru_cache {

	list <T> 						q;
	unordered_map < T, typename list <T>:: iterator >	m;
	int 							csize;

	public:
	_lru_cache (int size) {

		csize = size;
	}

	void push_data (T data) {

		cout<<"pushing:: "<<data<<endl;	
		if (m.find (data) == m.end()) {

			if (q.size () == csize) {

				T val = q.back ();
				q.pop_back();
				m.erase (val);
			} 
			
		} else {

			q.erase (m[data]);
		}

		q.push_front (data);	
		m[data] = q.begin ();

	}

	void display_lru () {

		typename list <T>:: iterator itr;

		for (itr = q.begin(); itr != q.end(); itr++)
			cout<<" "<<*itr;
	
		cout<<endl;
	}

};


int main () {

	_lru_cache <int>	li(5);
	_lru_cache <string>	ls(4);

	li.push_data (1);
	li.display_lru ();
	li.push_data (5);
	li.display_lru ();
	li.push_data (2);
	li.display_lru ();
	li.push_data (8);
	li.display_lru ();
	li.push_data (0);
	li.display_lru ();
	li.push_data (9);
	li.display_lru ();

	ls.push_data ("hey");
	ls.display_lru ();
	ls.push_data ("how");
	ls.display_lru ();
	ls.push_data ("are");
	ls.display_lru ();
	ls.push_data ("you");
	ls.display_lru ();
	ls.push_data ("doing");
	ls.display_lru ();
	ls.push_data ("i'am");
	ls.display_lru ();
	ls.push_data ("here");
	ls.display_lru ();


return 0;
}
