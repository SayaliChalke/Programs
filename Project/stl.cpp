


#include<iostream>
using namespace std;


//STRUCTURE DECLARATION

template <typename T>//structure declaration for singlyll//singlycircular linked list,stack,queue
struct node   //singlyll
{
	T data;
	struct node* next;
};



template <typename T>///structue delclaration for Doubly linear linked list//DOubly circular linked list
 struct node1
{
	
	T data;
	struct node1 *next;
	struct node1 *prev;
};


template<typename T>// binary search tree
 struct nodeBST
{
	
	T data;
	struct nodeBST*lchild;
	struct nodeBST*rchild;
};



//CLASS DECLARATION
template <class T>
class SinglyLL
{
	private:
   node<T> *first;
	int size;
	
	public:
	SinglyLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
	
};

template <class T>
class SinglyCircular
{
  private:
	
	node<T> * first;
	node<T> * last;
	int size;
	
  public:
  
  SinglyCircular ();
  void Display();
  int Count();
  void InsertFirst(T);
  void InsertLast(T);
  void InsertAtPos(T,int);
  void DeleteFirst();
  void DeleteLast();
  void DeleteAtPos(int);
  
  
  
	
	
	
};

template <class T>
class DoublyLL
{
	private :
	node1<T>* first;
	node1<T> *last;
	int size;
	
	public:
	DoublyLL ();
  void Display();
  int Count();
  void InsertFirst(T);
  void InsertLast(T);
  void InsertAtPos(T,int);
  void DeleteFirst();
  void DeleteFirstX();
  void DeleteLast();
  void DeleteAtPos(int);
	

};

template <class T>
class DoublyCL
{
	private:
	 node1<T> *first;
	 node1<T> * last;
	 int size;
	 
	public:
     DoublyCL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
		
	
	
};


template <class T>
class Queue
{
	
	private:
	 node<T> * first;
	 int size;
	 
	public:
     Queue();
	 void Enqueue(T);
     int Dequeue();
	 void Display();
	 int Count();
	 
	 
};


template<class T>
class Stack
{
	
	private:
	node<T> *  first;
    int size;
	 
	public:
	Stack();
	void push(T);
    int pop();
	void Display();
	int Count();
	 
     
};


template<class T>
class BinarySearchTree
{
	private:
	nodeBST<T>* first;
	int size;
	
	public:
	BinarySearchTree();
	void Insert(T);
	bool Search(T);
	int Count();
	
};
/////////////////////////////////////////////////////////******************//////////////////

 template <class T>
 SinglyLL<T>::SinglyLL()
	{
		
		first=NULL;
		size=0;
		
	}

template <class T>
void SinglyLL<T>::InsertFirst(T no)

	{
		 node<T> * newn=new  node<T>;//newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		size++;
		
	}
	
template <class T>
void SinglyLL<T>::InsertLast(T no)
	{
		
		 node<T> * newn=new  node<T>;//newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		if(first==NULL)
		{
			first=newn;
		}
		else
		{
			 node <T>* temp=first;
			while(temp->next!=NULL)
			{
				
				temp=temp->next;
			}
			temp->next=newn;
		}
		size++;
		
	}
	
