package com.gabriel.jedson.listapp.Adapters;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.gabriel.jedson.listapp.Classes.Order;
import com.gabriel.jedson.listapp.R;

import java.util.ArrayList;
import java.util.Locale;

public class ItemListAdapter extends BaseAdapter {
    private Context appContext;
    private LayoutInflater mInflater;
    private ArrayList<Order.Item> items;

    public ItemListAdapter(Context appContext, ArrayList<Order.Item> items) {
        this.appContext = appContext;
        this.items = items;

        this.mInflater = (LayoutInflater)appContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        return items.size();
    }

    @Override
    public Object getItem(int position) {
        return this.items.get(position);
    }

    @Override
    public long getItemId(int position) {
        return ((Order.Item)this.getItem(position)).getItemID();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        Order.Item item = (Order.Item)this.getItem(position);
        View itemView = mInflater.inflate(R.layout.item_listview_detail, null);

        if(item.updateRef()) {
            TextView itemNameTextView = itemView.findViewById(R.id.itemNameTextView);
            TextView itemQntTextView = itemView.findViewById(R.id.itemQntTextView);
            TextView itemCostTextView = itemView.findViewById(R.id.itemCostTextView);

            itemNameTextView.setText(item.getName());
            itemQntTextView.setText(String.format(Locale.US, "x%d", item.getQuantity()));
            itemCostTextView.setText(String.format(Locale.US, "$ %.2f", item.getCost()));
        } else {
            itemView.setVisibility(View.INVISIBLE);
            items.remove(item);
        }

        return itemView;
    }
}
