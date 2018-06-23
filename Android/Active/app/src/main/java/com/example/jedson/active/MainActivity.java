package com.example.jedson.active;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
    private EditText userNameInputEditText;
    private EditText userPasswordInputEditText;
    private Button userConfirmBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setupViewInstances();
        setupViewMethods();
    }

    private void setupViewInstances() {
        this.userNameInputEditText = (EditText)findViewById(R.id.userNameInputEditText);
        this.userPasswordInputEditText = (EditText)findViewById(R.id.userPasswordInputLabelEditText);
        this.userConfirmBtn = (Button)findViewById(R.id.userConfirmBtn);
    }

    private void setupViewMethods() {
        this.userConfirmBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tryLogIn();
            }
        });
    }

    private void tryLogIn() {
        String userName = this.userNameInputEditText.getText().toString();
        String userPassword = this.userPasswordInputEditText.getText().toString();

        if(checkValidAccount(userName, userPassword)) {
            goToAccountHomeActivity(userName);
        } else {
            showFailedLoginMessage();
        }

    }

    private boolean checkValidAccount(String userName, String userPassword) {
        return true;
    }

    private void goToAccountHomeActivity(String userName) {
        Intent homeScreenIntent = new Intent(this.getApplicationContext(), AcountHomeActivity.class);
        homeScreenIntent.putExtra(getResources().getString(R.string.user_name_extra_key), userName);
        startActivity(homeScreenIntent);
    }

    private void showFailedLoginMessage() {
        // Use the Builder class for convenient dialog construction
        AlertDialog.Builder builder = new AlertDialog.Builder(this);

        builder.setTitle(R.string.dialog_failed_login_title)
                .setPositiveButton(R.string.ok, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        getFragmentManager().popBackStack();
                    }
                });

        // Create the AlertDialog object and return it
        builder.create();
        builder.show();
    }
}
