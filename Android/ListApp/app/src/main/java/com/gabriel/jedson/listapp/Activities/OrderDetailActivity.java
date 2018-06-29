package com.gabriel.jedson.listapp.Activities;

import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.TextView;

import com.gabriel.jedson.listapp.Adapters.ItemListAdapter;
import com.gabriel.jedson.listapp.Classes.Order;
import com.gabriel.jedson.listapp.R;

import java.util.Locale;

public class OrderDetailActivity extends AppCompatActivity {
    Order mOrder;
    TextView orderIdTextView;
    TextView itemsQntTextView;
    TextView totalCostTextView;
    ListView orderItemsListView;
    SwipeRefreshLayout itemListSwipeRefreshLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_order_detail);

        setupInstances();
        setupViewMethods();
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
        this.itemListSwipeRefreshLayout = (SwipeRefreshLayout)findViewById(R.id.itemListSwipeRefreshLayout);
    }

    private void setupViewMethods() {
        this.itemListSwipeRefreshLayout.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                refreshListView();
                itemListSwipeRefreshLayout.setRefreshing(false);
            }
        });
    }

    private void setupViewContent() {
        if(this.mOrder != null) {
            String id = getApplicationContext().getString(R.string.order_id).replaceAll("%order_id%", String.format(Locale.US, "%04d", mOrder.getOrderId()));
            this.orderIdTextView.setText(id);
            this.itemsQntTextView.setText(String.format(Locale.US, "%d items", mOrder.getTotalQuantity()));
            this.totalCostTextView.setText(String.format(Locale.US, "$ %.2f", mOrder.getTotalCost()));

            refreshListView();
        }
    }

    private void refreshListView() {
        ItemListAdapter itemListAdapter = new ItemListAdapter(getApplicationContext(), this.mOrder.getItems());

        this.orderItemsListView.setAdapter(itemListAdapter);
    }
}
