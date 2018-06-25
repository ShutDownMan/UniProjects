package com.gabriel.jedson.listapp.Classes;

import android.util.Log;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Locale;

public class ItemPool {
    private static final ItemPool ourInstance = new ItemPool();

    public static ItemPool getInstance() {
        return ourInstance;
    }

    private FirebaseDatabase mDatabase;
    private DatabaseReference mDatabaseRef;

    private ArrayList<Item> pool;

    private ItemPool() {
        this.pool = new ArrayList<Item>();
        this.mDatabase = FirebaseDatabase.getInstance();
        this.mDatabaseRef = FirebaseDatabase.getInstance().getReference();
    }

    public void addItem(int itemId, String name, double cost) {
        Item newItem = new Item(itemId, name, cost);

        this.pool.add(newItem);
        addToDatabase(newItem);
    }

    private void addToDatabase(Item newItem) {
        DatabaseReference itemRef = mDatabaseRef.child("items").child(Integer.toString(newItem.getItemId()));
        itemRef.child("name").setValue(newItem.name);
        itemRef.child("cost").setValue(newItem.cost);
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
        final Item[] foundItem = {null};

        DatabaseReference itemRef = mDatabaseRef.child("items").child(Integer.toString(id));
        ValueEventListener eventListener = new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                if(dataSnapshot.exists()) {
                    foundItem[0] = new Item(Integer.parseInt(dataSnapshot.getKey()), dataSnapshot.child("name").getValue().toString(), Double.parseDouble(dataSnapshot.child("cost").getValue().toString()));
                }
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {}
        };
        itemRef.addListenerForSingleValueEvent(eventListener);

        if(foundItem[0] != null)
            Log.d("ItemDatabase", String.format(Locale.US, "Item:\nId = %d\nname = %s\nCost = %f\n", foundItem[0].getItemId(), foundItem[0].getName(), foundItem[0].getCost()));

        return foundItem[0];
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
