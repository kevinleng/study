package com.example.open3g;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;

public class MainActivity extends Activity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        /*
        <intent
        android:action="android.intent.action.MAIN"
        android:targetPackage="com.android.phone"
        android:targetClass="com.android.phone.Settings" /> */
        
        Intent intent = new Intent(Intent.ACTION_MAIN);
        intent.setClassName("com.android.phone", "com.android.phone.Settings");
        
        startActivity(intent);
        finish();
    }

}
