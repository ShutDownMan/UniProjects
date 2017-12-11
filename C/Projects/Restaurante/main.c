#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAXSTR	128
#define MAXPTR 	1024

typedef struct Item {
	int id;
	char* name;
	int price;
} Item;

typedef struct Order {
	int id;
	Item* orderedItem;
	int quant;
} Order;

typedef struct Waiter {
	int id;
	char* name;
	float vendaTotal;
} Waiter;

typedef struct OrderData {
	struct tm startTimeStamp;
	struct tm endTimeStamp;

	Waiter* mainWaiter;

	int tableID;
	int quantPeople;

	Order** consumed;
	int quantConsumed;

} OrderData;

int loadData(char fileName[], OrderData** orders, int* quantOrders, Waiter** waiters, int* quantWaiters, Item** items, int* quantItems);

void loadDate(FILE* f, struct tm* date);
void loadWaiter(FILE* f, OrderData* order, Waiter** waiters, int* quantWaiters);
void loadConsumed(FILE* f, OrderData* order, Item** items, int* quantItems);

Waiter* findWaiter(char waiterName[], Waiter** waiters, int quantWaiters);
Item* findItem(char itemName[], Item** items, int quantItems);

int debugRelat(char fileName[], OrderData** orders, int quantOrders);

int main(int argc, char const *argv[]) {
	// orders store all orders of the day
	OrderData** orders = NULL;
	// waiters store all know waiters
	Waiter** waiters = NULL;
	// items store all known items
	Item** items = NULL;
	int quantOrders, quantWaiters, quantItems;

	// alloc memory for the arrays
	orders = malloc(sizeof(OrderData*) * MAXPTR);
	waiters = malloc(sizeof(Waiter*) * MAXPTR);
	items = malloc(sizeof(Item*) * MAXPTR);

	// If we load we good
	if(loadData("consumo.txt", orders, &quantOrders, waiters, &quantWaiters, items, &quantItems)) return 1;

	// Try'na not occupy unused space
	orders = realloc(orders, sizeof(OrderData*) * (quantOrders));
	waiters = realloc(waiters, sizeof(Waiter*) * (quantWaiters));
	items = realloc(items, sizeof(Item*) * (quantItems));

	// Let see if things loaded correctly
	debugRelat("debugrelat.txt", orders, quantOrders);

	return 0;
}

// LOAD DATA

int loadData(char fileName[], OrderData** orders, int* quantOrders, Waiter** waiters, int* quantWaiters, Item** items, int* quantItems) {
	FILE* f;
	struct tm date;
	int i;

	// Set it all to ZERO/NADA/NOTHING/NULL
	*quantOrders = *quantWaiters = *quantItems = 0;
	// open file with data
	if(!(f = fopen(fileName, "r"))) return 1;

	// Load day of data
	loadDate(f, &date);

	// read all orders
	for (i = 0; !feof(f); ++i) {
		// alloc memory for data
		orders[i] = malloc(sizeof(OrderData));

		// get table waiter
		loadWaiter(f, orders[i], waiters, quantWaiters);

		// get table ID
		fscanf(f, "%*s %d%*c", &orders[i]->tableID);

		// printf("table => %d\n", orders[i]->tableID);

		// Get hour of meal(?)
		fscanf(f, "%d%*c%d%*c", &orders[i]->startTimeStamp.tm_hour, &orders[i]->startTimeStamp.tm_min);
		fscanf(f, "%d%*c%d%*c", &orders[i]->endTimeStamp.tm_hour, &orders[i]->endTimeStamp.tm_min);

		// get quant of people at table
		fscanf(f, "%d%*c", &orders[i]->quantPeople);

		// get consumed items
		loadConsumed(f, orders[i], items, quantItems);

		// Increase order count
		(*quantOrders)++;
	}

	return 0;
}

