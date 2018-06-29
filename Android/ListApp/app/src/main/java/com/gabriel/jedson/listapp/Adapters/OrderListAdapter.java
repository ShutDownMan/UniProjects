package com.gabriel.jedson.listapp.Adapters;

import android.content.Context;
import android.util.SparseArray;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.gabriel.jedson.listapp.Classes.Order;
import com.gabriel.jedson.listapp.R;

import java.util.ArrayList;
import java.util.Locale;

public class OrderListAdapter extends BaseAdapter {
    private LayoutInflater mInflater;
    private Context appContext;
    private SparseArray<Order> orders;
    private SparseArray<Order> pending;

    public OrderListAdapter(Context appContext, SparseArray<Order> orders) {
        this.orders = new SparseArray<>();
        this.pending = orders;
        this.appContext = appContext;

        this.mInflater = (LayoutInflater)this.appContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

        initialize();
    }

    private void initialize() {
        checkPendingOrders();
    }

    private void checkPendingOrders() {
        for(int i = 0; i < this.pending.size();) {
            int key = this.pending.keyAt(i);
            Order order = this.pending.get(key);

            if(order.isLoaded()) {
                this.orders.put(order.getOrderId(), order);
                this.pending.remove(order.getOrderId());
            } else {
                i++;
            }
        }
    }

    @Override
    public int getCount() {
        return this.orders.size();
    }

    @Override
    public Object getItem(int position) {
        return this.orders.get(position);
    }

    @Override
    public long getItemId(int position) {
        return this.orders.get(position).getOrderId();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        Order order = (Order)this.getItem(position);
        View orderView = mInflater.inflate(R.layout.order_listview_detail, null);

        TextView idTextView = (TextView)orderView.findViewById(R.id.itemNameTextView);
        TextView quantityTextView = (TextView)orderView.findViewById(R.id.quantityTextView);
        TextView priceTextView = (TextView)orderView.findViewById(R.id.priceTextView);

        String id = String.format(Locale.US, "%04d", order.getOrderId());
        String quantity = this.appContext.getString(R.string.order_qnt).replaceAll("%qnt%", String.format(Locale.US, "%d", order.getTotalQuantity()));
        String cost = "$ " + String.format(Locale.US, "%.2f", order.getTotalCost());

        idTextView.setText(id);
        quantityTextView.setText(quantity);
        priceTextView.setText(cost);

        return orderView;
    }
}
