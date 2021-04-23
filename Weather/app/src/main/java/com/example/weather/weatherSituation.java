package com.example.weather;

import org.json.JSONException;
import org.json.JSONObject;

public  class weatherSituation  {
    public static weatherSituation fromJson(String json) throws JSONException {
        JSONObject jsonObject=new JSONObject(json);
        weatherSituation weather=new weatherSituation();
        weather.city=jsonObject.getString("city");
        weather.update_time=jsonObject.getString("update_time");
        weather.wea=jsonObject.getString("wea");
        weather.tem=jsonObject.getString("tem");
        weather.tem_day=jsonObject.getString("tem_day");
        weather.tem_night=jsonObject.getString("tem_night");
        weather.win=jsonObject.getString("win");
        weather.win_speed=jsonObject.getString("win_speed");
        weather.air=jsonObject.getString("air");
      //  System.out.println(jsonObject.toString());
        return weather;
    }

    private String city;
    private String update_time;
    private String wea;
    private String  tem;
    private String tem_day;
    private String tem_night;
    private String win;
    private String win_speed;
    private String win_meter;
    private String air;

    public void setCity(String city) {
        this.city = city;
    }

    public void setUpdate_time(String update_time) {
        this.update_time = update_time;
    }

    public void setWea(String wea) {
        this.wea = wea;
    }

    public void setTem(String tem) {
        this.tem = tem;
    }

    public void setTem_day(String tem_day) {
        this.tem_day = tem_day;
    }

    public void setTem_night(String tem_night) {
        this.tem_night = tem_night;
    }

    public void setWin(String win) {
        this.win = win;
    }

    public void setWin_speed(String win_speed) {
        this.win_speed = win_speed;
    }

    public void setWin_meter(String win_meter) {
        this.win_meter = win_meter;
    }

    public void setAir(String air) {
        this.air = air;
    }

    public String getCity() {
        return city;
    }

    public String getTem() {
        return tem;
    }

    public String getUpdate_time() {
        return update_time;
    }

    public String getWea() {
        return wea;
    }

    public String getTem_day() {
        return tem_day;
    }

    public String getTem_night() {
        return tem_night;
    }

    public String getWin() {
        return win;
    }

    public String getWin_speed() {
        return win_speed;
    }

    public String getWin_meter() {
        return win_meter;
    }

    public String getAir() {
        return air;
    }
}
