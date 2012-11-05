
package com.example.tabstemplate;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class Activity0 extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // TODO Auto-generated method stub
        super.onCreate(savedInstanceState);
        TextView tv = new TextView(this);
        tv.setText("text0");
        setContentView(tv);
    }

    @Override
    protected void onDestroy() {
        // TODO Auto-generated method stub
        super.onDestroy();
        System.out.println("Activity0 onDestroy");
    }

    @Override
    protected void onPause() {
        // TODO Auto-generated method stub
        super.onPause();
        System.out.println("Activity0 onPause");
    }

    @Override
    protected void onRestart() {
        // TODO Auto-generated method stub
        super.onRestart();
        System.out.println("Activity0 onRestart");
    }

    @Override
    protected void onResume() {
        // TODO Auto-generated method stub
        super.onResume();
        System.out.println("Activity0 onResume");
    }

    @Override
    protected void onStart() {
        // TODO Auto-generated method stub
        super.onStart();
        System.out.println("Activity0 onStart");
    }

    @Override
    protected void onStop() {
        // TODO Auto-generated method stub
        super.onStop();
        System.out.println("Activity0 onStop");
    }

}
