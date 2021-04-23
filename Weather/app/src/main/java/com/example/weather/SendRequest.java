package com.example.weather;

import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

import org.json.JSONException;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLEncoder;

public class SendRequest extends AppCompatActivity {
    public static final String URL_ROOT = "https://tianqiapi.com/free/day";
    public static final String APP_ID = "73634979";
    public static final String APP_SECRET = "aRabRG2R";
    public static String  CITYNAME;
    public static weatherSituation myweather;

    interface OnRequestResult{
        void onResult(String result);
    }

    public void sendRequestWithHttp(String city,OnRequestResult onRequestResult) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                String CITY=city;

                BufferedInputStream in = null;
                String url = null;
                if(CITY.equals("wu"))
                {
                    url = URL_ROOT + "?appid=" + APP_ID + "&appsecret=" + APP_SECRET;
                }else {
                    try {
                        url = URL_ROOT + "?appid=" + APP_ID + "&appsecret=" + APP_SECRET +"&city="+ URLEncoder.encode(CITY, "utf-8");
                    } catch (UnsupportedEncodingException e) {
                        e.printStackTrace();
                    }
                }

                try {
                    HttpURLConnection conn = (HttpURLConnection) new URL(url).openConnection();
                    in = new BufferedInputStream(conn.getInputStream());
                    StringBuilder stringBuilder = new StringBuilder();
                    byte[] bytes = new byte[1024];
                    while (in.read(bytes) != -1) {
                        stringBuilder.append(new String(bytes));
                    }
                    String jsonResponse = stringBuilder.toString();
                    myweather = weatherSituation.fromJson(jsonResponse);
                    onRequestResult.onResult(jsonResponse);
                } catch (MalformedURLException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }
    public weatherSituation getweather()
    {
        return myweather;
    }
}
