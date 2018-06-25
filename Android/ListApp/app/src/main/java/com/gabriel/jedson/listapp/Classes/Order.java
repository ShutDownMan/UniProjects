package com.gabriel.jedson.listapp.Classes;

import java.io.Serializable;
import java.util.ArrayList;

public class Order implements Serializable {
    private int orderId;
    private String orderType;
    private ArrayList<Item> itemsOrdered;

    public Order(int orderID, String orderType, ArrayList<Item> itemsOrdered) {
        this.orderId = orderID;
        this.orderType = orderType;
        this.itemsOrdered = itemsOrdered;
    }

    public String getOrderType() {
        return orderType;
    }

    public ArrayList<Item> getItems() {
        return itemsOrdered;
    }

    public int getOrderId() {
        return orderId;
    }

    public int getTotalQuantity() {
        int sum = 0;

        for (Order.Item item : this.getItems()) {
            sum += item.getQuantity();
        }

        return sum;
    }

    public double getTotalCost() {
        double sum = 0;

        for (Order.Item item : this.getItems()) {
            sum += item.getCost() * item.getQuantity();
        }

        return sum;
    }

    public static class Item implements Serializable{
        private int quantity;

        ItemPool.Item refItem;

        public Item(ItemPool.Item refItem, int quantity) {
            this.refItem = refItem;
            this.quantity = quantity;
        }

        public int getItemID() {
            return refItem.getItemId();
        }

        public int getQuantity() {
            return quantity;
        }

        public double getCost() {
            return refItem.getCost();
        }

        public String getName() {
            return refItem.getName();
        }
    }
}
