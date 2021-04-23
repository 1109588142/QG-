package com.example.weather;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.recyclerview.widget.StaggeredGridLayoutManager;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import org.json.JSONException;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.BlockingDeque;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    WeatherAdapter adapter;
    private static List<weatherSituation> weatherlist= Collections.synchronizedList(new ArrayList<weatherSituation>());
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ActionBar actionBar=getSupportActionBar();
        if(actionBar!=null)
        {
            actionBar.hide();
        }
        RecyclerView recyclerView=(RecyclerView)findViewById(R.id.recycle_view);
        LinearLayoutManager layoutManager=new LinearLayoutManager(this);
        layoutManager.setOrientation(LinearLayoutManager.HORIZONTAL);
        recyclerView.setLayoutManager(layoutManager);
        adapter=new WeatherAdapter(weatherlist);
        recyclerView.setAdapter(adapter);
       SendRequest s1=new SendRequest();
       s1.sendRequestWithHttp("wu", new SendRequest.OnRequestResult() {
            @Override
            public void onResult(String result) {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        try {
                            weatherlist.add(weatherSituation.fromJson(result));
                            adapter.notifyDataSetChanged();
                        } catch (JSONException e) {
                            e.printStackTrace();
                        }
                    }
                });
            }
        });
        SendRequest s2=new SendRequest();
        s2.sendRequestWithHttp("上海", new SendRequest.OnRequestResult() {
            @Override
            public void onResult(String result) {
               runOnUiThread(new Runnable() {
                   @Override
                   public void run() {
                       try {
                           Thread.sleep(800);
                           weatherlist.add(weatherSituation.fromJson(result));
                           adapter.notifyDataSetChanged();
                       } catch (JSONException e) {
                           e.printStackTrace();
                       } catch (InterruptedException e) {
                           e.printStackTrace();
                       }
                   }
               });
            }
        });
        SendRequest s3=new SendRequest();
        s3.sendRequestWithHttp("深圳", new SendRequest.OnRequestResult() {
            @Override
            public void onResult(String result) {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        try {
                            Thread.sleep(800);
                            weatherlist.add(weatherSituation.fromJson(result));
                            adapter.notifyDataSetChanged();
                        } catch (JSONException e) {
                            e.printStackTrace();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                });
            }
        });

       EditText editText=(EditText)findViewById(R.id.edit_text);
        editText.setFocusableInTouchMode(true);
        Button button1=(Button)findViewById(R.id.button1);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String inputText=editText.getText().toString();
                Intent intent=new Intent(MainActivity.this,Searchactivity.class);
                intent.putExtra("city",inputText);
                startActivity(intent);
            }
        });
}


}