void loadConsumed(FILE* f, OrderData* order, Item** items, int* quantItems) {
	int i;
	char currItemName[MAXSTR];
	int currItemQuant;
	float currItemPrice;

	// alloc memory for order array
	order->consumed = malloc(sizeof(Order*) * MAXPTR);

	// initialize cosumed items to ZERO
	order->quantConsumed = 0;

	// scan current line
	fscanf(f, "%s%*c", currItemName);
	// if not end keep reading
	for (i = 0; strcmp(currItemName, "<fim>"); ++i) {
		// got here, then read quant and price
		fscanf(f, "%d %f%*c", &currItemQuant, &currItemPrice);

		// alloc memory for that item
		order->consumed[i] = malloc(sizeof(Order));

		// printf("[%d] => %s\n", i, currItemName);

		// store item quantity and increase item array counter
		order->consumed[i]->quant = currItemQuant;
		order->quantConsumed++;

		// if current item not found in list
		if(!(order->consumed[i]->orderedItem = findItem(currItemName, items, *quantItems))) {

			// create a new one
			order->consumed[i]->orderedItem = malloc(sizeof(Item));

			// store id, name and price
			order->consumed[i]->orderedItem->id = *quantItems;
			order->consumed[i]->orderedItem->name = strcpy(malloc(sizeof(char) * strlen(currItemName)), currItemName);
			order->consumed[i]->orderedItem->price = currItemPrice;

			// add pointer to array and update list counter
			items[*quantItems] = order->consumed[i]->orderedItem;
			(*quantItems)++;
		}

		// scan for a new item
		fscanf(f, "%s%*c", currItemName);
	}
	// Gotta use less space o/
	realloc(order->consumed, sizeof(Order*) * (order->quantConsumed));
	// printf("------\n");
}

Item* findItem(char itemName[], Item** items, int quantItems) {
	int i;

	// for each item in array
	for (i = 0; i < quantItems; ++i) {
		// if found item, return it
		if(!strcmp(items[i]->name, itemName)) return items[i];
	}

	// if not, return 0
	return 0;
}

void loadWaiter(FILE* f, OrderData* order, Waiter** waiters, int* quantWaiters) {
	char waiterName[MAXSTR];

	// scan waiter name
	fscanf(f, "%[^\n]%*c", waiterName);

	// printf("name = %s / quant = %d\n", waiterName, *quantWaiters);

	// if waiter not found in array
	if(order->mainWaiter = findWaiter(waiterName, waiters, *quantWaiters)) return;

	// create a new one
	order->mainWaiter = malloc(sizeof(Waiter));

	// store it's id and name
	order->mainWaiter->id = *quantWaiters;
	order->mainWaiter->name = strcpy(malloc(sizeof(char) * strlen(waiterName)), waiterName);

	// add pointer to array and update array counter
	waiters[*quantWaiters] = order->mainWaiter;
	(*quantWaiters)++;

	// printf("waiters = %d\n", *quantWaiters);
}

Waiter* findWaiter(char waiterName[], Waiter** waiters, int quantWaiters) {
	int i;

	// for each waiter in array
	for (i = 0; i < quantWaiters; ++i) {
		// if waiter found, return it
		if(!strcmp(waiters[i]->name, waiterName)) return waiters[i];
	}

	// if not, return 0
	return 0;
}


void loadDate(FILE* f, struct tm* date) {
	// read day/month/year as it should be
	fscanf(f, "%d/%d/%d%*c", &(date->tm_mday), &(date->tm_mon), &(date->tm_year));

	// fprintf(stderr, "%d/%d/%d\n", date->tm_mday, date->tm_mon, date->tm_year);
}

// PRINT DATA

int debugRelat(char fileName[], OrderData** orders, int quantOrders) {
	FILE* f;
	int i;

	if(!(f = fopen(fileName, "w"))) return 1;

	fprintf(stderr, "quantOrders = %d\n", quantOrders);

	for (i = 0; i < quantOrders; ++i) {
		//fprintf(stderr, "%d/%d/%d\n", orders[i]->startTimeStamp.tm_mday, orders[i]->startTimeStamp.tm_mon, orders[i]->startTimeStamp.tm_year);
		//fprintf(stderr, "%s\n", orders[i]->mainWaiter->name);
		//fprintf(stderr, "MESA %d\n", orders[i]->tableID);
		//fprintf(stderr, "%d\n", orders[i]->quantPeople);
	}


}