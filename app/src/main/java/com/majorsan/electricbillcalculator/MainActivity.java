package com.majorsan.electricbillcalculator;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import androidx.appcompat.app.AppCompatActivity;

import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;
import com.google.android.material.button.MaterialButton;
import com.google.android.material.textfield.TextInputEditText;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private RadioGroup optionsRadioGroup;
    private RadioButton selectedButton;
    private TextInputEditText inputUnitEditText;
    private MaterialButton calculateButton;
    private TextView billOutputTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        optionsRadioGroup = findViewById(R.id.inputOptions);
        inputUnitEditText = findViewById(R.id.electricUnitInput);
        calculateButton = findViewById(R.id.calculateBill);
        calculateButton.setEnabled(false);

        // Example of a call to a native method
        billOutputTextView = findViewById(R.id.calculatedBillOutput);
        billOutputTextView.setText(stringFromJNI());

        inputUnitEditText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                if(charSequence.toString().trim().length()==0){
                    calculateButton.setEnabled(false);
                }
                else
                    calculateButton.setEnabled(true);
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        calculateButton.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                String selectedOption="";
                String inputUnitText="";
                int selectedId = optionsRadioGroup.getCheckedRadioButtonId();
                selectedButton = findViewById(selectedId);
                selectedOption += selectedButton.getText().toString();
                try{
                    inputUnitText = inputUnitEditText.getText().toString();
                }catch (NullPointerException error){
                    Toast.makeText(getApplicationContext(),"Please provide electric units", Toast.LENGTH_SHORT).show();
                }
                double inputUnit = Double.parseDouble(inputUnitText);

                Toast toastMessage = Toast.makeText(getApplicationContext(),"",Toast.LENGTH_SHORT);
                toastMessage.setText(selectedOption+ " " + inputUnit);
                toastMessage.show();
                if(selectedOption.equals("Domestic Usage"))
                {
                    billOutputTextView.setText(domesticBillResults(inputUnit));
                }

                if(selectedOption.equals("Industrial Usage"))
                {
                    billOutputTextView.setText(industrialBillResults(inputUnit));
                }
            }
        });

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String domesticBillResults(double inputUnit);
    public native String industrialBillResults(double inputUnit);
}