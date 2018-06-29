package com.gabriel.jedson.listapp.Classes;

import android.util.SparseArray;

import java.io.Serializable;
import java.util.ArrayList;

public class Order implements Serializable {
    private int orderId;
    private String orderType;
    private SparseArray<Item> itemsOrdered;

    public Order(int orderID, String orderType, SparseArray<Item> itemsOrdered) {
        this.orderId = orderID;
        this.orderType = orderType;
        this.itemsOrdered = itemsOrdered;
    }

    public String getOrderType() {
        return orderType;
    }

    public SparseArray<Item> getItemsOrdered() {
        return itemsOrdered;
    }

    SparseArray<Item> getItems() {
        return itemsOrdered;
    }

    public int getOrderId() {
        return orderId;
    }

    public int getTotalQuantity() {
        int sum = 0;

        for(int i = 0; i < this.itemsOrdered.size(); i++) {
            int key = this.itemsOrdered.keyAt(i);
            Item item = this.itemsOrdered.get(key);

            if(!item.isLoaded()) {
                sum += item.getQuantity();
            }

        }

        return sum;
    }

    public double getTotalCost() {
        double sum = 0;

        for(int i = 0; i < this.itemsOrdered.size(); i++) {
            int key = this.itemsOrdered.keyAt(i);
            Item item = this.itemsOrdered.get(key);

            if(!item.isLoaded()) {
                sum += item.getCost() * item.getQuantity();
            }

        }

        return sum;
    }

    public boolean isLoaded() {
        for(int i = 0; i < this.itemsOrdered.size(); i++) {
            int key = this.itemsOrdered.keyAt(i);
            Item item = this.itemsOrdered.get(key);

            if(!item.isLoaded()) {
                return false;
            }
        }

        return true;
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

        public boolean updateRef() {
            ItemPool itemPool = ItemPool.getInstance();
            int id = this.getItemID();
            this.refItem = itemPool.findItemById(id);

            if(this.refItem == null) {
                itemPool.removeItem(id);
                return false;
            }

            return true;
        }

        public boolean isLoaded() {
            return (this.refItem.getFetchStatus().equals("SUCCESSFUL"));
        }
    }
}
