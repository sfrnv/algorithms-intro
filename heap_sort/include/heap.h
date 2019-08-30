#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

struct heap {
	int size;
	int length;
	int *data;
};

struct heap *build_max_heap(int *, int);
struct heap *build_empty_heap(int);
int poll(struct heap *);
void insert(struct heap *pt, int new);