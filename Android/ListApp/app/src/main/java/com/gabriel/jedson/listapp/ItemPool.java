package com.gabriel.jedson.listapp;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.io.Serializable;
import java.util.ArrayList;

public class ItemPool implements Serializable {
    private static final ItemPool ourInstance = new ItemPool();

    static ItemPool getInstance() {
        return ourInstance;
    }

    private ArrayList<Item> pool;

    private ItemPool() {
        this.pool = new ArrayList<Item>();
    }

    public void addItem(int itemId, String name, double cost) {
        this.pool.add(new Item(itemId, name, cost));
    }

    public Item findItemById(int id) {
        Item foundItem = null;

        for (Item item : this.pool) {
            if(item.getItemId() == id) {
                return item;
            }
        }

        // get item from database
        foundItem = findOnDatabase(id);

        return foundItem;
    }

    private Item findOnDatabase(int id) {
        Item foundItem = null;
        FirebaseDatabase db = FirebaseDatabase.getInstance();
        DatabaseReference dbRef = db.getReference();

        return foundItem;
    }

    public static class Item implements Serializable {
        private int itemID;
        private String name;
        private double cost;

        public Item(int itemID, String name, double cost) {
            this.itemID = itemID;
            this.name = name;
            this.cost = cost;
        }

        public int getItemId() {
            return itemID;
        }

        public double getCost() {
            return cost;
        }

        public String getName() {
            return name;
        }
    }

}
