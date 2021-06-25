#ifndef Tree_h
#define Tree_h

/// <summary>
/// Each tree object
/// </summary>
class Tree
{
private:
	int status; //status of tree, 0 = no tre, 1 = tree, 2 = on fire
	int xcoord; //trees x coordinate
	int ycoord; //trees y coordinate
	int hydration; //hydration level of tree from 0 to 2

public:
	/// <summary>
	/// Construtor for the tree
	/// </summary>
	/// <param name="x">trees x coordinate</param>
	/// <param name="y">trees y coordinate</param>
	Tree(int x, int y);


	/// <summary>
	/// Get the trees x coordinate
	/// </summary>
	/// <returns></returns>
	int getX();

	/// <summary>
	/// get the trees y coordinate
	/// </summary>
	/// <returns></returns>
	int getY();

	/// <summary>
	/// get the trees hydration level
	/// </summary>
	/// <returns></returns>
	int getHydration();


	/// <summary>
	/// set the trees hydration level
	/// </summary>
	/// <param name="hydro"></param>
	void setHydration(int hydro);

	/// <summary>
	/// get the trees current status
	/// </summary>
	/// <returns></returns>
	int getStatus();

	/// <summary>
	/// set the trees current status
	/// </summary>
	/// <param name="newStatus"></param>
	void setStatus(int newStatus);
};

/// <summary>
/// Create a node for trees for a linked list
/// </summary>
class TreeNode
{
private:
	Tree* tree;
	TreeNode* next;
public:
	/// <summary>
	/// construtor
	/// </summary>
	/// <param name="x">trees x coordinate</param>
	/// <param name="y">trees y coordinate</param>
	TreeNode(int x, int y);

	//get the tree object the node has
	Tree* getTree();

	/// <summary>
	/// get the next node in the linked list
	/// </summary>
	/// <returns></returns>
	TreeNode* getNext();

	/// <summary>
	/// set the next node in the linked list
	/// </summary>
	/// <param name="nextNode"></param>
	void setNext(TreeNode* nextNode);
};

/// <summary>
/// Linked list of trees
/// </summary>
class TreeList
{
private:
	TreeNode* start;
	TreeNode* end;
public:
	/// <summary>
	/// Constructor
	/// </summary>
	TreeList();

	/// <summary>
	/// Find out if the linked list is empty
	/// </summary>
	/// <returns></returns>
	bool isEmpty();

	/// <summary>
	/// add a tree to the linked list
	/// </summary>
	/// <param name="x">trees x coordinate</param>
	/// <param name="y">trees y coordinate</param>
	void addTree(int x, int y);

	/// <summary>
	/// list all trees in linked list
	/// </summary>
	void listAll();

	/// <summary>
	/// get the first node in the linked list
	/// </summary>
	/// <returns></returns>
	TreeNode* getStart();
};

#endif // !Tree_h