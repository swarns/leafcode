#include <iostream>
#include <string>

using namespace std;

typedef  class _node {

	public:

	int 	data;
	_node 	*next;

	_node(int val) {

		data = val;
		next = NULL;
	}

}node;

node* new_node(int val) {

	node *tmp = new node(val);

return tmp;
}

node* rec_add(node* head1, node* head2, int &carry) {

	node *tmp = NULL;
	int val = 0;

	if (head1 == NULL && head2 == NULL)
		return NULL;
	
	tmp = new_node(0);
	tmp->next = rec_add(head1->next, head2->next, carry);
	val = ((head1->data + head2->data + carry) % 10);
	tmp->data = val;
	carry = (head1->data + head2->data + carry) / 10;

return tmp;	
}

int main() {

	node *head = NULL, *head1 = NULL, *head2 = NULL, *tmp = NULL, *tmp1 = NULL;
	string input1, input2;
	int len1 = 0, len2 = 0, len = 0;
	int carry = 0;

	cout<<"enter first integer: ";
	cin>>input1;	
	cout<<"input1 = "<<input1<<endl;	

	cout<<"enter second integer: ";
	cin>>input2;
	cout<<"input2 = "<<input2<<endl;	
	
	len1 = input1.size();	
	len2 = input2.size();	

	for (int i = len1 - 1; i >= 0; i--) {
		
		if (input1[i] < 48 || input1[i] > 57) {

			cout<<"digits allowed from 0 - 9 only"<<endl;
			return 0;
		}

		tmp =  new_node(input1[i] - 48);
		tmp->next = head1;
		head1 = tmp;
	}

	for (int i = len2 - 1; i >= 0; i--) {
		
		if (input2[i] < 48 || input2[i] > 57) {

			cout<<"digits allowed from 0 - 9 only"<<endl;
			return 0;
		}

		tmp =  new_node(input2[i] - 48);
		tmp->next = head2;
		head2 = tmp;
	}

	if (len1 > len2) {

		tmp = head2;
		len = len1 - len2;
	} else if (len1 < len2) {

		tmp = head1;
		len = len2 - len1;
	}

	while (len) {

		tmp1 = new_node(0);
		tmp1->next = tmp;		
		tmp = tmp1;
		len--;
	}

	if (len1 > len2)
		head2 = tmp;
	else if (len1 < len2)
		head1 = tmp;
	

	tmp = head1;
	cout<<"list1 = ";
	while (tmp) {

		len1++;
		cout<<tmp->data<<" -> ";
		tmp = tmp->next;
	}
	cout<<"NULL"<<endl;

	tmp = head2;
	cout<<"list2 = ";
	while (tmp) {

		len2++;
		cout<<tmp->data<<" -> ";
		tmp = tmp->next;
	}
	cout<<"NULL"<<endl;

	head = rec_add(head1, head2, carry);
	if (carry) {

		tmp = new_node(1);
		tmp->next = head;
		head = tmp;
	}

	tmp = head;
	while (tmp) {

		if (tmp->data == 0 && tmp->next != NULL) {
		
			head =  tmp->next;
		} else {

			break;
		}
		tmp = tmp->next;
	}

	cout<<"sum = ";
	tmp = head;
	while (tmp) {
	
		cout<<tmp->data<<" -> ";
		tmp  =  tmp->next;
	}
	cout<<"NULL"<<endl;

return 0;
}
