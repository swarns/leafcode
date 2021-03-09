/*
* Copyright 2021 @LeafCode
*
* This code is for creating a min heap data structure with heapify_up()
* heapify_down() methods which gets called after every add or removal of element from heap
* which keeps the heap constraint intact.
*
*/

#include <iostream>

using namespace std;

typedef class _min_heap {

	int 	capacity;
	int 	size;
	int 	*data;

	public:

	_min_heap () {

		size = 0;
		capacity = 10;
		data = new int [capacity];
	}

	int get_left_child_index (int parent_index) {

		return 2 * parent_index + 1;
	}

	int get_right_child_index (int parent_index) {

		return 2 * parent_index + 2;
	}
	
	int get_parent_index (int child_index) {

		return (child_index - 1) / 2;
	}

	int left_child (int index) {

		return data[ get_left_child_index (index) ];
	}
	
	int right_child (int index) {

		return data[ get_right_child_index (index) ];
	}

	int parent (int index) {

		return data[ get_parent_index (index) ];
	}

	bool has_left_child (int index) {

		return get_left_child_index (index) < size;
	}

	bool has_right_child (int index) {

		return get_right_child_index (index) < size;
	}

	bool has_parent (int index) {

		return get_parent_index (index) >= 0; 
	}

	//swap elements based on index
	void swap (int index1, int index2) {

		int temp = data [index1];
		
		data [index1] = data [index2];
		data [index2] = temp;
	}

	//increase the heap capacity by 2 if the heap is full
	void inc_capacity () {

		if (size == capacity) {

			int *temp = new int [capacity + 2];
			int *temp1 = NULL;

			for (int i = 0; i < size; i++)
				temp[i] = data[i];

			capacity += 2;
			temp1 = data;
			data = temp;

			delete temp1;
		}
	}

	//gives the minimum element (which is root) from a heap
	int peek () {

		if (size == 0) throw;

		return data[0];
	}

	//removes the minimum element from the heap and keeps heap property intact
	int poll () {

		if (size == 0) throw;

		int item = data [0];

		data [0] = data [size - 1]; 
		size--;
		heapify_down ();

		return item;
	}

	//adds new elelent to the heap and keep the heap property intact	
	void add (int item) {

		if (capacity == size)
			inc_capacity ();

		data [size] = item;
		size++;
		heapify_up ();	
	}

	// heapify the whole data strucutre from last node to root node to keep heap property intact
	// used when we add some element in heap
	void heapify_up () {

		int index = size - 1;
		
		while ( has_parent (index) && parent (index) > data [index] ) {
			
			swap (get_parent_index (index), index);
			index = get_parent_index (index);
		}
	}

	// heapify the whole data strucutre from root node to last node to keep heap property intact
	// used when we poll the root element from heap
	void heapify_down () {

		int index = 0;

		while ( has_left_child (index) ) {	

			int smaller_child_index = get_left_child_index (index);
			if ( has_right_child (index) && right_child (index) < left_child (index) ) { 
			
				smaller_child_index = get_right_child_index (index);
			}

			if ( data [index] < data [smaller_child_index] ) {

				break;
			} else {

				swap (index, smaller_child_index);
			}
			
			index = smaller_child_index;
		}
	}

	void display_heap () {

		if (size == 0) throw;
	
		for (int i = 0; i < size; i++)
			cout<<" "<<data[i];

		cout<<endl;
	}


}min_heap;


int main () {


	min_heap mh;

	mh.add (4);
	mh.add (2);
	mh.add (9);
	mh.add (1);
	mh.add (22);

	cout<<"peek() = "<< mh.peek ()<<endl;

	mh.display_heap ();
	mh.add (-1);
	mh.add (222);
	mh.add (999);
	mh.add (-2);
	mh.add (-11);
	mh.add (11);
	mh.add (22);
	mh.display_heap ();


return 0;
}
