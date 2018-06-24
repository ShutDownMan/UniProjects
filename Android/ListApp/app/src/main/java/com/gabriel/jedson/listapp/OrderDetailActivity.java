package com.gabriel.jedson.listapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.TextView;

import java.util.Locale;

public class OrderDetailActivity extends AppCompatActivity {
    Order mOrder;
    TextView orderIdTextView;
    TextView itemsQntTextView;
    TextView totalCostTextView;
    ListView orderItemsListView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_order_detail);

        setupInstances();
        setupViewContent();
    }

    private void setupInstances() {
        if(getIntent().hasExtra(getResources().getString(R.string.order_id_extra_key))) {
            this.mOrder = (Order)getIntent().getExtras().get(getResources().getString(R.string.order_id_extra_key));
        }
        this.orderIdTextView = (TextView)findViewById(R.id.orderIdTextView);
        this.itemsQntTextView = (TextView)findViewById(R.id.itemsQntTextView);
        this.totalCostTextView = (TextView)findViewById(R.id.totalCostTextView);
        this.orderItemsListView = (ListView)findViewById(R.id.orderItemsListView);
    }

    private void setupViewContent() {
        if(this.mOrder != null) {
            String id = getApplicationContext().getString(R.string.order_id).replaceAll("%order_id%", String.format(Locale.US, "%04d", mOrder.getOrderId()));
            this.orderIdTextView.setText(id);
            this.itemsQntTextView.setText(String.format(Locale.US, "%d items", mOrder.getTotalQuantity()));
            this.totalCostTextView.setText(String.format(Locale.US, "R$ %.2f", mOrder.getTotalCost()));

            setupItemListView();
        }
    }

    private void setupItemListView() {
        ItemListAdapter itemListAdapter = new ItemListAdapter(getApplicationContext(), this.mOrder.getItems());

        this.orderItemsListView.setAdapter(itemListAdapter);
    }
}