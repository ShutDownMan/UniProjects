package com.gabriel.jedson.listapp;

import android.content.Intent;
import android.support.design.widget.FloatingActionButton;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Random;

public class MainActivity extends AppCompatActivity {
    ListView ordersListView;
    SwipeRefreshLayout orderListSwipeRefreshLayout;
    FloatingActionButton addNewOrderFloatingActionButton;

    ArrayList<Order> orders;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupInstances();
        setupViewMethods();
        setupPlaceHolderItems();

        addPlaceHolderOrder();
        showOrderList();

    }

    private void setupInstances() {
        this.ordersListView = (ListView)findViewById(R.id.ordersListView);
        this.orderListSwipeRefreshLayout = (SwipeRefreshLayout)findViewById(R.id.orderListSwipeRefreshLayout);
        this.addNewOrderFloatingActionButton = (FloatingActionButton)findViewById(R.id.addNewOrderFloatingActionButton);

        this.orders = new ArrayList<Order>();
    }

    private void setupViewMethods() {
        this.orderListSwipeRefreshLayout.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                showOrderList();
                orderListSwipeRefreshLayout.setRefreshing(false);
            }
        });
        this.ordersListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                openOrderDetailScreen(id);
            }
        });
        this.addNewOrderFloatingActionButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addPlaceHolderOrder();
                showOrderList();
            }
        });
    }

    private void setupPlaceHolderItems() {
        ItemPool itemPool = ItemPool.getInstance();

        itemPool.addItem(0, "NONE", 0);
        itemPool.addItem(1, "coke", 1.99);
        itemPool.addItem(2, "ice cream", 2.99);
        itemPool.addItem(3, "candy", 0.99);
    }

    private void openOrderDetailScreen(long id) {
        Intent orderDetailScreenIntent = new Intent(this.getApplicationContext(), OrderDetailActivity.class);
        Order foundOrder = findOrderById(id);
        orderDetailScreenIntent.putExtra(getResources().getString(R.string.order_id_extra_key), findOrderById(id));
        Log.d("OrderSerialization", String.format(Locale.US, "Order:\nId = %d\nItems = %d\nCost = %f\n", id, foundOrder.getTotalQuantity(), foundOrder.getTotalCost()));
        startActivity(orderDetailScreenIntent);
    }

    private Order findOrderById(long id) {
        Order foundOrder = null;
        for (Order order : this.orders) {
            if (order.getOrderId() == id) {
                foundOrder = order;
            }
        }

        return foundOrder;
    }

    private void addPlaceHolderOrder() {
        Random random = new Random();
        ItemPool itemPool = ItemPool.getInstance();
        ArrayList<Order.Item> itemsList = new ArrayList<>();

        itemsList.add(new Order.Item(itemPool.findItemById(1), 1+random.nextInt(12)));
        itemsList.add(new Order.Item(itemPool.findItemById(2), 1+random.nextInt(12)));
        itemsList.add(new Order.Item(itemPool.findItemById(3), 1+random.nextInt(12)));

        this.orders.add(new Order(this.orders.size(), "NONE", itemsList));
    }

    private void showOrderList() {
        OrderListAdapter orderListAdapter = new OrderListAdapter(this, this.orders);

        this.ordersListView.setAdapter(orderListAdapter);
    }
}
