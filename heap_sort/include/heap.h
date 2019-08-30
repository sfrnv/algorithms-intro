#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

struct heap {
	int size;
	int length;
	int *data;
};

int parent(int);
int left(int);
int right(int);
void max_heapify(struct heap *, int);
struct heap *build_max_heap(int *, int);