template <class Type> class Queue 
{
public:
	Queue(): head(0), tail(0) {}
	Queue(const Queue &Q): head(0), tail(0)
	{ copy_elems(Q); }

	Queue& operator=(const Queue&);
	~Queue() {destroy(); }
	
