package com.gabriel.jedson.listapp.Classes;

import android.util.Log;
import android.util.SparseArray;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Locale;

public class ItemPool {
    private static final ItemPool ourInstance = new ItemPool();

    public static ItemPool getInstance() {
        return ourInstance;
    }

    private FirebaseDatabase mDatabase;
    private DatabaseReference mDatabaseRef;

    private SparseArray<Item> pool;

    private ItemPool() {
        this.pool = new SparseArray<Item>();
        this.mDatabase = FirebaseDatabase.getInstance();
        this.mDatabaseRef = FirebaseDatabase.getInstance().getReference();
    }

    public void addItem(int itemId, String name, double cost) {
        Item newItem = new Item(itemId, name, cost);

        this.pool.put(itemId, newItem);
//        addToDatabase(newItem);
    }

    public void removeItem(int id) {
        Item foundItem = findItemById(id);

        pool.remove(id);
    }

    private void addToDatabase(Item newItem) {
        DatabaseReference itemRef = mDatabaseRef.child("items").child(Integer.toString(newItem.getItemId()));
        itemRef.child("name").setValue(newItem.name);
        itemRef.child("cost").setValue(newItem.cost);
    }

    private void updateItem(Item item) {
        if(this.pool.get(item.itemID) != null) {
            this.pool.put(item.itemID, item);
        }
    }

    public Item findItemById(int id) {
        Item foundItem = null;

        if(this.pool.get(id) != null) {
            return this.pool.get(id);
        }

        return findOnDatabase(id);
    }

    private Item findOnDatabase(int id) {
        final Item foundItem = new Item(id, "FETCHING");

        DatabaseReference itemRef = mDatabaseRef.child("items").child(Integer.toString(id));
        ValueEventListener eventListener = new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                Item item = null;
                int id = Integer.parseInt(dataSnapshot.getKey());
                if(dataSnapshot.exists()) {
                    item = parseItemData(dataSnapshot);
                    item.setFetchStatus("SUCCESSFUL");
                } else {
                    Log.d("ItemDatabase", String.format(Locale.US, "ID NOT FOUND (%d)\n", id));
                    findItemById(id).setFetchStatus("FAILED");
                }
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {}
        };
        itemRef.addListenerForSingleValueEvent(eventListener);

        this.pool.put(foundItem.itemID, foundItem);

        return foundItem;
    }

    private Item parseItemData(DataSnapshot dataSnapshot) {
        Item newItem = null;

        int id = Integer.parseInt(dataSnapshot.getKey());
        Object name = dataSnapshot.child("name").getValue();
        Object cost = dataSnapshot.child("cost").getValue();

        if(name != null && cost != null) {
            newItem = new Item(id, name.toString(), Double.parseDouble(cost.toString()));
            updateItem(newItem);

            Log.d("ItemDatabase", String.format(Locale.US, "Item:\nId = %d\nname = %s\nCost = %f\n", id, name.toString(), Double.parseDouble(cost.toString())));
        }

        return newItem;
    }

    public static class Item implements Serializable {
        private int itemID;
        private String name;
        private double cost;
        private String fetchStatus;

        public Item(int itemId, String fetchStatus) {
            this.itemID = itemId;
            this.fetchStatus = fetchStatus;
        }

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

        public String getFetchStatus() {
            return fetchStatus;
        }

        public void setFetchStatus(String fetchStatus) {
            this.fetchStatus = fetchStatus;
        }
    }

}
