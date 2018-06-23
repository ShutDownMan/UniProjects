package com.example.jedson.addnum;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextWatcher onAdditionTextChanged;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.onAdditionTextChanged = new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {}

            @Override
            public void afterTextChanged(Editable s) {
                EditText firstNumEditText = (EditText) findViewById(R.id.firstNumEditText);
                EditText secondNumEditText = (EditText) findViewById(R.id.secondNumEditText);
                TextView resultTextVew = (TextView) findViewById(R.id.resultTextVew);

                int firstNum = Integer.parseInt(firstNumEditText.getText().toString());
                int secondNum = Integer.parseInt(secondNumEditText.getText().toString());

                resultTextVew.setText((firstNum + secondNum) + "");
            }
        };

        setupEditTexts();
    }

    private void setupEditTexts() {
        EditText firstNumEditText = (EditText) findViewById(R.id.firstNumEditText);
        EditText secondNumEditText = (EditText) findViewById(R.id.secondNumEditText);

        firstNumEditText.addTextChangedListener(this.onAdditionTextChanged);
        secondNumEditText.addTextChangedListener(this.onAdditionTextChanged);
    }
}
