package com.example.weather;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONException;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Searchactivity extends AppCompatActivity {
    public static final String URL_ROOT = "https://tianqiapi.com/free/day";
    public static final String APP_ID = "73634979";
    public static final String APP_SECRET = "aRabRG2R";
    private TextView city2;
    private TextView updatetime2;
    private TextView tem2;
    private TextView wea2;
    private TextView ttemdat2;
    private TextView temday2;
    private TextView ttemnight2;
    private TextView temnight2;
    private TextView wwin2;
    private TextView win2;
    private TextView wwwin2;
    private TextView winspeed2;
    private TextView aair2;
    private TextView air2;
    weatherSituation weather2=new weatherSituation();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_searchactivity);
        Intent intent=getIntent();
        String SelectCity=intent.getStringExtra("city");
        ActionBar actionBar=getSupportActionBar();
        if(actionBar!=null)
        {
            actionBar.hide();
        }
        city2=(TextView)findViewById(R.id.title_city2);
        updatetime2=(TextView)findViewById(R.id.title_update_time2);
        tem2=(TextView)findViewById(R.id.weather_tem2);
        wea2=(TextView)findViewById(R.id.weather_wea2);
        temday2=(TextView)findViewById(R.id.tem_day2);
        temnight2=(TextView)findViewById(R.id.tem_night2);
        win2=(TextView)findViewById(R.id.win2);
        winspeed2=(TextView)findViewById(R.id.win_speed2);
        air2=(TextView)findViewById(R.id.air2);
        loadWeather(SelectCity);

    }
    private void loadWeather(String city){
        new Thread(new Runnable() {
            @Override
            public void run() {
                BufferedInputStream in = null;
                String url = null;
                try {
                    url = URL_ROOT + "?appid=" + APP_ID + "&appsecret=" + APP_SECRET +"&city="+ URLEncoder.encode(city, "utf-8");
                } catch (UnsupportedEncodingException e) {
                    e.printStackTrace();
                }

                try {
                    HttpURLConnection conn = (HttpURLConnection) new URL(url).openConnection();
                    in = new BufferedInputStream(conn.getInputStream());
                    StringBuilder stringBuilder = new StringBuilder();
                    byte[] bytes = new byte[1024];
                    while(in.read(bytes) != -1){
                        stringBuilder.append(new String(bytes));
                    }

                    String jsonResponse = stringBuilder.toString();
                    weatherSituation weather = weatherSituation.fromJson(jsonResponse);
                    showWeather(weather);
                } catch (IOException | JSONException e) {
                    e.printStackTrace();
                } finally {
                    try{
                        if(in != null){
                            in.close();
                        }
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }

            }
        }).start();
    }
    private void showWeather(weatherSituation weather){

        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                city2.setText(weather.getCity());
                updatetime2.setText(weather.getUpdate_time());
                tem2.setText(weather.getTem());
                wea2.setText(weather.getWea());
                temday2.setText(weather.getTem_day());
                temnight2.setText(weather.getTem_night());
                win2.setText(weather.getWin());
                winspeed2.setText(weather.getWin_speed());
                air2.setText(weather.getAir());
            }
        });
    }
    }
