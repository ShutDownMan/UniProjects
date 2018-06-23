package com.example.jedson.active;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class AcountHomeActivity extends AppCompatActivity {
    private TextView userGreetingsTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_acount_home);

        setupViewInstances();
        setupViewText();
        //setupViewMethods();
    }

    private void setupViewInstances() {
        this.userGreetingsTextView = (TextView)findViewById(R.id.userGreetingsTextView);
    }

    private void setupViewText() {
        setupGreetingsText();
    }

    private void setupGreetingsText() {
        String userName = "user";
        String userNameExtraKey = getResources().getString(R.string.user_name_extra_key);

        if(getIntent().hasExtra(userNameExtraKey)) {
            userName = getIntent().getExtras().getString(userNameExtraKey);
        }

        String greetingsContent = getResources().getString(R.string.user_greetings_content);
        greetingsContent = greetingsContent.replaceAll("%user%", userName);

        this.userGreetingsTextView.setText(greetingsContent);
    }
}
