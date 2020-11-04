struct NodeBase {
	NodeBase() = default;
	NodeBase(const NodeBase&) = delete;
	NodeBase& operator=(const NodeBase&) = delete;
	NodeBase& operator=(NodeBase&& rhs)
	{
		parent = rhs.parent; rhs.parent = nullptr;
		children = move(rhs.children);
		return *this;
	}
	NodeBase(NodeBase&& rhs) { *this = move(rhs); }

	NodeBase* parent = nullptr;
	list<NodeBase*> children;

	bool isRoot() { return parent == nullptr; }
	bool isLeaf() { return children.empty(); }
	NodeBase* root(int* depth)
	{
		int d = 0;
		NodeBase* node = this;
		while (node->parent) {
			node = node->parent;
			d++;
		}
		if (depth) *depth = d;
		return node;
	}
	void appendChild(NodeBase* child)
	{
		if (child->parent) {
			child->parent->removeChild(child);
		}
		child->parent = this;
		children.push_back(move(child));
	}
	void removeChild(NodeBase* child)
	{
		if (child->parent == this) {
			children.remove(child);
			child->parent = nullptr;
		}
	}
};
