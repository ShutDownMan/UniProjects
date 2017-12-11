#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAXSTR	128
#define MAXPTR 	64

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
	int peopleNum;
	
	Order** consumed;
	int quantConsumed;

} OrderData;

int loadData(char fileName[], OrderData** orders, int* quantOrders, Waiter** waiters, int* quantWaiters, Item** items, int* quantItems);

void loadDate(FILE* f, OrderData* order);
void loadWaiter(FILE* f, OrderData* order, Waiter** waiters, int* quantWaiters);
void loadConsumed(FILE* f, OrderData* order, Item** items, int* quantItems);

Waiter* findWaiter(char waiterName[], Waiter** waiters, int* quantWaiters);
Item* findItem(char itemName[], Item** items, int* quantItems);

int debugRelat(char fileName[], OrderData** orders, int quantOrders);

int main(int argc, char const *argv[]) {
	OrderData** orders = NULL;
	Waiter** waiters = NULL;
	Item** items = NULL;
	int quantOrders, quantWaiters, quantItems;

	orders = malloc(sizeof(OrderData*) * MAXPTR);
	waiters = malloc(sizeof(Waiter*) * MAXPTR);
	items = malloc(sizeof(Item*) * MAXPTR);

	if(loadData("consumo.txt", orders, &quantOrders, waiters, &quantWaiters, items, &quantItems)) return 1;

	orders = realloc(orders, sizeof(OrderData*) * (quantOrders));
	waiters = realloc(waiters, sizeof(Waiter*) * (quantWaiters));
	items = realloc(items, sizeof(Item*) * (quantItems));

	debugRelat("debugrelat.txt", orders, quantOrders);


	return 0;
}

// LOAD DATA

int loadData(char fileName[], OrderData** orders, int* quantOrders, Waiter** waiters, int* quantWaiters, Item** items, int* quantItems) {
	FILE* f;
	int i;

	*quantOrders = *quantWaiters = *quantItems = 0;
	if(!(f = fopen(fileName, "r"))) return 1;

	for (i = 0; i < 1; ++i) {
		orders[i] = malloc(sizeof(OrderData));

		loadDate(f, orders[i]);

		loadWaiter(f, orders[i], waiters, quantWaiters);

		fscanf(f, "%*s %d%*c", &orders[i]->tableID);

		fscanf(f, "%d%*c%d ", &orders[i]->startTimeStamp.tm_hour, &orders[i]->startTimeStamp.tm_min);
		fscanf(f, "%d%*c%d%*c", &orders[i]->endTimeStamp.tm_hour, &orders[i]->endTimeStamp.tm_min);

		fscanf(f, "%d%*c", &orders[i]->peopleNum);

		loadConsumed(f, orders[i], items, quantItems);

		(*quantOrders)++;
	}

	return 0;
}

void loadConsumed(FILE* f, OrderData* order, Item** items, int* quantItems) {
	int i;
	char currItemName[MAXSTR];
	int currItemQuant;
	float currItemPrice;

	order->consumed = malloc(sizeof(Order*) * MAXPTR);

	order->quantConsumed = 0;

	fscanf(f, "%s", currItemName);
	for (i = 0; strcmp(currItemName, "<fim>"); ++i) {
		fscanf(f, "%d %f%*c", &currItemQuant, &currItemPrice);

		order->consumed[i] = malloc(sizeof(Order));

		if(order->consumed[i]->orderedItem = findItem(currItemName, items, quantItems)) {
			(*quantItems)++;
			return;
		}

		order->consumed[i]->orderedItem = malloc(sizeof(Item));

		order->consumed[i]->orderedItem->id = *quantItems;
		order->consumed[i]->orderedItem->name = strcpy(malloc(sizeof(char) * strlen(currItemName)), currItemName);
		order->consumed[i]->orderedItem->price = currItemPrice;

		order->consumed[i]->quant = currItemQuant;
		order->quantConsumed++;

		items[*quantItems] = order->consumed[i]->orderedItem;
		(*quantItems)++;

		fscanf(f, "%s", currItemName);
	}

}

Item* findItem(char itemName[], Item** items, int* quantItems) {
	int i;

	for (i = 0; i < *quantItems; ++i) {
		if(!strcmp(items[i]->name, itemName)) return items[i];
	}

	return 0;
}

void loadWaiter(FILE* f, OrderData* order, Waiter** waiters, int* quantWaiters) {
	char waiterName[MAXSTR];

	fscanf(f, "%[^\n]%*c", waiterName);

	if(order->mainWaiter = findWaiter(waiterName, waiters, quantWaiters)) return;

	order->mainWaiter = malloc(sizeof(Waiter));

	order->mainWaiter->id = *quantWaiters;
	order->mainWaiter->name = strcpy(malloc(sizeof(char) * strlen(waiterName)), waiterName);

	(*quantWaiters)++;
}

Waiter* findWaiter(char waiterName[], Waiter** waiters, int* quantWaiters) {
	int i;

	for (i = 0; i < *quantWaiters; ++i) {
		if(!strcmp(waiters[i]->name, waiterName)) return waiters[i];
	}

	return 0;
}

void loadDate(FILE* f, OrderData* order) {
	fscanf(f, "%d/%d/%d%*c", &(order->startTimeStamp.tm_mday), &(order->startTimeStamp.tm_mon), &(order->startTimeStamp.tm_year));

	order->endTimeStamp.tm_mday = order->startTimeStamp.tm_mday;
	order->endTimeStamp.tm_mon = order->startTimeStamp.tm_mon;
	order->endTimeStamp.tm_year = order->startTimeStamp.tm_year;
}

// PRINT DATA

int debugRelat(char fileName[], OrderData** orders, int quantOrders) {
	FILE* f;
	int i;

	if(!(f = fopen(fileName, "w"))) return 1;

	fprintf(stdout, "quantOrders = %d\n", quantOrders);

	for (i = 0; i < quantOrders; ++i) {
		fprintf(stderr, "%s\n", orders[i]->mainWaiter->name);
		//fprintf(stderr, "%d\n", orders[i]->tableID);
		//fprintf(f, "%-30s\n", orders[i]->mainWaiter->name);
	}


}