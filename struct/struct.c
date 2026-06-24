#include <stdio.h>
#include <stdlib.h>
struct Item {
	int value;
};

// A function that initialize existing struct variable
void create_item(struct Item *item){
	item->value = 5;
};


// A function that allocate struct in Heap, then pass address to corresponding function
struct Item *create_address_item(){
	struct Item *item = malloc(sizeof(struct Item));
	item->value = 6;
	return item;
};


int main(void) {
	printf("function create_item allocating struct Item in main stack\n");
	struct Item item1;
	create_item(&item1);

	printf("and returning value is: %d\n", item1.value);



	printf("function create_address_item allocate struct Item in Heap first, than pass address to main stack\n");
	struct Item *item2 = create_address_item();
	printf("allocating in Heap with address: %p\n", item2);
	printf("and returning value is: %d\n", item2->value);
	free(item2);
	item2 = NULL;
	printf("Just freed item2\n");
	printf("item2 addres: %p", item2);


	return 0;
}