template <class T>
void SinglyLL<T>::InsertAtPos(T no,int ipos)
	{
		 node<T> * newn =NULL;
		 node <T>* temp= first;
		
		
		int i=0;
		
		if((ipos<1)||(ipos>size+1))
		{
			printf("invalid position\n");
			return;
		}
	   if(ipos==1)
		{
			
			InsertFirst(no);
			
		}
		else if(ipos==size+1)
		{
			InsertLast(no);
			
		}
		else
		{
			node <T> * newn=new node<T>;
			newn->next=NULL;
			newn->data=no;
			for(i=1;i<ipos-1;i++)
			{
				
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
			size++;
		}
		
	}
template <class T>	
void SinglyLL<T>:: DeleteFirst()
	{
		 node<T> * temp=first;
		if(first!=NULL)
		{
			first=first->next;
			delete(temp);
			size--;
		}
	}
	
template <class T>
void SinglyLL<T>:: DeleteLast()
	{
		 node<T> * temp=first;
		
		if(first==NULL)
		{
			return;
		}
	
		else if(first->next==NULL)
		{
			 delete (first);
			 first=NULL;
			 size--;
		}
		else
		{
			while(temp->next->next!=NULL)
			{
				
				temp=temp->next;
			}
			delete (temp->next);
			temp->next=NULL;
			size--;
		}
	}
	
template <class T>	
void SinglyLL<T>:: DeleteAtPos(int ipos )
	{
		
		// 
		int i=0;
		 node <T>* targated=NULL;
		
		if((ipos<1)||(ipos>size+1))
		
		{
			printf("invalid position\n");
			return;
		}
		 if(ipos==1)
		{
			DeleteFirst();
		}
		else if(ipos==size)
		{
			DeleteLast();
		}
		else
		{
			node<T> * temp=first;
			for(i=1;i<ipos-1;i++)
			{
				
				temp=temp->next;
			}
			targated=temp->next;
			temp->next=targated->next;
			free(targated);
			size--;
		}
		
	}
	
template <class T>
void SinglyLL<T>:: Display()
	{
		
		 node <T>* temp=first;
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
	
template <class T>	
int SinglyLL<T>:: Count()
{
	{
		
		return size;
	}
	
	
}


//////////////////////////////////////////////////////////////

	
	
/////////////////////////////////////////////////////////////////////////////
/////Generic Singly circular linked list

template <class T>
 SinglyCircular<T>::SinglyCircular()
	{
		first =NULL;
		last=NULL;
		size=0;
	}
	


	
template <class T>	
void SinglyCircular<T>:: InsertFirst(T no)
	{
		node <T>* newn=new node<T>;
		newn->data=no;
		newn->next=NULL;
		
		if(first==NULL && last==NULL)
		{
			first=newn;
			last=newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		last->next=first;
		size++;
	}
	
template <class T>
void SinglyCircular<T>:: InsertLast(T no)
{
		node <T>* newn=new node<T>;
		newn->data=no;
		newn->next=NULL;
		
		if(first==NULL && last==NULL)
		{
			first=newn;
			last=newn;
		}
		else
		{
			last->next=newn;
			last=newn;
		}
		last->next=first;
		size++;
}


template <class T>
void SinglyCircular<T>:: Display()
	{
		node <T>* temp=first;
		if((first==NULL)&&(last==NULL))
		{
			return;
		}
		do
		{
			
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}while(temp!=last->next);
			cout<<"\n";
	}
	
	
	
	template <class T>
int SinglyCircular<T>::Count()
	{
		return size;
	}
	
template <class T>	
void SinglyCircular<T>:: InsertAtPos(T no,int ipos)
{
		if((ipos<1)||(ipos>(size+1)))//invalid position
		{
			return;
		}
		if(ipos==1)
		{
			InsertFirst(no);
		}
		else if(ipos==size+1)
		{
			InsertLast(no);
		}
		else
		{
			node <T>* newn=new node<T>;
			
			newn->data=no;
			newn->next=NULL;
			node <T>* temp=first;
			
			for(int i=1;i<ipos-1;i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
			size++;
			
		}
}
	
template <class T>	
void SinglyCircular<T>:: DeleteFirst()
{
		if(first==NULL && last==NULL)
		{
			return;
		}
		else if(first==last)
		{
			delete first;
			first=NULL;
			last=NULL;
		}
		else
		{
			first=first->next;
			delete last->next;
			last->next=first;
			
		}
		size--;
}
	
template <class T>
void  SinglyCircular<T>:: DeleteLast()
{
		node <T>* temp=first;
		if(first==NULL && last==NULL)
		{
			return;
		}
		else if(first==last)
		{
			delete first;
			first=NULL;
			last=NULL;
		}
		else
		{
			while(temp->next!=last)
			{
				temp=temp->next;
			}
			delete last;
			last=temp;
			last->next=first;
			
		}
		size--;
	
}
	
template <class T>	
void SinglyCircular<T>:: DeleteAtPos(int ipos)
{        int i=0;
		 node <T>* targated=NULL;
		 
		if((ipos<1)||(ipos>(size+1)))//invalid position
		{
			return;
		}
		 if(ipos==1)
		{
			DeleteFirst();
		}
		else if(ipos==size)
		{
			DeleteLast();
		}
		else
		{
			node <T>* temp=first;
			for( i=1;i<ipos-1;i++)
			{
				temp=temp->next;
			}
			targated=temp->next;
			temp->next=targated->next;
			delete targated;
			size--;
		}
}
	



/////////////////////////////////////////////////////////////////////////////////////////////
////Generic Doubly linear linked list


template <class T>
DoublyLL<T>::DoublyLL()
	{
		first=NULL;
		last=NULL;
		size=0;
		
	}
	

template <class T>
void DoublyLL<T>:: InsertFirst(T no)
{
	node1<T>* newn=new node1<T>;
	
	
	newn ->data=no;
	newn->next=NULL;
	newn-> prev=NULL;
	
	if(first==NULL)
	{
		
		first=newn;
	}
	else
	{
		
		newn->next=first;
		first->prev=newn;
		
		first=newn;
	}
	size++;
}

template <class T>
void DoublyLL<T>:: InsertLast(T no)

{
	node1<T>* newn=new node1<T>;
	node1<T>* temp=first;
	
	
	
	newn ->data=no;
	newn->next=NULL;
	newn-> prev=NULL;
	
	if(first==NULL)
	{
		
		first=newn;
	}
	else
	{
		
		while(temp->next !=NULL)
		{
			temp=temp->next;
		}
		
		
		temp->next=newn;
		newn->prev=temp;
		
	}
	size++;
}


template <class T>
void DoublyLL<T>:: Display()
	{
		
		node1<T>* temp=first;
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
	
template <class T>
int DoublyLL<T>:: Count()
{
	
	
	return size;
	
	
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
	node1<T> *temp=first;
	
	if(first!=NULL)//ATLEAST ONE NODE
	{
		first=first -> next;
		delete (temp);
		if(first!=NULL)
		{
		 first-> prev=NULL;
		 
		}
	}
	size--;
}

template <class T>
void DoublyLL<T>:: DeleteFirstX()
{
	if(first==NULL)
	{
		
		return;
	}
	else if(first->next==NULL)
	{
		
		delete first;
		first=NULL;
	}
	else
	{
		first=first->next;
		free(first->prev);
		first->prev=NULL;
	}
	size--;
}


template <class T>

void DoublyLL<T>:: DeleteLast()
{
	
	node1<T>* temp=first;
	if(first==NULL)
	{
		
		return;
	}
	else if(first->next==NULL)//atleast one node
	{
		
		delete first;
	first=NULL;
	}
	else
	{
		
		while(temp->next!=NULL)
		{
			
			
			temp=temp->next;
			
		}
		temp->prev->next=NULL;
       delete temp;
	}
	size--;
}


template <class T>
void DoublyLL<T>:: InsertAtPos(T no,int ipos)
{
	
	
	int i=0;
	node1<T>* temp=first;
	node1<T>* newn=NULL;
	
	if((ipos<1)||(ipos>size+1))
	{
		printf("invalid position");
		return;
		
	}
	else if(ipos==1)
	{
		
		InsertFirst(no);
	}
	else if(ipos==size+1)
	{
		
		InsertLast(no);
	}
	
	else
	{
		
		node1<T>* newn =new node1<T>;
		newn->next=NULL;
		newn->prev=NULL;
		newn->data=no;
		
		
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		
		newn->next=temp->next;
		newn->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		size++;
	}
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
	
	
	int i=0;
	node1<T>*temp=first;
	
	
	if((ipos<1)||(ipos>size))
	{
		printf("invalid position");
		return;
		
	}
	else if(ipos==1)
	{
		
		DeleteFirst();
	}
	else if(ipos==size)
	{
		
		DeleteLast();
	}
	
	else
	{
		
		
		
		for(i=1;i<ipos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		free(temp->next->prev);
		temp->next->prev=temp;
		size--;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////Generic Doubly circular linked list

//return_value class_name :: Function _Name(parameters)
template <class T>
DoublyCL<T> ::DoublyCL()
	{
		first =NULL;
		last=NULL;
		size=0;
		
		
	}
template <class T>
void DoublyCL<T>:: InsertFirst(T no)
{
	node1<T> * newn=new node1<T>;
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	if((first==NULL)&&(last==NULL))
	{
		first= newn;
		last=newn;
	}
	else
	{
		newn->next=first;
		first->prev=newn;
		first=newn;
		
	
	}
	last->next=first;
	 first->prev=last;
	size++;
	
}
template <class T>
void DoublyCL<T>:: InsertLast(T no)
{
	node1<T> * newn=new node1<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	if((first==NULL)&&(last==NULL))
	{
		first= newn;
		last=newn;
	}
	else
	{
		last->next=newn;
		newn->prev=last;
		last=newn;
		
	}
	last->next=first;
	 first->prev=last;
	size++;
	
}

template <class T>
void DoublyCL<T>:: Display()
{
	node1<T> * temp=first;
	for(int i=1;i<=size;i++)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	printf("\n");
}

template <class T>
int DoublyCL<T>::Count()
{
	return size;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first=NULL;
		last=NULL;
	}
	else
	{
		first=first->next;
		delete last->next;
		first->prev=last;
	    last->next=first;
	}
	
	
	size--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first=NULL;
		last=NULL;
	}
	else
	{
		last=last->prev;
		delete last->next;
		first->prev=last;
	    last->next=first;
	}
	
	
	size--;
}

template <class T>
void DoublyCL<T>:: InsertAtPos(T no,int ipos)
{
	if((ipos<1)||(ipos>size+1))
	{
		return;
	}
	if(ipos==1)
	{
		InsertFirst(no);
	}
	
	else if(ipos==size+1)
	{
		
		InsertLast(no);
	}
	else
	{
		node1<T> * newn=new node1<T>;
		
	    newn->data=no;
	    newn->next=NULL;
	    newn->prev=NULL;
		
		node1<T> * temp=first;
		for(int i=1;i<ipos-1;i++)
		{
			
			temp=temp->next;
		}
		newn->next=temp->next;
		newn->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
	}
	
	size++;
	
}


template <class T>
void DoublyCL<T>:: DeleteAtPos(int ipos)
{
	if((ipos<1)||(ipos>size+1))
	{
		return;
	}
	if(ipos==1)
	{
		DeleteFirst();
	}
	
	else if(ipos==size)
	{
		
		DeleteLast();
	}
	else
	{
		
		
		node1<T> * temp=first;
		for(int i=1;i<ipos-1;i++)
		{
			
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
		size--;
	}
	
	
	
}


//////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
//Generic QUEUE
#include<iostream>
using namespace std;



template <class T>
Queue <T>::Queue()//singly linear linked
	 {
		 first=NULL;
		 
		 size=0;
	 }
	 
	 
template <class T> 
 void Queue<T>:: Enqueue(T no)//InsertLast()
	 {
		 node<T> * newn=new node<T> ;
		 newn->data=no;
		 newn->next=NULL;
		 
		 
		 if(first==NULL)
		 {
			
			first=newn;
			
		 }
         else
		 {   node<T> * temp=first;
	         while(temp->next!=NULL)
			 {
		      temp=temp->next;
			    
			 }
			 temp->next=newn;
		  }
		 
		 size++;
	 }


template <class T>
int Queue<T>:: Dequeue()   //DeleteFirst()
	 {
		 int iValue=0;
		 node<T> * temp=first;
		 iValue=first->data;
		 if(first==NULL)
		 {
			 return 0;
		 }
		 else
		 {
			 
			 first=temp->next;
			 delete (temp);
			 size--;
		 }
		 return iValue;
	 }
	

template <class T>	
void Queue<T>:: Display()
	 { //
	     node<T> * temp=first;
		
		 for(int i=1;i<=size;i++,temp=temp->next)
		 {
			  cout<<"|"<< temp->data<<"|->";
			// temp= temp->next;
		 }
		  cout<<"NULL\n";
		  
	 }
	 
	 
	 
 template <class T>
int Queue<T>:: Count()
	 {
		 return size;
	 }
	


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Generic Stack


template<class T>
Stack<T>::Stack()//singly linear linked
	 {
		 first=NULL;
		 
		 size=0;
	 }
	 
	 
template<class T>	 
 void Stack<T>:: push(T no)//InsertFirst()
	 {
		 node<T> *  newn=new node<T>;
		 newn->data=no;
		 newn->next=NULL;
		 
		 
		 if(first==NULL)
		 {
			
			first=newn;
			
		 }
         else
		 {
		      newn->next=first;
			   first=newn;
		  }
		 
		 size++;
	 }	


template<class T>	 
int Stack<T>:: pop()   //DeleteFirst()
	 {
		 int iValue=0;
		 node<T> *  temp=first;
		 
		 if(first==NULL)
		 {
			 cout<<"stack is empty";
			 return -1;
		 }
		 if(  size==1)
		 {
			 iValue=first->data;
			 delete first;
			 first=NULL;
			
		 }
		 else
		 {
			 iValue=first->data;
			 first=first->next;
			 delete temp;
		 }
		  size--;
		 return iValue;
	 }
	 
	 
template<class T>	 
 void Stack<T>:: Display()
	 { 
	     node<T> *  temp=first;
		 while(temp!=NULL)
		 {
		   cout<<"|"<< temp->data<<"|\n";
		    temp=temp->next;
		 }
		
		 cout<<"NULL\n";
	 }
	 
template<class T>
	 
int Stack<T>:: Count()
	 {
		 return size;
	 }
	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Generic binary search tree


template<class T>
BinarySearchTree<T>:: BinarySearchTree()
{
	
	first=NULL;
	size=0;
}

template<class T>
void  BinarySearchTree<T>:: Insert(T no)
{
	nodeBST<T> * newn=new nodeBST<T> ;
	newn->data=no;
	newn->lchild=NULL;
	newn->rchild=NULL;
	
	if(first==NULL)
	{
		first=newn;
	}
	else
	{
		nodeBST<T> * temp=first;
		while(1)//while(true)///unconditional loop  for( ; ; )
		{
			if(temp->data==no)//
			{
				cout<<"Duplicate node\n";
				delete newn;
				break;
				
			}
			else if( no < (temp->data))//lahan data
			{
				   if(temp->lchild==NULL)
				   {
				       temp->lchild=newn;
				      break;
				    }
				temp=temp->lchild;
				
			}
			else if( no>(temp->data ))//motha data
			{
				if(temp->rchild==NULL)
				{
				  temp->rchild=newn;
				  break;
				}
				temp=temp->rchild;
			}
		}
	}
	size++;
	
}

template<class T>
bool BinarySearchTree<T>:: Search(T no)
{
	
	if(first==NULL)//tree is empty
	{
		return false;
	}
	else//tree contains atleast one node
	{
		while(first!=NULL)
		{
		      if(first->data==no)
		    {
				
			   break;
		    }
		
		    else if( no > (first->data))
			{
				
				first=first->rchild;
			}
			else if( no < (first->data))
			{
				
				first=first->lchild;
			}
		}
		if(first==NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

template<class T>
int  BinarySearchTree<T>:: Count()
{
	
	return size;
}


///////////////////////MAIN FUNCTION///////////////////////

int main()
{
    
    int iCount=0;
	int iRet=0;
	char ires='\0';
	int ino=0;
	char cValue='\0';
	
	bool bRet=false;
	

	SinglyLL<char> SLLcobj;
		
		
	SLLcobj.InsertFirst('A');
	SLLcobj.InsertFirst('B');
	SLLcobj.InsertFirst('C');
	
	
	SLLcobj.InsertLast('D');
	SLLcobj.InsertLast('E');
	
	

	SLLcobj.Display();
	iRet=SLLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	SLLcobj.InsertAtPos('F',3);
	SLLcobj.Display();
	
	iRet=SLLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	SLLcobj.DeleteAtPos(2);
	SLLcobj.Display();
	
	iRet=SLLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	//////////////////////////////////////////////////////////
	SinglyLL<int> SLLiobj;
		
		
	SLLiobj.InsertFirst(51);
	SLLiobj.InsertFirst(21);
	SLLiobj.InsertFirst(11);
	
	
	SLLiobj.InsertLast(101);
	SLLiobj.Display();
	
	iRet=SLLiobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	SLLiobj.InsertAtPos(52,3);
	SLLiobj.Display();
	
	iRet=SLLiobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	SLLiobj.DeleteAtPos(2);
	SLLiobj.Display();
	
	iRet=SLLiobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	

/////////////////////////////////////////


	
	SinglyCircular <int>SCiobj;
	SCiobj.InsertFirst(51);
	SCiobj.InsertFirst(21);
	SCiobj.InsertFirst(11);
	
	SCiobj.InsertLast(101);
	

	
	SCiobj.Display();
	
	iRet=SCiobj.Count();
	cout<<"number of elements  cout : "<<iRet<<"\n";
	
	SCiobj.InsertAtPos(40,3);
	SCiobj.Display();
	
	iRet=SCiobj.Count();
	cout<<"number of elements  cout : "<<iRet<<"\n";
	
	
	SCiobj.DeleteFirst();
	SCiobj.DeleteLast();
	SCiobj.Display();
	
	iRet=SCiobj.Count();
	cout<<"number of elements  cout : "<<iRet<<"\n";
	SCiobj.DeleteAtPos(2);
	
	SCiobj.Display();
	
	iRet=SCiobj.Count();
	cout<<"number of elements are  : "<<iRet<<"\n";
	
////////////////////////////////////////////////////////////////////////////////////

    SinglyCircular<char> SCcobj;
		
	SCcobj.InsertFirst('A');
	SCcobj.InsertFirst('B');
	SCcobj.InsertFirst('C');
	
	
	SCcobj.InsertLast('D');
	SCcobj.InsertLast('E');
	SCcobj.Display();
	
	iRet=SCcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	SCcobj.InsertAtPos('F',3);
	SCcobj.Display();
	
	iRet=SCcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	
	SCcobj.DeleteFirst();
	SCcobj.DeleteLast();
	
	SCcobj.Display();
	
	iRet=SCcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	SCcobj.DeleteAtPos(2);
	SCcobj.Display();
	
	iRet=SCcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	

///////////////////////////////////////////////////////////////////////////////////

	DoublyLL <int>DLLiobj;
	
	
	DLLiobj.InsertFirst(51);
	DLLiobj.InsertFirst(21);
	DLLiobj.InsertFirst(11);
	DLLiobj.InsertFirst(52);
	
	DLLiobj.InsertLast(101);
	
	
	DLLiobj.Display();
	
	iCount=DLLiobj.Count();
	cout<<"number of elements in linked list are :"<<iCount<<"\n";	
	
	DLLiobj.InsertAtPos(45,2);
	DLLiobj.Display();
	
	iCount=DLLiobj.Count();
	DLLiobj.DeleteFirst();
		cout<<"number of elements in linked list are :"<<iCount<<"\n";	
	DLLiobj.DeleteLast();
	DLLiobj.Display();
	
	iCount=DLLiobj.Count();
		cout<<"number of elements in linked list are :"<<iCount<<"\n";	
	DLLiobj.DeleteFirstX();
	DLLiobj.Display();
	
	iCount=DLLiobj.Count();
		cout<<"number of elements in linked list are :"<<iCount<<"\n";	
	
	DLLiobj.DeleteAtPos(2);
	DLLiobj.Display();
	
	iCount=DLLiobj.Count();
		cout<<"number of elements in linked list are :"<<iCount<<"\n";	

	////////////////////////////////////////////////////////////////////////////////////////
	DoublyLL<char> DLLcobj;
		
	DLLcobj.InsertFirst('A');
	DLLcobj.InsertFirst('B');
	DLLcobj.InsertFirst('C');
	
	
	DLLcobj.InsertLast('D');
	DLLcobj.InsertLast('E');
	DLLcobj.Display();
	
	iRet=DLLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	DLLcobj.InsertAtPos('F',3);
	DLLcobj.Display();
	
	iRet=DLLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	
	DLLcobj.DeleteFirst();
	DLLcobj.DeleteLast();
	
	DLLcobj.Display();
	
	iRet=DLLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	DLLcobj.DeleteAtPos(2);
	DLLcobj.Display();
	
	iRet=DLLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	
//////////////////////////////////////////////////////////////////

	DoublyCL<int> DCLiobj;
	
	
	DCLiobj.InsertFirst(21);
	DCLiobj.InsertFirst(11);
	
	DCLiobj.InsertLast(51);
	DCLiobj.InsertLast(101);
	
	
	DCLiobj.Display();
	
	DCLiobj.InsertAtPos(75,3);
	
	DCLiobj.Display();
    iRet=DCLiobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	DCLiobj.DeleteAtPos(3);
	DCLiobj.DeleteFirst();
	DCLiobj.DeleteLast();
	
	
	DCLiobj.Display();
	 iRet=DCLiobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	////////////////////////////////////////////
	DoublyCL<char> DCLcobj;
		
	DCLcobj.InsertFirst('A');
	DCLcobj.InsertFirst('B');
	DCLcobj.InsertFirst('C');
	
	
	DCLcobj.InsertLast('D');
	DCLcobj.InsertLast('E');
	DCLcobj.Display();
	
	iRet=DCLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	DCLcobj.InsertAtPos('F',3);
	DCLcobj.Display();
	
	iRet=DCLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";
	
	DCLcobj.DeleteAtPos(2);
	DCLcobj.Display();
	
	iRet=DCLcobj.Count();
	cout<<"number of elements are :"<<iRet<<"\n";

////////////////////////////////////////////////////////////////////////////////////////


	Queue<int> QueueIobj;
	
	
	QueueIobj.Enqueue(11);
	QueueIobj.Enqueue(21);
	QueueIobj.Enqueue(51);
	QueueIobj.Enqueue(101);
	
	
	QueueIobj.Display();    
	
	iRet=QueueIobj.Count();//
	cout<<"size of Queue is :"<<iRet<<"\n";
	
	 iRet=QueueIobj.Dequeue();
	cout<<"deleted element is:  "<<iRet<<"\n";         
	
	QueueIobj.Display();     
	
	iRet=QueueIobj.Count();//
	cout<<"size of Queue is :"<<iRet<<"\n";   
	
////////////////////////////////////////////	
	Queue<char> QueueCobj;
	
	QueueCobj.Enqueue('A');
	QueueCobj.Enqueue('B');
	QueueCobj.Enqueue('C');
	QueueCobj.Enqueue('D');
	
	QueueCobj.Display();     
	
	iRet=QueueCobj.Count();//
	cout<<"size of Queue is :"<<iRet<<"\n";
	
	 ires=QueueCobj.Dequeue();
	cout<<"deleted element is:  "<<ires<<"\n";         
	
	QueueCobj.Display();     
	
	iRet=QueueCobj.Count();//
	cout<<"size of Queue is :"<<iRet<<"\n";   
	
	




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	Stack<int> StackIobj;
	
	StackIobj.push(11);
	StackIobj.push(21);
	StackIobj.push(51);
	StackIobj.push(101);
	
	
	
	StackIobj.Display();     
	
	iRet=StackIobj.Count();//
	cout<<"size of stack is :"<<iRet<<"\n";
	
	 iRet=StackIobj.pop();
	cout<<"Poped element is:  "<<iRet<<"\n";        
	
	StackIobj.Display();     
	
	iRet=StackIobj.Count();//
	cout<<"size of stack is :"<<iRet<<"\n";   
	
	
	////////////////////////////
	Stack<char> StackCobj;
	
	StackCobj.push('A');
	StackCobj.push('B');
	StackCobj.push('C');
	StackCobj.push('D');
	
	StackCobj.Display();     
	
	iRet=StackCobj.Count();//
	cout<<"size of Queue is :"<<iRet<<"\n";
	
	 ires=StackCobj.pop();
	cout<<"deleted element is:  "<<ires<<"\n";         
	
	StackCobj.Display();     
	
	ires=StackCobj.Count();//
	cout<<"size of Queue is :"<<iRet<<"\n";   //3

//////////////////////////////////////////////////////////////////////////////////


	
	
	BinarySearchTree<int> BSTiobj;
	BSTiobj.Insert(21);
	BSTiobj.Insert(51);
	BSTiobj.Insert(101);
	
	
	cout<<"enter number to search"<<"\n";
	cin>>ino;
	
	bRet=BSTiobj.Search(ino);
	if(bRet==true)
	{
		cout<<"data is their\n";
	}
	else
	{
		cout<<"data is not their\n";
	}
	
	iRet=BSTiobj.Count();
	
	cout<<"number of nodes are "<<iRet<<"\n";
	
	
	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	BinarySearchTree<char> BSTcobj;
	BSTcobj.Insert('A');
	BSTcobj.Insert('B');
	BSTcobj.Insert('C');
	
	
	cout<<"enter charactor to search"<<"\n";
	cin>>cValue;
	
	bRet=BSTcobj.Search(cValue);
	if(bRet==true)
	{
		cout<<"data is their\n";
	}
	else
	{
		cout<<"data is not their\n";
	}
	
	iRet=BSTcobj.Count();
	
	cout<<"number of nodes are "<<iRet<<"\n";
	
	
	return 0;
}