#include <iostream>
//#include <string>

using std::string;
using std::cout;
using std::endl;

class BST;
class TreeNode
{
	private:
	    string element;
	    int key;
	    TreeNode *leftchild, *rightchild;

	public:
		TreeNode():element(""),key(0),leftchild(0),rightchild(0){};
        TreeNode(string a, int b):element(a),key(b),leftchild(0),rightchild(0){};

         int GetKey(){return key;}              // 為了在main()要能夠檢視node是否正確
        string GetElement(){return element;}   // 才需要這兩個member function讀取private data

	friend class BST;
};

class BST
{
	private:
		//TreeNode *root;

	public:
		TreeNode *root;

		BST():root(){};
		void search(int searchkey);
		void insert(string element, int key);
		void InorderPrint(TreeNode *current);
		void PreorderPrint(TreeNode *current);
		void PostorderPrint(TreeNode *current);
};

void BST::search(int searchkey)
{
	TreeNode *current = root;

	while(current != NULL && current->key != searchkey)
	{
       if(searchkey < current->key)
       {
           current = current->leftchild;
       }
       else if (searchkey > current->key)
       {
		   current = current->rightchild;
       }
       else
       {
       		cout << "\nThere is " << current->GetElement() << "(" << current->GetKey() << ")\n" << endl;
	   }
	}

	cout << " \nthere is no key(" << searchkey << ")\n"<<endl;
}

void BST::insert(string element, int key)
{
	TreeNode *InsertNode = new TreeNode(element,key);
    TreeNode *NewParent = root;

    while(NewParent != NULL)
    {
    	if(InsertNode->key < NewParent->key)
    		if(NewParent->leftchild != NULL)
    			NewParent = NewParent->leftchild;
    		else
    			break;
    	else
    		if(NewParent->rightchild != NULL)
    			NewParent = NewParent->rightchild;
    		else
    			break;
    }

    if(NewParent == NULL)
    	this->root = InsertNode;
    else if (InsertNode->key < NewParent->key)
    	NewParent->leftchild = InsertNode;
    else
        NewParent->rightchild = InsertNode;

}

void BST::InorderPrint(TreeNode *current)
{ 
	if(current != NULL)
	{
		InorderPrint(current->leftchild); //L
		cout << current->element << "(" << current->key << ")" << " " << endl; //當前root沒有左子樹 ，故開始輸出當前root
		InorderPrint(current->rightchild); //R
	}
}

void BST::PreorderPrint(TreeNode *current)
{ 
	if(current != NULL)
	{
		cout << current->element << "(" << current->key << ")" << " " << endl; //輸出當前root
		PreorderPrint(current->leftchild); //L
		PreorderPrint(current->rightchild); //R
	}
}

void BST::PostorderPrint(TreeNode *current)
{ 
	if(current != NULL)
	{
		PostorderPrint(current->leftchild); //L
		PostorderPrint(current->rightchild); //R
	    cout << current->element << "(" << current->key << ")" << " " << endl; //輸出當前root
	}
}


int main()
{
	BST T;

	T.insert("龜仙人",8);
    T.insert("悟空",1000);
    T.insert("克林",2);
    T.insert("比克",513);

    cout << "\nInorder Traversal:\n";
    T.InorderPrint(T.root);
    cout << endl;

    cout << "\nPreorder Traversal:\n";
    T.PreorderPrint(T.root);
    cout << endl;

    cout << "\nPostorder Traversal:\n";
    T.PostorderPrint(T.root);
    cout << endl;

    T.search(1000);

	system("pause");
	return 0;
}