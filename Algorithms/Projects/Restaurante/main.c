#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSTR	128
#define MAXPTR 	64

typedef struct Item {
	char name[MAXSTR];
	int price;
} Item;

typedef struct Order {
	int id;
	Item* orderedItem;
	int quant;
} Order;

typedef struct Waiter {
	int id;
	char name;
} Waiter;

typedef struct OrderData {
	struct tm startTimeStamp;
	struct tm endTimeStamp;

	Waiter* mainWaiter;
	char waiterName[MAXSTR];
	
	int tableID;
	int peopleNum;
	
	Order** consumed;
	int quantConsumed;

} OrderData;

int loadData(char fileName[], OrderData** orders, int* quantOrder, Waiter** waiters, int* quantWaiters);
void loadWaiter(FILE* f, OrderData* order, Waiter** waiters, int* quantWaiters);
void loadDate(FILE* f, OrderData* order);

int main(int argc, char const *argv[]) {
	OrderData** orders;
	Waiter** waiters;
	int quantOrder, quantWaiters;

	if(!loadData("consumo.txt", orders, &quantOrder)) return 1;



	return 0;
}

int loadData(char fileName[], OrderData** orders, int* quantOrder, Waiter** waiters, int* quantWaiters) {
	FILE* f;
	int i;

	orders = malloc(sizeof(OrderData*) * MAXPTR);
	waiters = malloc(sizeof(Waiter*) * MAXPTR);

	if(!(f = fopen(fileName, "r"))) return 1;

	for (i = 0; feof(f); ++i) {
		orders[i] = malloc(sizeof(OrderData));

		loadDate(f, orders[i]);

		loadWaiter(f, orders[i], waiters, quantWaiters);

	}


}

void loadWaiter(FILE* f, OrderData* order, Waiter** waiters, int* quantWaiters) {
	char** waiterName;

	waiterName = malloc(sizeof(char) * MAXSTR);

	fscanf("%[^\n]%*c", waiterName);


}

void loadDate(FILE* f, OrderData* order) {
	fscanf(f, "%d/%d/%d%*c", &(order->startTimeStamp.tm_mday), &(order->startTimeStamp.tm_mon), &(order->startTimeStamp.tm_year));

	order->endTimeStamp.tm_mday = order->startTimeStamp.tm_mday;
	order->endTimeStamp.tm_mon = order->startTimeStamp.tm_mon;
	order->endTimeStamp.tm_year = order->startTimeStamp.tm_year;
}